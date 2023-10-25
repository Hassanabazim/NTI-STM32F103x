/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  MUSART_priv.h
 *         @Module	:  USART
 *
 *  Description:  This file provide a local MACROS/Functions
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HEADER GUARD
 *********************************************************************************************************************/
#ifndef MUSART_MUSART_PRIV_H_
#define MUSART_MUSART_PRIV_H_


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
// CR1 REGISTER PINS
#define UE		                          13
#define M		                          12
#define PCE		                          10
#define PS 		                          9
#define TE 		                          3
#define RE 		                          2

// SR REGISTER PINS
#define TXE		                          7
#define TC		                          6
#define RXNE	                          5
#define IDLE	                          4
#define ORE		                          3
#define NE		                          2
#define FE		                          1
#define PE		                          0

// CR3 REGISTER PINS
#define HDSE	                          3

// BAUDRATE CONFIGURATION
#define MUSART_BAUDRATE_1200_CLK_8M       0X1A0B
#define MUSART_BAUDRATE_2400_CLK_8M       0X0D05
#define MUSART_BAUDRATE_4800_CLK_8M       0X0683
#define MUSART_BAUDRATE_9600_CLK_8M       0X0341
#define MUSART_BAUDRATE_19200_CLK_8M      0X01A1

// PRE FRAME CONGIFURATION
#define MUSART_PARITY_DISABLE	          1
#define MUSART_PARITY_EVEN		          3
#define MUSART_PARITY_ODD		          4
#define MUSART_8BIT_DATA		          5
#define MUSART_9BIT_DATA		          6
#define MUSART_HALF_DUPLEX		          7
#define MUSART_FULL_DUPLEX		          8
#define MUSART_STOPBIT1			          0
#define MUSART_STOPBIT2			          2
#define MUSART_MAX_LINES				  3
#define MUSART_NULL_CHR					'\0'

//PRIVATE MACROS MASKS
#define MUSART_1BYTE			          0xFF
#define MUSART_9BIT				          0x1FF
#define MUSART_STOPBITS_MASK	          0XFFFCFFF



#endif /* MUSART_MUSART_PRIV_H_ */
/**********************************************************************************************************************
 *  END OF FILE:  MUSART_int.h
 *********************************************************************************************************************/

