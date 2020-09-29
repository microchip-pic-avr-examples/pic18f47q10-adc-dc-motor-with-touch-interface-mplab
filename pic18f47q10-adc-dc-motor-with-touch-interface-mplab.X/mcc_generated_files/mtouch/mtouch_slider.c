/*
    MICROCHIP SOFTWARE NOTICE AND DISCLAIMER:

    You may use this software, and any derivatives created by any person or
    entity by or on your behalf, exclusively with Microchip's products.
    Microchip and its subsidiaries ("Microchip"), and its licensors, retain all
    ownership and intellectual property rights in the accompanying software and
    in all derivatives hereto.

    This software and any accompanying information is for suggestion only. It
    does not modify Microchip's standard warranty for its products.  You agree
    that you are solely responsible for testing the software and determining
    its suitability.  Microchip has no obligation to modify, test, certify, or
    support the software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE APPLY TO THIS SOFTWARE, ITS INTERACTION WITH MICROCHIP'S
    PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT, WILL MICROCHIP BE LIABLE, WHETHER IN CONTRACT, WARRANTY, TORT
    (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), STRICT LIABILITY,
    INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF
    ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWSOEVER CAUSED, EVEN IF
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE
    FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S TOTAL
    LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED
    THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR
    THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF
    THESE TERMS.
 */

/* Include files */
#include "mtouch_slider.h"
#include "mtouch_button.h"

/* 
 * =======================================================================
 * Slider State Machine
 * =======================================================================
 */
enum mtouch_slider_state
{
    MTOUCH_SLIDER_STATE_initializing = 0u,
    MTOUCH_SLIDER_STATE_notPressed = 1u,
    MTOUCH_SLIDER_STATE_pressed = 2u
};

/* 
 * =======================================================================
 * Slider manifest constants
 * =======================================================================
 */
#define SLIDER_RESOLUTION_BITS              12u      
#define SLIDER_RESOLUTION_VALUE             (uint16_t)((uint16_t)1u << SLIDER_RESOLUTION_BITS) 
#define SLIDER_DEAD_BAND_ONE_PERCENT        (SLIDER_RESOLUTION_VALUE/100u)

#define SLIDER_INTERPOLATION_16PLUS         8u

/* Slider status bits */
#define SLIDER_CURRENT_STATE        (uint8_t)((uint8_t)3u<<0u) 		/* Bit 0-1 */
#define SLIDER_POSITION_CHANGED     (uint8_t)((uint8_t)1u<<2u) 		/* Bit 2  */
#define SLIDER_REBURST_REQUEST      (uint8_t)((uint8_t)1u<<7u) 		/* Bit 7 */


/* Extract Resolution / Deadband */
#define SLIDER_RESOLUTION(m) (uint8_t)(((m) & 0xF0u) >> 4u)
#define SLIDER_DEADBAND(m)   (uint8_t)((m) & 0x0Fu)

/* Combine Resolution / Deadband */
#define SLIDER_RESOL_DEADBAND(r,p) (uint8_t)(((r) << 4u)|(p))

/* 
 * =======================================================================
 * Slider Segment Type Structure
 * =======================================================================
 */
typedef struct
{
    const enum mtouch_slider_names slider;
    const enum mtouch_slider_type type;
    const enum mtouch_sensor_names startSegment;
    const uint8_t segmentCount;
    const uint8_t resolDeadband;
    const uint8_t positionHysteresis;
    uint16_t contactThreshold;
    uint8_t rightHysteresis;
    uint8_t leftHysteresis;
    uint16_t rawPosition;
    uint16_t sliderPosition;
    uint16_t contactSize;
    uint8_t sliderStatus;
} mtouch_slider_t;

/* Slider Initialization */
/* By default, contactThreshold parameter should be set equal to threshold value of the underlying keys.
 * Then the parameter has to be tuned based on the actual contact size of the touch when moved over the slider.
 */
static mtouch_slider_t mtouch_slider[MTOUCH_SLIDERS] = {
    /* Slider1 */
    {
        Slider1,
        Slider1_TYPE,
        Slider1_START_SEGMENT,
        Slider1_NUM_SEGMENTS,
        SLIDER_RESOL_DEADBAND(Slider1_RESOLUTION, Slider1_DEADBAND),
        Slider1_POS_HYST,
        Slider1_THRESHOLD,
        0u, 0u, 0u, 0u, 0u, 0u
    }
};

/* Static variables */
static uint8_t sliderGroupStatus = 0u;
static uint16_t resol_value;
static uint8_t resol_bits;
static uint8_t middle_node;
static bool wheel_sensor_middle_channel_zero;
static int16_t left_signal = 0, right_signal = 0, middle_signal = 0;

/* Prototypes*/
static uint16_t calculate_raw_position  (mtouch_slider_t* slider);
static uint16_t positional_hysteresis   (mtouch_slider_t* slider, uint16_t current_position);
static uint16_t divide                  (uint16_t numerator, uint16_t denominator, uint8_t exponent);
static uint16_t interpolate             (uint16_t delta1, uint16_t delta2, uint16_t delta3, uint8_t num_bits);
static int16_t  get_difference          (mtouch_slider_t* slider, uint16_t previous_position, uint16_t current_position);
static uint16_t moving_average_filter   (mtouch_slider_t* slider, uint16_t current_position);
static void     Slider_Initialize       (enum mtouch_slider_names sliderName);
static void     Slider_Service          (enum mtouch_slider_names sliderName);
static int16_t  Slider_FindRight        (mtouch_slider_t* slider);
static int16_t  Slider_FindLeft         (mtouch_slider_t* slider);
static int16_t  Slider_FindMiddle       (mtouch_slider_t* slider);
static void     Slider_DefaultCallback  (enum mtouch_slider_names slider);

/*
 * =======================================================================
 *  Callback Function Pointers
 * =======================================================================
 */
static void (*callback_position_changed)   (enum mtouch_slider_names) = Slider_DefaultCallback;
static void (*callback_pressed)            (enum mtouch_slider_names) = Slider_DefaultCallback;
static void (*callback_released)           (enum mtouch_slider_names) = Slider_DefaultCallback;

/*============================================================================
Name : divide
------------------------------------------------------------------------------
Purpose: general unsigned division routine
Input  : numerator - the number that's divided
denominator - the number that the numerator is divided by
exponent - a power of 2 multiplier for the result
Output : (return value) - the result of the division divided by 2^exponent
- in case of an overflow, 0xffffu is returned
Notes  : The result is rounded down according to the resolution available in
the return value

Examples :
numerator denominator exponent => (result)
6          1          0           6    (6<<0)/1
6          2          0           3    (6<<0)/2
6          3          0           2
6          4          0           1
6          6          0           1
6          7          0           0
6         12          0           0

6          1          1          12    (6<<1)/1
6          2          1           6    (6<<1)/2
6          3          1           4
6          4          1           3
6          6          1           2
6         12          1           1

6          1          2          24    (6<<2)/1
6          2          2          12    (6<<2)/2
6          3          2           8
6          4          2           6
6          6          2           4
6         12          2           2

6          1         15        0xffff  (overflow)
6          2         15        0xffff  (overflow)
6          3         15        0xffff  (overflow)
6          4         15        0xc000  (6<<15)/4
6          6         15        0x8000  (6<<15)/6
6         12         15        0x4000  (6<<15)/12
============================================================================*/
static uint16_t divide(uint16_t numerator, uint16_t denominator, uint8_t exponent)
{
    uint16_t result = 0u;

    /* there is one shift less than expected */
    exponent++;

    if (denominator != 0u)
    {
        /*
         * scale the numerator and denominator to avoid overflows -
         * we shift them up to use the MSB of the 16 bit variables and keep track
         * of the shifts done in exponent
         */
        while (((numerator & 0x8000u) == 0u) && (exponent != 0u))
        {
            exponent--;
            numerator = (uint16_t) (numerator << 1);
        }

        while ((denominator & 0x8000u) == 0u)
        {
            exponent++;
            denominator = (uint16_t) (denominator << 1);
        }

        /* having done the scaling, we now do the actual divide */
        while ((exponent != 0u) && ((result & 0x8000u) == 0u))
        {
            result = (uint16_t) (result << 1);
            exponent--;
            if (numerator >= denominator)
            {
                numerator -= denominator;
                result++;
            }
            denominator >>= 1;
        }
    }
    else
    {
        result = 0xffffu;
    }

    /* if we have exponent left we have overflowed */
    if (exponent)
    {
        result = 0xffffu;
    }

    return result;
}

/*
 * ==========================================================================
 * Find the difference between current and previous positions.
 * This method also takes care of the rollover condition which occurs on the 
 * wheel sensor when the touch rolls over from last sensor to first sensor
 * ==========================================================================
 */
static int16_t get_difference(mtouch_slider_t* slider, uint16_t previous_position, uint16_t current_position)
{
    int16_t diff;
    uint16_t rollover_threshold;

    /* Initialize necessary parameters */
    rollover_threshold = resol_value >> 1u;

    /* Calculate difference between current_position and previous_position */
    diff = ((int16_t) current_position - (int16_t) previous_position);

    /* Check condition: wheel sensor with rollover occurred */
    if (slider->type == MTOUCH_TYPE_WHEEL)
    {
        if (diff < (int16_t) 0u)
        {
            if ((0 - (int16_t) rollover_threshold) > diff) /* forward rollover */
            {
                diff = (diff + (int16_t) resol_value);
            }
        }
        else
        {
            if (diff > ((int16_t) rollover_threshold)) /* reverse rollover */
            {
                diff = (diff - (int16_t) resol_value);
            }
        }
    }

    return diff;
}

/*
 * =======================================================================
 * To provide the hysteresis filtering over the calculated position
 * =======================================================================
 */
static uint16_t positional_hysteresis(mtouch_slider_t* slider, uint16_t current_position)
{
    uint16_t filtered_position, previous_position;
    uint8_t hyst_width;
    int16_t distance;
    uint8_t polarity = 0u;


    hyst_width = slider->positionHysteresis;
    previous_position = slider->sliderPosition;

    /* get distance */
    distance = get_difference(slider, previous_position, current_position);

    if (distance < 0)
    {
        distance = (0 - distance);
        polarity = 1u;
    }

    /* Find the distance moved from previous position to current calculated position */
    /* moving right (towards 255) gives +ve movement, left (towards 0) gives a -ve movement */
    if ((polarity == 1u) && (distance > (int16_t) slider->leftHysteresis))
    {
        /* we are scrolling left */
        slider->rightHysteresis = hyst_width;
        slider->leftHysteresis = 0u;
        filtered_position = current_position;
    }
    else if ((polarity == 0u) && (distance > (int16_t) slider->rightHysteresis))
    {
        /* we are scrolling right */
        slider->rightHysteresis = 0u;
        slider->leftHysteresis = hyst_width;
        filtered_position = current_position;
    }
    else
    {
        /* we have not moved beyond hysteresis threshold in either direction */
        filtered_position = slider->sliderPosition;
    }

    return filtered_position;
}

/*
 * ===========================================================================================================
 * Moving average filter implementation using 2 samples 
 * This method divides the difference in positions by 2 and the output is added/subtracted with the previous 
 * position. this is equivalent to 2 sample moving average --> (curr_position + prev_position)/2 
 * =============================================================================================================
 */
static uint16_t moving_average_filter(mtouch_slider_t* slider, uint16_t current_position)
{
    uint16_t filtered_position, dist_temp;
    uint16_t previous_position;
    int16_t distance;

    previous_position = slider->rawPosition;
    /* get difference between previous vs current position */
    distance = get_difference(slider, previous_position, current_position);

    /* if the distance moved is 1 count, no average is required */
    if ((distance == 1) || (distance == -1))
    {
        filtered_position = previous_position;
    }
    else
    {
        /* this is equivalent to 2 sample moving average */
        if (distance < 0)
        {
            distance = (0 - distance);
            dist_temp = (uint16_t) distance;
            dist_temp = dist_temp >> 1u;
            distance = (int16_t) (0 - (int16_t) dist_temp);

        }
        else
        {
            dist_temp = (uint16_t) (distance);
            dist_temp = dist_temp >> 1u;
            distance = (int16_t) (dist_temp);
        }
        filtered_position = (previous_position) + (uint16_t) (distance);
        filtered_position &= (resol_value - 1u);
    }

    return filtered_position;
}

/*
 * =======================================================================
 * Interpolate between three deltas
 * =======================================================================
 */
static uint16_t interpolate(uint16_t delta1, uint16_t delta2, uint16_t delta3, uint8_t num_bits)
{
    uint16_t rtnval;

    if (delta1 >= delta3)
    {
        rtnval = (uint16_t) ((delta2 - delta3) + (delta1 - delta3));
        rtnval = (uint16_t) (divide((uint16_t) (delta2 - delta3), rtnval, num_bits) - (uint16_t) ((uint16_t) 1u << (num_bits)));
    }
    else
    {
        rtnval = (uint16_t) ((delta2 - delta1) + (delta3 - delta1));
        rtnval = divide((uint16_t) (delta3 - delta1), rtnval, num_bits);
    }

    return rtnval;
}

/*
 * ==================================================================
 * Calculates the slider middle signal
 * ==================================================================
 */
static int16_t Slider_FindMiddle(mtouch_slider_t* slider)
{
    uint8_t i;
    int16_t channelDelta, maximumDelta;

    maximumDelta = 0;
    middle_node = slider->startSegment;

    /* loop over all channels in slider/wheel and find the peak node */
    for (i = slider->startSegment; i < (slider->startSegment + slider->segmentCount); i++)
    {
        /* get channel delta */
        channelDelta = (int16_t) MTOUCH_Button_Deviation_Get(i);

        /* find largest signal and assign as middle signal value*/
        if (channelDelta > maximumDelta)
        {
            middle_node = i;
            maximumDelta = channelDelta;
        }
    }

    return maximumDelta;
}

/*
 * =================================================================
 * Calculates the slider left signal
 * =================================================================
 */
static int16_t Slider_FindLeft(mtouch_slider_t* slider)
{
    uint8_t ref_node = slider->startSegment;

    wheel_sensor_middle_channel_zero = false;

    /* Identify the left signal */
    if (middle_node == ref_node)
    {
        if (slider->type == MTOUCH_TYPE_WHEEL)
        {
            /* logical coupling of last and first channels - for wheels */
            /* left signal is now the far-right */
            left_signal = (int16_t) MTOUCH_Button_Deviation_Get(ref_node + slider->segmentCount - 1u);

            /* set flag: this is a rotor, and middle is channel 0 */
            right_signal = (int16_t) MTOUCH_Button_Deviation_Get(ref_node + 1u);

            if(left_signal > right_signal)
            {
                wheel_sensor_middle_channel_zero = true;
            }
        }
        else
        {
            /* linear slider - we are on the far 'bottom' section */
            left_signal = 0;
        }
    }
    else
    {
        left_signal = (int16_t) MTOUCH_Button_Deviation_Get(middle_node - 1u);
    }

    if (left_signal < 0)
    {
        left_signal = 0;
    }
    return left_signal;
}

/*
 * ==============================================================
 * Calculates the slider right signal
 * ==============================================================
 */
static int16_t Slider_FindRight(mtouch_slider_t* slider)
{
    uint8_t ref_node = slider->startSegment;

    /* Identify the right signal */
    if (middle_node == (ref_node + slider->segmentCount - 1u))
    {
        if (slider->type == MTOUCH_TYPE_WHEEL)
        {
            /* logical coupling of first and last channels - for wheels */
            /* right signal is now the far-left */
            right_signal = (int16_t) MTOUCH_Button_Deviation_Get(ref_node);
        }
        else
        {
            /* linear slider - we are on the far 'top' section */
            right_signal = 0;
        }
    }
    else
    {
        right_signal = (int16_t) MTOUCH_Button_Deviation_Get(middle_node + 1u);
    }

    if (right_signal < 0)
    {
        right_signal = 0;
    }

    return right_signal;

}

/*
 * =======================================================================================
 * Calculates the slider/wheel position from the delta values of the slider nodes
 * =======================================================================================
 */
static uint16_t calculate_raw_position(mtouch_slider_t* slider)
{
    uint8_t ref_node;
    uint8_t interpolation_bits;
    uint8_t interpolation_scale;
    uint8_t size;
    uint16_t position, deadband, deadband_set;

    /* Initialize necessary parameters */
    ref_node = slider->startSegment;
    size = slider->segmentCount;


    /* STEP 1 : IDENTIFY THE MIDDLE, LEFT AND RIGHT SIGNALS */

    /* This information is already obtained when calculating contact size */


    /*  STEP 2 : CALCULATE THE POSITION WITH INTERNAL RESOLUTION SETTING (default = 12 bits) */
    if (size < 16u)
    {
        interpolation_bits = SLIDER_RESOLUTION_BITS;
        interpolation_scale = 0u;
    }
    else
    {
        interpolation_bits = SLIDER_INTERPOLATION_16PLUS;
        interpolation_scale = 4u;
    }

    /* Obtain slider/wheel position with middle node as reference */
    if (wheel_sensor_middle_channel_zero == 1u)
    {
        position = (uint16_t) ((uint16_t) (size) << interpolation_bits);
    }
    else
    {
        position = (uint16_t) ((middle_node - ref_node) << interpolation_bits);
    }

    /* Interpolate the middle signal offset with left/right signals and adjust the same with the calculated position */
    position += interpolate((uint16_t) left_signal, (uint16_t) middle_signal, (uint16_t) right_signal, interpolation_bits);

    /* scale to internal library resolution */
    if (size > 2u)
    {
        if (slider->type == MTOUCH_TYPE_WHEEL)
        {
            position = divide(position, (uint16_t) (size), interpolation_scale);
        }
        else
        {
            position = divide(position, (uint16_t) ((uint16_t) size - 1u), interpolation_scale);
        }
    }

    /* trap overflow due to when get zero deltas 1 and 3 on final channel of slider */
    if (position > SLIDER_RESOLUTION_VALUE)
    {
        position = SLIDER_RESOLUTION_VALUE;
    }

    /* STEP 3 : ADJUST THE POSITION WITH DEAD BAND AT START AND END NODES (not applicable to wheel sensor) */
    if ((slider->type == MTOUCH_TYPE_SLIDER) && (0u != (slider->resolDeadband & (0x0Fu))))
    {
        /* Adjust the position with deadband offset on both sides */
        deadband = 0u;
        deadband_set = (uint8_t) (slider->resolDeadband & (0x0Fu));
        while (deadband_set > 0u)
        {
            deadband_set--;
            deadband += SLIDER_DEAD_BAND_ONE_PERCENT;
        }

        if (position < deadband)
        {
            position = 0u;
        }
        else
        {
            position = (uint16_t) (position - deadband);
        }

        /* scale the position according to the new range after dead band adjustment */
        /* position = (position * resolution)/(resolution-deadband) */
        /* Position scaled to compensate for deadband. New Position = (Full length position / actual_length) */
        position = divide(position, (uint16_t) (SLIDER_RESOLUTION_VALUE - (uint16_t) (deadband << 1u)), 12u);
    }

    /* STEP 4 : SCALE TO USER RESOLUTION */
    position = position >> (SLIDER_RESOLUTION_BITS - resol_bits);

    /* validation against overflow */
    if (position > (uint16_t) (((uint16_t) 1 << resol_bits)) - 1u)
    {
        position = (uint16_t) ((uint16_t) 1 << resol_bits) - 1u;
    }

    return position;
}

/*
 * =======================================================================
 * Calculate contact size
 * =======================================================================
 */
static uint16_t calculate_contact_size(mtouch_slider_t* slider)
{
    uint16_t contact_size;

    middle_signal = Slider_FindMiddle(slider);
    right_signal = Slider_FindRight(slider);
    left_signal = Slider_FindLeft(slider);

    if (right_signal > left_signal)
    {
        contact_size = middle_signal + right_signal;
    }
    else
    {
        contact_size = middle_signal + left_signal;
    }

    if (contact_size < slider->contactThreshold)
    {
        contact_size = 0u;
    }

    return contact_size;
}

/*
 * =======================================================================
 * Calculate slider position
 * =======================================================================
 */
static uint16_t calculate_position(mtouch_slider_t* slider)
{
    uint16_t raw_position, filtered_position, position;

    /* Calculate Position */
    raw_position = calculate_raw_position(slider);

    /* Apply 2 sample IIR filter on raw position */
    if ((slider->sliderStatus & SLIDER_CURRENT_STATE) != MTOUCH_SLIDER_STATE_pressed)
    {
        /* New contact -> No position filter */
        filtered_position = raw_position;
    }
    else
    {
        filtered_position = moving_average_filter(slider, raw_position);
    }

    slider->rawPosition = raw_position;

    /* Apply hysteresis filter */
    position = positional_hysteresis(slider, filtered_position);

    return position;

}

/*
 * =======================================================================
 * Slider Service
 * =======================================================================
 */
static void Slider_Service(enum mtouch_slider_names sliderName)
{

    uint16_t segment, position;
    uint8_t status = 0u, group_status = 0u;
    uint8_t valid_contact_found = 0u;

    if (sliderName < MTOUCH_SLIDERS)
    {

        mtouch_slider_t* slider = &mtouch_slider[sliderName];

        if ((slider->type <= MTOUCH_TYPE_WHEEL) || (slider->resolDeadband <= 0xCFu))
        {
            /* Initialize necessary parameters */
            resol_bits = (slider->resolDeadband & 0xF0u) >> 4u;
            resol_value = (uint16_t) ((uint16_t) 1u << resol_bits);

            /* calculate the contact size */
            slider->contactSize = calculate_contact_size(slider);

            if (slider->contactSize >= slider->contactThreshold)
            {
                /* Previous contact requires only contact_size > min*/
                if ((slider->sliderStatus & SLIDER_CURRENT_STATE) == MTOUCH_SLIDER_STATE_pressed)
                {
                    valid_contact_found = 1u;
                }
                else
                {   /* New contact requires both Key Detect and contact_size > min */
                    /* Iterate through all the Keys in slider checking for touch detect */
                    segment = slider->startSegment;
                    do
                    {
                        if (MTOUCH_Button_isPressed(segment))
                        {
                            /* Flag detection */
                            valid_contact_found = 1u;
                            callback_pressed(sliderName);
                            break;
                        }

                        /* Increment segment */
                        segment = segment + 1u; 

                    }
                    while (segment < (slider->startSegment + slider->segmentCount));
                }
            }
            else
            {
                /* Do Nothing */
            }

            if (0u == valid_contact_found)
            {
                /* No keys in detect now, contact not found */
                slider->contactSize = 0u;
                /* set slider to idle state */
                if ((slider->sliderStatus & SLIDER_CURRENT_STATE) == MTOUCH_SLIDER_STATE_pressed)
                {
                    slider->sliderStatus = MTOUCH_SLIDER_STATE_notPressed;
                    callback_released(sliderName);
                }
                else
                {
                    slider->sliderStatus = MTOUCH_SLIDER_STATE_notPressed;
                }
            }
            else
            {
                /* Valid contact, calculate position */
                position = calculate_position(slider);

                /* check for position change with respect to previous value and update status */
                if (slider->sliderPosition != position)
                {
                    status |= SLIDER_POSITION_CHANGED;
                    slider->sliderPosition = position;
                    callback_position_changed(sliderName);
                }

                /* set slider to pressed state */
                status |= MTOUCH_SLIDER_STATE_pressed;
                /* if position calculated based on one active key, update status */
                status |= SLIDER_REBURST_REQUEST;
            }

            /* Get updated status information */
            slider->sliderStatus = status;
            /* Reburst Group status = logical OR of all individual slider reburst and pressed status */
            group_status |= (uint8_t) (status & (SLIDER_REBURST_REQUEST | MTOUCH_SLIDER_STATE_pressed));
            /* Update group status */
            sliderGroupStatus |= group_status;

        }/* Valid parameters */
    }/* Valid slider */

}

/*
 * =======================================================================
 * Slider Initialize
 * =======================================================================
 */
static void Slider_Initialize(enum mtouch_slider_names sliderName)
{
    if (sliderName < MTOUCH_SLIDERS)
    {
        mtouch_slider_t* slider = &mtouch_slider[sliderName];

        /* Initialize state */
        slider->sliderStatus = MTOUCH_SLIDER_STATE_initializing;
        /* Initialize hysteresis variables */
        slider->rightHysteresis = 0u;
        slider->leftHysteresis = slider->positionHysteresis;
        /* Initialize position variables */
        slider->rawPosition = 0u;
        slider->sliderPosition = 0u;
        slider->contactSize = 0u;
    }
}

/*
 * =======================================================================
 * Get Slider group status
 * =======================================================================
 */
uint8_t MTOUCH_Slider_GroupStatus_Get(void)
{
    return sliderGroupStatus;
}

/*
 * =======================================================================
 * To Check if Slider is pressed
 * =======================================================================
 */
bool MTOUCH_Slider_isInitialized(enum mtouch_slider_names sliderName)
{
    if (sliderName < MTOUCH_SLIDERS)
    {
        return ((mtouch_slider[sliderName].sliderStatus & SLIDER_CURRENT_STATE) == MTOUCH_SLIDER_STATE_initializing) ? false : true;
    }
    else
        return false;
}

/*
 * =======================================================================
 * To Check if Slider is pressed
 * =======================================================================
 */
bool MTOUCH_Slider_isPressed(enum mtouch_slider_names sliderName)
{
    if (sliderName < MTOUCH_SLIDERS)
    {
        return ((mtouch_slider[sliderName].sliderStatus & SLIDER_CURRENT_STATE) == MTOUCH_SLIDER_STATE_pressed) ? true : false;
    }
    else
        return false;
}

/*
 * =======================================================================
 * To Check if Slider reburst required
 * =======================================================================
 */
bool MTOUCH_Slider_isReburstRequest(enum mtouch_slider_names sliderName)
{
    if (sliderName < MTOUCH_SLIDERS)
    {
        return (mtouch_slider[sliderName].sliderStatus & SLIDER_REBURST_REQUEST) ? true : false;
    }
    else
        return false;
}

/*
 * =======================================================================
 * To Check if Slider position changed
 * =======================================================================
 */
bool MTOUCH_Slider_isPositionChanged(enum mtouch_slider_names sliderName)
{
    if (sliderName < MTOUCH_SLIDERS)
    {
        return (mtouch_slider[sliderName].sliderStatus & SLIDER_POSITION_CHANGED) ? true : false;
    }
    else
        return false;
}


/*
 * =======================================================================
 * Get Slider Status
 * =======================================================================
 */
uint8_t MTOUCH_Slider_Status_Get(enum mtouch_slider_names sliderName)
{
    if (sliderName < MTOUCH_SLIDERS)
    {
        return (mtouch_slider[sliderName].sliderStatus);
    }
    else
        return 0u;
}

/*
 * =======================================================================
 * Get Slider Position
 * =======================================================================
 */
uint16_t MTOUCH_Slider_Position_Get(enum mtouch_slider_names sliderName)
{
    if (sliderName < MTOUCH_SLIDERS)
    {
        return (mtouch_slider[sliderName].sliderPosition);
    }
    else
        return 0u;
}

/*
 * =======================================================================
 * Get Slider Threshold
 * =======================================================================
 */
uint16_t MTOUCH_Slider_Threshold_Get(enum mtouch_slider_names sliderName)
{
    if (sliderName < MTOUCH_SLIDERS)
    {
        return (mtouch_slider[sliderName].contactThreshold);
    }
    else
        return 0u;
}

/*
 * =======================================================================
 * Set Slider Threshold
 * =======================================================================
 */
uint8_t MTOUCH_Slider_Threshold_Set(enum mtouch_slider_names sliderName, uint16_t threshold)
{
    if (sliderName < MTOUCH_SLIDERS)
    {
        mtouch_slider[sliderName].contactThreshold = threshold;
        return 1u;
    }
    else
        return 0u;
}

/*
 * =======================================================================
 * Get Slider Deviation
 * =======================================================================
 */
uint16_t MTOUCH_Slider_Deviation_Get(enum mtouch_slider_names sliderName)
{
    if (sliderName < MTOUCH_SLIDERS)
    {
        return (mtouch_slider[sliderName].contactSize);
    }
    else
        return 0u;
}

/*
 * =======================================================================
 * Slider Initialize
 * =======================================================================
 */
void MTOUCH_Slider_InitializeAll(void)
{
    enum mtouch_slider_names slider;

    for (slider = 0u; slider < MTOUCH_SLIDERS; slider++)
    {
        Slider_Initialize(slider);
    }
}

/*
 * =======================================================================
 * Slider Service
 * =======================================================================
 */
void MTOUCH_Slider_ServiceAll(void)
{
    enum mtouch_slider_names slider;

    /* Initialize slider group status */
    sliderGroupStatus = 0u;

    for (slider = 0u; slider < MTOUCH_SLIDERS; slider++)
    {
        Slider_Service(slider);
    }
}


/*
 * =======================================================================
 * Slider Press/Release Callback Setter Functions
 * =======================================================================
 */
static void Slider_DefaultCallback(enum mtouch_slider_names slider) { }
void MTOUCH_Slider_SetPositionChangedCallback(void (*callback)(enum mtouch_slider_names))
{
    callback_position_changed = callback;
}

void MTOUCH_Slider_SetPressedCallback(void (*callback)(enum mtouch_slider_names))
{
    callback_pressed = callback;
}

void MTOUCH_Slider_SetReleasedCallback(void (*callback)(enum mtouch_slider_names))
{
    callback_released = callback;
}

