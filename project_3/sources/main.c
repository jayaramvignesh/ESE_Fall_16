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
#include "Message.h"
#include "log.h"
#include "profiling.h"
#include "nRF24L01.h"
#include "SPI.h"
#include "uart_init.h"

packet msg;


int main(void)
{
	uint8_t status,i;
	uint8_t transmit_address[5]={0x01,0x02,0x03,0x04,0x05};
	uint8_t read_transmit_address_value[5];
	Buffer_Init(&transmit_buff, 200);//initialize TX buffer of 100 bytes
	Buffer_Init(&receive_buff, 200);//initialize RX buffer of 100 bytes

	INIT_UART0();
	LED_INIT_PWM();


	__asm("cpsie i");		//Enable global interrupts


	 INIT_SPI();
	//for(i=0;i<10000;i++);
	 log0("STATUS");
	status=register_write(CONFIG_NRF,0x02);
	log0(&status);
	log0("CONFIG");
	status=register_read(CONFIG_NRF);
	log0(&status);

	log0("RF_SETUP");
	status=register_write(RF_SETUP_NRF, 0x20);
	//log0(&status);
	status=register_read(RF_SETUP_NRF);
	log0(&status);

	log0("FIFO");
	status=register_read(FIFO_STATUS_NRF);
	log0(&status);

	//status=register_read(STATUS_NRF);
	//log0(&status);

	log0("TX_ADDR");
	status=register_multiplebytes_write(TX_ADDR_NRF,transmit_address,5);
	//log0(&status);
	status=register_multiplebytes_read(TX_ADDR_NRF,read_transmit_address_value,5);
	log0(read_transmit_address_value);


	while(1){
		if(receive_buff.no_of_items == 5){
			__asm("cpsid i");
			Read_packet(&msg);
			__asm("cpsie i");
			Decode_packet(&msg);
		}
	}
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
