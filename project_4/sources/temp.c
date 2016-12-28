/*
 *
 * 	    Filename: temp.c
 *      Description:  This source file contains the functions for temperature sensor TMP36
 *
 *
 *      Created on: Dec 4, 2016
 *      Author: Arundhathi Swami and Vignesh Jayaram
 */

#include "temp.h"
#include "led.h"

char msg_tmp36[]="TMP36 temp value is:";
int tmp36_result;
float tmp36_temperature;
void temperature_Read(float *x)
{
	tmp36_result = adc0_read();
	tmp36_temperature = (tmp36_result) * 3300.0 / 65536; // convert ADC value to voltage
	tmp36_temperature = (tmp36_temperature - 500)/10;	 //convert voltage to temprature
	GPIOD_PSOR |= PORTD_PCR1_BLUE_LED;
	*x = tmp36_temperature;
	log1(msg_tmp36,tmp36_temperature);
	log0("\n\r");
}

double temperature_Read_Profiling()
{
	double time_taken;
	counter_start();
	tmp36_result = adc0_read();
	counter_stop();
	time_taken=counter_calculate();
	tmp36_temperature = (tmp36_result) * 3300.0 / 65536; 	//convert adc value to voltage
	tmp36_temperature = (tmp36_temperature - 500)/10;		// convert voltage to temperature
	log1(msg_tmp36,tmp36_temperature);
	log0("\n\r");
	return time_taken;
}



