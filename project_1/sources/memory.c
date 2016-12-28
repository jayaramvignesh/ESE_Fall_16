/********************************************
*   Authors: Arundhathi Swami, Vignesh Jayaram
*   Date Edited: 19 Sept 2016
*
*   File: memory.c
*
*   Description: Source file for memory manipulation
*                -my_memmove
*		 -my_memzero
*		 -my_reverse
*
********************************************************/

/* Program to implement memory related operations*/

#include<stdio.h>
#include<stdint.h>
#include"memory.h" //invokes user defined header file named memory


/* m.a) Program to move data from one memory location to another */

int8_t my_memmove(uint8_t * src,uint8_t *dst,uint32_t length)
{
 uint8_t i=0;
 if((dst<src)||(dst>src+(length-1))) //checking for memory overlap
 {
   for(i=0;i<length;i++)
   {
     *(dst+i)=*(src+i); //moving data from source to destination
   }
   return 1;
 }
 else
 {
   printf("error:mem move not possible \n");//error if memory overlaps 
   return 0;
 }
}


/* m.b) Program to put zeros in memory spaces*/

int8_t my_memzero(uint8_t * src,uint32_t length)
{
 uint32_t i;
 uint32_t check=0;
 for(i=0;i<length;i++)//fills zeros to src memory positions
  {
	*(src+i)=0;
  }
 for(i=0;i<length;i++)//checks if memory space is zero-ed out
  {
    if(*src==0)
      {
        check++;
      }
   }
 if(check==length)
  {
 	return 1;
  }
 else
  {
      printf("error:move failed");//error in case of  discrepancy
      return 0;
  }
}


/*m.c) program to reverse order of bytes in a specific memory location*/

int8_t my_reverse(uint8_t * src, uint32_t length)
{
 uint8_t *start;
 uint8_t *stop;
 char a;
 start=src;
 src += length-1;
 stop=src;
 src= src-length+1;
printf("\n");
 while(start<=stop)//reverses bytes using temporary pointer
  {
	 a=*start;
         *start=*stop;
         *stop=a;
         start++;
         stop--;
  }
return 0;
}
