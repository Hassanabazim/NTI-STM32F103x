/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  MGPIO_int.h
 *         @Module	:  GPIO
 *
 *  Description: This file Provide the Module APIs and Interfacing MACROS and Data types
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HEADER GUARD
 *********************************************************************************************************************/
#ifndef MGPIO_MGPIO_INT_H_
#define MGPIO_MGPIO_INT_H_

#include "ERROR_STATE.h"
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
//MGPIO_ID to select either (PIN0 - PIN7) OR (PIN8 - PIN15)
typedef enum
{
	GPIO_CRL_ID,
	GPIO_CRH_ID
}MGPIO_ID_t;


//MGPIO_PORT to select either (PORTA,PORTB,PORTC)
typedef enum
{
	PORTA,
	PORTB,
	PORTC
}MGPIO_PORT_t;

//MGPIO_PIN to select from (PIN0...PIN15)
typedef enum
{
	PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7, PIN8, PIN9,
	PIN10, PIN11, PIN12, PIN13, PIN14, PIN15
}MGPIO_PIN_t;

// GPIO MODE & CONFIGURATION
typedef enum
{
	 IN_ANALOG,
	 OUT_10MHZ_PUSH_PULL,
	 OUT_2MHZ_PUSH_PULL,
	 OUT_50MHZ_PUSH_PULL,
	 IN_FLOATING,
	 OUT_10MHZ_OPEN_DRAIN,
	 OUT_2MHZ_OPEN_DRAIN,
	 OUT_50MHZ_OPEN_DRAIN,
	 IN_PULL_UP_PULL_DOWN,
	 OUT_10MHZ_AF_PUSH_PULL,
	 OUT_2MHZ_AF_PUSH_PULL,
	 OUT_50MHZ_AF_PUSH_PULL,
	 OUT_10MHZ_AF_OPEN_DRAIN = 13 ,
	 OUT_2MHZ_AF_OPEN_DRAIN	,
	 OUT_50MHZ_AF_OPEN_DRAIN
}MGPIO_DIR_t;

//MGIO_MGPIO_VALUE_t to select either (HIGH - LOW)
typedef enum
{
	LOW, HIGH
}MGPIO_VALUE_t;


//MGPIO_MODE to select either (RESET - SET)
typedef enum
{
	GPIO_PIN_RESET,
	GPIO_PIN_SET
}MGPIO_MODE_t;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

ErrorState_t MGPIO_enInit(void);
ErrorState_t MGPIO_enSetPinValue(MGPIO_PORT_t copy_u8port, MGPIO_PIN_t copy_u8pin, MGPIO_VALUE_t copy_u8Value);
ErrorState_t MGPIO_enTogglePin(MGPIO_PORT_t copy_u8port, MGPIO_PIN_t copy_u8pin);
ErrorState_t MGPIO_enGetPinValue(MGPIO_PORT_t copy_u8port, MGPIO_PIN_t copy_u8pin, MGPIO_VALUE_t *pinValue);
ErrorState_t MGPIO_enSetPortDirection(MGPIO_ID_t copy_u8CRID,MGPIO_PORT_t copy_u8port,  MGPIO_DIR_t copy_u8Dir);
ErrorState_t MGPIO_enSetPortValue(MGPIO_ID_t copy_u8CRID, MGPIO_PORT_t copy_u8port, MGPIO_VALUE_t copy_u8Value);
ErrorState_t MGPIO_enSetResetPin(MGPIO_PORT_t copy_u8port,MGPIO_PIN_t copy_u8pin, MGPIO_MODE_t copy_u8Mode);
ErrorState_t MGPIO_enLockPin(MGPIO_PORT_t copy_u8port, MGPIO_PIN_t copy_u8pin);



#endif /* MGPIO_MGPIO_INT_H_ */

/**********************************************************************************************************************
 *  END OF FILE: MGPIO_int.h
 *********************************************************************************************************************/

