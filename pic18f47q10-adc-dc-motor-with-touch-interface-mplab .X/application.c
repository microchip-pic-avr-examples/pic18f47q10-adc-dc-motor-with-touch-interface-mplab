/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include "application.h"

static key_t keyInfo;
static uint16_t state = GET_EVENT;
static e_key buttonNo = NO_KEY;   
static uint16_t motorState = HALTED;

void ApplicationTask(void) 
{
    uint16_t motorSpeed = SPEED0;

    switch (state)
    {
        case GET_EVENT: 
            //Check if any button/slider pressed/released event is pending
            if (GetEvent() != NO_KEY) 
            {
                buttonNo = GetButton();
                if (buttonNo < MAX_KEYS)
                {
                    state = GET_CMD;
                }
                ClearButton();
                ClearEvent();
            }
            break;
        
        case GET_CMD:
            if (buttonNo == BUTTON1)
            {
                state = MOTOR_START;
            }
            else if (buttonNo == BUTTON2)
            {
                state = MOTOR_STOP;
            }
            else if (buttonNo == SLIDER)
            {
                state = SPEED_CTRL;
            }
            else
            {
                state = GET_EVENT;
            }
            // Clear the button to update in next event received
            buttonNo = NO_KEY;                    
            break;
            
        case MOTOR_START:
            if (motorState != RUNNING)
            {
                motorState = RUNNING; 
                //Set the DC Motor 8 Click EN pin
                EN_SetHigh();
                //Set the motor speed to minimum
                PWM4_LoadDutyValue(MIN_SPEED);   
                TurnOnSliderLED1();  
                BUTTON_LED2_SetHigh();
                BUTTON_LED1_SetLow();
            }
            else
            {
                state = GET_EVENT;
            }
            break;
            
        case MOTOR_STOP:
            if (motorState == RUNNING)
            {
                motorState = HALTED;
            
            //Reset the DC Motor 8 Click EN pin
            EN_SetLow();               
            
            //Set the motor speed to 0
            PWM4_LoadDutyValue(SPEED0); 
            TurnOffSliderLEDs();
            BUTTON_LED1_SetHigh();
            BUTTON_LED2_SetLow();
            }
            else
            {
                state = GET_EVENT;
            }
            break;
            
        case SPEED_CTRL:
            if (motorState == RUNNING)
            {
                // Get the motor speed value depending upon predefined ranges
                motorSpeed = GetMotorSpeed(keyInfo.sliderADCValue);
                //Set the motor speed to corresponding motor speed value
                PWM4_LoadDutyValue(motorSpeed); 
                keyInfo.sliderADCValue = 0;
            }
            state = GET_EVENT;
            break;
            
        default:
            state = GET_EVENT;
            break;
            
    }
}

void ProcessButtonRelease(enum mtouch_button_names button)
{
    switch (button)
    {
        case Button0:
            keyInfo.key = BUTTON1;
            keyInfo.keyStatus = KEY_RELEASED;
            break;
            
        case Button1:
            keyInfo.key = BUTTON2;
            keyInfo.keyStatus = KEY_RELEASED;
            break;
            
        default:
            break;
            
    }
}

void ProcessSliderChange(enum mtouch_slider_names slider)
{
    keyInfo.key = SLIDER;
    keyInfo.keyStatus = KEY_PRESSED;
    keyInfo.sliderADCValue = MTOUCH_Slider_Position_Get(Slider0);
}

e_key_state GetEvent(void)
{
    return keyInfo.keyStatus;
}

void ClearEvent(void)
{
    keyInfo.keyStatus = KEY_NO_ACTION;
}

e_key GetButton(void)
{
    return keyInfo.key;
}

void ClearButton(void)
{
    keyInfo.key = NO_KEY;
}

uint16_t GetMotorSpeed(uint16_t adcVal)
{
    uint16_t retVal = 0;
    
    if (adcVal < SLIDER_COUNT_MIN)
    {
        //turn off all the slider LEDs
        TurnOffSliderLEDs();
        retVal = SPEED0;
    }
    else if ((adcVal > (SLIDER_COUNT_MIN - 1) ) && (adcVal < SLIDER_COUNT_1))
    {
        //turn on slider LED 1
        TurnOnSliderLED1();
        retVal = SPEED1;
    }
    else if ((adcVal > (SLIDER_COUNT_1 - 1)) && (adcVal < SLIDER_COUNT_2))
    {
        //turn on slider LED 1 and 2
        TurnOnSliderLED2();
        retVal = SPEED2;
    }
    else if ((adcVal > (SLIDER_COUNT_2 - 1)) && (adcVal < SLIDER_COUNT_3))
    {
        //turn on slider LED 1, 2 and 3
        TurnOnSliderLED3();
        retVal = SPEED3;
    }
    else if ((adcVal > (SLIDER_COUNT_3 - 1)) && (adcVal < SLIDER_COUNT_4))
    {
        //turn on slider LED 1, 2, 3 and 4
        TurnOnSliderLED4();
        retVal = SPEED4;
    }
    else if ((adcVal > (SLIDER_COUNT_4 - 1)) && (adcVal < SLIDER_COUNT_MAX))
    {
        //turn on slider LED 1, 2, 3, 4 and 5
        TurnOnSliderLED5();
        retVal = SPEED5;
    }
    else if (adcVal > (SLIDER_COUNT_MAX - 1) )
    {
        //turn on all the slider LEDs 1, 2, 3, 4, 5 and 6
        TurnOnSliderLED6();
        retVal = MAX_SPEED;
    }
    else
    {
        retVal = 0;
    }
    return retVal;
}

