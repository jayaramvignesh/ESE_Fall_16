/*
 * Authors: Arundhathi Swami, Vignesh Jayaram
*   Date Edited: 14 Oct 2016
*
*   File: BUFFER.h
*
*   Description: header file for circular buffer
*        -buffer_full
*		 -buffer_add
*		 -buffer_empty
*		 -buffer_remove
*		 -circularbuffer_memoryallocate
*        -circularbuffer_memoryfree
 *
 *  Created on: Oct 12, 2016
 */

#ifndef INCLUDES_BUFFER_H_
#define INCLUDES_BUFFER_H_
#include <stdint.h>
#include <stdlib.h>
enum circular_buffer{full,Empty,available,pass,fail};

typedef struct cir_buf{         //defining a struct
uint8_t length;                 //defines length of the buffer-constant
uint8_t *buffer;                //defines pointer to first element of buffer = constant
uint8_t *head;                  //defines pointer to head of buffer for every new element
uint8_t *tail;                 //defines pointer to every element taken out of the buffer
uint8_t no_of_elements;       //indicates current number of elements in the buffer
enum circular_buffer buff_states;
}c_b;                           //defining a structure tag for the structure

c_b cb1;
//uint8_t cir_buffer;

uint8_t buffer_add();      //function declaration of adding elements to buffer
uint8_t buffer_full();              //function declaration of checking if buffer is full
uint8_t buffer_empty();             //function declaration of checking if buffer is empty
uint8_t buffer_remove();            ////function declaration of removing elements from buffer
void circularbuffer_memoryallocate(uint8_t value);  //function declaration to allocate memory for the buffer in heap
void circularbuffer_memoryfree();                   //function declaration to free the allocated memor



#endif /* INCLUDES_BUFFER_H_ */
