/***********************************************************************************
 * Author 	  : Hesham Ahmed													   *
 * Date   	  : 30/4/2022														   *
 * File name  : LCD_Program.c											 		   *
 * Description: This File contain the implementation for the function		       *
 * Version    :  01																   *
 ***********************************************************************************/
#include <util/delay.h>

#include "../../../LIB/DEFINTATION.h"
#include "../../../LIB/STDTYPE.h"
#include "../../../LIB/BITMATH.h"

#include "../../../MCAL/DIO/Header/DIO_Interface.h"

#include "../Header/LCD_Register.h"
#include "../Header/LCD_Privet.h"
#include "../Header/LCD_Configruation.h"
#include "../Header/LCD_Interface.h"

/*Global Variable To Store the Type of Mode*/

/*############################################################################
# Function name : LCD_VoidSendCommand()                            			 #
# Argument      : U8 Local_Command											 #
# Return        : Void                                                		 #
# Description   : this function Will Send The Command To LCD		 		 #
##############################################################################*/
void LCD_VoidSendCommand(U8 Local_Command)
{
	/*Select The RS Pin is Low TO Send Command*/
	DIO_VoidSetPinValue(LCD_PortControl,LCD_PinRS,LCD_PinLOW);
	/*Select The RW Pin is LOW Because we Will Write*/
	DIO_VoidSetPinValue(LCD_PortControl,LCD_PinRW,LCD_PinLOW);
	/*SET THE E Pin*/
	DIO_VoidSetPinValue(LCD_PortControl,LCD_PinE,LCD_PinHIGH);
	/*Send Command*/
	DIO_VoidSetPortValue(LCD_PortData,Local_Command);
	/*Clear The E Pin*/
	DIO_VoidSetPinValue(LCD_PortControl,LCD_PinE,LCD_PinLOW);
}


/*############################################################################
# Function name : LCD_VoidSendChar()                            			 #
# Argument      : U8 Local_Char												 #
# Return        : Void                                                		 #
# Description   : this function Will Display The Char on LCD			     #
##############################################################################*/
void LCD_VoidSendChar(U8 Local_Char)
{
	/*Select The RS Pin is Low TO Send Command*/
	DIO_VoidSetPinValue(LCD_PortControl,LCD_PinRS,LCD_PinHIGH);
	/*Select The RW Pin is LOW Because we Will Write*/
	DIO_VoidSetPinValue(LCD_PortControl,LCD_PinRW,LCD_PinLOW);
	/*SET THE E Pin*/
	DIO_VoidSetPinValue(LCD_PortControl,LCD_PinE,LCD_PinHIGH);
	/*Send Command*/
	DIO_VoidSetPortValue(LCD_PortData,Local_Char);
	/*Clear The E Pin*/
	DIO_VoidSetPinValue(LCD_PortControl,LCD_PinE,LCD_PinLOW);
}

/*########################################################################################################
# Function name : LCD_VoidInit()             		               										 #
# Argument      : void																				     #
# Return        : Void                                                									 #
# Description   : this function Make Some Init To the LCD Worked 	 									 #
##########################################################################################################*/
void LCD_VoidInit(void)
{
	/*Will Select The PORT DATA AND Pin In PORT CONTROL IS OUTPUT*/
	DIO_VoidSetPortDir(LCD_PortData,LCD_PORTMAXVALUE);
	DIO_VoidSetPinDir(LCD_PortControl,LCD_PinE,LCD_PinOUTPUT);
	DIO_VoidSetPinDir(LCD_PortControl,LCD_PinRW,LCD_PinOUTPUT);
	DIO_VoidSetPinDir(LCD_PortControl,LCD_PinRS,LCD_PinOUTPUT);

	/*Will Write The Routine Init From Datasheet*/
	_delay_ms(30);
	LCD_VoidSendCommand(LCD_Set8Bit2Line5x8);
	LCD_VoidSendCommand(LCD_CursorON);
	_delay_ms(2);
	_delay_ms(1);
	LCD_VoidSendCommand(LCD_DisplayON);
	_delay_ms(2);
	LCD_VoidSendCommand(LCD_ReturnHome);
	_delay_ms(15);
	LCD_VoidSendCommand(LCD_ClearDisplay);
	_delay_ms(15);
	LCD_VoidSendCommand(LCD_EntryMode2);
	_delay_ms(2);


}

/*############################################################################
# Function name : LCD_VoidSendString()                            			 #
# Argument      : U8 *Address_String										 #
# Return        : Void                                                		 #
# Description   : this function Will Display The Some Of Char on LCD(String) #
##############################################################################*/
void LCD_VoidSendString(U8 *Address_String)
{   /* Local loop Counter */
	U8 Local_Counter = 0 ;
	while(Address_String[Local_Counter]!=NULL_Charecter)
	{
		/* Write Character on LCD */
		LCD_VoidSendChar(Address_String[Local_Counter]);
		/* Increment local loop index */
		Local_Counter++;
	}
}


/*############################################################################
# Function name : LCD_VoidSendNumber()              	              		 #
# Argument      : U32 local_U32Number					 					 #
# Return        : Void                                                		 #
# Description   : this function Will take The Number and Convert to Char     #
 	 	 	 	  And Display it 	 									     #
##############################################################################*/
void LCD_VoidSendNumber(U32 local_U32Number)
{
	S32 Local_S32Num = 1;

	if(local_U32Number == 0 )
	{
		LCD_VoidSendChar('0');
	}
	else if (local_U32Number < 0)
	{
		LCD_VoidSendChar('-');
		local_U32Number *= -1;
	}
	while (local_U32Number != 0)
	{
		Local_S32Num = ((Local_S32Num * 10) + (local_U32Number % 10));
		local_U32Number = (local_U32Number / 10);
	}
	while (Local_S32Num != 1)
	{
		LCD_VoidSendChar((Local_S32Num % 10) + 48);
		Local_S32Num = (Local_S32Num / 10);
	}

}

/*############################################################################
# Function name : LCD_VoidGoToXY()              	              			 #
# Argument      : U8 Local_XPosition,U8 Local_YPosition 					 #
# Return        : Void                                                		 #
# Description   : this function Will move the cursor to the required\        #
 	 	 	 	  X and Y												     #
##############################################################################*/
void LCD_VoidGoToXY(U8 Local_XPosition,U8 Local_YPosition)
{
	U8 Local_U8Address;
	switch(Local_XPosition)
	{
	case 0 :Local_U8Address=Local_YPosition;  break;
	case 1 :Local_U8Address=Local_YPosition + LCD_SecondLine;  break;
	default:  break;
	}
	LCD_VoidSendCommand(Local_U8Address + LCD_SetAddressDDRAM);
}


/*############################################################################
# Function name : LCD_VoidStoreSpecialChar()              	              	 #
# Argument      : U8* Local_U8PatternArray , U8 Local_U8PatternNum			 #
# Return        : Void                                                		 #
# Description   : this function Store Special Char In CGRAM 	 		     #
##############################################################################*/
void LCD_VoidStoreSpecialChar(U8* Local_U8PatternArray , U8 Local_U8PatternNum)
{
	U8 Local_Counter = 0 ;
	/* set address of first byte of the pattern at pattern number n*/
	LCD_VoidSendCommand(LCD_SetAddressCGRAM + Local_U8PatternNum*LCD_CGRAMPatternSize );
	/* send the pattern  data bytes one by one */
	for(Local_Counter = 0 ; Local_Counter <LCD_CGRAMPatternSize ; Local_Counter++)
	{
		LCD_VoidSendChar(Local_U8PatternArray[Local_Counter]);
	}

}

/*############################################################################
# Function name : LCD_VoidStoreSpecialChar()              	              	 #
# Argument      : U8* Local_U8PatternNum 									 #
# Return        : Void                                                		 #
# Description   : this function Display Special Char In CGRAM 	 		     #
##############################################################################*/
void LCD_VoidDisplaySpecialChar(U8 Local_U8PatternNum)
{

	LCD_VoidSendChar(Local_U8PatternNum);

}



