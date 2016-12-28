/*
    Authors: Arundhathi Swami, Vignesh Jayaram
*   Date Edited: 14 Oct 2016
*
*   File: logger_header.c
*
*   Description: header file for logger
*        -LOG_0
*		 -LOG_1
*		 -my_ftoa
*		 -my_itoa
 *
 *  Created on: Oct 11, 2016
 *
 */

#ifndef INCLUDES_LOGGER_H_
#define INCLUDES_LOGGER_H_

#include "MKL25Z4.h"
#include "system_MKL25Z4.h"
#include<stdint.h>
#include "UART0_INIT.h"

void LOG_0(char *str);
void LOG_1(char *str, float value);
char* ftoa(double value, uint32_t resolution);
int8_t my_itoa(int32_t data, int8_t *str, int32_t base);


#endif /* INCLUDES_LOGGER_H_ */

