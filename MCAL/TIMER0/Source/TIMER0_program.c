
#include "../../../LIB/STDTYPE.h"
#include "../../../LIB/DEFINTATION.h"
#include "../../../LIB/BITMATH.h"

#include "../Header/TIMER0_config.h"

#include <avr/io.h>

void TIMER0_OVERflow_init(void)
{
	/*NORmal mode*/
	TCCR0 &= ~(1<<WGM00);
	TCCR0 &= ~(1<<WGM01);
	/* PRESCALLER*/
	TCCR0 &= ~(1<<CS02);
	TCCR0 |= (1<<CS01);
	TCCR0 &= ~(1<<CS00);
	/*preload*/
	TCNT0 = OVER_FLOW_PRELOAD;
	/*IE*/
	TIMSK |= (1<<TOIE0);
}


/*ISR of TIMER0 overflow*/
void __vector_11(void)
{
	static char count = 0;
	count ++;
	if (count == NUMBER_OF_COUNTS)
	{

	}
}

/* Another method for ISR */
//ISR(TIMER0_OVF_vect)
//{
//
//}

void CTC_init(void)
{

}


