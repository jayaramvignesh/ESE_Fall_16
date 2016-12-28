/*
Authors: Arundhathi Swami, Vignesh Jayaram
*   Date Edited: 14 Oct 2016
*
*   File: LOGGER.c
*
*   Description: source file for logger
*        -LOG_0
*		 -LOG_1
*		 -ftoa
*		 -my_itoa
*/
#include "MKL25Z4.h"
#include "system_MKL25Z4.h"
#include <stdint.h>
#include "UART0_INIT.h"
#include "LOGGER.h"

void LOG_0(char *str)
{
	/*Intiatilased Tx*/
	UARTT_INIT();
	uart_string(str);
	uart_string("\n");
	uart_string("\r");//printing log0

}

void LOG_1(char *str,float value)
{
      uint8_t length=0;
      uint8_t length_ftoa=0;
      while(*str!='\0')
      {
          length++;
          str++;
      }
      char *str1;
      str1=ftoa(value,3);
      *str=*str1;
      while(*str1++!='\0')
      {
           str++;
          *str=*str1;
           length_ftoa++;
      }
      str=str-length-length_ftoa;
      UARTT_INIT();
      uart_string(str);
      uart_string("\n");
      uart_string("\r");
}



char* ftoa(double value, uint32_t resolution)
{
 int8_t answer[100];
 char *ptr;
 ptr=(char*)answer;

 char *ptr1;
 ptr1=(char*)answer;

 int32_t integer = (int32_t)value;

 my_itoa(integer,ptr,10);

 uint8_t length=0;

 while(*(ptr+length)!= '\0')
 {
     length=length+1;
 }

ptr=ptr+length;

if(value<0)
{
    value=-value;
    integer=-integer;
}
uint8_t temp;
double decimal = value - (double)integer;
if(decimal>0.00000)
{
*ptr='.';
while(resolution--)
{
    decimal=decimal*10;
}
ptr=ptr+1;
my_itoa(decimal,ptr, 10);
return ptr1;
}
else
{
 return ptr1;
}
}

int8_t my_itoa( int32_t data,int8_t *str, int32_t base)
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







