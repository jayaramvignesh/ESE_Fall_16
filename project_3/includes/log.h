/***************************************************************************
 *
 *  	Filename: log.h
 *      Description:  This header file contains the functions for logger
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/

#ifndef LOG
#define LOG

#include "MKL25Z4.h"
#include "uart_init.h"
#include <string.h>
#include "circbuff.h"
#include "conversion.h"
//#include "main.h"

void log0(uint8_t *string);
void log3(uint8_t *string, float param);

#endif
