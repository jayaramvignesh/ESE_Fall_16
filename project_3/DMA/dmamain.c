/*
 * date: October 30, 2016
 * Authors: Arundhathi Swami, Vignesh Jayaram
 * Project:  ECEN 5013- Project 3
 */

#include "MKL25Z4.h"
#include "dma.h"
#include "timer.h"
#include "uart.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main()
{

#define MODULE_1

#ifdef MODULE_1

 uint8_t src[1] = {0};
 uint8_t dst[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 double transfer;
 uint32_t no_of_bytes = 10;
 dma_initiate();
 counter();
 //UARTT_INIT();
 char msg[] = "MEMZERO 5000 Bytes ==> Time Taken: (in us) ";
 transfer = memzero_dma (src, dst, no_of_bytes);
 LOG_1(msg, transfer);

#endif



 return 0;
}

