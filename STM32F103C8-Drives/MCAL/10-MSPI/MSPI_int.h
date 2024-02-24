/********************************************************************************
* 	@file        		:  MSPI_int.h							 				*
*	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
*	@Version 			:  1.0.0							 					*
*	@Date				:  05/08/2023											*
*********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef MSPI_MSPI_INT_H_
#define MSPI_MSPI_INT_H_

/********************************************************************************
* Interface MACROS
********************************************************************************/
// PORT A
#define MSPI1_NSS_PIN		PIN4
#define MSPI1_CLK_PIN		PIN5
#define MSPI1_MISO_PIN		PIN6
#define MSPI1_MOSI_PIN		PIN7

//PORTB
#define MSPI2_NSS_PIN		PIN12
#define MSPI2_CLK_PIN		PIN13
#define MSPI2_MISO_PIN		PIN14
#define MSPI2_MOSI_PIN		PIN15

/********************************************************************************
* typedefs Struct
********************************************************************************/
typedef struct
{
	u16 copy_u16Txdata;
	u16* ptr_u16Rxdata;
	void (*callback_TxRx)(void);
}MSPI_CALLBACK_t;

/********************************************************************************
* typedefs Enum
********************************************************************************/
typedef enum
{
	MSPI1, MSPI2
}MSPI_t;

typedef enum
{
	MSPI_ERR_INT = 5,
	MSPI_RXNE_INT,
	MSPI_TXE_INT,

}MSPI_INT_t;

/********************************************************************************
* APIs Prototypes
********************************************************************************/

ErrorState_t MSPI_enMasterInit(MSPI_t copy_u8SPInum);
/********************************************************************************
* @fun name			:  MSPI_enMasterInit										*
* @para 	 		:  copy_u8SPInum											*
* @retval 			:  ErrorState (SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  Initialize all <pre>configuration of SPI Master			*
********************************************************************************/



ErrorState_t MSPI_enSlaveInit(MSPI_t copy_u8SPInum);
/********************************************************************************
* @fun name			:  MSPI_enSlaveInit											*
* @para 	 		:  copy_u8SPInum											*
* @retval 			:  ErrorState (SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  Initialize all <pre>configuration of SPI Slave			*
********************************************************************************/


ErrorState_t MSPI_enMasterSend(MSPI_t copy_u8SPInum, u16 copy_u16data);
/********************************************************************************
* @fun name			:  MSPI_enMasterSend										*
* @para 	 		:  copy_u8SPInum, copy_u16data								*
* @retval 			:  ErrorState (SUCCESS, OUT_OF_RANG_ERR)					*
* @Description  	:  SPI Master send data to Slave		 					*
********************************************************************************/


ErrorState_t MSPI_enSlaveReceive(MSPI_t copy_u8SPInum, u16 *ptr_u16data);
/********************************************************************************
* @fun name			:  MSPI_enSlaveReceive										*
* @para 	 		:  copy_u8SPInum, *ptr_u16data								*
* @retval 			:  ErrorState (SUCCESS, OUT_OF_RANG_ERR, NULL_PTR_ERR)		*
* @Description  	:  SPI Slave receive data from Master 						*
********************************************************************************/


ErrorState_t MSPI_enEnableInt(MSPI_t copy_u8SPInum, MSPI_INT_t copy_u8Intnum);
/********************************************************************************
* @fun name			:  MSPI_enEnableInt											*
* @para 	 		:  copy_u8SPInum, copy_u8Intnum								*
* @retval 			:  ErrorState (SUCCESS, OUT_OF_RANG_ERR)					*
* @Description  	:  Enable an SPI Interrupt 									*
********************************************************************************/


ErrorState_t MSPI_enDisableInt(MSPI_t copy_u8SPInum, MSPI_INT_t copy_u8Intnum);
/********************************************************************************
* @fun name			:  MSPI_enDisableInt										*
* @para 	 		:  copy_u8SPInum, copy_u8Intnum								*
* @retval 			:  ErrorState ( SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  Disable an SPI Interrupt  								*
********************************************************************************/


ErrorState_t MSPI_enIntCallBack(MSPI_t copy_u8SPInum, MSPI_CALLBACK_t *ptr_context);
/********************************************************************************
* @fun name			:  MSPI_enIntCallBack										*
* @para 	 		:  copy_u8SPInum, *ptr_context to struct					*
* @retval 			:  ErrorState (SUCCESS, NULL_PTR_ERR)						*
* @Description      :  CallBack to Execute APP fun from MCAL 					*
********************************************************************************/




#endif /* MSPI_MSPI_INT_H_ */
