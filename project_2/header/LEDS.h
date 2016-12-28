/*
 * LEDS.h
 *
 *  Created on: Oct 12, 2016
 *      Author: Arundhathi Swami, Vignesh Jayaram
 *
 *  Header Defined for Intialising LEDS configured to display PWM values
 */

#ifndef INCLUDES_LEDS_H_
#define INCLUDES_LEDS_H_

#include "MKL25Z4.h"
#include "system_MKL25Z4.h"
#include <stdint.h>
#include "UART0_INIT.h"

typedef enum Colour_Selection
{
	OFF,
	R,
	G,
	B,
	Y,
	V,
	C,
	WHITE,
}LColour;

void LED_Init();   //initialising and clock gating LED
void LED_Function(uint8_t function);   //used to either toggle colour values or intensities
void LED_Intensity(LColour LEDColour, uint16_t Intensity); //changes intensity based on selected Colour values
void LED_Colours(char value); //function to input colour values through the UART
void LED_Toggle(uint32_t colour); //Function to only toggle colours on the LED
void UART0_IRQHandler(); //Invoking Interrupt Handler Function



#endif /* INCLUDES_LEDS_H_ */
