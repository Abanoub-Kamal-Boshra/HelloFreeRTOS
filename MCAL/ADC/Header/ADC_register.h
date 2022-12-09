/*
 * ADC_register.h
 *
 *  Created on: 4 Dec 2021
 *      Author: Alaa Taher
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define  ADC_ADMUX			*((volatile U8*)0x27)
#define  ADC_ADMUX_REFS0		7
#define  ADC_ADMUX_REFS1		6
#define  ADC_ADMUX_ADLAR		5
#define  ADC_ADMUX_MUX4		4
#define  ADC_ADMUX_MUX3		3
#define  ADC_ADMUX_MUX2		2
#define  ADC_ADMUX_MUX1		1
#define  ADC_ADMUX_MUX0		0

#define  ADC_ADCSRA			*((volatile U8*)0x26)
#define  ADC_ADCSRA_ADEN		7
#define  ADC_ADCSRA_ADSC		6
#define  ADC_ADCSRA_ADATE	5
#define  ADC_ADCSRA_ADIF		4
#define  ADC_ADCSRA_ADIE		3
#define  ADC_ADCSRA_ADPS2	2
#define  ADC_ADCSRA_ADPS1	1
#define  ADC_ADCSRA_ADPS0	0


#define DATA_ADCH		*((volatile U8*)0x25)
#define DATA_ADCL		*((volatile U8*)0x24)

#define DATA_ADC		*((volatile U16*)0x24)



#endif /* ADC_REGISTER_H_ */
