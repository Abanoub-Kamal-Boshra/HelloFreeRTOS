/*
 * UART_program.c
 *
 *  Created on: May 16, 2022
 *      Author: Abanoub
 */

#include <avr/io.h>

#define BAUD_RATE		9600

void UART_Init(void)
{
//	UCSRB UCSZ2
	UCSRC |= (1<<URSEL); //register select
	UCSRC &= ~(1<<UMSEL); //
	UCSRC |= (1<<UPM1);

}

void UART_Tx(char data)
{

}

char UART_Rx(void)
{

}
