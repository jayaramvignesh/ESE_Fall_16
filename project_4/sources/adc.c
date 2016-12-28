/*
 *  Filename: adc.c
 *  Description: This source file contains the functions for ADC.
 *
 *  Created on: December 1, 2016
 *  Author: Arundhathi Swami, Vignesh Jayaram
 *
 *
 */




#include "MKL25Z4.h"
#include "adc.h"
#include <stdint.h>

void adc0_init(void)
{
SIM->SCGC5 |= 0x2000;  //clock gating PORT E
PORTE->PCR[20] = 0;  // Setting PTE 20 as an analog input using ALT 0
SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;	// Activating the clock to ADC
ADC0->SC2 &= ~0x40; //Bit 6==> ADCTRG setting ADC to accept a software trigger (clearing bit)
ADC0->SC3 |= 0x07; //Enables Hardware Avg (bit 2),Selects 32 samples to be averaged (bits 1,0 = 1,1)
//Bits 6,5 = 1,0 ==> Divides clock by 4 to get ADCK clock, Bit 4 =1 ==> Long Sampling Time,
//Bit 3,2 = 1,1 ==> 16 bit resolution for the ADC, Bit, Bits 1,0 = ADICLK ==> Using the Bus clock as it is i.e. 20.94 MHz
ADC0->CFG1 = 0x40 | 0x10 | 0x0C | 0x00;
}

int adc0_read(void)
{
 int result;
 ADC0->SC1[0] = 0; //enabling ADC channel 0 to start conversion
 while(!(ADC0->SC1[0] & 0x80)) //polling bit 8 i.e. conversion complete flag
 {
	 /* wait for COCO */
 }
 result = ADC0->R[0]; //reading conversion result
 return result;
}

void adc4_init(void)
{
SIM->SCGC5 |= 0x2000; //clock gating PORT E
PORTE->PCR[21] = 0;// Setting PTE 21 as an analog input using ALT 0
SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;	// Activating the clock to ADC
ADC0->SC2 &= ~0x40; //Bit 6==> ADCTRG setting ADC to accept a software trigger (clearing bit)
ADC0->SC3 |= 0x07; //Enables Hardware Avg (bit 2),Selects 32 samples to be averaged (bits 1,0 = 1,1)
//Bits 6,5 = 1,0 ==> Divides clock by 4 to get ADCK clock, Bit 4 =1 ==> Long Sampling Time,
//Bit 3,2 = 1,1 ==> 16 bit resolution for the ADC, Bit, Bits 1,0 = ADICLK ==> Using the Bus clock as it is i.e. 20.94 MHz
ADC0->CFG1 = 0x40 | 0x10 | 0x0C | 0x00;
}

int adc4_read(void)
{
 int result;
 ADC0->SC1[0] = 4;//enabling ADC channel 4 to start conversion
 while(!(ADC0->SC1[0] & 0x80)) //polling bit 8 i.e. conversion complete flag
 {
	 /* wait for COCO */
 }
 result = ADC0->R[0]; //reading conversion result
 return result;
}

