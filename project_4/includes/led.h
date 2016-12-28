/***************************************************************************
 *
 *   	Filename: led.h
 *      Description:  This header file contains the functions for LED
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: December 3,2016
 *
 *      1. Configure_LEDS
 *      > This function is used to configure the on-board LEDS.
 *      > This function enables clock to port B and port D
 *      > Port D Pin 1, Port B pin 18 and Port B pin 19 are set in GPIO mode.
 *      > These pins are then pulled high and the set as output pins.
 *
 *      2. EXLED_INIT_GPIO()
 *      > This function is used to set up the external LED required for LDR.
 *      > CLock to Port E is enabled and Port E pin 22 is used in GPIO mode.
 *      > The pin is then set in output mode.
 *
 *		3. LED_INIT_PWM()
 *		> Clocks for Port E and TPM2 timer is setup
 *		> PLL is selected as clock source for TPM2.
 *		> MUX for Port E pin 22 is set to PWM mode.
 *		> MOD value is set to 1875.
 *
 *		4. LED_INTENSITY
 *		> This function is used to control the brightness of LED.
 *
 *		5. Static Inline Functions
 *		> Static inline functions have been written to turn on the various on-board LED colors and to switch the led off.
 ****************************************************************************/

#ifndef INCLUDES_LED_H_
#define INCLUDES_LED_H_

#include "MKL25Z4.h"

#define CLOCK_GATE_PORTD_PORTB 0x00001400
#define SET_GPIO_MODE_ALT 0x00000100
#define PORTD_PCR1_BLUE_LED  0x00000002
#define PORTB_PCR19_GREEN_LED 0x00080000
#define PORTB_PCR18_RED_LED 0x00040000


void Configure_LEDS (void);
void EXLED_INIT_GPIO(void);
void  LED_INTENSITY(uint16_t intensity);

static inline void glow_red()
{
	GPIOB_PCOR |= PORTB_PCR18_RED_LED;                          //Glow RED
	GPIOB_PSOR |= PORTB_PCR19_GREEN_LED;
	GPIOD_PSOR |= PORTD_PCR1_BLUE_LED;
}

static inline void glow_blue()
{
	GPIOD_PCOR |=  PORTD_PCR1_BLUE_LED;                          //Glow BLue
	GPIOB_PSOR |= PORTB_PCR19_GREEN_LED;
	GPIOB_PSOR |= PORTB_PCR18_RED_LED;
}

static inline void glow_green()
{
	GPIOD_PSOR |=  PORTD_PCR1_BLUE_LED;                          //Glow GREEN
	GPIOB_PCOR |= PORTB_PCR19_GREEN_LED;
	GPIOB_PSOR |= PORTB_PCR18_RED_LED;
}

static inline void glow_cyan()
{
	GPIOD_PCOR |=  PORTD_PCR1_BLUE_LED;                          //Glow CYAN
	GPIOB_PCOR |= PORTB_PCR19_GREEN_LED;
	GPIOB_PSOR |= PORTB_PCR18_RED_LED;
}

static inline void turn_off()
{
	GPIOB_PSOR |= PORTB_PCR18_RED_LED;                          //Turn off all LEDs
	GPIOB_PSOR |= PORTB_PCR19_GREEN_LED;
	GPIOD_PSOR |= PORTD_PCR1_BLUE_LED;
}



#endif /* SOURCES_TOUCH_LED_C_ */
