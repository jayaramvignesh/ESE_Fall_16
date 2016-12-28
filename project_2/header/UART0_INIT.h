/*
 * UART0_INIT.h
 *
 *  Created on: Oct 12, 2016
 *      Author: Arundhathi Swami, Vignesh Jayaram
 *
 *  Header defined for initialising UART for various configurations
 */

#ifndef INCLUDES_UART0_INIT_H_
#define INCLUDES_UART0_INIT_H_


#include "MKL25Z4.h"
#include "system_MKL25Z4.h"
#include<stdint.h>
#include "LOGGER.h"
#include "LEDS.h"

void UARTRE_INIT(void); //Receiver Initialisation
void UARTT_INIT (void); //Transmitter Initialisation
void uart_print(char c); //Transmitter Printing Strings
void uart_string(char s[]);
void UARTR_INT_init(); //Receiver initialisation in Interrupt Mode

#endif /* INCLUDES_UART0_INIT_H_ */
