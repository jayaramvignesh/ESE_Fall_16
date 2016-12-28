/**************************************************************************
 *
 *       Filename: message.h
 *      Description:  This header file contains the functions for Messaging
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 *      1. enum Cmds_t
 *      > An enumeration for different commands is created.
 *      > Depending on each command and the corresponding data received, the program executes a particular functionality.
 *      > The different commands are:
 *      		a. TEMP(01) => for temperature measurement and its profiling
 *      		b. LDR(02) => for LDR measurement and its profiling
 *      		c. CAP_SENSE(03) => for measuring touch value and its profiling
 *      > Data 01 is for performing functionalities like temperature measurement , LDR measurement and cap_sense measurement respectively.
 *      > Data 02 is for performing the profiling of above functionalities.
 *
 *      2. Struct packet_t
 *      > A structure containing the various members of command packet is created.
 *
 *      3. Read_packet
 *      > This function is used to read the contents of the command packet sent
 *
 *      4. Decode_packet
 *      > This function is used to decode the contents of the packet read.
 *      > Depending on the command and data received, the function will execute the corresponding task
 *
 *
 ****************************************************************************/

#ifndef MSG
#define MSG

#include "MKL25Z4.h"
#include "adc.h"
#include "log.h"
#include "uart.h"
#include "circbuff.h"
#include "conversion.h"
#include "profiling.h"
#include "capsense.h"
#include "led.h"
#include "ldr.h"
#include "temp.h"

#define MAX_SIZE_DATA 2

typedef enum Cmds_t{
	TEMP = 0x01,
	LDR = 0x02,
	CAP_SENSE = 0x03
}Cmds_color;

typedef struct packet_t{
	Cmds_color command;
	uint8_t length;
	uint8_t data[MAX_SIZE_DATA];
}packet;

void Decode_packet(packet* message);
void Read_packet(packet* message);

#endif
