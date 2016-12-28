/***************************************************************************
 *
 *  	Filename: uart_init.h
 *      Description:  This header file contains the functions for UART0
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
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
void write_string(uint8_t *str);
void log1(uint8_t * str, uint32_t param);
#endif
