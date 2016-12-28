/*
 * 	    Filename: touch.h
 *      Description:  This header file contains the functions that configure the onboard capacitive touch sensor.
 *
 *		Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: December 3,2016
 *
 *     1. INIT_TOUCH
 *     > This function configures the cap sesnor for the following attributes:
 *     i. Mode: capacitive Sensing mode (non-noise detection)
 *     ii. Reference Charge Oscillator Current: 1uA (This decides the touch sensitivity. Lower the value higher the sensitivity)
 *     iii. DVOLT : 00 DV = 1.03 V; VP = 1.33 V; Vm = 0.30 V
 *     iv. Electrode Oscillator Charge Current : 500nA
 *     v. PreScalar : 1 - Divides the electrode oscillator frequency by 1
 *     vi. NSCN = 00 (No of Scans for each electrode) = 1
 *     vii. TSICH = 9 Use the ninth channel to take readings
 *     viii. SWTS = 1 ==> Software trigger enabled
 *
 *     2. TOUCH_GET_VALUES
 *     > This function pols the touch sensing electrode till itgets a definitive value (i.e till EOSF flg is set)
 *     > It then transfers values from the tsicnt reg to a variable
 *
 *     3. ENABLE_TOUCH
 *     > This function enables touch sensing (TSIEN = 1)
 *
 *     4. DISABLE_TOUCH
 *     >This function disables touch sensing (TSIEN = 0) and disables the software trigger bit.
 */






#ifndef TOUCH
#define TOUCH
#include "MKL25Z4.h"

void INIT_TOUCH(void);
uint16_t TOUCH_GET_VALUES(void);
void ENABLE_TOUCH(void);
void DISABLE_TOUCH(void);
uint16_t TOUCH_SENSE(void);

#endif
