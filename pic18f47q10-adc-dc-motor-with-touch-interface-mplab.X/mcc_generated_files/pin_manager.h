/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC18F47Q10
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSELA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSELA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSELA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set SLED2 aliases
#define SLED2_TRIS                 TRISBbits.TRISB1
#define SLED2_LAT                  LATBbits.LATB1
#define SLED2_PORT                 PORTBbits.RB1
#define SLED2_WPU                  WPUBbits.WPUB1
#define SLED2_OD                   ODCONBbits.ODCB1
#define SLED2_ANS                  ANSELBbits.ANSELB1
#define SLED2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SLED2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SLED2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SLED2_GetValue()           PORTBbits.RB1
#define SLED2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SLED2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SLED2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SLED2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SLED2_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define SLED2_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define SLED2_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define SLED2_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set BLED2 aliases
#define BLED2_TRIS                 TRISBbits.TRISB2
#define BLED2_LAT                  LATBbits.LATB2
#define BLED2_PORT                 PORTBbits.RB2
#define BLED2_WPU                  WPUBbits.WPUB2
#define BLED2_OD                   ODCONBbits.ODCB2
#define BLED2_ANS                  ANSELBbits.ANSELB2
#define BLED2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BLED2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BLED2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define BLED2_GetValue()           PORTBbits.RB2
#define BLED2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BLED2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BLED2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define BLED2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define BLED2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define BLED2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define BLED2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define BLED2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set SLED4 aliases
#define SLED4_TRIS                 TRISCbits.TRISC4
#define SLED4_LAT                  LATCbits.LATC4
#define SLED4_PORT                 PORTCbits.RC4
#define SLED4_WPU                  WPUCbits.WPUC4
#define SLED4_OD                   ODCONCbits.ODCC4
#define SLED4_ANS                  ANSELCbits.ANSELC4
#define SLED4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SLED4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SLED4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SLED4_GetValue()           PORTCbits.RC4
#define SLED4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SLED4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SLED4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SLED4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SLED4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SLED4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SLED4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define SLED4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set SLED5 aliases
#define SLED5_TRIS                 TRISCbits.TRISC5
#define SLED5_LAT                  LATCbits.LATC5
#define SLED5_PORT                 PORTCbits.RC5
#define SLED5_WPU                  WPUCbits.WPUC5
#define SLED5_OD                   ODCONCbits.ODCC5
#define SLED5_ANS                  ANSELCbits.ANSELC5
#define SLED5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SLED5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SLED5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SLED5_GetValue()           PORTCbits.RC5
#define SLED5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SLED5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SLED5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SLED5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SLED5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SLED5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SLED5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define SLED5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set SLED6 aliases
#define SLED6_TRIS                 TRISCbits.TRISC6
#define SLED6_LAT                  LATCbits.LATC6
#define SLED6_PORT                 PORTCbits.RC6
#define SLED6_WPU                  WPUCbits.WPUC6
#define SLED6_OD                   ODCONCbits.ODCC6
#define SLED6_ANS                  ANSELCbits.ANSELC6
#define SLED6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SLED6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SLED6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SLED6_GetValue()           PORTCbits.RC6
#define SLED6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SLED6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SLED6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SLED6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SLED6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SLED6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define SLED6_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define SLED6_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set SLED1 aliases
#define SLED1_TRIS                 TRISCbits.TRISC7
#define SLED1_LAT                  LATCbits.LATC7
#define SLED1_PORT                 PORTCbits.RC7
#define SLED1_WPU                  WPUCbits.WPUC7
#define SLED1_OD                   ODCONCbits.ODCC7
#define SLED1_ANS                  ANSELCbits.ANSELC7
#define SLED1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SLED1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SLED1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SLED1_GetValue()           PORTCbits.RC7
#define SLED1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SLED1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SLED1_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define SLED1_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define SLED1_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define SLED1_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define SLED1_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define SLED1_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set EN aliases
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

// get/set BLED1 aliases
#define BLED1_TRIS                 TRISDbits.TRISD5
#define BLED1_LAT                  LATDbits.LATD5
#define BLED1_PORT                 PORTDbits.RD5
#define BLED1_WPU                  WPUDbits.WPUD5
#define BLED1_OD                   ODCONDbits.ODCD5
#define BLED1_ANS                  ANSELDbits.ANSELD5
#define BLED1_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define BLED1_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define BLED1_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define BLED1_GetValue()           PORTDbits.RD5
#define BLED1_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define BLED1_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define BLED1_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define BLED1_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define BLED1_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define BLED1_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define BLED1_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define BLED1_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set SLED3 aliases
#define SLED3_TRIS                 TRISDbits.TRISD6
#define SLED3_LAT                  LATDbits.LATD6
#define SLED3_PORT                 PORTDbits.RD6
#define SLED3_WPU                  WPUDbits.WPUD6
#define SLED3_OD                   ODCONDbits.ODCD6
#define SLED3_ANS                  ANSELDbits.ANSELD6
#define SLED3_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define SLED3_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define SLED3_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define SLED3_GetValue()           PORTDbits.RD6
#define SLED3_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define SLED3_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define SLED3_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define SLED3_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define SLED3_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define SLED3_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define SLED3_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define SLED3_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set RD7 procedures
#define RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define RD7_GetValue()              PORTDbits.RD7
#define RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define RD7_SetPullup()             do { WPUDbits.WPUD7 = 1; } while(0)
#define RD7_ResetPullup()           do { WPUDbits.WPUD7 = 0; } while(0)
#define RD7_SetAnalogMode()         do { ANSELDbits.ANSELD7 = 1; } while(0)
#define RD7_SetDigitalMode()        do { ANSELDbits.ANSELD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/