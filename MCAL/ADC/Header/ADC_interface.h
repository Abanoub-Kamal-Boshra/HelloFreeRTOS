/*
 * ADC_interface.h
 *
 *  Created on: 4 Dec 2021
 *      Author: Alaa Taher
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);

/*input must be value from 0 to 7*/
U8 ADC_u8GetChannelRead(U8 Copy_u8Channel);

void ADC_init(void);
U16 ADC_Read(U8 Channel);
#endif /* ADC_INTERFACE_H_ */
