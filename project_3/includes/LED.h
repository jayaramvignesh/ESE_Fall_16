/***************************************************************************
 *
 *  	Filename: LED.c
 *      Description:  This header file contains the functions for LED
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/

#ifndef LED
#define LED

#include "MKL25Z4.h"
#include "circbuff.h"
#include "uart_init.h"


 enum color{
	OFF,
	RED,
	YELLOW,
	MAGENTA,
	GREEN,
	CYAN,
	BLUE,
	WHITE
};

void LED_INIT_GPIO(void);
void LED_INTENSITY(uint8_t color, uint16_t bright);
void LED_INIT_PWM(void);

#endif
