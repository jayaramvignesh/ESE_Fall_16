/***************************************************************************
 *
 *  	Filename: led.c
 *      Description:  This header file contains the functions for circular buffer
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/
#include "LED.h"
#include "MKL25Z4.h"



void Configure_LEDS (void)
{
	SIM_SCGC5 |= CLOCK_GATE_PORTD_PORTB; //enabling clock inputs to ports b and d
	PORTD_PCR1 |= SET_GPIO_MODE_ALT; //sets port d pin 1 in GPIO mode
	PORTB_PCR19 |= SET_GPIO_MODE_ALT; //sets port b pin 19 in GPIO mode
	PORTB_PCR18 |= SET_GPIO_MODE_ALT; //sets port b pin 18 in GPIO mode
	GPIOD_PDOR |= PORTD_PCR1_BLUE_LED; //pulls port d pin 1 high  ==> BLUE LEd
	GPIOB_PDOR |= PORTB_PCR19_GREEN_LED; //pulls port b pin 19 high ==> GREEN LEd
	GPIOD_PDDR |= PORTD_PCR1_BLUE_LED; //Sets port d pin 1 to GPIO output   ==> BLUE LEd
	GPIOB_PDDR |= PORTB_PCR19_GREEN_LED; //Sets port b pin 19 to GPIO output  ==> GREEN LEd
	GPIOB_PDOR |= PORTB_PCR18_RED_LED; //pulls port b pin 19 high ==> RED LED
	GPIOB_PDDR |= PORTB_PCR18_RED_LED; //Sets port b pin 19 to GPIO output  ==> RED LEd
}

void EXLED_INIT_GPIO(void)
{
	SIM->SCGC5 |= 0x2000; /* clock to PORTE */
	PORTE->PCR[22] = 1; /* PTE22 GPIO input */
	GPIOE_PDDR |= (1<<22);//Set pin22 as output.
	GPIOE_PSOR = (1<<22);
}


void LED_INIT_PWM(void){
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK|SIM_SCGC5_PORTD_MASK;//setup clock for port B and port D
	SIM_SCGC6	|= SIM_SCGC6_TPM2_MASK; // enable clock for TPM2 module
	SIM_SOPT2	|= SIM_SOPT2_TPMSRC(1); //select PLL as clock source for TPM2

	//FOR RED LED
	PORTE_PCR22 = PORT_PCR_MUX(3);//set MUX to PWM for pin 18
	TPM_MOD_REG(TPM2_BASE_PTR) = 1875;//reset 100 times in a second
	TPM_SC_REG(TPM2_BASE_PTR)|= TPM_SC_CMOD(1) | TPM_SC_PS(7); //select prescaler of 8 and increament every clock cycle

	TPM_CnSC_REG(TPM2_BASE_PTR, 0) |= TPM_CnSC_MSB_MASK|TPM_CnSC_ELSA_MASK;//Sets the mode in which output clears on match and sets on low
	TPM_CnV_REG(TPM2_BASE_PTR,0) = 100;}

void LED_INTENSITY(uint16_t intensity)
{
		TPM_CnV_REG(TPM2_BASE_PTR,0) = intensity;
}
