/***************************************************************************
 *
 *  	Filename: cirbuff.h
 *      Description:  This header file contains the functions for circular buffer
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/

#ifndef CIRC
#define CIRC

/*This structure contains the variables for the buffer*/
typedef struct {
	uint8_t* buffer;		//pointer to the circular buffer
	uint8_t* head;			//pointer to the head of the buffer
	uint8_t* tail;			//pointer to the tail of the buffer
	uint32_t length;		//Total length of the buffer
	uint32_t no_of_items;		//number of items present in the buffer
}cirbuff_t;


/*Enumeration for the state of the buffer*/
typedef enum {
	FULL,
	EMPTY,
	SUCCESS,
	FAIL
}states;


/*Prototypes of the functions*/
uint8_t Buffer_Full(cirbuff_t *buff);
uint8_t Buffer_Empty(cirbuff_t *buff);
states add_item(cirbuff_t *buff, uint8_t data);
states remove_item(cirbuff_t *buff, uint8_t *removed_item);
void Buffer_Init(cirbuff_t *buff, uint32_t length);
void Buffer_Flush(cirbuff_t *buff);
void Buffer_fill(cirbuff_t *buff);
void Buffer_Free(cirbuff_t *buff);


#endif
