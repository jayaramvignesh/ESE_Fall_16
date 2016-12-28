/***************************************************************************
 *      Filename: log.h
 *      Description:  This header file contains the functions for data logger used to print to the terminal.
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 *      1.log0
 *      > This function is used to print a string of characters onto the serial terminal.
 *      > It is configured using a UART in order to output important data about the program being run.
 *
 *      2. log1
 *      > This function takes a string and a number {integer or float} and then prints them onto the serial number.
 *      > It uses the FTOA function to convert a given integer or float value to an ascii string.
 *      > It then appends this ascii value with the given string and displays them together.
 *
 *      3.delay()
 *      >This function is used to add a delay between logging functions.
 *
 ****************************************************************************/

#ifndef LOG
#define LOG

#include "MKL25Z4.h"
#include "uart.h"
#include <string.h>
#include "circbuff.h"
#include "conversion.h"
//#include "main.h"

void log0(uint8_t *string);
void log1(uint8_t *string, float param);
void delay(void);

#endif
