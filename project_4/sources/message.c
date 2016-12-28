/***************************************************************************
 *
 *      Filename: message.c
 *      Description:  This source file contains the functions for Messaging
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/

#include "message.h"
#include <stdint.h>

uint8_t unused;
int i;

void Decode_packet(packet* message){
	uint8_t x;
	switch(message->command){
		case TEMP:
		{
			LED_INTENSITY(1875);
			//GPIOE_PSOR = (1<<22);
			turn_off();
			float sum=0;
			float average = 0;
			char temp_msg[]="avg temp in the given span: ";
			if(message->data[0] == 0x01)
			{
				float value[1];
				for(x=0; x<15;x++)
				{
						temperature_Read(value);
                        sum = sum + value[0];
						delay();
				}
				average= sum/15;
				if(average < 5)
				{
					glow_red();
					delay();
					delay();
					delay();
				}
				turn_off();
				log1(temp_msg,average);
				log0("\n\r");
			}
			else if(message->data[0] == 0x02)
			{
			 double time_taken;
			 time_taken=temperature_Read_Profiling();;
			 log1("time taken for one temp read in microseconds is ",time_taken);
			 log0("\n\r");
			}
			break;
		}

		case LDR:
			{
				turn_off();
				if(message->data[0] == 0x01)
				{
					for(x=0; x<15;x++)
					{
						ldr_read();
						delay();
					}
						log0("LDR Testing has ended ");
						log0("\n\r");
				}
				else if(message->data[0] == 0x02)
				{
					double time_taken;
					time_taken=ldr_profiling();
					log1("time taken for one LDR read in microseconds is ",time_taken);
					log0("\n\r");	}
					break;
			}

		case CAP_SENSE:
				{
					LED_INTENSITY(1875);
					//GPIOE_PSOR = (1<<22);
					if(message->data[0] == 0x01)
					{
						for(x=0; x<15;x++)
						{
							capsense_response();
								delay();
						}
						log0("Capacitor sensing has ended");
						log0("\n\r");
					}
					else if(message->data[0] == 0x02)
					{
					 double time_taken;
					 counter();
					 counter_start();
					 capsense_response();
					 counter_stop();
					 time_taken = counter_calculate();
					 log1("time taken for one capsense read in microseconds is ",time_taken);
					 log0("\n\r");
					}
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
}



