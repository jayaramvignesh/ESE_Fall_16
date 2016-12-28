/*
 *	  	Filename: profiling.h
 *      Description:  This header file contains the functions for profiling.
 *
 *  	Created on: Oct 30, 2016
 *  	Author: Arundhathi Swami, Vignesh Jayaram
 *
 *		1.counter()
 *		> TPM0 and FLL clock are configured for timer profiling.
 *		> MOD value is set to 65535.
 *		> count is initialized to zero.
 *		> Counter is configured for UP_COUNT only.
 *
 *		2.  counter_calculate()
 *		> Responsible for taking the counter value after counter stop and calculating the time taken in usecs.
 *
 *		2. Macro Function for counter_start()
 *		> count value is set to zero.
 *		> mode for count is set, this starts the counter.
 *
 *		3. Macro function for counter_stop()
 *		> mode for count is disabled.
 *
 *		4. Macro variable CLOCK_RESOLUTION is set to 0.047.
 *		> Since, we are using 20.97 MHz,the resolution is (1/20.97MHz) i.e. 0.047 microseconds
 *
 */

#ifndef INCLUDES_PROFILING_H_
#define INCLUDES_PROFILING_H_

#include "MKL25Z4.h"
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

#define CLOCK_RESOLUTION 0.047
#define counter_start() 	TPM0->CNT = 0x0; \
							TPM0->SC = 0x00000008

#define counter_stop()		TPM0->SC = 0x00000000

double time_elapsed;
double cpu_ticks;

void counter();
double counter_calculate(void);

#endif /* INCLUDES_PROFILING_H_ */

