/***************************************************************************
 *
 *  	Filename: profiling.h
 *      Description:  This header file contains the functions for Profiling
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/

#ifndef INCLUDES_PROFILING_H_
#define INCLUDES_PROFILING_H_

#include "MKL25Z4.h"
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

#define CLOCK_RESOLUTION 0.047

void initialize_counter();
void counter_start();
void counter_stop();

#endif /* INCLUDES_PROFILING_H_ */
