/**
 * **********************************************************
 *  include files
 * **********************************************************
 **/
#include "application.h"


/**
 * **********************************************************
 *  Macros definitions
 * **********************************************************
 **/

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

/**
 * **********************************************************
 *  File local data types & typedefs
 * **********************************************************
 **/

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
    uint16_t sliderADC_Val;
} key_t;

/**
 * **********************************************************
 *  File local variables
 * **********************************************************
 **/
static key_t BUTTON;
static uint16_t state = GET_EVENT;
static e_key buttonNo = NO_KEY;   
static uint16_t motorState = HALTED;
/**
 * **********************************************************
 *  static function's declaration
 * **********************************************************
 **/
static e_key_state GetEvent(void);
static void ClearEvent(void);
static e_key GetButton(void);
static void ClearButton(void);
static uint16_t GetMotorSpeed(uint16_t adcVal);


/**
 * **********************************************************
 *  global function's definition
 * **********************************************************
 **/

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
 **/
void ProcessButtonRelease(enum mtouch_button_names button)
{
    switch (button)
    {
    case Button1:
        BUTTON.key = BUTTON1;
        BUTTON.keyStatus = KEY_RELEASED;
        break;
        
    case Button2:
        BUTTON.key = BUTTON2;
        BUTTON.keyStatus = KEY_RELEASED;
        break;
        
    default:
        break;
    }
}

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
 **/
void ProcessSliderChange(enum mtouch_slider_names slider)
{
    BUTTON.key = SLIDER;
    BUTTON.keyStatus = KEY_PRESSED;
    BUTTON.sliderADC_Val = MTOUCH_Slider_Position_Get(Slider1);
}

/**
 * **********************************************************
 *  local function's definition
 * **********************************************************
 **/

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
e_key_state GetEvent(void)
{
    return BUTTON.keyStatus;
}

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
void ClearEvent(void)
{
    BUTTON.keyStatus = KEY_NO_ACTION;
}

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
e_key GetButton(void)
{
    return BUTTON.key;
}

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
void ClearButton(void)
{
    BUTTON.key = NO_KEY;
}



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
        else
        {
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
            BLED2_SetHigh();
            BLED1_SetLow();
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
            BLED1_SetHigh();
            BLED2_SetLow();
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
            motorSpeed = GetMotorSpeed(BUTTON.sliderADC_Val);
            
            //Set the motor speed to corresponding motor speed value.
            PWM4_LoadDutyValue(motorSpeed); 
            BUTTON.sliderADC_Val = 0;
        }
        else
        {            
        }
        state = GET_EVENT;
        break;
        
    default:
        state = GET_EVENT;
        break;
    }
}