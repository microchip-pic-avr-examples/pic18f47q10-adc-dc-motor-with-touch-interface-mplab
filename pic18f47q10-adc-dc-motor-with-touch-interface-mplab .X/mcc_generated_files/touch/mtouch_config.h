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
#ifndef MTOUCH_CONFIG_H
#define MTOUCH_CONFIG_H

#include <stdint.h>
#include <stdbool.h>
#include "mtouch_sensor.h"
#include "mtouch_button.h"
#include "mtouch_slider.h"


/*
 * =======================================================================
 * Application / Configuration Settings
 * =======================================================================
 */
    #define MTOUCH_SENSORS          5u
    #define MTOUCH_BUTTONS          5u
    #define MTOUCH_SLIDERS          1u


    /* 
     * =======================================================================
     * Sensor Parameters
     * =======================================================================
     */

    
    #define MTOUCH_SENSOR_ADPCH_Sensor_ANA2              0x2
    #define MTOUCH_SENSOR_PRECHARGE_Sensor_ANA2          48u
    #define MTOUCH_SENSOR_ACQUISITION_Sensor_ANA2        16u
    #define MTOUCH_SENSOR_OVERSAMPLING_Sensor_ANA2       32u
    #define MTOUCH_SENSOR_ADDITIONALCAP_Sensor_ANA2      0u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_SENSOR_ADPCH_Sensor_AND7              0x1f
    #define MTOUCH_SENSOR_PRECHARGE_Sensor_AND7          48u
    #define MTOUCH_SENSOR_ACQUISITION_Sensor_AND7        16u
    #define MTOUCH_SENSOR_OVERSAMPLING_Sensor_AND7       32u
    #define MTOUCH_SENSOR_ADDITIONALCAP_Sensor_AND7      0u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_SENSOR_ADPCH_Sensor_ANB4              0xc
    #define MTOUCH_SENSOR_PRECHARGE_Sensor_ANB4          48u
    #define MTOUCH_SENSOR_ACQUISITION_Sensor_ANB4        16u
    #define MTOUCH_SENSOR_OVERSAMPLING_Sensor_ANB4       32u
    #define MTOUCH_SENSOR_ADDITIONALCAP_Sensor_ANB4      0u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_SENSOR_ADPCH_Sensor_ANA5              0x5
    #define MTOUCH_SENSOR_PRECHARGE_Sensor_ANA5          48u
    #define MTOUCH_SENSOR_ACQUISITION_Sensor_ANA5        16u
    #define MTOUCH_SENSOR_OVERSAMPLING_Sensor_ANA5       32u
    #define MTOUCH_SENSOR_ADDITIONALCAP_Sensor_ANA5      0u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_SENSOR_ADPCH_Sensor_ANA4              0x4
    #define MTOUCH_SENSOR_PRECHARGE_Sensor_ANA4          48u
    #define MTOUCH_SENSOR_ACQUISITION_Sensor_ANA4        16u
    #define MTOUCH_SENSOR_OVERSAMPLING_Sensor_ANA4       32u
    #define MTOUCH_SENSOR_ADDITIONALCAP_Sensor_ANA4      0u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_SENSOR_ACTIVE_THRESHOLD               100u  

    /* 
     * =======================================================================
     * Button Parameters
     * =======================================================================
     */

    #define MTOUCH_BUTTON_READING_GAIN              ((uint8_t)2u)
    #define MTOUCH_BUTTON_BASELINE_GAIN             ((uint8_t)4u)
    #define MTOUCH_BUTTON_BASELINE_INIT             ((mtouch_button_baselinecounter_t)16u)
    #define MTOUCH_BUTTON_BASELINE_RATE             ((mtouch_button_baselinecounter_t)64u)
    #define MTOUCH_BUTTON_BASELINE_HOLD             ((mtouch_button_baselinecounter_t)1024u)
    #define MTOUCH_BUTTON_NEGATIVEDEVIATION         ((mtouch_button_statecounter_t)64u)
    #define MTOUCH_BUTTON_PRESSTIMEOUT              ((mtouch_button_statecounter_t)1000u)

    #define MTOUCH_BUTTON_SENSOR_Button0             Sensor_ANA2
    #define MTOUCH_BUTTON_SENSOR_Button1             Sensor_AND7
    #define MTOUCH_BUTTON_SENSOR_Slider0_Seg0             Sensor_ANB4
    #define MTOUCH_BUTTON_SENSOR_Slider0_Seg1             Sensor_ANA5
    #define MTOUCH_BUTTON_SENSOR_Slider0_Seg2             Sensor_ANA4

    #define MTOUCH_BUTTON_THRESHOLD_Button0          100u
    #define MTOUCH_BUTTON_THRESHOLD_Button1          100u
    #define MTOUCH_BUTTON_THRESHOLD_Slider0_Seg0          50u
    #define MTOUCH_BUTTON_THRESHOLD_Slider0_Seg1          50u
    #define MTOUCH_BUTTON_THRESHOLD_Slider0_Seg2          50u
    
    #define MTOUCH_BUTTON_SCALING_Button0            1u
    #define MTOUCH_BUTTON_SCALING_Button1            1u
    #define MTOUCH_BUTTON_SCALING_Slider0_Seg0            1u
    #define MTOUCH_BUTTON_SCALING_Slider0_Seg1            1u
    #define MTOUCH_BUTTON_SCALING_Slider0_Seg2            1u

    #define MTOUCH_BUTTON_COMMON_HYSTERESIS         HYST_50_PERCENT


    /* 
     * =======================================================================
     * Slider Parameters
     * =======================================================================
     */

  /**  Config:  Slider0 **/
    /* Slider Type <0-65534>
     * Type of the slider
     * Range: MTOUCH_TYPE_SLIDER or MTOUCH_TYPE_WHEEL
     */
    #define Slider0_TYPE                  MTOUCH_TYPE_SLIDER 
    /* Start Segment <0-65534>
     * Start Segment of the slider
     * Range: 0 to 65534
     */
    #define Slider0_START_SEGMENT         2    
    /* Number of Channel <0-255>
     * Number of Channels for the slider
     * Range: 0 to 255
     */
    #define Slider0_NUM_SEGMENTS          3u
    /*  Position Resolution 
     *  Full scale position resolution reported
     *  SCR_RESOL_2_BIT - SCR_RESOL_12_BIT
     */
    #define Slider0_RESOLUTION            SCR_RESOL_8_BIT
    /*  Position Deadband Percentage
     *  Full scale position deadband Percentage
     *  SCR_DB_NONE - SCR_DB_15_PERCENT
     */
    #define Slider0_DEADBAND              SCR_DB_1_PERCENT
    /* Position Hysteresis <0-255>
     * The minimum travel distance to be reported after contact or direction change
     */
    #define Slider0_POS_HYST              8u
    /* Contact Threshold <0-65534>
     * The minimum contact size measurement for persistent contact tracking.
     * Contact size is the sum of neighbouring Segments touch deltas forming the touch contact.
     * By default, contact Threshold parameter should be set equal to threshold value of the underlying keys.
     * Then the parameter has to be tuned based on the actual contact size of the touch when moved over the slider.
     */
    #define Slider0_THRESHOLD             50u





#endif // MTOUCH_CONFIG_H
/**
 End of File
*/
