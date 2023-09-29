/********************************************************************************
* 	@file        		:  MUSART_int.h							 				*
*	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
*	@Version 			:  1.0.0							 					*
*	@Date				:  03/08/2023											*
*********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef MUSART_MUSART_INT_H_
#define MUSART_MUSART_INT_H_

/********************************************************************************
* Interface MACRO
********************************************************************************/
#define MUSART_TX_PIN		PIN9
#define MUSART_RX_PIN		PIN10

/********************************************************************************
* typedefs Struct
********************************************************************************/
/* struct of Callback Interrupts */
typedef struct
{
	u8 *copy_u8Rxdata;
	u8 copy_u8Txdata;
	void (*TxRx_callback)(void);
}MUSART_Callback_t;


/********************************************************************************
* typedefs Enums
********************************************************************************/
/* Definition of USART CHANNELS (USART1 .. 3) */
typedef enum
{
	MUSART1, MUSART2, MUSART3
}MUSART_t;


/* DEfinition of USART INTRRUPTS */
typedef enum
{
	Error_INT,
	IDLE_INT = 4,
	RXNEmpty_INT,
	TXCompelete_INT,
	TXEmpty_INT,
	ParityEror_INT,
}MUSART_INT_t;

/********************************************************************************
* APIs Prototypes
********************************************************************************/

ErrorState_t MUSART_enInit(MUSART_t copy_u8USARTnum);
/********************************************************************************
* @fun name			:  MUSART_enInit											*
* @para 	 		:  copy_u8USARTnum											*
* @retval 			:  ErrorState ( SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  Initialize all <pre>configuration of USART Frame 		*
* 		 																		*
********************************************************************************/


ErrorState_t MUSART_enBusySendByte(MUSART_t copy_u8USARTnum, u8 copy_u8Data);
/********************************************************************************
* @fun name			:  MUSART_enBusySendByte									*
* @para 	 		:  copy_u8USARTnum, copy_u8Data								*
* @retval 			:  ErrorState ( SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  USART Transmit Byte data 								*
********************************************************************************/



ErrorState_t MUSART_enBusySendString(MUSART_t copy_u8USARTnum, char *copy_u8Data);
/********************************************************************************
* @fun name			:  MUSART_enBusySendString									*
* @para 	 		:  copy_u8USARTnum, *copy_u8Data							*
* @retval 			:  ErrorState (SUCCESS, OUT_OF_RANG_ERR, NULL_PTR_ERR)		*
* @Description  	:  USART Transmit String of Byte data 						*
********************************************************************************/


ErrorState_t MUSART_enBusyReceiveByte(MUSART_t copy_u8USARTnum, u8 *ptr_u8Data);
/********************************************************************************
* @fun name			:  MUSART_enBusyReceiveByte									*
* @para 	 		:  copy_u8USARTnum, *ptr_u8Data								*
* @retval 			:  ErrorState (SUCCESS, OUT_OF_RANG_ERR, NULL_PTR_ERR)		*
* @Description  	:  USART Receive Byte of Data 						  		*
********************************************************************************/



ErrorState_t MUSART_enEnableInt(MUSART_t copy_u8USARTnum, MUSART_INT_t copy_u8Intnum);
/********************************************************************************
* @fun name			:  MUSART_enEnableInt										*
* @para 	 		:  copy_u8USARTnum, copy_u8Intnum							*
* @retval 			:  ErrorState (SUCCESS, OUT_OF_RANG_ERR)					*
* @Description  	:  Enable an USART Interrupt 								*
********************************************************************************/



ErrorState_t MUSART_enDisableInt(MUSART_t copy_u8USARTnum, MUSART_INT_t copy_u8Intnum);
/********************************************************************************
* @fun name			:  MUSART_enDisableInt										*
* @para 	 		:  copy_u8USARTnum, copy_u8Intnum							*
* @retval 			:  ErrorState ( SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  Disable an USART Interrupt  								*
********************************************************************************/



ErrorState_t MUSART_enIntCallBack(MUSART_t copy_u8USARTnum, MUSART_Callback_t *copy_u8context);
/********************************************************************************
* @fun name			:  MUSART_enIntCallBack, 									*
* @para 	 		:  copy_u8USARTnum, ptr to function							*
* @retval 			:  ErrorState (SUCCESS, NULL_PTR_ERR)						*
* @Description      :  CallBack to Execute APP fun from MCAL 					*
********************************************************************************/




#endif /* MUSART_MUSART_INT_H_ */
