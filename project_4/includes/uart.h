/***************************************************************************
 *
 *  	Filename: uart.h
 *      Description:  This header file contains the functions for UART0
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 *      1. INIT_UART0
 *      >This function configures the onboard UART0 for the following set of attributes:
 *      1. 8 bit data transmission
 *      2. No parity checking
 *      3. 1 Stop bit
 *      4. clock source: 20.97 MHz  = PLL/2
 *      5. Baud rate 38400 symbols/sec
 *      6. interrupts activated
 *      7.
 ****************************************************************************/

#ifndef UART
#define UART

#include "MKL25Z4.h"
#include "circbuff.h"
#include <string.h>
#include "conversion.h"

#define BAUD 38400
cirbuff_t transmit_buff,  receive_buff;

void INIT_UART0(void);
#endif
