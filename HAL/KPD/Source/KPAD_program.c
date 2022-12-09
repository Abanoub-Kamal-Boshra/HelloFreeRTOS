/*
 * KPAD_program.c
 *
 *  Created on: May 11, 2022
 *      Author: Abanoub
 */

#include "../../../LIB/STDTYPE.h"
#include "../../../LIB/DEFINTATION.h"
#include "../../../LIB/BITMATH.h"

#include "../Header/KPAD_interface.h"
#include "../Header/KPAD_private.h"


//char copy_DDRPort, char copy_PORTPort
void KPAD_init()
{
	/* MAKE THE
	 * PENs PORTA0,1,2,3 IS OUTPUT
	 * PENs POSTA4,5,6,7 IS INPUT*/
	SET_PROT_VALUE(DDRD, 0x0f);		//	DDRD = 0xF0;

	/*make
	 * PA0,1,2,3 as HIGH
	 * PA4,5,6,7 PULLUP Resistor */
	SET_PORT(PORTD);		//	PORTD = 0xFF;
}

//char copy_PORTPort, char copy_PINPort
char KPAD_getPressedKey(){

	char keyValue = -1 ;
	char keyPressed = -1;
	for(char col=0; col<4; col++)
	{
		CLR_PIN(PORTD, col);
		for(char row=4; row<8; row++)
		{

			keyValue = -1 ;
			keyValue = GET_PIN(PIND, row);
			if(keyValue == 0)
			{
				keyPressed = keyPadButtons[row-4][col];
				break;
			}
		}
		SET_PIN(PORTD, col);
	}
	return keyPressed;
}
