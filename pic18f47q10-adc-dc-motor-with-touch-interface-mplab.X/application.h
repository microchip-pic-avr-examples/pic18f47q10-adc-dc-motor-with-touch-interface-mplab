/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APPLICATION_H
#define	APPLICATION_H

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * **********************************************************
 *  include files
 * **********************************************************
 **/
#include"mcc_generated_files/mcc.h"
#include "mcc_generated_files/pwm4.h"
    
 /**
 * **********************************************************
 *  Macros definitions
 * **********************************************************
 **/
    
#define TurnOffSliderLEDs() SLED6_SetHigh();\
                            SLED5_SetHigh();\
                            SLED4_SetHigh();\
                            SLED3_SetHigh();\
                            SLED2_SetHigh();\
                            SLED1_SetHigh()

#define TurnOnSliderLED1()  SLED6_SetLow();\
                            SLED5_SetHigh();\
                            SLED4_SetHigh();\
                            SLED3_SetHigh();\
                            SLED2_SetHigh();\
                            SLED1_SetHigh()    

#define TurnOnSliderLED2()  SLED6_SetLow();\
                            SLED5_SetLow();\
                            SLED4_SetHigh();\
                            SLED3_SetHigh();\
                            SLED2_SetHigh();\
                            SLED1_SetHigh() 
    
#define TurnOnSliderLED3()  SLED6_SetLow();\
                            SLED5_SetLow();\
                            SLED4_SetLow();\
                            SLED3_SetHigh();\
                            SLED2_SetHigh();\
                            SLED1_SetHigh() 

#define TurnOnSliderLED4()  SLED6_SetLow();\
                            SLED5_SetLow();\
                            SLED4_SetLow();\
                            SLED3_SetLow();\
                            SLED2_SetHigh();\
                            SLED1_SetHigh()    

#define TurnOnSliderLED5()  SLED6_SetLow();\
                            SLED5_SetLow();\
                            SLED4_SetLow();\
                            SLED3_SetLow();\
                            SLED2_SetLow();\
                            SLED1_SetHigh() 
    
#define TurnOnSliderLED6()  SLED6_SetLow();\
                            SLED5_SetLow();\
                            SLED4_SetLow();\
                            SLED3_SetLow();\
                            SLED2_SetLow();\
                            SLED1_SetLow() 
    
/**
   @Param
    button number
   @Returns
    none
   @Description
    callback function for button release
    to get the button status and button name
   @Example    
 */
void ProcessButtonRelease(enum mtouch_button_names button);

/**
   @Param
    none
   @Returns
    button number
   @Description
    callback function for slider change
    to get the slider position and pressed status
   @Example    
 */
void ProcessSliderChange(enum mtouch_slider_names slider);

/**
   @Param
    none
   @Returns
    none 
   @Description
    function for main application task.
   @Example 
    executeCommand();   
 */
void ApplicationTask (void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

