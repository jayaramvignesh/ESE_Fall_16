/***************************************************************************
 *
 *  	Filename: nRF24L01.c
 *      Description:  This source file contains the functions for NRF24L01
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/

#include "nRF24L01.h"
#include "SPI.h"

void chipenable_low(void){
	GPIOC_PCOR = (1<<0);
}

void chipenable_high(void){
	GPIOC_PSOR = (1<<0);
}

uint8_t register_write(uint8_t reg_addr,uint8_t data ){
	uint8_t status;
	chipselect_low();
	status = TRANSFER_SPI(WRITE_REGISTER | ( REGISTER_MASK & reg_addr ));
	TRANSFER_SPI(data);
	chipselect_high();

	return status;
}

uint8_t register_multiplebytes_write(uint8_t reg_addr,uint8_t* data, uint8_t length ){
	uint8_t status;
	chipselect_low();
	status = TRANSFER_SPI(WRITE_REGISTER | ( REGISTER_MASK & reg_addr ));
	while(length--)
	{
	TRANSFER_SPI(*data++);
	}
	chipselect_high();

	return status;
}

uint8_t register_read(uint8_t reg_addr){
	uint8_t read_value;

	chipselect_low();
	TRANSFER_SPI( READ_REGISTER | ( REGISTER_MASK & reg_addr ) );
	read_value = TRANSFER_SPI(0xba);
	chipselect_high();

	return read_value;
}

uint8_t register_multiplebytes_read(uint8_t reg_addr,uint8_t* read_value, uint8_t length ){
	uint8_t status;

	chipselect_low();
	status = TRANSFER_SPI(READ_REGISTER | ( REGISTER_MASK & reg_addr ));  //to initiate read
	while(length--)
	{
		*read_value = TRANSFER_SPI(0xff);    //0xff is for no-operation
		 read_value++;
	}
	chipselect_high();

	return status;
}
