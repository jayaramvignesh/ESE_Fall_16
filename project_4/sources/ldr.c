/*
 *		Filename: ldr.c
 *      Description: This source file contains the functions for ldr.
 *
 *
 *  	Created on: Dec 4, 2016
 *      Author: Arundhathi Swami, Vignesh Jayaram
 */


#include "ldr.h"

uint16_t ldr_result;
uint16_t ldr_value_mvs;
char ldr[]="Ldr value in mvs:";

void ldr_read()
{
	ldr_result = adc4_read();
	ldr_value_mvs = (ldr_result) * 3300.0 / 65536;
	if(ldr_value_mvs > 1600)
		LED_INTENSITY(0);
	else if(ldr_value_mvs < 400)
		LED_INTENSITY(1875);
	else
		LED_INTENSITY(1200);
	log1(ldr,ldr_value_mvs);
	log0("\n\r");
}

double ldr_profiling()
{
	double time_taken;
	counter_start();
	ldr_result = adc4_read();
	counter_stop();
	time_taken=counter_calculate();
	ldr_value_mvs = (ldr_result) * 3300.0 / 65536;
	if(ldr_value_mvs > 1600)
		LED_INTENSITY(0);
	else if(ldr_value_mvs < 400)
		LED_INTENSITY(1875);
	else
		LED_INTENSITY(1200);
	log1(ldr,ldr_value_mvs);
	log0("\n\r");

	return time_taken;
}



