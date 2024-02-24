/********************************************************************************
 * @file        		:  MSPI_prog.c								 			*
 * @Author 	 			:  HASSAN ABDELAZIM ABDELSALAM							*
 * @Version 			:  1.0.0							 					*
 * @Date				:  05/08/2023											*
 ********************************************************************************
 * @attention  SPI Driver Implementation for STM32F103C8
 *
 * This Driver support Polling and Interrupt driven data which is you can send
 * and receive data by waiting for corresponding flag or from App Callback
 * The Driver has 7 APIs which is SPI_MasterInit, SPI SlaveInit MasterSend,
 * SlaveReceive, Enable Interrupt, Disable Interrupt, Callback Interrupt fun
 *********************************************************************************
 * INCLUDES
 ********************************************************************************/
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "REGISTERS.h"
#include "BIT_MATH.h"
#include "MSPI_int.h"
#include "MSPI_config.h"
#include "MSPI_priv.h"

/********************************************************************************
 * GLOBAL VARIABLES
 ********************************************************************************/
/*Initialize static array of pointers of SPI base Address to SPI registers 	*/
static volatile SPI_REG_DEF_t* MSPI_CHANNELS[2] = {SPI1, SPI2};

/*Initialize an static array of Callback with two SPI Handlers elements */
static MSPI_CALLBACK_t MSPI_CALLBACK[2] = {0};

/********************************************************************************
 * APIs IMPLEMENTATION
 ********************************************************************************/
/* @brief	SPI Master Initialization of <pre> configuration settings,
 *			prescaler, DataSize, DataOrder, clk Phase, Polarity
 *			half/full Duplex, HW,SW Slave Select, Master mode
 * @param	copy_u8SPInum
 * @retval 	ErrorState (SUCCESS, OUT_OF_RANG_ERR)
 */
ErrorState_t MSPI_enMasterInit(MSPI_t copy_u8SPInum)
{
	ErrorState_t local_state = SUCCESS;

	if (copy_u8SPInum <= MSPI2)
	{
		/* 1. Set up the pre_configured Prescaler */
		MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1 &= MSPI_PRESCALER_MASK;
		MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1 |= MSPI_MASTER_PRESCALER << MSPI_PRESCALER_OFFSET;

		/*2. set up the pre_configured CLK Polarity */
#if(MSPI_MASTER_CLK_POL == MSPI_CLK_POL_LOW_IDLE)
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, CPOL);
#elif(MSPI_MASTER_CLK_POL == MSPI_CLK_POL_HIGH_IDLE)
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, CPOL);
#else
#error("INVALID CLOCK POLARITY");
#endif

		/*3. set up the pre_configured CLK Phase */
#if (MSPI_MASTER_CLK_PH == MSPI_CLK_PH_READ_WRITE)
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, CPHA);
#elif(MSPI_MASTER_CLK_PH == MSPI_CLK_PH_WRITE_READ)
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, CPHA);
#else
#error("INVALID CLOCK PHASE");
#endif

		/*4. set up the pre_configured Data Size  */
#if (MSPI_MASTER_DATA_FRAME == MSPI_DATA_FRAME_8BIT)
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, DFF);
#elif(MSPI_MASTER_DATA_FRAME == MSPI_DATA_FRAME_16BIT)
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, DFF);
#else
#error("INVALID DATA SIZE");
#endif

		/*5. set up the pre_configured Data Order  */
#if (MSPI_MASTER_DATA_ORDER == MSPI_DATA_ORDER_LSB)
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, FIRST_LSB);
#elif(MSPI_MASTER_DATA_ORDER == MSPI_DATA_ORDER_MSB)
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, FIRST_LSB);
#else
#error("INVALID DATA ORDER");
#endif

		/*6. set up the pre_configured Data Half/Full Duplex */
#if (MSPI_MASTER_DATA_WIRE == MSPI_HALF_DUPLEX_MODE)
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, BIDI_MODE);
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, BIDI_OE);

#elif(MSPI_MASTER_DATA_WIRE == MSPI_FULL_DUPLEX_MODE)
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, BIDI_MODE);
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, BIDI_OE);
#else
#error("INVALID DATA WIRE TX/RX ");
#endif

		/*7. set up the Slave select Management  */
#if (MSPI_MASTER_SSM_MODE	== MSPI_SW_SLAVE_SELECT)
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, SSM);
#elif(MSPI_MASTER_SSM_MODE ==	MSPI_HW_SLAVE_SELECT)
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, SSM);
#else
#error ("INVALID SLAVE SELECT ");
#endif

		/*8. set up  the operation Mode Master  */
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, MSTR);

		/*9. Enable the SPI Peripheral  */
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, SPE);
	}

	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}

/* @brief	SPI Slave Initialization of <pre> configuration settings,
 *			prescaler, DataSize, DataOrder, clk Phase, Polarity
 *			half/full Duplex, HW,SW Slave Select, slave mode
 * @param	copy_u8SPInum
 * @retval 	ErrorState (SUCCESS, OUT_OF_RANG_ERR)
 */
ErrorState_t MSPI_enSlaveInit(MSPI_t copy_u8SPInum)
{
	ErrorState_t local_state = SUCCESS;

	if (copy_u8SPInum <= MSPI2)
	{
		/* 1. Set up the pre_configured Prescaler */
		MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1 &= MSPI_PRESCALER_MASK;
		MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1 |= MSPI_SLAVE_PRESCALER << MSPI_PRESCALER_OFFSET;

		/*2. set up the pre_configured CLK Polarity */
#if(MSPI_SLAVE_CLK_POL == MSPI_CLK_POL_LOW_IDLE)
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, CPOL);
#elif(MSPI_SLAVE_CLK_POL == MSPI_CLK_POL_HIGH_IDLE)
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, CPOL);
#else
#error("INVALID CLOCK POLARITY");
#endif

		/*3. set up the pre_configured CLK Phase */
#if (MSPI_SLAVE_CLK_PH == MSPI_CLK_PH_READ_WRITE)
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, CPHA);
#elif(MSPI_SLAVE_CLK_PH == MSPI_CLK_PH_WRITE_READ)
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, CPHA);
#else
#error("INVALID CLOCK PHASE");
#endif

		/*4. set up the pre_configured Data Size  */
#if (MSPI_SLAVE_DATA_FRAME == MSPI_DATA_FRAME_8BIT)
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, DFF);
#elif(MSPI_SLAVE_DATA_FRAME == MSPI_DATA_FRAME_16BIT)
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, DFF);
#else
#error("INVALID DATA SIZE");
#endif

		/*5. set up the pre_configured Data Order  */
#if (MSPI_SLAVE_DATA_ORDER == MSPI_DATA_ORDER_LSB)
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, FIRST_LSB);
#elif(MSPI_SLAVE_DATA_ORDER == MSPI_DATA_ORDER_MSB)
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, FIRST_LSB);
#else
#error("INVALID DATA ORDER");
#endif

		/*6. set up the pre_configured Data Half/Full Duplex */
#if (MSPI_SLAVE_DATA_WIRE == MSPI_HALF_DUPLEX_MODE)
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, BIDI_MODE);
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, BIDI_OE);

#elif(MSPI_SLAVE_DATA_WIRE == MSPI_FULL_DUPLEX_MODE)
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, BIDI_MODE);
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, BIDI_OE);
#else
#error("INVALID DATA WIRE TX/RX ");
#endif

		/*7. set up the Slave select Management  */
#if (MSPI_SLAVE_SSM_MODE	== MSPI_SW_SLAVE_SELECT)
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, SSM);
#elif(MSPI_SLAVE_SSM_MODE ==	MSPI_HW_SLAVE_SELECT)
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, SSM);
#else
#error ("INVALID SLAVE SELECT ");
#endif

		/*8. set up  the operation as Slave  */
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, MSTR);

		/*9. Enable the SPI Peripheral  */
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR1, SPE);
	}

	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}
/* @brief	SPI Master send data to slave
 *
 * @param	copy_u8SPInum, copy_u16data
 * @retval	ErrorState (SUCCESS, OUT_OF_RANG_ERR)
 */
ErrorState_t MSPI_enMasterSend(MSPI_t copy_u8SPInum, u16 copy_u16data)
{
	ErrorState_t local_state = SUCCESS;

	if (copy_u8SPInum <= MSPI2)
	{
		/* 1. waiting for TX buffer to be Empty */
		while (!(GET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_SR, TXE)));

		/* 2. copy the data into the SPI data register */
		MSPI_CHANNELS[copy_u8SPInum]->SPI_DR = copy_u16data;

		/*3. waiting for the communication to be completed */
		while (GET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_SR, BSY));
	}

	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}



/* @brief	SPI slave receive data from Master
 *
 * @param	copy_u8SPInum, *ptr_u16data
 * @retval	ErrorState (SUCCESS, OUT_OF_RANG_ERR, NULL_PTR_ERR)
 */
ErrorState_t MSPI_enSlaveReceive(MSPI_t copy_u8SPInum, u16 *ptr_u16data)
{
	ErrorState_t local_state = SUCCESS;

	if (copy_u8SPInum <= MSPI2)
	{
		if (ptr_u16data != NULL)
		{
			/* 1. waiting for RX buffer to be Not Empty */
			while (!(GET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_SR, RXN)));

			/* 2. get the data from the SPI data register and assign it to ptr */
			*ptr_u16data = MSPI_CHANNELS[copy_u8SPInum]->SPI_DR ;
		}

		else
		{
			local_state = NULL_PTR_ERR;
		}
	}

	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}



/* @brief	SPI Enable the Corresponding Interrupt
 * 			TXEmpty, RXNEmpty and Error Interrupt
 *
 * @param	copy_u8SPInum, copy_u8Intnum
 * @retval	ErrorState (SUCCESS, OUT_OF_RANG_ERR)
 */
ErrorState_t MSPI_enEnableInt(MSPI_t copy_u8SPInum, MSPI_INT_t copy_u8Intnum)
{
	ErrorState_t local_state = SUCCESS;

	if ((copy_u8SPInum <= MSPI2)&&(copy_u8Intnum <= MSPI_TXE_INT) && (copy_u8Intnum>=MSPI_ERR_INT))
	{
		SET_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR2, copy_u8Intnum);
	}

	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}


/* @brief	SPI Enable the Corresponding Interrupt
 * 			TXEmpty, RXNEmpty and Error Interrupt
 *
 * @param	copy_u8SPInum, copy_u8Intnum
 * @retval	ErrorState (SUCCESS, OUT_OF_RANG_ERR)
 */
ErrorState_t MSPI_enDisableInt(MSPI_t copy_u8SPInum, MSPI_INT_t copy_u8Intnum)
{
	ErrorState_t local_state = SUCCESS;

	if ((copy_u8SPInum <= MSPI2)&&(copy_u8Intnum <= MSPI_TXE_INT) && (copy_u8Intnum>=MSPI_ERR_INT))
	{
		CLR_BIT(MSPI_CHANNELS[copy_u8SPInum]->SPI_CR2, copy_u8Intnum);
	}

	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}


/* @brief
 *
 * @param	copy_u8SPInum, *ptr_context
 * @retval	ErrorState (SUCCESS, OUT_OF_RANG_ERR, NULL_PTR_ERR)
 */
ErrorState_t MSPI_enIntCallBack(MSPI_t copy_u8SPInum, MSPI_CALLBACK_t *ptr_context)
{
	ErrorState_t local_state = SUCCESS;

	if (copy_u8SPInum <= MSPI2)
	{
		if (ptr_context != NULL)
		{
			MSPI_CALLBACK[copy_u8SPInum].callback_TxRx = ptr_context->callback_TxRx;
			MSPI_CALLBACK[copy_u8SPInum].copy_u16Txdata = ptr_context->copy_u16Txdata;
		}

		else
		{
			local_state = NULL_PTR_ERR;
		}

	}

	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}




/********************************************************************************
 * HANDLER IMPLEMENTATION
 ********************************************************************************/
/* @brief	Handler moods checks for any corresponding is fired and perform tasks
 * 			implementation add double check of interrupt if enabled to prevent any
 * 			undefined behavior and perform the App callback function
 *
 * @param	void
 * @retval	void
 */

void SPI1_IRQHandler(void)
{
	if (MSPI_CALLBACK[MSPI1].callback_TxRx!= NULL)
	{
		/* check if the Tx Buffer empty is fired, so copy the data and transmit it  */
		if ((GET_BIT(MSPI_CHANNELS[MSPI1]->SPI_SR, TXE))&&(GET_BIT(MSPI_CHANNELS[MSPI1]->SPI_CR2, MSPI_TXE_INT)))
		{
			MSPI_CHANNELS[MSPI1]->SPI_DR = MSPI_CALLBACK[MSPI1].copy_u16Txdata;
		}

		/* check if the Rx buffer Not empty is fired and ready to receive,so return the data  */
		else if ((GET_BIT(MSPI_CHANNELS[MSPI1]->SPI_SR, RXN))&&(GET_BIT(MSPI_CHANNELS[MSPI1]->SPI_CR2, MSPI_RXNE_INT)))
		{
			MSPI_CALLBACK[MSPI1].ptr_u16Rxdata = (u16*)MSPI_CHANNELS[MSPI1]->SPI_DR ;
		}

		/* check if the Mode Fault interrupt is fired, and notify it  */
		else if ((GET_BIT(MSPI_CHANNELS[MSPI1]->SPI_SR, MODF))&&(GET_BIT(MSPI_CHANNELS[MSPI1]->SPI_CR2, MSPI_ERR_INT)))
		{

		}

		/* check if the Mode Fault interrupt is fired, and notify it  */
		else if ((GET_BIT(MSPI_CHANNELS[MSPI1]->SPI_SR, OVR))&&(GET_BIT(MSPI_CHANNELS[MSPI1]->SPI_CR2, MSPI_ERR_INT)))
		{

		}
	}
	/* perform the Callback fun from the App */
	MSPI_CALLBACK[MSPI1].callback_TxRx();
}

void SPI2_IRQHandler(void)
{
	if (MSPI_CALLBACK[MSPI2].callback_TxRx!= NULL)
	{
		/* check if the Tx Buffer empty is fired, so copy the data and transmit it  */
		if ((GET_BIT(MSPI_CHANNELS[MSPI2]->SPI_SR, TXE))&&(GET_BIT(MSPI_CHANNELS[MSPI2]->SPI_CR2, MSPI_TXE_INT)))
		{
			MSPI_CHANNELS[MSPI2]->SPI_DR = MSPI_CALLBACK[MSPI2].copy_u16Txdata;
		}

		/* check if the Rx buffer Not empty is fired and ready to receive,so return the data  */
		else if ((GET_BIT(MSPI_CHANNELS[MSPI2]->SPI_SR, RXN))&&(GET_BIT(MSPI_CHANNELS[MSPI2]->SPI_CR2, MSPI_RXNE_INT)))
		{
			MSPI_CALLBACK[MSPI2].ptr_u16Rxdata = (u16*)MSPI_CHANNELS[MSPI2]->SPI_DR ;
		}

		/* check if the Mode Fault interrupt is fired, and notify it  */
		else if ((GET_BIT(MSPI_CHANNELS[MSPI2]->SPI_SR, MODF))&&(GET_BIT(MSPI_CHANNELS[MSPI2]->SPI_CR2, MSPI_ERR_INT)))
		{

		}

		/* check if the Mode Fault interrupt is fired, and notify it  */
		else if ((GET_BIT(MSPI_CHANNELS[MSPI2]->SPI_SR, OVR))&&(GET_BIT(MSPI_CHANNELS[MSPI2]->SPI_CR2, MSPI_ERR_INT)))
		{

		}
	}
	/* perform the Callback fun from the App */
	MSPI_CALLBACK[MSPI2].callback_TxRx();
}
