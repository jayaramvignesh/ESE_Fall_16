/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* ECEN 5013 - Embedded Software Essentials -> Project 2
 * Project Group: Arundhathi Swami, Vignesh Jayaram
 * Date: 12th October 2016
 */

#include "MKL25Z4.h"
#include "system_MKL25Z4.h"
#include <stdint.h>
#include <stdlib.h>
#include "UART0_INIT.h"
#include "LOGGER.h"
#include "LEDS.h"
#include "BUFFER.h"
#include "CBUNITTESTS.h"



uint32_t i = 0;
void delayMs(uint32_t delay);

#define LED

int main(void)
{
#ifdef	VERBOSE    //Logging Fuctionality
	/*checking Log0 Function*/
	char str[]="Testing123, Serial Print Test, no params";
	char *ptr;
	ptr=str;
	LOG_0(ptr);

	/*Checking Log1 function with several test cases*/
	 char array1[]="This is an integer number: ";
	 float value1=200;
	 char *str1;
	 str1=array1;
	 LOG_1(str1, value1);

	 char array2[]="This is an integer number: ";
	 float value2=4096;
	 char *str2;
	 str2=array2;
	 LOG_1(str2, value2);

	 char array3[]="This is an integer number: ";
	 float value3=123456;
	 char *str3;
	 str3=array3;
	 LOG_1(str3, value3);

	 char array4[]="This is a float number: ";
	 float value4=1543.321;
	 char *str4;
	 str4=array4;
	 LOG_1(str4, value4);

#endif


#ifdef PWM //checking PWM functionality

	 char c;
	 	__disable_irq();
	 		UARTR_INT_init();
	 		LED_Init();
	 		__enable_irq();

	 		while(1)
	 		{
	 			LED_Function(f);
	 		}

#endif




#ifdef BUFFER  //printing out circular Buffer unit tests on the FRDM board

TEST1();
TEST2();
TEST3();
TEST4();
TEST5();
#endif

	return 0;
}









