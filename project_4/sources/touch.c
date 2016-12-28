/***************************************************************************
 *
 *  	Filename: touch.c
 *      Description:  This source file contains the functions for configuring and enabling/disabling the onboard capacitive touch sensor.
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: December 1,2016
 *
 ****************************************************************************/
#include "touch.h"

//uint16_t value[50];

void INIT_TOUCH(void){
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;	//clock to port B
	SIM_SCGC5 |= SIM_SCGC5_TSI_MASK;	//clock ot TSI module

	PORTB_PCR16 = PORT_PCR_MUX(0);		//set alternate function for TSI
	TSI0_GENCS |= TSI_GENCS_REFCHRG(1);	//set reference charge to 1uA

}

uint16_t TOUCH_GET_VALUES(void){
	uint16_t value;
	while((TSI0_GENCS & TSI_GENCS_SCNIP_MASK));  // polls the SCAN IN PROGRESS mask that indicates that a scan is being conducted
	TSI0_DATA |= TSI_DATA_TSICH(9); //the cap sensor has 16 channels. we use the 9th channel
	TSI0_DATA |= TSI_DATA_SWTS_MASK;	//start scanning by setting the SWTS bit (Software Trigger Start)
	while(!(TSI0_GENCS & TSI_GENCS_EOSF_MASK)); //polls the EOSF flag (end of scan flag)
	value = (uint16_t)(TSI0_DATA & TSI_DATA_TSICNT_MASK); //collects sensed touch value from the TSI_DATA reg bits TSICNT (touch sense input conversion counter value)
	return value;
}

void  ENABLE_TOUCH(void){
	TSI0_GENCS |= TSI_GENCS_TSIEN_MASK;	//enable TSI module using TSIEN (Touch Sesne input enable)
}

void DISABLE_TOUCH(void){
	TSI0_DATA &= ~TSI_DATA_SWTS_MASK;	//stop scanning by clearing the SWTS bit
	TSI0_GENCS &= ~TSI_GENCS_TSIEN_MASK;	//disable TSI module by clearing the TSIEN bit
}

uint16_t TOUCH_SENSE(void){ // cumultive function to read the touch sensed values in order to use them.
	uint16_t touch_result;
	ENABLE_TOUCH();
	touch_result=TOUCH_GET_VALUES();
	DISABLE_TOUCH();


	return touch_result;
}
