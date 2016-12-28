/*
 *  Authors: Arundhathi Swami, Vignesh Jayaram
*   Date Edited: 14 Oct 2016
*
*   File: BUFFER.c
*
*   Description: source file for circular buffer
*        -buffer_full
*		 -buffer_add
*		 -buffer_empty
*		 -buffer_remove
*		 -circularbuffer_memoryallocate
*        -circularbuffer_memoryfree
 *
 *  Created on: Oct 12, 2016
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "BUFFER.h"

/*Function to check if Buffer is full*/
 uint8_t buffer_full()
{
 if((cb1->length)==(cb1->no_of_elements))       //condition to check if buffer is full
  {
   (cb1->buff_states)=full;                     //set the enum to "full" state if buffer is full
   return (cb1->buff_states);
  }
  else
    {
     (cb1->buff_states)=available;              //set the enum to "available" state if buffer is not full
     return (cb1->buff_states);
    }
}


 /*Function to check if Buffer is Empty*/
uint8_t buffer_empty()
{
 if(((cb1->head)==(cb1->tail)) && ((cb1->no_of_elements)==0)) //Condition check for buffer emptiness
  {
    (cb1->buff_states)=Empty;  //invoke enum to set buffer status to empty
    return (cb1->buff_states);
  }
  else
  {
     (cb1->buff_states)=available; //sets enum to buffer still having space for more elements but not full or empty
     return (cb1->buff_states);
  }
}

/*Function to add elemnets to Buffer */
uint8_t buffer_add()
{

if((cb1->head == cb1->tail) && ((cb1->no_of_elements) > (cb1->length))) //clearing garbage values
 {
  (cb1->no_of_elements)=0; //setting no of elements to 0
}

	uint8_t count = 4;
	uint8_t i=0;
	uint8_t data;

	for(i=0;i<count;i++)
	{

		data = i+1; //adding elemnts
		if((cb1->no_of_elements)!=(cb1->length)) //checking fullness
	{
    *(cb1->head)=data;
    (cb1->no_of_elements)++; //incrementing no of elemnts in buffer
    (cb1->head)++;          //incrementing head of buffer
    if((cb1->head)>((cb1->length)+(cb1->buffer)-1)) //wrapping around
    {
     (cb1->head)=(cb1->buffer);
    }
    (cb1->buff_states)=pass;
       	       return (cb1->buff_states);
  }
  else
  {
	  (cb1->buff_states)=fail;
	       return (cb1->buff_states);
  }
}
}



/*Function to remove elements from the buffer*/
uint8_t buffer_remove()
{
 uint8_t removed_item;
 if((cb1->no_of_elements)!=0) //checking for buffer empty
  {
       removed_item= *(cb1->tail); //assigning removed item to a variable
      (cb1->tail)++;     //incrementing tail
     (cb1->no_of_elements)--; //decrementing no of elements in the buffer
    if((cb1->tail)>((cb1->length)+(cb1->buffer)-1)) //wrapping around  tail
    {
      (cb1->tail)=(cb1->buffer);
    }
    return removed_item;
  }
  else
  {
	  (cb1->buff_states)=fail;
	       return (cb1->buff_states);
  }

}



/*Function to allocate buffer some heap space*/
void circularbuffer_memoryallocate(uint8_t value)
{

 cb1=(c_b *) calloc(1,sizeof(c_b)); //
 cir_buffer= (uint8_t *) calloc(value,sizeof(uint8_t));

}

/*Function to free heap memory*/
void circularbuffer_memoryfree()
{
    free(cb1);
    free(cir_buffer);
}


