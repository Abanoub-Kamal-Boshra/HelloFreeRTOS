/***********************************************************************************
 * Author 	  : Hesham Ahmed													   *
 * Date   	  : 30/4/2022														   *
 * File name  : DIO_Interface.h											 		   *
 * Description: This File Contain The Prototype for API's			               *
 * Version    :  01																   *
 ***********************************************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "DIO_Privet.h"
#include "../../../LIB/STDTYPE.h"
/*API's For Access BIT*/
/*############################################################################
# Function name : DIO_VoidSetPinDir()                            			 #
# Argument      : U8 Local_PortName , U8 Local_PinNumber , U8 Local_Direction#
# Return        : Void                                                		 #
# Description   : this function select A specific Pin INPUT OR OUTPUT 		 #
##############################################################################*/
void DIO_VoidSetPinDir(U8 Local_PortName , U8 Local_PinNumber , U8 Local_Direction);

/*############################################################################
# Function name : DIO_VoidSetPinValue()                            			 #
# Argument      : U8 Local_PortName , U8 Local_PinNumber , U8 Local_Value	 #
# Return        : Void                                                		 #
# Description   : this function select O/P A specific Pin HIGH OR LOW 		 #
##############################################################################*/
void DIO_VoidSetPinValue(U8 Local_PortName , U8 Local_PinNumber , U8 Local_Value);

/*############################################################################
# Function name : DIO_U8GetPinValue()                            			 #
# Argument      : U8 Local_PortName , U8 Local_PinNumber 					 #
# Return        : U8                                                		 #
# Description   : this function Read  A specific Pin Value			 		 #
##############################################################################*/
U8 DIO_U8GetPinValue(U8 Local_PortName , U8 Local_PinNumber);

/*############################################################################
 # Function name : DIO_voidPullupPinControl()                                #
 # Argument      : u8 Local_PortName,u8 Local_PinNumber,u8 Local_PullupState #
 # Return        : void                                                    	 #
 # Description   : this function control about Internal Pull up Resistance\  #
 #              	   for a specific of pin                                 #
 ############################################################################*/
void DIO_voidPullupPinControl(U8 Local_PortName,U8 Local_PinNumber,U8 Local_PullupState);

/*---------------------------------------------------------------------------------------------------*/
/*API's For Access PORT*/
/*############################################################################
# Function name : DIO_VoidSetPortDir()                            			 #
# Argument      : U8 Local_PortName , U8 Local_Direction					 #
# Return        : Void                                                		 #
# Description   : this function Select The Port the INPUT OR OUTPUT 		 #
##############################################################################*/
void DIO_VoidSetPortDir(U8 Local_PortName , U8 Local_Direction);

/*############################################################################
# Function name : DIO_VoidSetPortValue()                          			 #
# Argument      : U8 Local_PortName , U8 Local_Value						 #
# Return        : Void                                                		 #
# Description   : this function Select The Port the HIGH OR LOW		 		 #
##############################################################################*/
void DIO_VoidSetPortValue(U8 Local_PortName , U8 Local_Value);

/*############################################################################
# Function name : DIO_U8GetPortValue()                          			 #
# Argument      : U8 Local_PortName 										 #
# Return        : U8                                                		 #
# Description   : this function Select The Port the INPUT OR OUTPUT 		 #
##############################################################################*/
U8 DIO_U8GetPortValue(U8 Local_PortName);



#endif /* DIO_INTERFACE_H_ */
