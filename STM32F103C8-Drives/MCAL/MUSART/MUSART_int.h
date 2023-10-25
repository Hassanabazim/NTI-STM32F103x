/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  MUSART_int.h
 *         @Module	:  USART
 *
 *  Description:  This file Provide the Module APIs and Interfacing MACROS and Data types
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HEADER GUARD
 *********************************************************************************************************************/
#ifndef MUSART_MUSART_INT_H_
#define MUSART_MUSART_INT_H_

/**********************************************************************************************************************
*	INTERFACING MACROS
 *********************************************************************************************************************/
#define MUSART1_TX_PIN		PORTA, PIN9
#define MUSART1_RX_PIN		PORTA, PIN10

#define MUSART2_TX_PIN		PORTA, PIN2
#define MUSART2_RX_PIN		PORTA, PIN3

#define MUSART3_TX_PIN		PORTB, PIN10
#define MUSART3_RX_PIN		PORTB, PIN11

/**********************************************************************************************************************
*	GLOBAL MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
//USART CHANNELS (USART1 .. 3)
typedef enum
{
	MUSART1, MUSART2, MUSART3
}MUSART_t;


//USART INTRRUPTS
typedef enum
{
	Error_INT,
	IDLE_INT = 4,
	RXNEmpty_INT,
	TXCompelete_INT,
	TXEmpty_INT,
	ParityEror_INT,
}MUSART_INT_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

ErrorState_t MUSART_enInit(MUSART_t copy_u8USARTnum);
ErrorState_t MUSART_enBusySendByte(MUSART_t copy_u8USARTnum, u8 copy_u8Data);
ErrorState_t MUSART_enSendMessage(MUSART_t copy_u8USARTnum, u8 *copy_u8msg);
ErrorState_t MUSART_enBusyReceiveByte(MUSART_t copy_u8USARTnum, u8 *ptr_u8Data);
ErrorState_t MUSART_enEnableInt(MUSART_t copy_u8USARTnum, MUSART_INT_t copy_u8Intnum);
ErrorState_t MUSART_enDisableInt(MUSART_t copy_u8USARTnum, MUSART_INT_t copy_u8Intnum);
ErrorState_t MUSART_enSendMessage(MUSART_t copy_u8USARTnum, u8 *copy_u8msg);
ErrorState_t MUSART_enReceieveMessage(MUSART_t copy_u8USARTnum, u8 *copy_u8msg);
ErrorState_t MUSART_enIntCallBack(MUSART_t copy_u8USARTnum, void (*ptr)(void));



#endif /* MUSART_MUSART_INT_H_ */
/**********************************************************************************************************************
 *  END OF FILE:   MUSART_int.h
 *********************************************************************************************************************/
