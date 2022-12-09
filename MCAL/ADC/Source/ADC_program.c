
#include "../../../LIB/STDTYPE.h"
#include "../../../LIB/DEFINTATION.h"
#include "../../../LIB/BITMATH.h"

#include <avr/io.h>
//#include "ADC_interface.h"
#include "../Header/ADC_register.h"

//void ADC_voidInit(void)
//{
	/*Choose Aref as AVcc value*/
//	SET_BIT(ADMUX,ADMUX_REFS0);
//	CLR_BIT(ADMUX,ADMUX_REFS1);


	/*Choose prescaler value as 128*/
	//SET_BIT(ADCSRA,ADCSRA_ADPS0);
	//SET_BIT(ADCSRA,ADCSRA_ADPS1);
	//SET_BIT(ADCSRA,ADCSRA_ADPS2);

	/*Enable ADC*/
	//SET_BIT(ADCSRA,ADCSRA_ADEN);
//}

//u8 ADC_u8GetChannelRead(u8 Copy_u8Channel)
//{
	/*Clear MUX bits*/
	//ADMUX &= 0b11100000;

	/*Set MUX bits with desired value*/
	//ADMUX |= Copy_u8Channel;

	/*Start conversion*/
	//SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*Wait until conversion finished*/
	//while((GET_BIT(ADCSRA,ADCSRA_ADIF)) != 0);

	/*Flag clearing*/
//	SET_BIT(ADCSRA,ADCSRA_ADIF);

	//return ADC;


//}



void ADC_init(void)
{
	ADMUX = (1<<REFS0);
	ADCSRA = (1<<ADEN)|(1<<ADPS1)|(1<<ADPS2);
}

U16 ADC_Read(U8 Channel)
{
	DDRA&=~(1<<Channel);
	Channel = Channel & 0x07; // Filtering Channel (3 bits)
	ADMUX &=0xE0;  // Clearing least 5 bits "0"

	ADMUX |=Channel;

	ADCSRA |=(1<<ADSC);  // Start Conversion
	while( ADCSRA &(1<<ADSC)); // Waiting till Bit 0

	return ADC;
}


