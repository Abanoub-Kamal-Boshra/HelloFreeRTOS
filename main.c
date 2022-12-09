/*
 * main.c
 *
 *  Created on: May 1, 2022
 *      Author: hisha
 */
//#include <util/delay.h>
#include "MCAL/DIO/Header/DIO_Interface.h"
#include "OS/FreeRTOSConfig.h"
#include "OS/FreeRTOS.h"
#include "OS/task.h"

void vTask1Blink500( void * pvParameters );
void vTask1Blink1000( void * pvParameters );
void vTask1Blink1500( void * pvParameters );


void main(void)
{

	DIO_VoidSetPinDir(PORT_A, PIN_A0, OUTPUT);
	DIO_VoidSetPinDir(PORT_A, PIN_A1, OUTPUT);
	DIO_VoidSetPinDir(PORT_A, PIN_A2, OUTPUT);
	xTaskCreate(vTask1Blink500, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(vTask1Blink1000, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(vTask1Blink1500, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);

	vTaskStartScheduler();

	while(1)
	{

	}

}



/////////////////////////////////////////////////// task 1 //////////////////////////////////////
/* Task to be created. */
void vTask1Blink500( void * pvParameters )
{
//    The parameter value is expected to be 1 as 1 is passed in the
//    pvParameters value in the call to xTaskCreate() below.
//    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );

    char flag = 0;

    for( ;; )
    {
        /* Task code goes here.          */
    	if(flag == 0){
    		DIO_VoidSetPinValue(PORT_A, PIN_A0, HIGH);
    		flag = 1;
    	}else{
    		DIO_VoidSetPinValue(PORT_A, PIN_A0, LOW);
    		flag = 0;
    	}
    	vTaskDelay(500);

    }
}

void vTask1Blink1000( void * pvParameters )
{
//    The parameter value is expected to be 1 as 1 is passed in the
//    pvParameters value in the call to xTaskCreate() below.
//    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );

    char flag = 0;

    for( ;; )
    {
    	/* Task code goes here.          */
		if(flag == 0){
			DIO_VoidSetPinValue(PORT_A, PIN_A1, HIGH);
			flag = 1;
		}else{
			DIO_VoidSetPinValue(PORT_A, PIN_A1, LOW);
			flag = 0;
		}
		vTaskDelay(1000);

    }
}

void vTask1Blink1500( void * pvParameters )
{
//    The parameter value is expected to be 1 as 1 is passed in the
//    pvParameters value in the call to xTaskCreate() below.
//    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );

    char flag = 0;

    for( ;; )
    {
    	/* Task code goes here.          */
		if(flag == 0){
			DIO_VoidSetPinValue(PORT_A, PIN_A2, HIGH);
			flag = 1;
		}else{
			DIO_VoidSetPinValue(PORT_A, PIN_A2, LOW);
			flag = 0;
		}
		vTaskDelay(1500);

    }
}
