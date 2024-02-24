/********************************************************************************
* 	@file        		:  MSPI_priv.h							 				*
*	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
*	@Version 			:  1.0.0							 					*
*	@Date				:  05/08/2023											*
*********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef MSPI_MSPI_PRIV_H_
#define MSPI_MSPI_PRIV_H_


/********************************************************************************
* MOST USED REGISTER PINS
********************************************************************************/

//SPI_CR1 Register Pins

#define CPHA		0		//Clock phase
#define CPOL		1		//Clock polarity
#define MSTR		2		//Master selection
#define SPE			6		//SPI enable
#define FIRST_LSB	7		//Frame format
#define SSI			8		//Internal slave select
#define SSM			9		//Software slave management
#define RX_ONLY		10		//Receive only
#define DFF			11		//Data frame format
#define BIDI_OE		14		//Output enable in bidirectional mode
#define BIDI_MODE	15		//Bidirectional data mode enable


//SPI_CR2 Register Pins
#define RXDMAE		0		//Rx buffer DMA enable
#define TXDMAEN		1		//Tx buffer DMA enable
#define SSOE		2		//SS output enable


//SPI_SR Register Pins
#define RXN			0		//Receive buffer not empty
#define TXE			1		//Transmit buffer empty
#define MODF		5		//Mode fault
#define OVR			6		//Overrun flag
#define BSY			7		//Busy flag


/********************************************************************************
* PRIVATE MACROS CONFIGURATION
********************************************************************************/
#define MSPI_PRESCALER_DIV_2		0
#define MSPI_PRESCALER_DIV_4		1
#define MSPI_PRESCALER_DIV_8		2
#define MSPI_PRESCALER_DIV_16		3
#define MSPI_PRESCALER_DIV_32		4
#define MSPI_PRESCALER_DIV_64		5
#define MSPI_PRESCALER_DIV_128		6
#define MSPI_PRESCALER_DIV_256		7

#define MSPI_DATA_FRAME_8BIT		8
#define MSPI_DATA_FRAME_16BIT		9
#define MSPI_CLK_POL_LOW_IDLE		10
#define MSPI_CLK_POLHIGH_IDLE		11
#define MSPI_CLK_PH_READ_WRITE		12
#define MSPI_CLK_PH_WRITE_READ		13
#define MSPI_DATA_ORDER_MSB			14
#define MSPI_DATA_ORDER_LSB			15
#define MSPI_HALF_DUPLEX_MODE		16
#define MSPI_FULL_DUPLEX_MODE		17
#define MSPI_SW_SLAVE_SELECT		18
#define MSPI_HW_SLAVE_SELECT		19
#define MSPI_MASTER_SELECT			20
#define MSPI_SLAVE_SELECT			21
#define MSPI_SLAVE_RXONLY			22



/********************************************************************************
*  PRIVATE MACROS MASKS
********************************************************************************/
#define MSPI_PRESCALER_MASK	0xFFC7


/********************************************************************************
*  PRIVATE OFFSET MACROS
********************************************************************************/
#define MSPI_PRESCALER_OFFSET		3


#endif /* MSPI_MSPI_PRIV_H_ */
