/***************************************************************************
 *
 *  	Filename: Message.h
 *      Description:  This header file contains the functions for Messaging
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/

#ifndef MSG
#define MSG

#include "MKL25Z4.h"
#include "circbuff.h"
#include "LED.h"
#include "log.h"

#define MAX_SIZE_DATA 2

typedef enum Cmds_t{
	COLOR_RED = 0x01,
	COLOR_BLUE = 0x02,
	COLOR_GREEN = 0x03,
	COLOR_YELLOW = 0x04,
	COLOR_MAGENTA = 0x05,
	COLOR_CYAN = 0x06,
	COLOR_WHITE = 0x07
}Cmds_color;

typedef struct packet_t{
	Cmds_color command;
	uint8_t length;
	uint8_t data[MAX_SIZE_DATA];
	uint8_t checksum;
}packet;

void Decode_packet(packet* message);
void Read_packet(packet* message);

#endif
