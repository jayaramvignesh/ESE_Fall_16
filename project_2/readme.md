ECEN 5013- Embedded Software Essentials 
PROJECT 2

Group Members: Arundhathi Swami
			   Vignesh jayaram 
			   
This project was implemented to achieve the following goals:
1. Writing drivers for various functionalities on the FRDM board
2. Code profiling 

The project is comprised of various files set up for a number of functions 
1. main.c - This source file contains compile time switches for various functionalities like UART initilisation, Logging, Circular Buffer testing etc 

2. UART0_INIT.h / UART0_INIT.c- These are interconnected files that contain different configuration settings for the UART0 as both transmitter and receiver with software pollimg and interrupt enabled set ups

3. LOGGER.h/ LOGGER.c - Logging functionality is emulated using two logger functions for printing loggig information of strings and numbers 

4. LEDS.h / LEDS.c - These two functions are header and source files respectively for igniting the onboard LED with different colors depending on pulse width modulation values and by changing the duty cycle to give diffreent viewable wavelengths based on three primary colours.
The native implementation is configured as :
+ - increses the intensity of the current LED colour
- - decrements the intensity of the current colour
u - Changes the colour of the LED in the upward direction 
d - chnages the LED colour in the downward directon

This requires changing of the duty cycle which is equivalent to changing the pulse width according to the visibility of colour required.

5. BUFFER.h / BUFFER.c - These files implement a circular FIFO buffer 

6. CBUNITTESTS.h / CBUNITTESTS.c - These files are implemented to perform unit tests on the buffer to check for it's appropriate functioning 

apart from that we have performed timer profiling on both the BBB and FRDM boards 

7. codeprofiling_FRDM.c - This file performs code profiling for the FRDM board and gives the time taken by each function to compile with a resolution of usecs.
8. codeprofiling_BBB.c - This source file perfomrs code profiling of the same functions for the BEagle Bone Black dev board. 

 