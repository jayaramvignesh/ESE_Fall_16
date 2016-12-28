/***************************************************************************
 *
 *   	Filename: log.c
 *      Description:  This source file contains the functions for logger
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/
#include "log.h"


void log0(uint8_t *string){
	while(*string !='\0'){
		add_item(&transmit_buff, *string++);
	}

	if(!(Buffer_Empty(&transmit_buff)) && !(UART0_C2_REG(UART0) & UART0_C2_TIE_MASK ))
			UART0_C2 |= UART_C2_TIE_MASK;
}

void log1(uint8_t *string, float param){
	uint8_t a[20], i=0, string_final[100];
		my_ftoa(param, a,3);
	while(*(string+i) !='\0'){
		*(string_final+i) = *(string+i);
		i++;
	}
	*(string_final+i)= '\0';
	strcat(string_final, a);
	log0(string_final);
}

void delay(void)
{
	int i;
	int j;
	for(i = 0 ; i < 1000; i++)
		for (j = 0; j < 1000; j++) {}
}
