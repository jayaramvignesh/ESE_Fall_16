/*
 *  Filename: capsense.c
 *  Description: This source file contains the functions for capacitive touch sensor.
 *
 *
 *  Created on: Dec 4, 2016
 *  Author: Arundhathi Swami and Vignesh Jayaram
 */

#include "capsense.h"


void capsense_response(void)
{
	float touch_result;
	char test[]= "T:";
	touch_result = TOUCH_SENSE();
	if (touch_result >= 30 && touch_result <= 50)
	{
		glow_red();
	}
	else if (touch_result >= 51 && touch_result <= 65)
	{
		glow_blue();
	}
	else if (touch_result >= 65 && touch_result <= 85 )
	{
		glow_green();
	}
	else
	{
		glow_cyan();
	}
	log1(test,touch_result);
	log0( "\n\r");
	for (uint32_t i = 0; i<100000; i++){}

}

void capsense_profiling(void)
{
	double time_taken;
	float touch_result;
	char test[]= "T:";
	counter_start();
	touch_result = TOUCH_SENSE();
	counter_stop();
	log1(test,touch_result);
	log0( "\n\r");
	time_taken = counter_calculate();
	log1("time taken for one capsense read in microseconds is ",time_taken);
	log0("\n\r");
	if (touch_result >= 30 && touch_result <= 50)
	{
		glow_red();
	}
	else if (touch_result >= 51 && touch_result <= 65)
	{
		glow_blue();
	}
	else if (touch_result >= 65 && touch_result <= 85 )
	{
		glow_green();
	}
	else
	{
		glow_cyan();
	}

	for (uint32_t i = 0; i<100000; i++){}

}



