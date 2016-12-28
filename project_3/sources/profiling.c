/***************************************************************************
 *
 *  	Filename: profiling.c
 *      Description:  This source file contains the functions for Profiling
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/

#include "MKL25Z4.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "profiling.h"




void initialize_counter()
{

	SIM->SCGC6 |= 0x01000000;            //initializing TPM0
	SIM->SOPT2 |= 0x01000000;           //Selecting FLL clock
	TPM0->SC = 0x0;                     //Disabling everything
	TPM0->MOD = 0x0000FFFF;             //Setting Mod value to 65535
	TPM0->CNT = 0x0;                    //making count 0
	TPM0->SC = 0X00000080;              //counter overflow
}

void counter_start()
{
	TPM0->CNT = 0x0;                    //making count 0
	TPM0->SC = 0x00000008;              //selecting mode for count
}

void counter_stop()
{
	TPM0->SC = 0x0;                   //disabling the counter
}
