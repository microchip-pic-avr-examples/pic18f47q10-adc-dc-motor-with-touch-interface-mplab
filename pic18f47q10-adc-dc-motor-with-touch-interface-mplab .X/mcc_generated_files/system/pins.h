/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
*/

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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA2 aliases
#define IO_RA2_TRIS                 TRISAbits.TRISA2
#define IO_RA2_LAT                  LATAbits.LATA2
#define IO_RA2_PORT                 PORTAbits.RA2
#define IO_RA2_WPU                  WPUAbits.WPUA2
#define IO_RA2_OD                   ODCONAbits.ODCA2
#define IO_RA2_ANS                  ANSELAbits.ANSELA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_RA2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA3 aliases
#define IO_RA3_TRIS                 TRISAbits.TRISA3
#define IO_RA3_LAT                  LATAbits.LATA3
#define IO_RA3_PORT                 PORTAbits.RA3
#define IO_RA3_WPU                  WPUAbits.WPUA3
#define IO_RA3_OD                   ODCONAbits.ODCA3
#define IO_RA3_ANS                  ANSELAbits.ANSELA3
#define IO_RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define IO_RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define IO_RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define IO_RA3_GetValue()           PORTAbits.RA3
#define IO_RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define IO_RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define IO_RA3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define IO_RA3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define IO_RA3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define IO_RA3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define IO_RA3_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define IO_RA3_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RA4 aliases
#define IO_RA4_TRIS                 TRISAbits.TRISA4
#define IO_RA4_LAT                  LATAbits.LATA4
#define IO_RA4_PORT                 PORTAbits.RA4
#define IO_RA4_WPU                  WPUAbits.WPUA4
#define IO_RA4_OD                   ODCONAbits.ODCA4
#define IO_RA4_ANS                  ANSELAbits.ANSELA4
#define IO_RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IO_RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IO_RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IO_RA4_GetValue()           PORTAbits.RA4
#define IO_RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IO_RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IO_RA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define IO_RA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define IO_RA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define IO_RA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define IO_RA4_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define IO_RA4_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 aliases
#define IO_RA5_TRIS                 TRISAbits.TRISA5
#define IO_RA5_LAT                  LATAbits.LATA5
#define IO_RA5_PORT                 PORTAbits.RA5
#define IO_RA5_WPU                  WPUAbits.WPUA5
#define IO_RA5_OD                   ODCONAbits.ODCA5
#define IO_RA5_ANS                  ANSELAbits.ANSELA5
#define IO_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_RA5_GetValue()           PORTAbits.RA5
#define IO_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_RA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define IO_RA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define IO_RA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define IO_RA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define IO_RA5_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define IO_RA5_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RB1 aliases
#define SLIDER_LED2_TRIS                 TRISBbits.TRISB1
#define SLIDER_LED2_LAT                  LATBbits.LATB1
#define SLIDER_LED2_PORT                 PORTBbits.RB1
#define SLIDER_LED2_WPU                  WPUBbits.WPUB1
#define SLIDER_LED2_OD                   ODCONBbits.ODCB1
#define SLIDER_LED2_ANS                  ANSELBbits.ANSELB1
#define SLIDER_LED2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SLIDER_LED2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SLIDER_LED2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SLIDER_LED2_GetValue()           PORTBbits.RB1
#define SLIDER_LED2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SLIDER_LED2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SLIDER_LED2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SLIDER_LED2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SLIDER_LED2_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define SLIDER_LED2_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define SLIDER_LED2_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define SLIDER_LED2_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 aliases
#define  BUTTON_LED2_TRIS                 TRISBbits.TRISB2
#define  BUTTON_LED2_LAT                  LATBbits.LATB2
#define  BUTTON_LED2_PORT                 PORTBbits.RB2
#define  BUTTON_LED2_WPU                  WPUBbits.WPUB2
#define  BUTTON_LED2_OD                   ODCONBbits.ODCB2
#define  BUTTON_LED2_ANS                  ANSELBbits.ANSELB2
#define  BUTTON_LED2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define  BUTTON_LED2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define  BUTTON_LED2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define  BUTTON_LED2_GetValue()           PORTBbits.RB2
#define  BUTTON_LED2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define  BUTTON_LED2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define  BUTTON_LED2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define  BUTTON_LED2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define  BUTTON_LED2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define  BUTTON_LED2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define  BUTTON_LED2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define  BUTTON_LED2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC4 aliases
#define SLIDER_LED4_TRIS                 TRISCbits.TRISC4
#define SLIDER_LED4_LAT                  LATCbits.LATC4
#define SLIDER_LED4_PORT                 PORTCbits.RC4
#define SLIDER_LED4_WPU                  WPUCbits.WPUC4
#define SLIDER_LED4_OD                   ODCONCbits.ODCC4
#define SLIDER_LED4_ANS                  ANSELCbits.ANSELC4
#define SLIDER_LED4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SLIDER_LED4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SLIDER_LED4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SLIDER_LED4_GetValue()           PORTCbits.RC4
#define SLIDER_LED4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SLIDER_LED4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SLIDER_LED4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SLIDER_LED4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SLIDER_LED4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SLIDER_LED4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SLIDER_LED4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define SLIDER_LED4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 aliases
#define SLIDER_LED5_TRIS                 TRISCbits.TRISC5
#define SLIDER_LED5_LAT                  LATCbits.LATC5
#define SLIDER_LED5_PORT                 PORTCbits.RC5
#define SLIDER_LED5_WPU                  WPUCbits.WPUC5
#define SLIDER_LED5_OD                   ODCONCbits.ODCC5
#define SLIDER_LED5_ANS                  ANSELCbits.ANSELC5
#define SLIDER_LED5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SLIDER_LED5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SLIDER_LED5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SLIDER_LED5_GetValue()           PORTCbits.RC5
#define SLIDER_LED5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SLIDER_LED5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SLIDER_LED5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SLIDER_LED5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SLIDER_LED5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SLIDER_LED5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SLIDER_LED5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define SLIDER_LED5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 aliases
#define SLIDER_LED6_TRIS                 TRISCbits.TRISC6
#define SLIDER_LED6_LAT                  LATCbits.LATC6
#define SLIDER_LED6_PORT                 PORTCbits.RC6
#define SLIDER_LED6_WPU                  WPUCbits.WPUC6
#define SLIDER_LED6_OD                   ODCONCbits.ODCC6
#define SLIDER_LED6_ANS                  ANSELCbits.ANSELC6
#define SLIDER_LED6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SLIDER_LED6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SLIDER_LED6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SLIDER_LED6_GetValue()           PORTCbits.RC6
#define SLIDER_LED6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SLIDER_LED6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SLIDER_LED6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SLIDER_LED6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SLIDER_LED6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SLIDER_LED6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define SLIDER_LED6_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define SLIDER_LED6_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 aliases
#define SLIDER_LED1_TRIS                 TRISCbits.TRISC7
#define SLIDER_LED1_LAT                  LATCbits.LATC7
#define SLIDER_LED1_PORT                 PORTCbits.RC7
#define SLIDER_LED1_WPU                  WPUCbits.WPUC7
#define SLIDER_LED1_OD                   ODCONCbits.ODCC7
#define SLIDER_LED1_ANS                  ANSELCbits.ANSELC7
#define SLIDER_LED1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SLIDER_LED1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SLIDER_LED1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SLIDER_LED1_GetValue()           PORTCbits.RC7
#define SLIDER_LED1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SLIDER_LED1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SLIDER_LED1_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define SLIDER_LED1_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define SLIDER_LED1_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define SLIDER_LED1_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define SLIDER_LED1_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define SLIDER_LED1_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set RD4 aliases
#define EN_TRIS                 TRISDbits.TRISD4
#define EN_LAT                  LATDbits.LATD4
#define EN_PORT                 PORTDbits.RD4
#define EN_WPU                  WPUDbits.WPUD4
#define EN_OD                   ODCONDbits.ODCD4
#define EN_ANS                  ANSELDbits.ANSELD4
#define EN_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define EN_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define EN_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define EN_GetValue()           PORTDbits.RD4
#define EN_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define EN_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define EN_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define EN_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define EN_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define EN_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define EN_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set RD5 aliases
#define  BUTTON_LED1_TRIS                 TRISDbits.TRISD5
#define  BUTTON_LED1_LAT                  LATDbits.LATD5
#define  BUTTON_LED1_PORT                 PORTDbits.RD5
#define  BUTTON_LED1_WPU                  WPUDbits.WPUD5
#define  BUTTON_LED1_OD                   ODCONDbits.ODCD5
#define  BUTTON_LED1_ANS                  ANSELDbits.ANSELD5
#define  BUTTON_LED1_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define  BUTTON_LED1_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define  BUTTON_LED1_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define  BUTTON_LED1_GetValue()           PORTDbits.RD5
#define  BUTTON_LED1_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define  BUTTON_LED1_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define  BUTTON_LED1_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define  BUTTON_LED1_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define  BUTTON_LED1_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define  BUTTON_LED1_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define  BUTTON_LED1_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define  BUTTON_LED1_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set RD6 aliases
#define SLIDER_LED3_TRIS                 TRISDbits.TRISD6
#define SLIDER_LED3_LAT                  LATDbits.LATD6
#define SLIDER_LED3_PORT                 PORTDbits.RD6
#define SLIDER_LED3_WPU                  WPUDbits.WPUD6
#define SLIDER_LED3_OD                   ODCONDbits.ODCD6
#define SLIDER_LED3_ANS                  ANSELDbits.ANSELD6
#define SLIDER_LED3_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define SLIDER_LED3_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define SLIDER_LED3_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define SLIDER_LED3_GetValue()           PORTDbits.RD6
#define SLIDER_LED3_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define SLIDER_LED3_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define SLIDER_LED3_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define SLIDER_LED3_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define SLIDER_LED3_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define SLIDER_LED3_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define SLIDER_LED3_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define SLIDER_LED3_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set RD7 aliases
#define IO_RD7_TRIS                 TRISDbits.TRISD7
#define IO_RD7_LAT                  LATDbits.LATD7
#define IO_RD7_PORT                 PORTDbits.RD7
#define IO_RD7_WPU                  WPUDbits.WPUD7
#define IO_RD7_OD                   ODCONDbits.ODCD7
#define IO_RD7_ANS                  ANSELDbits.ANSELD7
#define IO_RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IO_RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IO_RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IO_RD7_GetValue()           PORTDbits.RD7
#define IO_RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IO_RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IO_RD7_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define IO_RD7_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define IO_RD7_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define IO_RD7_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define IO_RD7_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define IO_RD7_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/