/*
 * UART0_INIT.c
 *
 *  Created on: Oct 11, 2016
 *      Author: Windows
 */

#include "MKL25Z4.h"
#include "system_MKL25Z4.h"
#include <stdint.h>
#include "UART0_INIT.h"
#include "LEDS.h"


/*Uart receiver initialised*/
void UARTRE_INIT(void)
{
		SIM->SCGC4 |= 0x0400; //Clock gating the UART
		SIM->SOPT2 |= 0x05000000; //Selecting FLL clock source for UART and TPM

		UART0_C2 = 0x00; //turning off the UART to disbale interrupts during UART config
		UART0_BDH = 0x00; //Setting the BDH and BDL for 57600 Buad Rate
		UART0_BDL = 0x17; // Setting the BDL for 56700 Baud Rate

		UART0_C4 = 0x0F; // Setting the OVER sampling Ratio to 16
		UART0_C1 = 0x00; //UART control reg is set for 8bit transmission, no parity and 1 stop bit
		UART0_C2 = 0x04; //Enabling the Timer Interrupts after config

		SIM->SCGC5 |= 0x0200; //Enabling clock to TPM and UART
		PORTA->PCR[1] = 0x0200; //Setting port a pcr 1 to alt 2 where the pin is configured as UART0 rx pin
}

/*Initialising UART Receiver in Interrupt Mode*/
void UARTR_INT_init()
{
	SIM->SCGC4 |= 0x0400;   //Clock gating the UART
	SIM->SOPT2 |= 0x05000000;//Selecting FLL clock source for UART and TPM

	UART0->C2 = 0x00;   //turning off the UART to disbale interrupts during UART config
	UART0->BDH = 0x00;  //Setting the BDH and BDL for 57600 Buad Rate
	UART0->BDL = 0x17;  // Setting the BDL for 56700 Baud Rate


	UART0->C4 = 0x0F;   // Setting the OVER sampling Ratio to 16
	UART0->C1 = 0x00;    //UART control reg is set for 8bit transmission, no parity and 1 stop bit
	UART0->C2 = 0x24;   //Enabling the Timer Interrupts (RIE) after config an dthe receiver pin

	NVIC->ISER[0]|= 0x00001000; //Enabling Interrupts for UART0  at pin 12

	SIM->SCGC5 |= 0x0200;   //Enabling clock to TPM and UART

	PORTA->PCR[1] = 0x0200; //Setting port a pcr 1 to alt 2 where the pin is configured as UART0 rx pin
}

/*initialising uart0 transmitter*/
void UARTT_INIT (void)
{


	SIM_SCGC4 |= 0x00000400;		//provides clock to UART0
	SIM_SOPT2 |= 0x05000000;		//selecting FLL for uart0 and tpm
	UART0_C2 = 0x00;						//turn off UART0 to disable interrupts
	UART0_BDH =0x00;						//configuring BDH and BDL to set the baud rate
	UART0_BDL =0x17;						//baud rate set to 57600
	UART0_C4 = 0x0f;						//Over Sampling Ratio is set to 16
	UART0_C1 = 0x00;						//Control 1 register is set for 1 stop bit, no parity bit and 8 bit data
	UART0_C2 = 0x08;						//Enabling the transmitter

	SIM_SCGC5 |= 0x00000200;		//enabling clock to port A
	PORTA_PCR2 = 0x0200;				//using PTA2 to be transmitter as ALT 2

}

/*Defining UART functions for outputting character strings */
void uart_print(char c)
	{
		while(!(UART0->S1 & 0xC0))
		  {}
		  UART0_D = c;

	}

void uart_string(char s[])
	{
		int i=0;

		while (s[i] != 0x00)
		{
			uart_print(s[i]);
			i++;
		}

	}

