/*

 * LEDS.c
 *
 *  Created on: Oct 12, 2016
 *      Author: Arundhathi Swami, Vignesh Jayaram
 *
 *      Source file defining all functions required for interfacing the LED and TPM sections of the FRDM board
 */

#include <math.h>
#include "MKL25Z4.h"
#include "system_MKL25Z4.h"
#include <stdint.h>
#include "UART0_INIT.h"
#include "LEDS.h"


LColour LED_Colour=OFF;
uint16_t  level=100;

void UART0_IRQHandler() //Invoking Interrupt Hnadler function
{
	char f;
	f = UART0->D; //accepting input from the UART Data reg
	LED_Function(f);

}


void LED_Init (void)
{
	SIM_SCGC6 |= 0x07000000;  //enabling clocks to TPM0, TPM1 & TPM2
	SIM_SCGC5 |= 0x00001400;   //enable clock to port D for blue LED and port B for red and green

	/*enabling blue led*/
	PORTD_PCR1 =0x00000400; //ENABLING BLUE led alt 4 tpm0 ch1
	//PTD->PDDR |= 0X00000002; //making port D pin 1 an output pin

	/*Enabling red led*/
	PORTB_PCR18=0x00000300; //ENABLING RED led alt 3 tpm2 ch0
	//PTB->PDDR |= 0X00040000; //making port b pin 18 an output pin


	/*enabling green led*/
	PORTB_PCR19=0X00000300; //ENABLING GREEN led at alt 3 tpm2 ch1
	//PTB->PDDR |= 0X00080000; //making port b pin 19 an output pin

	SIM_SOPT2 |= 0x01000000; //USING MCGFLLCLK AS TIMER COUNTER CLOCK for TPM source clock

	//TPM0_SC = 0x00000000; //DISABLING TMP0
	//TPM2_SC = 0x00000000; //DISABLING TMP2


	/*Starting the controls for blue led: tpm 0 channel 1:*/
	TPM0->CONTROLS[1].CnSC = 0x00000024; //0x20 | 0x08;  // EDGE ALIGNED, PULSE HIGH
	TPM0_MOD = 1875; //
	TPM0_SC = 0x0000000F; //SETTING PRESCALER TO 128 and CMOD value to 1


	/*Setting Controls for TPM2*/
	TPM2_MOD = 1875; //
	TPM2_SC = 0x0000000F; //SETTING PRESCALER to 128 and CMOD value to 1
	/*Starting the controls for red led: tpm 2 channel 0:*/
	TPM2->CONTROLS[0].CnSC = 0x00000024; //0x20 | 0x08;  // EDGE ALIGNED, PULSE HIGH
	/*Starting the controls for GREEN led: tpm 2 channel 1:*/
	TPM2->CONTROLS[1].CnSC = 0x00000024; //0x20 | 0x08;  // EDGE ALIGNED, PULSE HIGH
}



/*Section to switch colours with inputs*/
#ifdef LED_Toggle
void LED_Toggle(uint32_t colour)
{

	if (colour == 'r')
	{

		TPM2->CONTROLS[0].CnV = level;      //r
		TPM2->CONTROLS[1].CnV = 0; //g
		TPM0->CONTROLS[1].CnV = 0; //b
	}


	else if (colour == 'g') {
		TPM2->CONTROLS[0].CnV = 0; //r
		TPM2->CONTROLS[1].CnV = level; //g
		TPM0->CONTROLS[1].CnV = 0; //b
	}

	else if (colour == 'b') {
		TPM2->CONTROLS[0].CnV = 0; //r
		TPM2->CONTROLS[1].CnV = 0; //g
		TPM0->CONTROLS[1].CnV = level; //b
	}

	else if (colour == 'c')
	{
		TPM2->CONTROLS[0].CnV = 0; //r
		TPM2->CONTROLS[1].CnV = level; //g
		TPM0->CONTROLS[1].CnV = level; //b

	}

	else if (colour == 'v')
	{
		TPM2->CONTROLS[0].CnV = level; //r
		TPM2->CONTROLS[1].CnV = 0; //g
		TPM0->CONTROLS[1].CnV = level; //b
	}

	else if (colour == 'y')
	{
		TPM2->CONTROLS[0].CnV = level; //r
		TPM2->CONTROLS[1].CnV = level; //g
		TPM0->CONTROLS[1].CnV = 0; //b
	}

	else if (colour == 'w')
	{
		TPM2->CONTROLS[0].CnV = level; //r
		TPM2->CONTROLS[1].CnV = level; //g
		TPM0->CONTROLS[1].CnV = level; //b
	}

	else
	{
		TPM2->CONTROLS[0].CnV = 0; //r
		TPM2->CONTROLS[1].CnV = 0; //g
		TPM0->CONTROLS[1].CnV = 0; //b
	}


}
#endif

void LED_Function(uint8_t function)  //Function to accept inputs from the user and toggle either brightness or colour
{
      if(function=='+' && level<1000) //if + entered, increase brightness
      {
    	  level+=100;  //increment intensity/brightness levels

      }
      else if(function=='-' && level>0)  //if - entered, decrease brightness
       {
             level-=100;  //decrementing intensity
        }

      else if(function=='u')  //if u, change the colours upward
            {
          	 LED_Colour++;
          	 if(LED_Colour>=8)
          	 {
          		 LED_Colour=0; //reset to first colour
          	 }

            }
      else if(function=='d')  //if d, change the colours downward
             {
              LED_Colour--;
               if(LED_Colour<=0)
                {
                 LED_Colour=7; //reset to last colour
                }
              }
      LED_Intensity(LED_Colour, value); //calling function to perform LED changes

}


void LED_Intensity(LColour LEDColour, uint16_t Intensity) // Function that actually changes colours and intensity
{
	if (LEDColour == 'R')                       //if the colour is RED
		{

			TPM2->CONTROLS[0].CnV = Intensity; //r
			TPM2->CONTROLS[1].CnV = 0; //g
			TPM0->CONTROLS[1].CnV = 0; //b
		}


		else if (colour == 'G')  //if the colour is GREEN
		{
			TPM2->CONTROLS[0].CnV = 0; //r
			TPM2->CONTROLS[1].CnV = Intensity; //g
			TPM0->CONTROLS[1].CnV = 0; //b
		}

		else if (colour == 'B') //if the colour is BLUE
		{
			TPM2->CONTROLS[0].CnV = 0; //r
			TPM2->CONTROLS[1].CnV = 0; //g
			TPM0->CONTROLS[1].CnV = Intensity; //b
		}

		else if (colour == 'C') //if the colour is CYAN = BLUE+GREEN
		{
			TPM2->CONTROLS[0].CnV = 0; //r
			TPM2->CONTROLS[1].CnV = Intensity; //g
			TPM0->CONTROLS[1].CnV = Intensity; //b

		}

		else if (colour == 'V') //if the colour is VIOLET= RED+BLUE
		{
			TPM2->CONTROLS[0].CnV = Intensity; //r
			TPM2->CONTROLS[1].CnV = 0; //g
			TPM0->CONTROLS[1].CnV = Intensity; //b
		}

		else if (colour == 'Y') //if the colour is YELLOW=RED+GREEN
		{
			TPM2->CONTROLS[0].CnV = Intensity; //r
			TPM2->CONTROLS[1].CnV = Intensity; //g
			TPM0->CONTROLS[1].CnV = 0; //b
		}

		else if (colour == 'W') //if the colour is WHITE=RED+GREEN+BLUE
		{
			TPM2->CONTROLS[0].CnV = Intensity; //r
			TPM2->CONTROLS[1].CnV = Intensity; //g
			TPM0->CONTROLS[1].CnV = Intensity; //b
		}

		else //OFF condition
		{
			TPM2->CONTROLS[0].CnV = 0; //r
			TPM2->CONTROLS[1].CnV = 0; //g
			TPM0->CONTROLS[1].CnV = 0; //b
		}



}




void delayMs(uint32_t delay)
		{
			uint32_t i;
			uint32_t j;
			for (i=0;i<delay;i++)
			{
				for (j=0;j<delay;j++)
				{
				}
			}

		 }





