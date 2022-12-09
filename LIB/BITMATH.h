/***********************************************************************************
 * Author 	  : Hesham Ahmed													   *
 * Date   	  : 30/4/2022														   *
 * File name  : BITMATH.h														   *
 * Description: This File Contain About Macro function to Acess Bits               *
 * Version    :  01																   *
 ***********************************************************************************/
#ifndef BITMATH_H_
#define BITMATH_H_
/*Access bit*/
/*Set The Specific bit by 1  */
#define SET_BIT(Register,BIT)     (Register|=(1<<BIT))
/*Clear The SPecific bit by 0*/
#define CLEAR_BIT(Register,BIT)   (Register&=~(1<<BIT))
/*Toggle The Specific bit ->if bit = 0 will change to 1 and if bit = 1 will change to 0*/
#define TOGGLE_BIT(Register,BIT)  (Register^=(1<BIT))
/*Read Value For Specific bit*/
#define GET_BIT(Register,BIT)     ((Register>>BIT)& 0x01)
/*Checking about Specific Bit if equal Zero or not */
#define READ_ZERO(Register,BIT)   (Register&(1<<BIT))
/*Checking about Specific Bit if equal ONE or not */
#define READ_ONE(Register,BIT)   (!Register &(1<<BIT))
/*-------------------------------------------------------------------------------------*/
/*Access Port*/
/*Set Port in the Value */
#define SET_PORT(Register,Value)     (Register=Value)

/*Toggle Port in the Value */
#define TOGGLE_PORT(Register,Value)     (Register^=Value)




#endif /* BITMATH_H_ */
