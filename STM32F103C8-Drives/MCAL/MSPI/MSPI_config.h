/********************************************************************************
* 	@file        		:  MSPI_config.h							 			*
*	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
*	@Version 			:  1.0.0							 					*
*	@Date				:  03/08/2023											*
*********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef MSPI_MSPI_CONFIG_H_
#define MSPI_MSPI_CONFIG_H_

/********************************************************************************
* PLEASE CHOOSE SPI PRESCALER FROM THE FOLLOWING:
*
*	MSPI_PRESCALER_DIV_2
* 	MSPI_PRESCALER_DIV_4
* 	MSPI_PRESCALER_DIV_8
* 	MSPI_PRESCALER_DIV_16
* 	MSPI_PRESCALER_DIV_32
* 	MSPI_PRESCALER_DIV_64
* 	MSPI_PRESCALER_DIV_128
*	MSPI_PRESCALER_DIV_256
********************************************************************************/
#define MSPI_MASTER_PRESCALER			MSPI_PRESCALER_DIV_2
#define MSPI_SLAVE_PRESCALER			MSPI_PRESCALER_DIV_2



/********************************************************************************
* PLEASE CHOOSE DATA FRAME FROM THE FOLLOWING:
*
* MSPI_DATA_FRAME_8BIT
* MSPI_DATA_FRAME_16BIT
********************************************************************************/
#define MSPI_MASTER_DATA_FRAME			MSPI_DATA_FRAME_8BIT
#define MSPI_SLAVE_DATA_FRAME			MSPI_DATA_FRAME_8BIT



/********************************************************************************
* PLEASE CHOOSE CLOCK POLARITY FROM THE FOLLOWING:
*
*	 MSPI_CLK_POL_LOW_IDLE
*	 MSPI_CLK_POLHIGH_IDLE
********************************************************************************/
#define MSPI_MASTER_CLK_POL				MSPI_CLK_POL_LOW_IDLE
#define MSPI_SLAVE_CLK_POL				MSPI_CLK_POL_LOW_IDLE



/********************************************************************************
* PLEASE CHOOSE	CLK PHASE FROM THE FOLLOWING:
*
*	MSPI_CLK_PH_READ_WRITE
* 	MSPI_CLK_PH_WRITE_READ
********************************************************************************/
#define MSPI_MASTER_CLK_PH				MSPI_CLK_PH_WRITE_READ
#define MSPI_SLAVE_CLK_PH				MSPI_CLK_PH_WRITE_READ



/********************************************************************************
* PLEASE CHOOSE DATA ORDER FROM THE FOLLOWING:
*
* 	MSPI_DATA_ORDER_MSB
*	MSPI_DATA_ORDER_LSB
********************************************************************************/
#define MSPI_MASTER_DATA_ORDER			MSPI_DATA_ORDER_MSB
#define MSPI_SLAVE_DATA_ORDER			MSPI_DATA_ORDER_MSB



/********************************************************************************
* PLEASE CHOOSE DATA WIRE TX,RX FROM THE FOLLOWING:
*
* 	MSPI_HALF_DUPLEX_MODE
*	MSPI_FULL_DUPLEX_MODE
*
********************************************************************************/
#define MSPI_MASTER_DATA_WIRE			MSPI_FULL_DUPLEX_MODE
#define MSPI_SLAVE_DATA_WIRE			MSPI_FULL_DUPLEX_MODE



/********************************************************************************
* PLEASE CHOOSE SLAVE SELECT MANGEMENT FROM THE FOLLOWING:
*
* 	MSPI_SW_SLAVE_SELECT
*	MSPI_HW_SLAVE_SELECT
********************************************************************************/
#define MSPI_MASTER_SSM_MODE			MSPI_HW_SLAVE_SELECT
#define MSPI_SLAVE_SSM_MODE				MSPI_HW_SLAVE_SELECT




#endif /* MSPI_MSPI_CONFIG_H_ */
