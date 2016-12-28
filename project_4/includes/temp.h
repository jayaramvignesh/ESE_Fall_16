/*
 * 	    Filename: temp.h
 *      Description:  This header file contains the functions for temperature sensor TMP36
 *
 *		Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: December 3,2016
 *
 *      1. temperature_Read
 *      > This function uses adc channel 0 to read the value of the temperature sensor TMP36 for fifteen consecutive times.
 *      > If the temperature falls below 5 degrees Celsius then red LED will glow and if temperature drops below 0 degrees Celsius, green LED will glow.
 *      > The values obtained are also logged onto the serial terminal.
 *      > The final values are based on the average of fifteen consecutive readings.
 *
 *      2. temperature_Read_Profiling
 *      > This function is same as temperature_Read.
 *      > Profiling is added in this function to calculate the time required for one adc read i.e reading analog from the sensor and converting it to a digital float value..
 *
 *
 */

#ifndef INCLUDES_TEMP_H_
#define INCLUDES_TEMP_H_

#include "adc.h"
#include "log.h"
#include "uart.h"
#include "circbuff.h"
#include "conversion.h"
#include "profiling.h"

void temperature_Read(float *x);
double temperature_Read_Profiling();

#endif /* INCLUDES_TEMP_H_ */
