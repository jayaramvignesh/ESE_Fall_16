/***************************************************************************
 *
 *  	Filename: SPI.h
 *      Description:  This header file contains the functions for SPI
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/

#ifndef SPI
#define SPI

#include "MKL25Z4.h"

void INIT_SPI(void);
uint8_t TRANSFER_SPI(uint8_t value);
void chipselect_low(void);
void chipselect_high(void);

#endif
