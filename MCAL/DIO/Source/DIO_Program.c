/***********************************************************************************
 * Author 	  : Hesham Ahmed													   *
 * Date   	  : 30/4/2022														   *
 * File name  : DIO_Program.c											 		   *
 * Description: This File contain the implementation for the function		       *
 * Version    :  01																   *
 ***********************************************************************************/

#include "../../../LIB/STDTYPE.h"
#include "../../../LIB/BITMATH.h"
#include "../../../LIB/DEFINTATION.h"

#include "../Header/DIO_Register.h"
#include "../Header/DIO_Privet.h"

#include "../Header/DIO_Interface.h"

/*API's For Access BIT*/
/*############################################################################
# Function name : DIO_VoidSetPinDir()                            			 #
# Argument      : U8 Local_PortName , U8 Local_PinNumber , U8 Local_Direction#
# Return        : Void                                                		 #
# Description   : this function select A specific Pin INPUT OR OUTPUT 		 #
##############################################################################*/
void DIO_VoidSetPinDir(U8 Local_PortName , U8 Local_PinNumber , U8 Local_Direction)
{
	if(Local_PortName <= PORT_D  && Local_PinNumber <= PIN_D7)
	{
		if(Local_Direction == DIO_OUTPUT)
		{
			switch (Local_PortName)
			{
			case PORT_A : SET_BIT(DDRA_REG,Local_PinNumber);break;
			case PORT_B : SET_BIT(DDRB_REG,Local_PinNumber);break;
			case PORT_C : SET_BIT(DDRC_REG,Local_PinNumber);break;
			case PORT_D : SET_BIT(DDRD_REG,Local_PinNumber);break;
			}
		}
		else if (Local_Direction==DIO_INPUT)
		{
			switch(Local_PortName)
			{
			case PORT_A : CLEAR_BIT(DDRA_REG,Local_PinNumber);break;
			case PORT_B : CLEAR_BIT(DDRB_REG,Local_PinNumber);break;
		   case PORT_C  : CLEAR_BIT(DDRC_REG,Local_PinNumber);break;
            case PORT_D : CLEAR_BIT(DDRD_REG,Local_PinNumber);break;
			}
	     }
	}
}


/*############################################################################
# Function name : DIO_VoidSetPinValue()                            			 #
# Argument      : U8 Local_PortName , U8 Local_PinNumber , U8 Local_Value	 #
# Return        : Void                                                		 #
# Description   : this function select O/P A specific Pin HIGH OR LOW 		 #
##############################################################################*/
void DIO_VoidSetPinValue(U8 Local_PortName , U8 Local_PinNumber , U8 Local_Value)
{
	if(Local_PortName <= PORT_D && Local_PinNumber <= PIN_D7)
	{
		if(Local_Value == DIO_HIGH)
		{
			switch(Local_PortName)
			{
			case PORT_A : SET_BIT(PORTA_REG,Local_PinNumber);break;
			case PORT_B : SET_BIT(PORTB_REG,Local_PinNumber);break;
			case PORT_C : SET_BIT(PORTC_REG,Local_PinNumber);break;
			case PORT_D : SET_BIT(PORTD_REG,Local_PinNumber);break;
			}
		}
		else if(Local_Value == DIO_LOW)
		{
			switch(Local_PortName)
			{
			case PORT_A : CLEAR_BIT(PORTA_REG,Local_PinNumber);break;
			case PORT_B : CLEAR_BIT(PORTB_REG,Local_PinNumber);break;
			case PORT_C : CLEAR_BIT(PORTC_REG,Local_PinNumber);break;
			case PORT_D : CLEAR_BIT(PORTD_REG,Local_PinNumber);break;
			}
		}
	}

}



/*############################################################################
# Function name : DIO_U8GetPinValue()                            			 #
# Argument      : U8 Local_PortName , U8 Local_PinNumber 					 #
# Return        : U8                                                		 #
# Description   : this function Read  A specific Pin Value			 		 #
##############################################################################*/
U8 DIO_U8GetPinValue(U8 Local_PortName , U8 Local_PinNumber)
{
	U8 Local_PinValue ;
	if(Local_PortName<PORT_D && Local_PinNumber <= PIN_D7)
	{
		switch(Local_PortName)
		{
		case PORT_A : Local_PinValue = GET_BIT(PINA_REG,Local_PinNumber);break;
		case PORT_B : Local_PinValue = GET_BIT(PINB_REG,Local_PinNumber);break;
		case PORT_C : Local_PinValue = GET_BIT(PINC_REG,Local_PinNumber);break;
		case PORT_D : Local_PinValue = GET_BIT(PIND_REG,Local_PinNumber);break;
		}
	}
	return Local_PinValue;
}


/*############################################################################
 # Function name : DIO_voidPullupPinControl()                                #
 # Argument      : u8 Local_PortName,u8 Local_PinNumber,u8 Local_PullupState #
 # Return        : void                                                    	 #
 # Description   : this function control about Internal Pull up Resistance\  #
 #              	   for a specific of pin                                 #
 ############################################################################*/
void DIO_voidPullupPinControl(U8 Local_PortName,U8 Local_PinNumber,U8 Local_PullupState)
{
	DIO_VoidSetPinDir(Local_PortName,Local_PinNumber,DIO_INPUT);
	DIO_VoidSetPinValue(Local_PortName,Local_PinNumber,Local_PullupState);
}
/*------------------------------------------------------------------------------------------------------------------*/
/*API's For Access PORT*/
/*############################################################################
# Function name : DIO_VoidSetPortDir()                            			 #
# Argument      : U8 Local_PortName , U8 Local_Direction					 #
# Return        : Void                                                		 #
# Description   : this function Select The Port the INPUT OR OUTPUT 		 #
##############################################################################*/
void DIO_VoidSetPortDir(U8 Local_PortName , U8 Local_Direction)
{
	if(Local_PortName<= PORT_D)
	{
		switch(Local_PortName)
		{
		case PORT_A : DDRA_REG = Local_Direction ; break;
		case PORT_B : DDRB_REG = Local_Direction ; break;
		case PORT_C : DDRC_REG = Local_Direction ; break;
		case PORT_D : DDRD_REG = Local_Direction ; break;
		}
	}

}


/*############################################################################
# Function name : DIO_VoidSetPortValue()                          			 #
# Argument      : U8 Local_PortName , U8 Local_Value						 #
# Return        : Void                                                		 #
# Description   : this function Select The Port the HIGH OR LOW		 		 #
##############################################################################*/
void DIO_VoidSetPortValue(U8 Local_PortName , U8 Local_Value)
{
	if(Local_PortName<= PORT_D)
		{
			switch(Local_PortName)
			{
			case PORT_A : PORTA_REG = Local_Value ; break;
			case PORT_B : PORTB_REG = Local_Value ; break;
			case PORT_C : PORTC_REG = Local_Value ; break;
			case PORT_D : PORTD_REG = Local_Value ; break;
			}
		}

}


/*############################################################################
# Function name : DIO_U8GetPortValue()                          			 #
# Argument      : U8 Local_PortName 										 #
# Return        : U8                                                		 #
# Description   : this function Select The Port the INPUT OR OUTPUT 		 #
##############################################################################*/
U8 DIO_U8GetPortValue(U8 Local_PortName)
{
	U8 Local_PortValue ;
	if(Local_PortName<= PORT_D)
			{
				switch(Local_PortName)
				{
				case PORT_A :Local_PortValue = PINA_REG; break;
				case PORT_B :Local_PortValue = PINB_REG ; break;
				case PORT_C :Local_PortValue = PINC_REG ; break;
				case PORT_D :Local_PortValue = PIND_REG ; break;
				}
			}
return Local_PortValue;
}


