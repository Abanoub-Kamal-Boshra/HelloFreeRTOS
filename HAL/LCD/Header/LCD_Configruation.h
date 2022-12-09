/***********************************************************************************
 * Author 	  : Hesham Ahmed													   *
 * Date   	  : 30/4/2022														   *
 * File name  : LCD_Program.c											 		   *
 * Description: This File contain for the information can  user change		       *
 * Version    :  01																   *
 ***********************************************************************************/
#ifndef HAL_LCD_HEADER_LCD_CONFIGRUATION_H_
#define HAL_LCD_HEADER_LCD_CONFIGRUATION_H_


/*************************************************************************************
 *                          Abstraction of the physical connection                   *
 *************************************************************************************/

/*Please Select The Data Port From (PORT_A/PORT_B/PORT_C/PORT_D)*/
#define LCD_PortData      PORT_D

/*If you Will Used 4bit Mode Please Select the PIN*/
#define   LCD_PinData1    PIN_D0
#define   LCD_PinData2    PIN_D1
#define   LCD_PinData3    PIN_D2
#define   LCD_PinData4    PIN_D3

/*Please Select The Control Port From (PORT_A/PORT_B/PORT_C/PORT_D)*/
#define LCD_PortControl   PORT_C

/*Please Select The Control PIN From (PIN_A0:PIN_A7,PIN_B0:PIN_B7,PIN_C0:PIN_C7,PIN_D0:PIN_D7)*/
#define LCD_PinRS         PIN_C5
#define LCD_PinRW         PIN_C6
#define LCD_PinE 		  PIN_C7
#endif /* HAL_LCD_HEADER_LCD_CONFIGRUATION_H_ */
