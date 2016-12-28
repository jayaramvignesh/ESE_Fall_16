/********************************************
*   Authors: Arundhathi Swami, Vignesh Jayaram
*   Date Edited: 19 Sept 2016
*
*   File: data_ff.h
*
*   Description: Header file for data manipulation 
*		 for FRDMKL25z Board
*                -my_itoa
*		 -my_atoi
*		 -dump_memory
*		 -big_to_little
*		 -little_to_big
*
*
********************************************************

/* header  file for function called "data"*/

#ifndef data_INCLUDED
#define data_H_INCLUDED

#include <stdint.h>

	int8_t* my_itoa(int8_t *str, int32_t data, int32_t base);//function converting integral values to strings
	int32_t my_atoi(int8_t *str);//function converting string ascii inputs to integers
	void dump_memory(uint8_t *start, uint32_t length);//printing values from memory in hex representation
	uint32_t big_to_little(uint32_t data);//changes endianness
	uint32_t little_to_big(uint32_t data);//changes endianness
#endif

