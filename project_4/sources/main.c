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

#include "MKL25Z4.h"
#include "touch.h"
#include "adc.h"
#include "uart.h"
#include "message.h"
#include "log.h"
#include "circbuff.h"
#include "conversion.h"
#include <stdint.h>
#include <stdio.h>
#include "led.h"
#include "capsense.h"
#include "temp.h"
#include "profiling.h"
#include "ldr.h"


int main(void)
{
	packet msg;
	Buffer_Init(&transmit_buff, 200);//initialize TX buffer of 100 bytes
	Buffer_Init(&receive_buff, 200);//initialize RX buffer of 100 bytes
	INIT_UART0();
	adc0_init();
	adc4_init();
	EXLED_INIT_GPIO();
	counter();
	INIT_TOUCH();
	Configure_LEDS();
	LED_INIT_PWM();
	log0("Project 4 ESE:Arundhathi Swami and Vignesh Jayaram");
	log0("\n\r");

	while(1)
	{
		LED_INTENSITY(1875);
		if(receive_buff.no_of_items == 4)
		{
		__asm("cpsid i");
		Read_packet(&msg);
		__asm("cpsie i");
		Decode_packet(&msg);
		}
	}
  return 0;
}

