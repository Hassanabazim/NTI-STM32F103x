/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  MGPIO_priv.h
 *         @Module	:  GPIO
 *
 *  Description:  This file provide a local MACROS/Functions
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HEADER GUARD
 *********************************************************************************************************************/
#ifndef MGPIO_MGPIO_PRIV_H_
#define MGPIO_MGPIO_PRIV_H_

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
//MOST USED PINS
#define LCKK 							16

//GPIO MASK&OFFSETS
#define MGPIO_MASK						0xF
#define MGPIO_OFFSET					4

//GPIO VALUES
#define MGPIO_CRL_MAX					8
#define MGPIO_CRH_MAX					16
#define MGPIO_PORT_OFFSET				0xFF
#define MGPIO_PORT_LVALUE				0x00FF
#define MGPIO_PORT_HVALUE				0xFF00
#define MGPIO_PORT_RESET				0x0


#endif /* MGPIO_MGPIO_PRIV_H_ */

/**********************************************************************************************************************
 *  END OF FILE: MGPIO_priv.h
 *********************************************************************************************************************/
