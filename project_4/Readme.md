Project 4 : ECEN 5013- Embedding Software Essentials

Group Members: 1. Arundhathi Swami
	       2. Vignesh Jayaram

This module comprises of 3 modules and their integration:

MODULE 1:

In module 1, we configured the ADC to read analog temperature sensor TMP36. Channel 0 of ADC is used to read the temperature. The ADC is set to 16 bit resolution.

The ADC result obtained is converted into voltage using the formula:
ADC_result_voltage = ADC_result * (3300/65536). {3300 = reference voltage for ADC , 65536 = 16 bit ADC}
The converted voltage value is in millivolts.

The voltage result calculated is then converted to temperature degree celsius.
Temperature_celsius = (ADC_result_voltage - 500)/10  {500 is the offset}

Also, profiling is done to calculate the time required for one ADC conversion.

MODULE 2:

In module 2, we configured the ADC to read a light dependent resistor.Channel 4 of ADC is used to read the LDR. The ADC is set to 16 bit resolution.

The ADC result obtained is converted into voltage using the formula:
ADC_result_voltage = ADC_result * (3300/65536). {3300 = reference voltage for ADC , 65536 = 16 bit ADC}
The converted voltage value is in millivolts.

Depending on the ADC_result_voltage value, the brightness of external red led is controlled. The LED is connect to a GPIO pin. The intensity of LED is controlled using pulse width modulation.

Also, profiling is done to calculate the time required for one ADC conversion.

MODULE 3:

In module 3, library for the on-board capacitive touch sensor is written.
The result of the touch value determines the color of the on-board LED.

Also, profiling is done to calculate the time required for one touch sensing.

INTEGRATION:

We designed a message interface to transfer commands between two devices. The transmitting device was serial monitor of the local host machine and FRDM KL25Z board was the receiver. The message packet structure comprised of 3 members namely: command, length and data. Using the message packet, the previous 3 modules were integrated. Depending on the command and the corresponding data received ,one of the modules will be executed.

The command ID i.e. the first structure member comprises of the different functionalities. These funcationalities are defined in an enumeration. The command IDs for different funcationalities are:

       TEMP = 0x01,

       LDR = 0x02,

       CAP_SENSE = 0x03
 
If the data received is 01 then the functionality is executed i.e tempereature measurement or ldr mesaurement etc whereas if data received is 02 then profiling for the same is done.
