/*
 *      Filename: ldr.h
 *      Description: This header file contains the functions for ldr.
 *
 *
 *  	Created on: Dec 4, 2016
 *      Author: Arundhathi Swami, vignehs Jayaram
 *
 *      This header file contains all functions pertaining to reading values off of the LDR and converting them to usable units.
 *
 *
 *      1. ldr_read
 *      > This function uses adc channel 4 to read the value of the light dependent resistor.
 *      > Depending on the ldr value, the brightness of external LED is controlled.
 *      > The values obtained are also logged onto the serial terminal.
 *
 *      2. ldr_profiling
 *      > This function is same as ldr_test.
 *      > Profiling is added in this function to calculate the time required for one adc read.
 */

#ifndef INCLUDES_LDR_H_
#define INCLUDES_LDR_H_

#include "MKL25Z4.h"
#include "adc.h"
#include "log.h"
#include "uart.h"
#include "circbuff.h"
#include "conversion.h"
#include "led.h"
#include "profiling.h"

void ldr_read();
double ldr_profiling();

#endif /* INCLUDES_LDR_H_ */
