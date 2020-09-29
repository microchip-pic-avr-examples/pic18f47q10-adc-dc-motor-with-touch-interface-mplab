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

#ifndef __MTOUCH_SLIDER_H__
#define __MTOUCH_SLIDER_H__

/*----------------------------------------------------------------------------
  include files
----------------------------------------------------------------------------*/
#include "../mcc.h"
#include <stdint.h>
#include <__null.h>
#include "mtouch_button.h"

/* 
 * =======================================================================
 * Slider Enumerations
 * =======================================================================
 */
enum mtouch_slider_type
{
    MTOUCH_TYPE_SLIDER    = 0u,
    MTOUCH_TYPE_WHEEL     = 1u
};

enum mtouch_slider_names
{
        Slider1 = 0
};

/* slider resolution setting */
typedef enum tag_resolution_t
{
        RESOL_2_BIT = 2,
        RESOL_3_BIT,
        RESOL_4_BIT,
        RESOL_5_BIT,
        RESOL_6_BIT,
        RESOL_7_BIT,
        RESOL_8_BIT,
        RESOL_9_BIT,
        RESOL_10_BIT,
        RESOL_11_BIT,
        RESOL_12_BIT	
}scr_resolution_t;

/* slider deadband percentage setting */
typedef enum tag_deadband_t
{
        DB_NONE,
        DB_1_PERCENT,
        DB_2_PERCENT,
        DB_3_PERCENT,
        DB_4_PERCENT,
        DB_5_PERCENT,
        DB_6_PERCENT,
        DB_7_PERCENT,
        DB_8_PERCENT,
        DB_9_PERCENT,
        DB_10_PERCENT,
        DB_11_PERCENT,
        DB_12_PERCENT,
        DB_13_PERCENT,
        DB_14_PERCENT,
        DB_15_PERCENT
}scr_deadband_t;

/*----------------------------------------------------------------------------
 *   Slider APIs
 *----------------------------------------------------------------------------*/
/*============================================================================
void   MTOUCH_Slider_InitializeAll (void)
------------------------------------------------------------------------------
Purpose: Initialize all sliders
Input  : void
Output : void
Notes  : none
============================================================================*/
void   MTOUCH_Slider_InitializeAll (void);

/*============================================================================
void   MTOUCH_Slider_ServiceAll (void)
------------------------------------------------------------------------------
Purpose: Srevice all sliders
Input  : void
Output : void
Notes  : none
============================================================================*/
void   MTOUCH_Slider_ServiceAll    (void);

/*============================================================================
bool MTOUCH_Slider_isInitialized(enum mtouch_slider_names sliderName)
------------------------------------------------------------------------------
Purpose: To check if slider is initialised  
Input  : slider id
Output : bool; returns true if initalized and false if not initialized
Notes  : none
============================================================================*/
bool MTOUCH_Slider_isInitialized(enum mtouch_slider_names sliderName);

/*============================================================================
bool MTOUCH_Slider_isPressed(enum mtouch_slider_names sliderName)
------------------------------------------------------------------------------
Purpose: To check if slider is pressed  
Input  : slider id
Output : bool; returns true if pressed and false if not pressed
Notes  : none
============================================================================*/
bool MTOUCH_Slider_isPressed(enum mtouch_slider_names sliderName);

/*============================================================================
bool MTOUCH_Slider_isReburstRequest(enum mtouch_slider_names sliderName)
------------------------------------------------------------------------------
Purpose: To check if slider is reburst requested  
Input  : slider id
Output : bool; returns true if rebust requested ; false else
Notes  : none
============================================================================*/
bool MTOUCH_Slider_isReburstRequest(enum mtouch_slider_names sliderName);

/*============================================================================
bool MTOUCH_Slider_isPositionChanged(enum mtouch_slider_names sliderName)
------------------------------------------------------------------------------
Purpose: To check if slider position changed 
Input  : slider id
Output : bool; returns 1 if position changed ; 0 else
Notes  : none
============================================================================*/
bool MTOUCH_Slider_isPositionChanged(enum mtouch_slider_names sliderName);

/*============================================================================
uint8_t MTOUCH_Slider_Status_Get(enum mtouch_slider_names sliderName)
------------------------------------------------------------------------------
Purpose: Get a slider current status
Input  : slider id
Output : uint8_t   bit0-1:indicate slider touch state(0->Initializing, 1:released 2:pressed)
                   bit 2: indicate if position is changed
                   bit 7: indicate if slider needs reburst 
Notes  : none
============================================================================*/
uint8_t MTOUCH_Slider_Status_Get(enum mtouch_slider_names sliderName);

/*============================================================================
uint16_t MTOUCH_Slider_Position_Get(enum mtouch_slider_names sliderName)
------------------------------------------------------------------------------
Purpose: Get a slider position
Input  : slider id
Output : uint16_t
Notes  : none
============================================================================*/
uint16_t MTOUCH_Slider_Position_Get(enum mtouch_slider_names sliderName);

/*============================================================================
uint16_t MTOUCH_Slider_Threshold_Get(enum mtouch_slider_names sliderName)
------------------------------------------------------------------------------
Purpose: Get a slider threshold
Input  : slider id
Output : uint16_t
Notes  : none
============================================================================*/
uint16_t MTOUCH_Slider_Threshold_Get(enum mtouch_slider_names sliderName);

/*============================================================================
uint8_t MTOUCH_Slider_Threshold_Set(enum mtouch_slider_names sliderName, uint16_t threshold)
------------------------------------------------------------------------------
Purpose: Set a slider threshold
Input  : slider id, Threshold
Output : uint8_t
Notes  : none
============================================================================*/
uint8_t MTOUCH_Slider_Threshold_Set(enum mtouch_slider_names sliderName, uint16_t threshold);

/*============================================================================
uint16_t MTOUCH_Slider_Deviation_Get(enum mtouch_slider_names sliderName)
------------------------------------------------------------------------------
Purpose: Get a slider deviation 
Input  : slider id
Output : uint16_t
Notes  : none
============================================================================*/
uint16_t MTOUCH_Slider_Deviation_Get(enum mtouch_slider_names sliderName);

/*============================================================================
uint8_t MTOUCH_Slider_GroupStatus_Get(void);
------------------------------------------------------------------------------
Purpose: Get the or'ed status for all sliders
Input  : none
Output : uint8_t   bit0-1:indicate slider touch state(0->Initializing, 1:released 2:pressed)
                   bit 2: indicate if position is changed
                   bit 7: indicate if slider needs reburst 
Notes  : none
============================================================================*/
uint8_t MTOUCH_Slider_GroupStatus_Get(void);

/*============================================================================
uint8_t MTOUCH_Slider_Status_Get(void);
------------------------------------------------------------------------------
Purpose: Get the status for the selected slider
Input  : slider name/index
Output : uint8_t   bit0-1:indicate slider touch state(0->Initializing, 1:released 2:pressed)
                   bit 2: indicate if position is changed
                   bit 7: indicate if slider needs reburst 
Notes  : none
============================================================================*/
uint8_t MTOUCH_Slider_Status_Get(enum mtouch_slider_names sliderName);
/*============================================================================
bool MTOUCH_Slider_Reburst_Service(void)
------------------------------------------------------------------------------
Purpose: process the slider reburst request
Input  : none
Output : bool; returns true if need reburst; false else
Notes  : none
============================================================================*/
bool MTOUCH_Slider_Reburst_Service(void);

/*============================================================================
void MTOUCH_Slider_SetPositionChangedCallback(void (*callback)(enum mtouch_slider_names))
------------------------------------------------------------------------------
Purpose: Set the callback function for slider position changed event 
Input  : pointer of the callback function
Output : none
Notes  : none
============================================================================*/
void MTOUCH_Slider_SetPositionChangedCallback(void (*callback)(enum mtouch_slider_names));

/*============================================================================
void MTOUCH_Slider_SetPressedCallback(void (*callback)(enum mtouch_slider_names))
------------------------------------------------------------------------------
Purpose: Set the callback function for slider pressed event 
Input  : pointer of the callback function
Output : none
Notes  : none
============================================================================*/
void MTOUCH_Slider_SetPressedCallback(void (*callback)(enum mtouch_slider_names));


/*============================================================================
void MTOUCH_Slider_SetReleasedCallback(void (*callback)(enum mtouch_slider_names))
------------------------------------------------------------------------------
Purpose: Set the callback function for slider released event 
Input  : pointer of the callback function
Output : none
Notes  : none
============================================================================*/
void MTOUCH_Slider_SetReleasedCallback(void (*callback)(enum mtouch_slider_names));
#endif  // __MTOUCH_SLIDER_H__

