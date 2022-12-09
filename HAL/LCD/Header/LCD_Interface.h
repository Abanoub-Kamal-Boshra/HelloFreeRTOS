/***********************************************************************************
 * Author 	  : Hesham Ahmed													   *
 * Date   	  : 30/4/2022														   *
 * File name  : LCD_Interface.h											 		   *
 * Description: This File Contain The Prototype for API's			               *
 * Version    :  01																   *
 ***********************************************************************************/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "LCD_Privet.h"


/*########################################################################################################
# Function name : LCD_VoidInit()             		               										 #
# Argument      : void																				     #
# Return        : Void                                                									 #
# Description   : this function Make Some Init To the LCD Worked 	 									 #
##########################################################################################################*/
void LCD_VoidInit(void);

/*############################################################################
# Function name : LCD_VoidSendCommand()                            			 #
# Argument      : U8 Local_Command											 #
# Return        : Void                                                		 #
# Description   : this function Will Send The Command To LCD		 		 #
##############################################################################*/
void LCD_VoidSendCommand(U8 Local_Command);


/*############################################################################
# Function name : LCD_VoidSendCommand()                            			 #
# Argument      : U8 Local_Char												 #
# Return        : Void                                                		 #
# Description   : this function Will Display The Char on LCD			     #
##############################################################################*/
void LCD_VoidSendChar(U8 Local_Char);

/*############################################################################
# Function name : LCD_VoidSendString()                            			 #
# Argument      : U8 *Address_String										 #
# Return        : Void                                                		 #
# Description   : this function Will Display The Some Of Char on LCD(String) #
##############################################################################*/
void LCD_VoidSendString(U8 *Address_String);

/*############################################################################
# Function name : LCD_VoidGoToXY()              	              			 #
# Argument      : U8 Local_XPosition,U8 Local_YPosition 					 #
# Return        : Void                                                		 #
# Description   : this function Will move the cursor to the required\        #
 	 	 	 	  X and Y												     #
##############################################################################*/
void LCD_VoidGoToXY(U8 Local_XPosition,U8 Local_YPosition);

/*############################################################################
# Function name : LCD_VoidSendNumber()              	              		 #
# Argument      : U32 local_U32Number					 					 #
# Return        : Void                                                		 #
# Description   : this function Will take The Number and Convert to Char     #
 	 	 	 	  And Display it 	 									     #
##############################################################################*/
void LCD_VoidSendNumber(U32 local_U32Number);

/*############################################################################
# Function name : LCD_VoidStoreSpecialChar()              	              	 #
# Argument      : U8* Local_U8PatternArray , U8 Local_U8PatternNum			 #
# Return        : Void                                                		 #
# Description   : this function Store Special Char In CGRAM 	 		     #
##############################################################################*/
void LCD_VoidStoreSpecialChar(U8* Local_U8PatternArray , U8 Local_U8PatternNum);
/*############################################################################
# Function name : LCD_VoidStoreSpecialChar()              	              	 #
# Argument      : U8* Local_U8PatternNum 									 #
# Return        : Void                                                		 #
# Description   : this function Store Special Char In CGRAM 	 		     #
##############################################################################*/
void LCD_VoidDisplaySpecialChar(U8 Local_U8PatternNum);

#endif /* LCD_INTERFACE_H_ */
