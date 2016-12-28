/*
 *       Filename: capsense.h
 *      Description: This header file contains the functions for capacitive touch sensor.
 *
 *
 *  	Created on: Dec 4, 2016
 *      Author: Arundhathi Swami, Vignesh Jayaram
 *
 *  This header file includes functions that map touch response inputs to the onboard LED
 *
 *  1. capsense_response(): This function turns the LED on or off in different colours according to the touch range detected.
 *	2. capsense_profiling(): This function is same as capsense_response. It just performs the timme profiling for one capsense_Read.
 *
 */

#ifndef INCLUDES_CAPSENSE_H_
#define INCLUDES_CAPSENSE_H_

#include "touch.h"
#include "log.h"
#include "uart.h"
#include "circbuff.h"
#include "conversion.h"
#include "profiling.h"
#include "led.h"


void capsense_response(void);
void capsense_profiling(void);


#endif /* INCLUDES_CAPSENSE_H_ */
