/***************************************************************************
 *
 *  	Filename: Message.c
 *      Description:  This source file contains the functions for Messaging
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/

#include "Message.h"

uint8_t unused;

void Decode_packet(packet* message){
	switch(message->command){
		case COLOR_RED:{
			LED_INTENSITY(RED,(message->data[0]*100));
			break;
					}

		case COLOR_BLUE:{
			LED_INTENSITY(BLUE,(message->data[0]*100));
			break;
					  }

		case COLOR_GREEN:{
			LED_INTENSITY(GREEN,(message->data[0]*100));
			break;
						}

		case COLOR_YELLOW:{
			LED_INTENSITY(YELLOW,(message->data[0]*100));
			break;
						}

		case COLOR_CYAN:{
			LED_INTENSITY(CYAN,(message->data[0]*100));
			break;
				}

		case COLOR_MAGENTA:{
			LED_INTENSITY(MAGENTA,(message->data[0]*100));
			 break;
						}

		case COLOR_WHITE:{
			LED_INTENSITY(WHITE,(message->data[0]*100));
			break;
						}

	}
}

void Read_packet(packet* message){
	uint8_t i;

		remove_item(&receive_buff,&(message->command));
		remove_item(&receive_buff,&(message->length));

		if(message->length != 0){
			for(i=0;i<(message->length);i++)
				remove_item(&receive_buff,&(message->data[i]));
			for(i=(message->length);i<2;i++)
				remove_item(&receive_buff,&unused);
		}
		else{
			for(i=0;i<2;i++)
				remove_item(&receive_buff,&unused);
		}

		remove_item(&receive_buff, &(message->checksum));
}



