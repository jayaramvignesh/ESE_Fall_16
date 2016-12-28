/*
 * 	Filename: adc.h
 *  Description: This header file contains the functions for ADC.
 *
 *
 *  Created on: December 1, 2016
 *  Author: Arundhathi Swami, Vignesh Jayaram
 *
 *  ADC is configured for the following specs:
 *  1. clock source: Bus Clock
 *  2. reference voltage: VREFH, VREFL
 *  3. trigger: Software Trigger
 *  4. resolution: 16 bit
 *  5. output : Single Ended
 *  6. sample time: long Sample time
 *  7. averaging: hardware averaging enabled, averages for 32 samples with continuous conversion
 *
 *
 *  1. adc0_init()
 *  >This function configures the ADC to use its channel 0 to read values sent by temperature sensor (TMP36) at PTE20
 *
 *
 *  2. adc0_read()
 *  > This function reads converted values of the analog input.
 *
 *  3. adc4_init()
 *  >This function enables the ADC to use its channel 4 to read analog values sent in by the thermistor at pin 21 of PORT E.
 *
 *  4. adc4_read()
 *  >This function reads converted values of the analog input from channel 4.
 *
 *
 */

#ifndef ADC_H_
#define ADC_H_

#include "MKL25Z4.h"

/* Prototypes */
void adc0_init(void);
int adc0_read(void);

void adc4_init(void);
int adc4_read(void);

#endif /* ADC_H_ */
