/*
 * dma.h
 *
 * Date: October 30, 2016
 * Authors: Arundhathi Swami, Vignesh Jayaram
 * Project:  ECEN 5013- Project 3
 * Module 1: DMA Transfers
 * */

#ifndef INCLUDES_DMA_H_
#define INCLUDES_DMA_H_

#include "timer.h"
#include "MKL25Z4.h"
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>


typedef enum DMA_errors
{
	CE_BIT_SET = 0,
	SOURCE_CYCLE_ERROR_BES = 1,
	DESTINATION_CYCLE_ERROR_BED = 2,

} dma_error;

#define DMA_MUX_CLOCK_GATING 0x00000002
#define DMA_CLOCK_GATING 0x00000100
#define CONFIG_DCR_WORD_MOVE 0x00480000
#define CONFIG_DCR_BYTE_MOVE 0x005A0000
#define CONFIG_DCR_WORD_ZERO 0x00080000
#define CONFIG_DCR_BYTE_ZERO 0x001A0000
#define START_TRANSFER 0x00010000


void dma_initiate();
uint8_t memmove_dma(uint8_t* source, uint8_t* destination, uint32_t length);
uint8_t memmove_word_dma (uint32_t words);
uint8_t memmove_byte_dma (uint32_t bytes);
uint8_t memzero_dma(uint8_t* source, uint8_t* destination, uint32_t length);
uint8_t memzero_word_dma (uint32_t words);
uint8_t memzero_byte_dma (uint32_t bytes);




#endif /* INCLUDES_DMA_H_ */
