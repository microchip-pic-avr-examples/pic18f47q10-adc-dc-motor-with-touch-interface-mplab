<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="200"/></a>

## DC Motor Control Using Capacitive Touch Interface

## Introduction

The PIC18-Q10 family of microcontrollers (MCUs) is equipped with a 10-bit Analog-to-Digital Converter with Computation (ADCC) and Hardware Capacitive Voltage Divider (CVD) technique for advanced capacitive touch sensing, which are used to demonstrate this application demo. Along with these peripherals, the PIC18-Q10 family has a rich set of analog and digital peripherals, communication modules, and Core Independent Peripherals (CIP). This application demo discusses one of the simple and very useful real-time control application, DC motor control using capacitive touch buttons and a slider.

 Click the image below to view the demo operation video of DC Motor Control Using Capacitive Touch Interface.

<p align="left">
<br><a href="https://youtu.be/-_WE2X03uRQ" rel="nofollow"><img src="images/videofrontimage.png" alt="AVR DA" width="500"/></a>
</p>


## Software used

- [MPLAB® X IDE v6.20](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_PIC18-Q10&utm_content=pic18f47q10-adc-dc-motor-with-touch-interface-mplab-github&utm_bu=MCU08) or newer
- [XC8 Compiler 2.46](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_PIC18-Q10&utm_content=pic18f47q10-adc-dc-motor-with-touch-interface-mplab-github&utm_bu=MCU08) or newer
- [MPLAB Code Configurator (MCC) 5.5.0](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_PIC18-Q10&utm_content=pic18f47q10-adc-dc-motor-with-touch-interface-mplab-github&utm_bu=MCU08) or newer
- [Microchip PIC18F-Q Series Device Support 1.25.433](https://packs.download.microchip.com/) or newer

**Note:** For running the demo, the installed tool versions should be the same or later. This example is not tested with the previous versions.


## Hardware used

- [DC Motor 8 click]( https://www.mikroe.com/dc-motor-8-click "DC Motor 8 click")
- [PIC18F47Q10 Curiosity Nano](https://www.microchip.com/en-us/development-tool/DM182029?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_PIC18-Q10&utm_content=pic18f47q10-adc-dc-motor-with-touch-interface-mplab-github&utm_bu=MCU08)
- [Curiosity Nano Base for Click boards™](https://www.microchip.com/developmenttools/ProductDetails/AC164162 "Curiosity Nano Base for Click boards")
- [QT7 Xplained Pro Extension Kit](https://www.microchip.com/developmenttools/ProductDetails/atqt7-xpro "QT7 Xplained Pro Extension Kit")


## Useful Links

- [PIC18F47Q10 Product Page](https://www.microchip.com/en-us/product/PIC18F47Q10?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_PIC18-Q10&utm_content=pic18f47q10-adc-dc-motor-with-touch-interface-mplab-github&utm_bu=MCU08)
- [QT7 Xplained Pro User Guide](https://www.microchip.com/50002725A)
- [DC Motor Control with Touch Interface and IR Communication-Application Note](http://ww1.microchip.com/downloads/en/AppNotes/AN2933-DC-Motor-Control-with-Touch-Interface-and-IR00002933A.pdf "DC Motor Control with Touch Interface and IR Communications-Application Note")


## Description

In this application demo, Curiosity Nano base for Click boards with PIC18F47Q10 Curiosity Nano board, QT7 Xplained Pro extension board for capacitive touch sensors, and DC motor 8 Click board to control the DC motor are used. This application demonstrates the usage of ADCC with hardware CVD technique and Pulse-Width Modulation (PWM) peripherals of the PIC18F47Q10 MCU to control the DC motor with touch interface. For more details about the CVD technique please refer to the [mTouch™ Sensing Solution Acquisition Methods Capacitive Voltage Divider](https://ww1.microchip.com/downloads/en/appnotes/01478A.pdf) application note available on Microchip website. The firmware libraries for this demo example is generated with the help of MPLAB® X Code Configurator (MCC) plugin available with MPLAB X IDE. For more details about how to set up a basic mTouch project please refer to [mTouch® Capacitive Sensing Library Module for Mplab® X Code Configurator User’s Guide.](http://ww1.microchip.com/downloads/en/DeviceDoc/40001852A.pdf "mTouch® Capacitive Sensing Library Module for Mplab® X Code Configurator User’s Guide").


## Implementation Of DC Motor Control Using Touch Interface

To develop this application, the PIC18F47Q10 MCU is interfaced with QT7 Xplained Pro extension board and its analog pins are required to acquire the capacitive touch sensors data, which is analog in nature. This demo used ADC computation feature along with CVD technique to acquire said data. The QT7 Xplained Pro extension board has got two touch buttons and one slider. Additionally, the board has 8 LEDs that indicate the touch detection. The DC Motor 8 click board from MikroElektronika is used to drive the DC motor. This click board relies on the MIC4605, an 85V half-bridge MOSFET driver with adaptive dead-time and shoot-through protection, from Microchip. The DC Motor 8 click employs a boost converter made of MIC2206, a 2 MHz boost regulator from Microchip. The click board can drive motors with up to 40V with an output current of up to 1 amp. The PWM signal from MCU drives the motor. The EN pin which is used to enable the device is routed to the mikroBUS™ CS pin. Logic HIGH on EN pin will set the MIC4605 to work in Normal mode, while logic LOW on EN pin will put the MIC4605 into the Power Conservative Shutdown mode. This pin is pulled HIGH with the on board resistor. Figure 1 shows the basic block diagram of the implementation of the application demo.

<p align="left">
  <img width=auto height=auto src="images/blockdiagram.png">
</p>

### Hardware setup

<p align="left">
  <img width=auto height=auto src="images/hardwaresetup.png">
</p>

As shown in the above figure, QT7 Xplained Pro Extension board is connected to Curiosity Nano Base for click boards. DC motor 8 Click is connected to mikroBUS slot 1 of Curiosity Nano Base board. DC Motor along with rotating wheel is connected to the DC motor 8 Click and also to the power pins of the Curiosity Nano Base board.

The following table shows the connections between QT7 Extension Pro and Curiosity Nano Base for click boards.

|S No. | Xplained Pro Extension Header Pin Names | Signal Name of Pins of PIC18F47Q10 | Pin Number in QT7 Header1 |Signal Name of QT7 pins | IN/OUT Pin configuration in MCU|
|:---------:|:----------:|:-----------:|:---------:|:------------:|:------------:|
| 1     | AN3  	| RA2	  | 4	| Y-LINE-1       |	IN   |
| 2     | RST2 	| RC7 	| 5 | LED0           |  OUT  |
| 3     | RST3 	| RD5 	| 6	| LED6           |  OUT  |
| 4     | PWM2 	| RA4 	| 7	| Y-LINE-2       |	IN   |
| 5     | PWM3 	| RA5	  | 8	| Y-LINE-3       |	IN   |
| 6    	| INT2 	| RB4 	| 9	| Y-LINE-4       |  IN   |
| 7     | CS3  	| RD7 	| 10| Y-LINE-0       |  IN   |
| 8     | SDA   | RB2   | 11| LED7           |  OUT  |
| 9     | SCL   | RB1   | 12| LED1           |  OUT  |
| 10    | CS2   | RD6   | 15| LED2           |  OUT  |
| 11    | MOSI  | RC4   | 16| LED3           |  OUT  |
| 12    | MISO  | RC5   | 17| LED4           |  OUT  |
| 13    | SCK   | RC6   | 18| LED5           |  OUT  |


## Operation

This application demonstrates DC motor control using capacitive touch buttons and a slider. The buttons start and stop the DC motor while the slider adjusts the speed. Their configuration is explained below:

1. Touch Button1 to start the motor.
2. Move the finger on the Slider to increase or decrease the motor speed.
3. Touch Button2 to stop the running motor.

After a system reset, all LEDs present on the QT7 Xplained Pro board are in OFF state and DC motor is turned OFF.

<p align="left">
  <img width=auto height=auto src="images/initialstate.png">
  <br> DC motor is in the Reset state <br>
</p>

Press Button1 to start the motor and make it run at a pre-defined minimum speed. The LED associated with the Button1 turns ON to indicate the Button1 press event. Also, the slider's lowest position LED is turned ON to indicate the start position of the motor

<p align="left">
  <img width=auto height=auto src="images/lowestspeed.png">
  <br> DC motor starts running at a pre-defined speed<br>
</p>

Moving the finger from left to right on the slider gradually increases the speed of the motor, which is also indicated by the LEDs turning on.

<p align="left">
  <img width=auto height=auto src="images/increasingSpeed.png">
  <br>DC motor is running at a moderate speed<br>
</p>

Once the finger reaches the extreme right position on the slider, the motor runs at the highest speed and all the indication LEDs will be turned ON.

<p align="left">
  <img width=auto height=auto src="images/highestspeed.png">
  <br> DC motor is running at the highest speed<br>
</p>

Moving the finger from right to left on the slider gradually decreases the speed of the motor, which is also indicated by the LEDs turning off. Once the finger reaches the extreme left position on the slider, the speed of the motor becomes zero and it will stop.

<p align="left">
  <img width=auto height=auto src="images/lowestspeed.png">
  <br> DC motor is running at the lowest speed<br>
</p>

Press Button2 to stall the motor. The indication LED of Button2 will turn ON to indicate the button press event.

<p align="left">
  <img width=auto height=auto src="images/motorStopped.png">
  <br> DC motor is stalled <br>
</p>


## Peripheral Configuration
This section explains how to configure the peripherals using MPLAB X IDE with MCC plug-in to recreate the project.

Refer to the [Software Used ](https://github.com/microchip-pic-avr-examples/pic18f47q10-adc-dc-motor-with-touch-interface-mplab#software-used) section to install required tools.

Additional Links: [MCC Melody Technical Reference](https://onlinedocs.microchip.com/v2/keyword-lookup?keyword=MCC.MELODY.INTRODUCTION&version=latest&redirect=true)

| Module | Configuration | Usage |
|--------|----------------|----------------|
| Clock control |   Clock Source - HFINTOSC<br> HF Internal Clock - 32 MHz<br> Clock Divider - 1 | System Clock|
| ADCC          |   *Hardware Settings* <br> Enable ADCC<br> Operating mode - Basic mode <br> Result Alignment - right<br><br>*Interrupt Settings* <br> Enable ADCC Threshold Interrupt| Process output of Touch |
|PWM  | *Software Settings*<br> Timer Dependency Selector - Timer2<br><br> *Hardware Settings* <br> PWM Enable - Enable <br> Select a Timer - TMR2 | To vary DC motor speed |
| Timer2| *Hardware Settings* <br> Enable Timer <br> Control Mode - Roll over pulse <br><br> *Timer clock* <br>Clock Source - Fosc/4 <br> Prescaler - 1:1<br> Postscaler - 1:1 <br><br> *Timer Period*<br>Timer Period - 25 us <br>| To control PWM module|
| Pins| *Pins - Custom Name*<br> RC7 - SLED1<br> RB1 - SLED2<br> RD6 - SLED3<br> RC4 - SLED4<br>RC5 - SLED5<br> RC6 - SLED1<br> RD5 - BLED1<br> RB7 - BLED2<br> RD4 - EN<br> <br> *Pin Grid View* <br> *PWM*<br> PWM4OUT - RA3<br> *Touch*<br>RA2 (Y-LINE-1)<br>RA4 (Y-LINE-2)<br> RA5 (Y-LINE-3)<br>RB4 (Y-LINE-4)<br>RD7 (Y-LINE-0)<br> *Pins* <br> *Output:* <br> RB1 (SLED2)<br>RB2 (BLED2)<br> RC4 (SLED4)<br>RC5 (SLED5)<br>RC6 (SLED6)<br>RC7 (SLED7)<br> RD4 (EN)<br>RD5 (BLED1)<br>RD6 (SLED3)<br>| Pin Configuration|

To add the Touch library to the project, open Content Manager in MCC, select Touch under Libraries and click on **Apply**. Now, Touch will be added to the device resources. Click Touch Configurator in the device resources and click the add symbol to add the Touch library to your project. Now, let's configure the Touch library.  

The table below shows the Touch library configuration in MCC.

| Module | Configuration | Usage |
|--------|----------------|----------------|
| Touch  | *Create*<br>Button - 4 <br> Slider - 3 <br> (click **Add**  after selecting these)<br><br> *Configure*<br> *Sensor pins:*<br>  Button 0 -  ANA2 (RA2)<br>  Button 1 - AND7 (RD7) <br> Slider 0 - ANB4 (RB4)<br> Slider 0 - ANA5 (RA5)<br>  Slider 0 - ANA4 (RA4)<br> *Sensor parameters:*<br> Slider 0 Threshold - 50<br> *Common Parameters:* <br> *Sensor*<br> Scan Rate Configuration in (ms) - Free Running <br> *Buttons*<br> Interface Method - Callback function notifies application | To configure touch and generate API's for its Application  |


## Summary
This application demo shows the usage of a few important peripherals of the PIC18-Q10 family of MCUs such as ADCC with CVD, PWM, and Timer for simple, real-time control applications. The combination of PWM and other core independent peripherals along with advanced analog peripherals offers a lower system cost, low-power, reliable and predictable application development.
