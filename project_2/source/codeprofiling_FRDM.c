/********************************************
*   Authors: Arundhathi Swami, Vignesh Jayaram
*   Date Edited: 14 Oct 2016
*
*   File: codeprofiling_FRDM.c
*
*   Description: file for code_profiling o FRDM
*
********************************************************/

#include "MKL25Z4.h"
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>


void initialize_counter();
void counter_start();
void counter_stop();

double system_clock= 0.047;
double time_elapsed;
double cpu_ticks;

void my_malloc(uint16_t value);
void my_free();
int8_t my_reverse(uint8_t * src, uint32_t length);
int8_t my_memzero(uint8_t * src,uint32_t length);
int8_t my_memmove(uint8_t * src,uint8_t *dst,uint32_t length);
void my_ftoa(double value, uint32_t resolution);
int8_t* my_itoa( int32_t data,int8_t *str, int32_t base);
int32_t my_atoi(int8_t* str);


char *source;
char *destination;

int main(void)
{

	initialize_counter();
	counter_start();
	uint16_t value =5000;
	my_malloc(value);
	my_memmove(source,destination,value);
	counter_stop();

	cpu_ticks = TPM0->CNT;
    time_elapsed= cpu_ticks*system_clock;

	return 0;
}

void initialize_counter()
{

	SIM->SCGC6 = 0x01000000;
	SIM->SOPT2 |= 0x01000000;
	TPM0->SC = 0x0;
	TPM0->MOD = 0x0000FFFF;
	TPM0->CNT = 0x0;
	TPM0->SC = 0X00000080;
}

void counter_start()
{
	TPM0->CNT = 0x0;
	TPM0->SC = 0x00000008;
}

void counter_stop()
{
	TPM0->SC = 0x0;
}

int8_t my_memmove(uint8_t * src,uint8_t *dst,uint32_t length)
{
 uint32_t i=0;
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

void my_malloc(uint16_t value)
{
 source = (char*) malloc(sizeof(char)*value);
 destination = (char*) malloc(sizeof(char)*value);
}

void my_free()
{
 free(source);
 free(destination);
}

void my_ftoa(double value, uint32_t resolution)
{
 int8_t buffer[100];
 char *ptr;
 ptr=(char*)buffer;
 //char buffer2[10];

 int32_t integer = (int32_t)value;

 my_itoa(integer,ptr,10);

 uint32_t length=0;

 while(*(ptr+length)!= '\0')
 {
     length=length+1;
 }

ptr=ptr+length;
*ptr='.';

if(value<0)
{
    value=-value;
    integer=-integer;
}
double decimal = value - (double)integer;


while(resolution--)
{
    decimal=decimal*10;
}


ptr=ptr+1;


my_itoa(decimal,ptr, 10);

 printf("The FTOA output is %s",buffer);

}

int8_t* my_itoa( int32_t data,int8_t *str, int32_t base)
{
    if (data == 0)
      {
        *str++ = '0';
        *str-- = '\0';
        return str;
      }


    int8_t negative = 0;
    int remainder = 0;
    uint8_t length = 0;

    if (data < 0)
        {
        negative = -1;
        data = -data;
        }


    while (data != 0)
    {
        remainder = data % base;
        *str++ = (remainder > 9)? (remainder-10) + 'A' : remainder + '0';
        length++;
        data = data/base;
    }


    if(negative == -1)
    {
        *str++ = '-';
        length++;
    }

    *str = '\0';

    str = str - length;
    int8_t temp=0;
    int8_t* begin;
    int8_t* end;
    begin=str;
    str=str+ length-1;
    end=str;
    str= str-length+1;

    while(begin<end)
    {
     temp=*begin;
     *begin=*end;
     *end=temp;
     ++begin;
     --end;
    }
    return str;
}

int32_t my_atoi(int8_t* str)//function to convert ascii data to integral values
{
 int32_t neg=1;
 int32_t ans=0;
 int32_t k=0;

 printf("\n");
 if (*str == '\0')//determines whether accepted data is a null
 return 0;

 if (*str=='-')//determines if string is negative by checking the first element then increments the element pointed to by the pointer str
   {
    neg=-1;
    k++;
   }
 while(*(str+k)!='\0')
   {
    if(*(str+k)<='0' || *(str+k)>='9')//eleminates non-integer values
       {
     printf("error\n");
         return 0;
         k++;
       }
    ans=(ans*10)+ *(str+k)- '0';//converts from ascii strings to integer values
    k++;
   }
 return neg*ans;//returns integer value with sign
}
