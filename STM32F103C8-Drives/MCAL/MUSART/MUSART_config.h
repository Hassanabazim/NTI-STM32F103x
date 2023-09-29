/********************************************************************************
* 	@file        		:  MUSART_config.h							 			*
*	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
*	@Version 			:  1.0.0							 					*
*	@Date				:  03/08/2023											*
*********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef MUSART_MUSART_CONFIG_H_
#define MUSART_MUSART_CONFIG_H_

/********************************************************************************
* PLEASE CHOOSE USART WIRE MODE FROM THE FOLLOWING:
*
*	MUSART_HALF_DUPLEX
* 	MUSART_FULL_DUPLEX
*
********************************************************************************/
#define MUSART_WIRE_MODE		MUSART_FULL_DUPLEX



/********************************************************************************
* PLEASE CHOOSE USART DATA SIZE FROM THE FOLLOWING:
*
*	MUSART_8BIT_DATA
* 	MUSART_9BIT_DATA
*
********************************************************************************/
#define MUSART_DATA_SIZE		MUSART_8BIT_DATA



/********************************************************************************
* PLEASE CHOOSE USART PARITY MODE FROM THE FOLLOWING:
*
*	MUSART_PARITY_DISABLE
*	MUSART_PARITY_EVEN
* 	MUSART_PARITY_ODD
*
********************************************************************************/
#define MUSART_PARITY_MODE		MUSART_PARITY_DISABLE



/********************************************************************************
* PLEASE CHOOSE USART STOP BIT NUMBER FROM THE FOLLOWING:
*
*	MUSART_STOPBIT1
* 	MUSART_STOPBIT2
*
********************************************************************************/
#define MUSART_STOPBIT_NUM		MUSART_STOPBIT1


/********************************************************************************
* PLEASE CHOOSE USART BAUDRATE FROM THE FOLLOWING:
*
*	MUSART_BAUDRATE_1200_CLK_8M
*	MUSART_BAUDRATE_2400_CLK_8M
*	MUSART_BAUDRATE_4800_CLK_8M
*	MUSART_BAUDRATE_9600_CLK_8M
*	MUSART_BAUDRATE_19200_CLK_8M
*
********************************************************************************/
#define MUSART_BAUDRATE			MUSART_BAUDRATE_9600_CLK_8M



#endif /* MUSART_MUSART_CONFIG_H_ */