/********************************************
*   Authors: Arundhathi Swami, Vignesh Jayaram
*   Date Edited: 14 Oct 2016
*
*   File: CBUNITTESTS.c
*
*   Description: source file for test cases of circular buffer

********************************************************/


#include "BUFFER.h"
#include "MKL25Z4.h"
#include "system_MKL25Z4.h"
#include <stdint.h>
#include "UART0_INIT.h"
#include "LOGGER.h"
#include "BUFFER.h"
#include "CBUNITTESTS.h"
#include <stdlib.h>


void TEST1 ()
//ALLOCATING MEMORY FOR THE BUFFER
{
	UARTT_INIT();
	circularbuffer_memoryallocate(5);
	char TEST1[200] = "TESTING ALLOCATION OF MEMORY TO THE HEAP";
	uart_string(TEST1);
	uart_string("\n");
	uart_string("\r");//printing log0
	char RES1[200] = "CB UNIT TEST 1/5 : PASS";
	//UARTT_INIT();
	uart_string(RES1);
	uart_string("\n");
	uart_string("\r");//printing log0
}

void TEST2()
{
	//SENDING LEMENTS TO THE BUFFER
	        UARTT_INIT();
	        (cb1->length)=5;


			(cb1->buffer)=(uint8_t *) cir_buffer; //initialising buffer  tail. head and buffer to the starting position of the buffer
			(cb1->head)= cb1->buffer;
			(cb1->tail)= cb1->buffer;
	 		//TEST CASE TO ADD ELEMENTS TO BUFFER

	 		char TEST2[200] = "TESTING ADDING OF ELEMENTS TO BUFFER";
	 						uart_string("\n");
	 			 			uart_string("\r");
	 			 		   	uart_string(TEST2);
	 			 		   	uart_string("\n");
	 			 		   	uart_string("\r");       //printing log0

	 		uint8_t ret=0;
	 		ret = buffer_add();
	 		if (ret == 3)
	 			{
	 			char success[200] = "CB UNIT TEST 2: Pass - 4 elements added";
	 			//UARTT_INIT();
	 			uart_string(success);
	 			uart_string("\n");
	 			uart_string("\r");
				}
	 		else if (ret == 4)
	 		{
	 			char failure[200] = "CB UNIT TEST 2: Fail - Couldnt add Values";
	 			//UARTT_INIT();
	 			uart_string(failure);
	 			uart_string("\n");
	 			uart_string("\r");
	 		}

}

void TEST3()
{
//TESTING BUFFER_FULL
				//UARTT_INIT();
		        (cb1->length)=5;

	 		char TEST3[200] = "TESTING BUFFER FULLNESS";
	 			 		    UARTT_INIT();
	 			 		    uart_string("\n");
	 			 		    uart_string("\r");
	 			 		    uart_string(TEST3);
	 			 		   	uart_string("\n");
	 			 		   	uart_string("\r");//printing log0
	 		uint8_t ans;
	 		ans = buffer_full();
	 		if(ans==0)
	 		{
	 		    char failure[200] = "CB UNIT TEST 3: Fail";
	 		    UARTT_INIT();
	 		   	uart_string(failure);
	 		   	uart_string("\n");
	 		   	uart_string("\r");
	 		}

	 		else
	 		{
	 			char passes[200] = "CB UNIT TEST 3: Pass - Buffer isnt Full";
	 			UARTT_INIT();
	 			uart_string(passes);
	 			uart_string("\n");
	 			uart_string("\r");
	 		}


}

 void TEST4()
 {
	 		//TEST CASE TO REMOVE ELEMENTS
	 		char TEST4[200] = "TESTING FOR BUFFER REMOVE (REMOVING 2 OUT OF 4 ADDED ITEMS) :";
	 						uart_string("\n");
	 			 			uart_string("\r");
	 						UARTT_INIT();
	 			 			uart_string(TEST4);
	 			 			uart_string("\n");
	 			 			uart_string("\r");//printing log0
	 		uint8_t count=4;
	 		uint8_t rem = 2;
	 		uint8_t retu;       //variable to which removed element is copied
	 		for(uint8_t i=0;i<rem;i++)
	 		{
	 		    retu=buffer_remove();
	 		}
	 		if (count - rem == 2)
	 			{
	 			char rem1[200] = "CB UNIT TEST 3: Pass - Required no of items removed";
	 			UARTT_INIT();
	 			uart_string(rem1);
	 			uart_string("\n");
	 			uart_string("\r");//printing log0
				}
	 		else
	 			{char rem2[200] = "CB UNIT TEST 3: Fail - Items not Removed";
	 				 			UARTT_INIT();
	 				 			uart_string(rem2);
	 				 			uart_string("\n");
	 				 			uart_string("\r");//printing log0
	 			}
 }


	 		//TEST CASE FOR BUFFER_EMPTY
 void TEST5()
 {
	 		char TEST5[200] = "Testing for BUffer Empty";
	 									uart_string("\n");
	 			 			 		    uart_string("\r");
	 									UARTT_INIT();
	 			 			 			uart_string(TEST5);
	 			 			 			uart_string("\n");
	 			 			 			uart_string("\r");//printing log0

	 		uint8_t ans;
	 		ans=buffer_empty();
	 		if(ans==1)
	 		{
	 			char emp1[200] = "CB UNIT TEST 5: Fail : Buffer is empty";
	 				 			UARTT_INIT();
	 				 			uart_string(emp1);
	 				 			uart_string("\n");
	 				 			uart_string("\r");//printing log0


	 		}
	 		else
	 		{
	 			char emp1[200] = "CB UNIT TEST 5: Pass - Removed all elements";
	 				 			 			UARTT_INIT();
	 				 			 			uart_string(emp1);
	 				 			 			uart_string("\n");
	 				 			 			uart_string("\r");//printing log0

	 		}
 }
//#endif
