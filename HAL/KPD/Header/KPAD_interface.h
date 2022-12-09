/*
 * KPAD_interface.h
 *
 *  Created on: May 11, 2022
 *      Author: Abanoub
 */

#ifndef KPAD_INTERFACE_H_
#define KPAD_INTERFACE_H_

#include <avr/io.h>

#define GET_PIN(reg,n) 		( (reg >> n) & 0x01 )
#define SET_PIN(reg,n) 		( reg |= (0x01 << n) )
#define CLR_PIN(reg,n) 		( reg &= ~(0x01 << n) )
#define TOG_PIN(reg, n) 	( reg ^= (0x01 << n) )

#define SET_PORT(reg)				(reg = 0xFF)
#define CLR_PORT(reg) 				(reg = 0x00)
#define SET_PROT_VALUE(reg, value) 	(reg = value)

void KPAD_init();

//char copy_PORTPort, char copy_PINPort
char KPAD_getPressedKey();



#endif /* KPAD_INTERFACE_H_ */
