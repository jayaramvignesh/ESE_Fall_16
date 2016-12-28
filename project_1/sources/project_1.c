/********************************************
*   Authors: Arundhathi Swami, Vignesh Jayaram
*   Date Edited: 19 Sept 2016
*
*   File: data.c
*
*   Description: Source file for the final project report
*                -project_1_report
*
********************************************************
//*Program to implement project requirements*/

#include<stdio.h>
#include<stdint.h>
#include"data.h"
#include"memory.h"
#include"project_1.h"//invokes user defined header file named project_1

void project_1_report()
{
 char arr[32];
 uint8_t * aptr_1;
 uint8_t * aptr_2;
 uint8_t * aptr_3;
 uint32_t i;
 uint32_t length;

 aptr_1=(uint8_t *)&arr[0];
 aptr_2=(uint8_t *)&arr[8];
 aptr_3=(uint8_t *)&arr[16];


 for(i=0;i<16;i++)
 {
    *(aptr_1+i)= i+31;
 }
 length=16;
 my_memzero(aptr_3,length);

 length=8;
 my_memmove(aptr_1,aptr_3,length);

 length=16;
 my_memmove(aptr_2,aptr_1,length);

 length=32;
 my_reverse(aptr_1,length);

printf("length is:%d",length);
 for(i=0;i<32;i++)
  {
    printf("%d\t",*(aptr_1+i));
    
  }



//testing all the created functions

 printf("\n\n\n testing of functions\n");

//1. testing memory functions
 uint32_t k;
 uint32_t count=0;
 int32_t res;

 uint8_t arr1[]={"ESE Project1"};
 printf("\nthe array for testing is:%s ",arr1);
 uint8_t arr2[15]={'\0'};

    // MEMMOVE TESTING
 my_memmove(arr1,arr2,12);
 printf("\nMEMMOVE:  string at arr2 after memmove is:");
 printf("%s",arr2);

    // MEMZERO TESTING
 my_memzero(arr2,12);
 printf("\nMEMZERO:  after memzero,value is:");
 for(k=0;k<12;k++)
  {
    printf("%d",arr2[k]);
  }

    //REVERSE TESTIN
 my_reverse(arr1,12);
 printf("\nREVERSE:  the reversed string is:");
 printf("%s",arr1);

 //2. testing data functions

int32_t temp_num;
int32_t num1= 1567;
temp_num=num1;
printf("\n\n\nnum1 for data testing is: %d",num1);


    //TESTING ITOA FUNCTION FOR BASE 10 and BASE 8
int8_t num_arr[20];

while(temp_num!=0)
    {
        temp_num/= 10;
        ++count;
    }

 my_itoa(num_arr,num1,10);
 printf("\nITOA_10:   the itoa output for base 10 is:");
 for(k=0;k<count;k++)
  {
    printf("%d",num_arr[k]);
  }

 my_itoa(num_arr,num1,8);
 printf("\nITOA_8:   the itoa output for base 8 is:");
 for(k=0;k<count;k++)
  {
    printf("%d",num_arr[k]);
  }
 printf("\n");

    //TESTING ATOI FUNCTION FOR VALID AND INVALID INPUTS

 int8_t test_arr1[]={"-1234"};
 printf("\nthe test_arr1 for atoi conversion is :%s",test_arr1);
 res=my_atoi(test_arr1);
 printf("ATOI_INTEGERS:  The atoi conversion output for integers is:%d",res);

 int8_t test_arr2[]={"abcd"};
 printf("\n\nthe test_arr2 for atoi conversion is :%s",test_arr2);
 printf("\nATOI_CHARACTERS:  The atoi conversion output for characters is:");
 res=my_atoi(test_arr2);


    //TESTING DUMP FUNCTION
 uint8_t dump[6]={"12qB4/"};
 printf("\nDUMP:   Dumping 6 bytes of memory:");
 dump_memory((uint8_t*)dump,5);

    //TESTING LITTLE_TO _BIG ENDIAN CONVERSION
 int32_t endian= 0x1234abcd;

 printf("\n\nthe value for endian conversion is:%x",endian);
 res=little_to_big(endian);
 printf("\nLITTLE_TO_BIG:   the litte to bid endian conversion gives %x",res);

    // TESTING BIG_TO_LITLLE ENDIAN CONVERSION
 printf("\n\nthe value for endian conversion is:%x",endian);
 res=big_to_little(endian);
 printf("\nBIG_TO_LITTLE:   the big to little endian conversion gives %x \n",res);

}

