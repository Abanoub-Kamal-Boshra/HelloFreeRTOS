/*
 * TIMER0_interface.h
 *
 *  Created on: May 15, 2022
 *      Author: Abanoub
 */

#ifndef MCAL_TIMER0_HEADER_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_HEADER_TIMER0_INTERFACE_H_

void TIMER0_OVERflow_init(void);
/*ISR of TIMER0 overflow*/
void __vector_11(void) __attribute__((signal));

#endif /* MCAL_TIMER0_HEADER_TIMER0_INTERFACE_H_ */
