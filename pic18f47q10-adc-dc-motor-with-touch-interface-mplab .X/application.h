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


// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APPLICATION_H
#define	APPLICATION_H

#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/pwm/pwm4.h" 

// Macros for Application FSM states
#define GET_EVENT             (0)
#define GET_CMD               (1)
#define MOTOR_START           (2)
#define MOTOR_STOP            (3)
#define SPEED_CTRL            (4) 

// Macros for motorState
#define RUNNING               (1)
#define HALTED                (0)

// Macros for PWM period values to change duty cycle
#define MIN_SPEED             (180)
#define MAX_SPEED             (530)
#define SPEED_OFFSET          (70)
#define SPEED0                (0)
#define SPEED1                (MIN_SPEED)               //180
#define SPEED2                (SPEED1 + SPEED_OFFSET)   //250
#define SPEED3                (SPEED2 + SPEED_OFFSET)   //320
#define SPEED4                (SPEED3 + SPEED_OFFSET)   //390
#define SPEED5                (SPEED4 + SPEED_OFFSET)   //460
#define SPEED6                (MAX_SPEED)               //530

// Macros for ADC value received from slider to set range cutoffs 
#define MIN_ADC_COUNT         (20)
#define MAX_ADC_COUNT         (255)
#define ADC_COUNT_OFFSET      (40)
#define SLIDER_COUNT_MIN      (MIN_ADC_COUNT)                        //20
#define SLIDER_COUNT_1        (SLIDER_COUNT_MIN + ADC_COUNT_OFFSET)  //60
#define SLIDER_COUNT_2        (SLIDER_COUNT_1 + ADC_COUNT_OFFSET)    //100
#define SLIDER_COUNT_3        (SLIDER_COUNT_2 + ADC_COUNT_OFFSET)    //140
#define SLIDER_COUNT_4        (SLIDER_COUNT_3 + ADC_COUNT_OFFSET)    //180
#define SLIDER_COUNT_MAX      (MAX_ADC_COUNT - ADC_COUNT_OFFSET)     //215

    
#define TurnOffSliderLEDs() SLIDER_LED6_SetHigh();\
                            SLIDER_LED5_SetHigh();\
                            SLIDER_LED4_SetHigh();\
                            SLIDER_LED3_SetHigh();\
                            SLIDER_LED2_SetHigh();\
                            SLIDER_LED1_SetHigh()

#define TurnOnSliderLED1()  SLIDER_LED6_SetLow();\
                            SLIDER_LED5_SetHigh();\
                            SLIDER_LED4_SetHigh();\
                            SLIDER_LED3_SetHigh();\
                            SLIDER_LED2_SetHigh();\
                            SLIDER_LED1_SetHigh()    

#define TurnOnSliderLED2()  SLIDER_LED6_SetLow();\
                            SLIDER_LED5_SetLow();\
                            SLIDER_LED4_SetHigh();\
                            SLIDER_LED3_SetHigh();\
                            SLIDER_LED2_SetHigh();\
                            SLIDER_LED1_SetHigh();
    
#define TurnOnSliderLED3()  SLIDER_LED6_SetLow();\
                            SLIDER_LED5_SetLow();\
                            SLIDER_LED4_SetLow();\
                            SLIDER_LED3_SetHigh();\
                            SLIDER_LED2_SetHigh();\
                            SLIDER_LED1_SetHigh() 

#define TurnOnSliderLED4()  SLIDER_LED6_SetLow();\
                            SLIDER_LED5_SetLow();\
                            SLIDER_LED4_SetLow();\
                            SLIDER_LED3_SetLow();\
                            SLIDER_LED2_SetHigh();\
                            SLIDER_LED1_SetHigh()    

#define TurnOnSliderLED5()  SLIDER_LED6_SetLow();\
                            SLIDER_LED5_SetLow();\
                            SLIDER_LED4_SetLow();\
                            SLIDER_LED3_SetLow();\
                            SLIDER_LED2_SetLow();\
                            SLIDER_LED1_SetHigh() 
    
#define TurnOnSliderLED6()  SLIDER_LED6_SetLow();\
                            SLIDER_LED5_SetLow();\
                            SLIDER_LED4_SetLow();\
                            SLIDER_LED3_SetLow();\
                            SLIDER_LED2_SetLow();\
                            SLIDER_LED1_SetLow() 

// enum typedef for button status 
typedef enum
{
    KEY_NO_ACTION,
    KEY_PRESSED,
    KEY_RELEASED,
    MAX_KEY_STATE
            
} e_key_state;

// enum typedef for button numbers
typedef enum
{
    NO_KEY,
    BUTTON1,
    BUTTON2,
    SLIDER,
    MAX_KEYS
            
} e_key;

// struct typedef for button 
typedef struct
{
    e_key key;
    e_key_state keyStatus;
    uint16_t sliderADCValue;   
} key_t;

/**
   @Param
    none
   @Returns
    button status 
   @Description
    this function gives the current status of button/slider
   @Example    
    buttonStatus = GetEvent();
 **/
e_key_state GetEvent(void);

/**
   @Param
    none
   @Returns
    button status 
   @Description
    this function clears the current status of button/slider.
    this function must be used after calling the GetEvent() function call to 
    clear the status.
   @Example    
    ClearEvent();
 **/
void ClearEvent(void); 

/**
   @Param
    none
   @Returns
    none 
   @Description
    this function gives the name of button/slider
   @Example    
    button = GetButton();
 **/
e_key GetButton(void);

/**
   @Param
    none
   @Returns
    button status 
   @Description
    this function clears the current captured button/slider.
    this function must be used after calling the GetButton() function call to 
    clear the captured button/slider.
   @Example    
    ClearButton();
 **/
void ClearButton(void);

/**
   @Param
    ADC value
   @Returns
    PWM duty cycle 
   @Description
    function for getting PWM duty cycle based on ADC values received to control 
    motor speed 
   @Example 
    motorSpeed = GetMotorSpeed(adcVal);   
 **/
uint16_t GetMotorSpeed(uint16_t adcVal);

/**
   @Param
    none
   @Returns
    none
   @Description
    main application task to perform motor speed control based on touch-pad inputs 
   @Example 
    ApplicationTask();   
 **/
void ApplicationTask(void);

/**
   @Param
    slider number
   @Returns
    none 
   @Description
    callback function for slider change
    Based on slider position, An event for slider pressed will be updated with
    ADC value.
   @Example
    MTOUCH_Button_SetNotPressedCallback(ProcessSliderRelease);
  
 **/
void ProcessSliderChange(enum mtouch_slider_names slider);

/**
   @Param
    button number
   @Returns
    none
   @Description
    callback function for button release
    if any button is released, An event will be updated for button released 
    with corresponding button.
   @Example
    MTOUCH_Button_SetNotPressedCallback(ProcessButtonRelease);
    
 **/
void ProcessButtonRelease(enum mtouch_button_names button);


#endif	/* APPLICATION_H */