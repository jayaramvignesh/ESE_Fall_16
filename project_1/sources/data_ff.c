/********************************************
*   Authors: Arundhathi Swami, Vignesh Jayaram
*   Date Edited: 19 Sept 2016
*
*   File: data_ff.c
*
*   Description: Source file for data manipulation 
*		 for FRDMKL25z Board
*                -my_itoa
*		 -my_atoi
*		 -dump_memory
*		 -big_to_little
*		 -little_to_big
*
********************************************************

/*Program to implement data manipulations*/
#pragma GCC poison printf

#include<stdio.h>
#include<stdint.h>
#include"data_ff.h"//invokes user defined header file for data


int8_t* my_itoa(int8_t *str, int32_t data, int32_t base)//function to convert integers to strings (ascii strings)
{

 uint32_t i=0;
 //uint32_t j=0;
 uint8_t neg=0;
 uint32_t l=0;

 if (data==0)//checks if data sent by user is 0, returns string of zeros
   {
	*str=0;
	*(str+1)='\0';
	return str;
   }

 if(data<0 && base==10)//checks if data sent by user is positive or negative, if negative it negates data
   {
	neg=1;
	data=-data;
   }

 while(data!=0)//converts to ascii value
   {
	uint8_t rem;
	rem= data%base;
      	if(rem>9)
	   {
		rem=rem-10;
		rem=rem+'a';
           }
	*(str+i)=rem;
	data=data/base;
	i++;
    }
 l=i;

 if(neg==1)//appends minus to negative detected data  followed by null character
   {
	l++;
        *(str+l)='-';
    	*(str+l+1)='\0';
   }
 else
   {
  	*(str+l)='\0';
   }
 char temp=0;
 int8_t* begin;
 int8_t* end;
 begin=str;
 str=str+ l-1;
 end=str;
 str= str-l+1;
 while(begin<end)//reverses the remainder string obtained to display correct ascii value
   {
	temp=*begin;
	*begin=*end;
	*end=temp;
	begin++;
	end--;
   }

 return str; //returns ascii value
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

void dump_memory(uint8_t *start, uint32_t length)//function that prints out the hex value of data held in memory pointed at
{
 printf("\n");
 uint32_t i;
 for(i=0;i<length;i++)
  {
	printf("%x ",*start);
    	start++;
  }
}



uint32_t little_to_big(uint32_t data)//program to switch endianness
{
 uint32_t b0, b1, b2, b3;
 uint32_t answer;
 b0 = (data & 0x000000FF) >> 0 ;//masks all but lsB  and left shifts to lsB position
 b1 = (data & 0x0000FF00) >> 8 ;
 b2 = (data & 0x00FF0000) >> 16 ;
 b3 = (data & 0xFF000000) >> 24 ;
 answer=(b0 << 24) | (b1 << 16) | (b2 << 8) | (b3 << 0);//assembles all bytes after appropriate shifting to get required endian representation
 return(answer);
}



uint32_t big_to_little(uint32_t data)//program to switch endianness
{
 uint32_t b0, b1, b2, b3;
 uint32_t answer;
 b0 = (data & 0x000000FF) >> 0 ;//masks all but lsB  and left shifts to lsB position
 b1 = (data & 0x0000FF00) >> 8 ;
 b2 = (data & 0x00FF0000) >> 16 ;
 b3 = (data & 0xFF000000) >> 24 ;
 answer=(b0 << 24) | (b1 << 16) | (b2 << 8) | (b3 << 0);//assembles all bytes after appropriate shifting to get required endian representation
 return(answer);
}
