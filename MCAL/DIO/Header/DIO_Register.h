/***********************************************************************************
 * Author 	  : Hesham Ahmed													   *
 * Date   	  : 30/4/2022														   *
 * File name  : DIO_REGISTER.h											 		   *
 * Description: This File Contain The Address for DIO Register	                   *
 * Version    :  01																   *
 ***********************************************************************************/
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_
/*--------------------------------Memory Mapping Register----------------------*/

/****************************GROUP A*******************************/
 #define PORTA_REG      (*(volatile U8*)0x3B)
 #define DDRA_REG       (*(volatile U8*)0x3A)
 #define PINA_REG       (*(volatile U8*)0x39)

/****************************GROUP B*******************************/
 #define PORTB_REG      (*(volatile U8*)0x38)
 #define DDRB_REG       (*(volatile U8*)0x37)
 #define PINB_REG       (*(volatile U8*)0x36)

/****************************GROUP C*******************************/
 #define PORTC_REG      (*(volatile U8*)0x35)
 #define DDRC_REG       (*(volatile U8*)0x34)
 #define PINC_REG       (*(volatile U8*)0x33)

/****************************GROUP D*******************************/
 #define PORTD_REG      (*(volatile U8*)0x32)
 #define DDRD_REG       (*(volatile U8*)0x31)
 #define PIND_REG       (*(volatile U8*)0x30)

/*----------------------------------------------------------------------*/

/*--------------------------------Porting Mapping Register----------------------*/

/****************************GROUP A*******************************/
 #define PORTA_PREG      (*(volatile u8*)0x1B)
 #define DDRA_PREG       (*(volatile u8*)0x1A)
 #define PINA_PREG       (*(volatile u8*)0x19)

/************************GROUP B*******************************/
 #define PORTB_PREG      (*(volatile u8*)0x18)
 #define DDRB_PREG       (*(volatile u8*)0x17)
 #define PINB_PREG       (*(volatile u8*)0x16)

/****************************GROUP C*******************************/
 #define PORTC_PREG      (*(volatile u8*)0x15)
 #define DDRC_PREG       (*(volatile u8*)0x14)
 #define PINC_PREG       (*(volatile u8*)0x13)

/****************************GROUP A*******************************/
 #define PORTD_PREG      (*(volatile u8*)0x12)
 #define DDRD_PREG       (*(volatile u8*)0x11)
 #define PIND_PREG       (*(volatile u8*)0x10)

/*----------------------------------------------------------------------*/


#endif /* DIO_REGISTER_H_ */
