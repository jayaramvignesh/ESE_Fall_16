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

void UARTRE_INIT(void); //Receiver Initialisation
void UARTT_INIT (void); //Transmitter Initialisation
void uart_print(char c); //Transmitter Printing Strings
void uart_string(char s[]);
void UARTR_INT_init(); //Receiver initialisation in Interrupt Mode
void LOG_1(char *str,double value);
char* ftoa(double value,uint32_t resolution);
void my_itoa( int32_t data,int8_t *str, int32_t base);
void LOG_0(char *str);


#endif /* INCLUDES_UART0_INIT_H_ */
