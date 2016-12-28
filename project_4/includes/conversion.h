/***************************************************************************
 *
 *   	Filename: conversion.c
 *      Description:  This header file contains the functions for conversion of data
 *      from uint, int to  float, string and char.
 *
 *      1. my_itoa
 *      > This function converts integers to ascii values
 *
 *      2. my_atoi
 *      > This function converts ascii characters to their integral equivalents
 *
 *      3. TransferFloatingToDecimal
 *      > this function converts fractional (float) values to integers
 *
 *      4. intToStr
 *      > this function converts integers to strings
 *
 *      5. my_ftoa
 *      > float values are converted to their equivalent ascii values
 *
 *      6. reverse
 *      > This function is generically used to reverse the order of a set of integers and/or characters
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/

#ifndef Conversion_h
#define Conversion_h

#include <stdio.h>
#include <stdint.h>

uint8_t *my_itoa( uint8_t * str, int32_t data, int32_t base );

int32_t my_atoi(uint8_t * str);

float TransferFloatingToDecimal(uint8_t s[32]);

void reverse(uint8_t *str, uint32_t len);
uint8_t intToStr(uint16_t x, uint8_t str[], uint32_t d);
void my_ftoa(float n, uint8_t *res, uint16_t afterpoint);


#endif
