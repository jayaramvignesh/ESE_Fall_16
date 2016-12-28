/*
 * dma.c
 * Date: October 30, 2016
 * Authors: Arundhathi Swami, Vignesh Jayaram
 * Project:  ECEN 5013- Project 3
 *
 *  Module: #1 ==> DMA transfers
 */
#include "timer.h"
#include "dma.h"
#include "MKL25Z4.h"
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>



void dma_initiate()
{
	SIM->SCGC6 |= DMA_MUX_CLOCK_GATING; //clock gating the MUX
	SIM->SCGC7 |= DMA_CLOCK_GATING; //clock gating the DMA

	DMAMUX0_CHCFG0 = 0x00; //Disabling DMA before configuration

}

#define MEMZERO

#ifdef MEMMOVE
uint8_t memmove_dma (uint8_t* source, uint8_t* destination, uint32_t length)
{
	DMA_SAR0 = source; //assigning source
	DMA_DAR0 = destination; //assigning destination

	uint8_t quo_words = length / 4; //no of words
	uint8_t rem_bytes = length % 4; //no of bytes
	uint32_t no_of_words  = quo_words * 4;
	double time_byte_move;
	double time_word_move;
	uint8_t transfer_time;

	if (quo_words != 0)
		time_word_move = memmove_word_dma (no_of_words); //moving words
	if (rem_bytes != 0)
		time_byte_move = memmove_byte_dma (rem_bytes); //moving bytes

	transfer_time = time_word_move + time_byte_move; //calculating total move time

	return transfer_time;
}


uint8_t memmove_word_dma (uint32_t words)
{

	DMA_DCR0 |= CONFIG_DCR_WORD_MOVE; //configuring DMA to move one word at a time
	DMA_DSR_BCR0 = words; //proving number of words to BCR


	DMAMUX0_CHCFG0 |= 0x3C;
	DMAMUX0_CHCFG0 |= 0xDC;

	counter_start(); //start counter
	DMA_DCR0 |= START_TRANSFER; //enabling START bit
	counter_stop(); //stoppin counter

	double cpu_ticks_words_move;
	double time_words_move;

	 cpu_ticks_words_move = TPM0->CNT; //obtaining no of cpu ticks
	 time_words_move = cpu_ticks_words_move * CLOCK_RESOLUTION; //obtaining time

	 return time_words_move;

}


uint8_t memmove_byte_dma (uint32_t bytes)
{

	DMA_DCR0 |= CONFIG_DCR_BYTE_MOVE; //configuring DMA to move one word at a time
	DMA_DSR_BCR0 = bytes; //proving number of words to BCR

	DMAMUX0_CHCFG0 |= 0x3C;
	DMAMUX0_CHCFG0 |= 0xDC;

	counter_start(); //start counter
	DMA_DCR0 |= START_TRANSFER; //enabling START bit
	counter_stop(); //stoppin counter

	double cpu_ticks_bytes_move;
	double time_bytes_move;

	 cpu_ticks_bytes_move = TPM0->CNT; //obtaining no of cpu ticks
	 time_bytes_move = cpu_ticks_bytes_move * CLOCK_RESOLUTION; //obtaining time

	 return time_bytes_move;
}


#endif

#ifdef MEMZERO
uint8_t memzero_dma (uint8_t* source, uint8_t* destination, uint32_t length)
{
	DMA_SAR0 = source; //assigning source
	DMA_DAR0 = destination; //assigning destination

	uint32_t quo_words = length / 4; //no of words
	uint32_t rem_bytes = length % 4; //no of bytes
	uint32_t no_of_words  = quo_words * 4;
	double time_byte_zero;
	double time_word_zero;
	uint8_t transfer_zero;

	if (quo_words != 0)
		time_word_zero = memzero_word_dma (no_of_words); //moving words
	if (rem_bytes != 0)
		time_byte_zero = memzero_byte_dma (rem_bytes); //moving bytes

	transfer_zero = time_word_zero + time_byte_zero; //calculating total move time

	return transfer_zero;
}

uint8_t memzero_word_dma (uint32_t words)
{

	DMA_DCR0 |= CONFIG_DCR_WORD_ZERO; //configuring DMA to move one word at a time
	DMA_DSR_BCR0 = words; //proving number of words to BCR


	DMAMUX0_CHCFG0 |= 0x3C;
	DMAMUX0_CHCFG0 |= 0xDC;

	counter_start(); //start counter
	DMA_DCR0 |= START_TRANSFER; //enabling START bit
	counter_stop(); //stoppin counter

	double cpu_ticks_words_zero;
	double time_words_zero;

	 cpu_ticks_words_zero = TPM0->CNT; //obtaining no of cpu ticks
	 time_words_zero = cpu_ticks_words_zero * CLOCK_RESOLUTION; //obtaining time

	 return time_words_zero;

}

uint8_t memzero_byte_dma (uint32_t bytes)
{

	DMA_DCR0 |= CONFIG_DCR_BYTE_ZERO; //configuring DMA to move one word at a time
	DMA_DSR_BCR0 = bytes; //proving number of words to BCR

	DMAMUX0_CHCFG0 |= 0x3C;
	DMAMUX0_CHCFG0 |= 0xDC;

	counter_start(); //start counter
	DMA_DCR0 |= START_TRANSFER; //enabling START bit
	counter_stop(); //stoppin counter

	double cpu_ticks_bytes_zero;
	double time_bytes_zero;

	 cpu_ticks_bytes_zero = TPM0->CNT; //obtaining no of cpu ticks
	 time_bytes_zero = cpu_ticks_bytes_zero * CLOCK_RESOLUTION; //obtaining time

	 return time_bytes_zero;
}
#endif
