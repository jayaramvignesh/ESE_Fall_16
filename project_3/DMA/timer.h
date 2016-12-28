/*
 * timer_profiling.h
 *
 *  Created on: Oct 30, 2016
 *      Author: Arundhathi Swami, Vignesh Jayaram
 */

#ifndef INCLUDES_PROFILING_H_
#define INCLUDES_PROFILING_H_

#include "MKL25Z4.h"
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

#define CLOCK_RESOLUTION 0.047

void counter();
void counter_start();
void counter_stop();

#endif /* INCLUDES_PROFILING_H_ */
