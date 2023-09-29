/********************************************************************************
 * @file        		:  MUSART_prog.c								 		*
 * @Author 	 			:  HASSAN ABDELAZIM ABDELSALAM							*
 * @Version 			:  1.0.0							 					*
 * @Date				:  03/08/2023											*
 ********************************************************************************
 * @attention  USART Driver Implementation for STM32F103C8
 *
 * This Driver support Polling and Interrupt driven data which is you can send
 * and receive data by waiting for corresponding flag or from App Callback
 * The Driver has 7-APIS, Driver Init, Send, Receive 1 Byte or string of Bytes
 * Enable, Disable and Interrupt CallBack fun for TX,RX,Err handling
 *
 *********************************************************************************
 * INCLUDES
 ********************************************************************************/
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "REGISTERS.h"
#include "BIT_MATH.h"
#include "MUSART_int.h"
#include "MUSART_config.h"
#include "MUSART_priv.h"

/********************************************************************************
 * GLOBAL STATIC VARIABLES
 ********************************************************************************/
/* Initialize an array of three pointers of USART Channels to Registers */
static volatile USART_REG_DEF_t* USART_CH[3] = {USART1, USART2, USART3};

/* Initialize an array of three callback pointer has APP fun Address */
static MUSART_Callback_t Callback_CH[3] = {0};

/********************************************************************************
 * APIs IMPLEMENTATION
 ********************************************************************************/

/*
 *@brief 	MUSART Initialize all <pre> configuration of USART Frame
 *			Half Duplex or Full Duplex, Parity even or odd or Disabled
 *		 	8bit or 9bit Data Frame, 1bit or 2bit Stop bit
 *		 	Select the Required BaudRate,Enable TX,RX,USART
 *
 *@param 	copy_u8USARTnum
 *@retval 	ErrorState ( SUCCESS, OUT_OF_RANG_ERR)
 *
 */
ErrorState_t MUSART_enInit(MUSART_t copy_u8USARTnum)
{
	ErrorState_t local_state = SUCCESS;
	if (copy_u8USARTnum <= MUSART3)
	{
		/* 1. Select USART FULL OR HALF DUPLEX */
#if (MUSART_WIRE_MODE == USART_HALF_DUPLEX)
		SET_BIT(USART_CH[copy_u8USARTnum]->USART_CR3, HDSE);
#elif (MUSART_WIRE_MODE == MUSART_FULL_DUPLEX)
		CLR_BIT(USART_CH[copy_u8USARTnum]->USART_CR3, HDSE);
#else
#error("INVALID USART1 WIRE MODE");
#endif

		/*2. Select 8BIT OR 9BIT DATA FRAME */
#if (MUSART_DATA_SIZE == MUSART_8BIT_DATA)
		CLR_BIT(USART_CH[copy_u8USARTnum]->USART_CR1, M);
#elif(MUSART_DATA_SIZE == MUSART_9BIT_DATA)
		SET_BIT(USART_CH[copy_u8USARTnum]->USART_CR1, M);
#else
#error("INVALID USART1 DATA SIZE");
#endif

		/* 3.Select ODD OR EVEN OR DISABLED PARITY*/
#if (MUSART_PARITY_MODE == MUSART_PARITY_EVEN)
		SET_BIT(USART_CH[copy_u8USARTnum]->USART_CR1, PCE);
		CLR_BIT(USART_CH[copy_u8USARTnum]->USART_CR1, PS);

#elif(MUSART_PARITY_MODE == MUSART_PARITY_ODD)
		SET_BIT(USART_CH[copy_u8USARTnum]->USART_CR1, PCE);
		SET_BIT(USART_CH[copy_u8USARTnum]->USART_CR1, PS);

#elif (MUSART_PARITY_MODE == MUSART_PARITY_DISABLE)
		CLR_BIT(USART_CH[copy_u8USARTnum]->USART_CR1, PCE);
#else
#error("INVALID USART1 PARITY MODE");
#endif
		/* 4. Select 1BIT OR 2BIT STOP BITS */
		USART_CH[copy_u8USARTnum]->USART_CR2 &= MUSART_STOPBITS_MASK;
		USART_CH[copy_u8USARTnum]->USART_CR2 |= MUSART_STOPBIT_NUM << 12;

		/* 5. Select The Requirement Baud Rate */
		USART_CH[copy_u8USARTnum]->USART_BRR = 0x341;

		/* 6. Enable The Transmission Mode */
		SET_BIT(USART_CH[copy_u8USARTnum]->USART_CR1, TE);
		/* 7. Enable The Receiver Mode */
		SET_BIT(USART_CH[copy_u8USARTnum]->USART_CR1, RE);
		/* 8. Enable The USART Peripheral */
		SET_BIT(USART_CH[copy_u8USARTnum]->USART_CR1, UE);

		/* 9. Clear the USART Flags Register */
		USART_CH[copy_u8USARTnum]->USART_SR = 0;
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}
	return local_state;
}

/*
 *@brief 	MUSART SendByte use the Polling Technique to transmit the data
 *			Capture the CPU of waiting Corresponding Flag
 *
 *@param 	copy_u8USARTnum, copy_u8Data
 *@retval 	ErrorState ( SUCCESS, OUT_OF_RANG_ERR)
 *
 */
ErrorState_t MUSART_enBusySendByte(MUSART_t copy_u8USARTnum, u8 copy_u8Data)
{
	ErrorState_t local_state = SUCCESS;
	if (copy_u8USARTnum <= MUSART3)
	{
		/* 1. waiting of TX Empty Flag to be set */
		while (!(GET_BIT(USART_CH[copy_u8USARTnum]->USART_SR, TXE)));
		/* 2. copy the Data into the USART Data Register */
		USART_CH[copy_u8USARTnum]->USART_DR = copy_u8Data;
		/* 3. waiting of TX Complete Flag to be set */
		while (!(GET_BIT(USART_CH[copy_u8USARTnum]->USART_SR, TC)));
		/* Clear the TX Complete flag by writing 0 into it */
		CLR_BIT(USART_CH[copy_u8USARTnum]->USART_SR, TC);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}

/*
 *@brief 	MUSART SendString use the Polling Technique to transmit the data
 *			Byte by Byte, Capture the CPU of waiting Corresponding Flag
 *
 *@param 	copy_u8USARTnum, *copy_u8Data
 *@retval 	ErrorState (SUCCESS, OUT_OF_RANG_ERR, NULL_PTR_ERR)
 *
 */
ErrorState_t MUSART_enBusySendString(MUSART_t copy_u8USARTnum, char *copy_u8Data)
{
	ErrorState_t local_state = SUCCESS;
	/* 1. Initialize a local counter to iterate through the string */
	u8 local_u8Counter = 0;
	if (copy_u8USARTnum <= MUSART3)
	{
		if (copy_u8Data != NULL)
			/* 2. check the end of the string if has NULL CHR or Not, if Not iterate */
			while (copy_u8Data[local_u8Counter] != '\0')
			{
				/* 3. Send Byte by Byte of string indexed by local Counter */
				MUSART_enBusySendByte(copy_u8USARTnum, copy_u8Data[local_u8Counter]);
				/* 4. count up the local counter */
				local_u8Counter++;
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

/*
 *@brief 	MUSART ReceiveByte use the Polling Technique to Receive the data
 *			Capture the CPU of waiting Corresponding Flag
 *
 *@param 	copy_u8USARTnum, *copy_u8Data
 *@retval 	ErrorState (SUCCESS, OUT_OF_RANG_ERR, NULL_PTR_ERR)
 *
 */
ErrorState_t MUSART_enBusyReceiveByte(MUSART_t copy_u8USARTnum, u8 *ptr_u8Data)
{
	ErrorState_t local_state = SUCCESS;
	if (copy_u8USARTnum <= MUSART3)
	{
		if (ptr_u8Data != NULL)
		{
			/* 1. waiting of RX Not Empty Flag to be set */
			while (!(GET_BIT(USART_CH[copy_u8USARTnum]->USART_SR, RXNE)));
			/* 2. get the Data from Data Register AND with 1Byte
			 * Assign the value into the ptr_u8Data to be returned as ptr
			 * the flag is cleared by reading the Data from the register
			 */
			*ptr_u8Data = USART_CH[copy_u8USARTnum]->USART_DR & MUSART_1BYTE;
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

/*
 *@brief 	MUSART Enable Interrupt of the Corresponding Event
 *			Error, IDLE, RXNEmpty, TXCompelete, TXEmpty, ParityEror Interrupt
 *
 *@param 	copy_u8USARTnum, copy_u8Intnum
 *@retval 	ErrorState ( SUCCESS, OUT_OF_RANG_ERR)
 *
 */
ErrorState_t MUSART_enEnableInt(MUSART_t copy_u8USARTnum, MUSART_INT_t copy_u8Intnum)
{
	ErrorState_t local_state = SUCCESS;
	if ((copy_u8Intnum >= IDLE_INT) && (copy_u8Intnum <= ParityEror_INT)&& copy_u8USARTnum <= MUSART3)
	{
		SET_BIT(USART_CH[copy_u8USARTnum]->USART_CR1, copy_u8Intnum);
	}
	else if (copy_u8Intnum == Error_INT)
	{
		SET_BIT(USART_CH[copy_u8USARTnum]->USART_CR3, copy_u8Intnum);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}
	return local_state;
}

/*
 *@brief 	MUSART Disable Interrupt of the Corresponding Event
 *			Error, IDLE, RXNEmpty, TXCompelete, TXEmpty, ParityEror Interrupt
 *
 *@param 	copy_u8USARTnum, copy_u8Intnum
 *@retval 	ErrorState ( SUCCESS, OUT_OF_RANG_ERR)
 *
 */
ErrorState_t MUSART_enDisableInt(MUSART_t copy_u8USARTnum, MUSART_INT_t copy_u8Intnum)
{
	ErrorState_t local_state = SUCCESS;
	if ((copy_u8Intnum >= IDLE_INT) && (copy_u8Intnum <= ParityEror_INT)&& copy_u8USARTnum <= MUSART3)
	{
		CLR_BIT(USART_CH[copy_u8USARTnum]->USART_CR1, copy_u8Intnum);
	}
	else if (copy_u8Intnum == Error_INT)
	{
		SET_BIT(USART_CH[copy_u8USARTnum]->USART_CR3, copy_u8Intnum);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}
	return local_state;
}

/*
 *@brief 	MUSART Interrupt callBack of the Corresponding Event
 *			Error, IDLE, RXNEmpty, TXCompelete, TXEmpty, ParityEror Interrupt
 *
 *@param 	copy_u8USARTnum, ptr to function
 *@retval 	ErrorState ( SUCCESS, OUT_OF_RANG_ERR)
 *
 */
ErrorState_t MUSART_enIntCallBack(MUSART_t copy_u8USARTnum, MUSART_Callback_t *copy_u8context)
{
	ErrorState_t local_state = SUCCESS;

	if (copy_u8context != NULL)
	{
		/* callback fun of Channel Index has a address of Application fun */
		Callback_CH[copy_u8USARTnum].TxRx_callback = copy_u8context->TxRx_callback;
		Callback_CH[copy_u8USARTnum].copy_u8Txdata = copy_u8context->copy_u8Txdata;
	}
	else
	{
		local_state = NULL_PTR_ERR;
	}

	return local_state;
}

/********************************************************************************
 * HANDLEAR IMPLEMENTATION
 ********************************************************************************/
/*
 *@brief 	USART1,2,3_IQHandler when any Interrupt happens,
 *		 	going to Handler Mood and Execute Application function
 *
 *@param 	void
 *@retval 	void
 *
 */
void USART1_IRQHandler (void)
{
	if (Callback_CH[MUSART1].TxRx_callback != NULL)
	{
		/* check if the IDLE Interrupt is fired */
		if ((GET_BIT(USART_CH[MUSART1]->USART_SR,IDLE))&&(GET_BIT(USART_CH[MUSART1]->USART_CR1,IDLE_INT)))
		{

		}

		/* check if the TXE is fired */
		if ((GET_BIT(USART_CH[MUSART1]->USART_SR,TXE))&&(GET_BIT(USART_CH[MUSART1]->USART_CR1,TXEmpty_INT)))
		{
			/* transmit the data */
			USART_CH[MUSART1]->USART_DR = Callback_CH[MUSART1].copy_u8Txdata;
		}

		/* check if the TC is fired */
		else if ((GET_BIT(USART_CH[MUSART1]->USART_SR,TC))&&(GET_BIT(USART_CH[MUSART1]->USART_CR1,TXCompelete_INT)))
		{
			/* Clear the TC Flag by software */
			CLR_BIT(USART_CH[MUSART1]->USART_SR, TC);
		}

		/* check if the RXNE is fired */
		else if ((GET_BIT(USART_CH[MUSART1]->USART_SR,RXNE))&&(GET_BIT(USART_CH[MUSART1]->USART_CR1,RXNEmpty_INT)))
		{
			/* receive the data */
			Callback_CH[MUSART1].copy_u8Rxdata = (u8*)USART_CH[MUSART1]->USART_DR ;
		}

		/* check if the parity error Interrupt is fired */
		else if ((GET_BIT(USART_CH[MUSART1]->USART_SR,PE))&&(GET_BIT(USART_CH[MUSART1]->USART_CR1,ParityEror_INT)))
		{

		}

		/* check if the frame error Interrupt is fired */
		else if ((GET_BIT(USART_CH[MUSART1]->USART_SR,FE))&&(GET_BIT(USART_CH[MUSART1]->USART_CR3,Error_INT)))
		{

		}

		/* check if the overrun error Interrupt is fired */
		else if ((GET_BIT(USART_CH[MUSART1]->USART_SR,ORE))&&(GET_BIT(USART_CH[MUSART1]->USART_CR1,RXNEmpty_INT)))
		{

		}

		/* check if the noise error Interrupt is fired */
		else if ((GET_BIT(USART_CH[MUSART1]->USART_SR,NE))&&(GET_BIT(USART_CH[MUSART1]->USART_CR3,Error_INT)))
		{

		}

		/* perform Action Callback */
		Callback_CH[MUSART1].TxRx_callback();
	}
}

void USART2_IRQHandler (void)
{
	if (Callback_CH[MUSART2].TxRx_callback != NULL)
	{
		/* check if the IDLE Interrupt is fired */
		if ((GET_BIT(USART_CH[MUSART2]->USART_SR,IDLE))&&(GET_BIT(USART_CH[MUSART2]->USART_CR1,IDLE_INT)))
		{

		}

		/* check if the TXE is fired */
		if ((GET_BIT(USART_CH[MUSART2]->USART_SR,TXE))&&(GET_BIT(USART_CH[MUSART2]->USART_CR1,TXEmpty_INT)))
		{
			/* transmit the data */
			USART_CH[MUSART2]->USART_DR = Callback_CH[MUSART2].copy_u8Txdata;
		}

		else if ((GET_BIT(USART_CH[MUSART2]->USART_SR,TC))&&(GET_BIT(USART_CH[MUSART2]->USART_CR1,TXCompelete_INT)))
		{
			/* Clear the TC Flag by software */
			CLR_BIT(USART_CH[MUSART2]->USART_SR, TC);
		}

		/* check if the RXNE is fired */
		else if ((GET_BIT(USART_CH[MUSART2]->USART_SR,RXNE))&&(GET_BIT(USART_CH[MUSART2]->USART_CR1,RXNEmpty_INT)))
		{
			/* receive the data */
			Callback_CH[MUSART2].copy_u8Rxdata = (u8*)USART_CH[MUSART1]->USART_DR ;
		}

		/* check if the parity error Interrupt is fired */
		else if ((GET_BIT(USART_CH[MUSART2]->USART_SR,PE))&&(GET_BIT(USART_CH[MUSART2]->USART_CR1,ParityEror_INT)))
		{

		}

		/* check if the frame error Interrupt is fired */
		else if ((GET_BIT(USART_CH[MUSART2]->USART_SR,FE))&&(GET_BIT(USART_CH[MUSART2]->USART_CR3,Error_INT)))
		{

		}

		/* check if the overrun error Interrupt is fired */
		else if ((GET_BIT(USART_CH[MUSART2]->USART_SR,ORE))&&(GET_BIT(USART_CH[MUSART2]->USART_CR1,RXNEmpty_INT)))
		{

		}

		/* check if the noise error Interrupt is fired */
		else if ((GET_BIT(USART_CH[MUSART2]->USART_SR,NE))&&(GET_BIT(USART_CH[MUSART2]->USART_CR3,Error_INT)))
		{

		}

		/* perform Action Callback */
		Callback_CH[MUSART2].TxRx_callback();
	}
}

void USART3_IRQHandler (void)
{
	if (Callback_CH[MUSART3].TxRx_callback != NULL)
	{
		/* check if the IDLE Interrupt is fired */
		if ((GET_BIT(USART_CH[MUSART3]->USART_SR,IDLE))&&(GET_BIT(USART_CH[MUSART3]->USART_CR1,IDLE_INT)))
		{

		}

		/* check if the TXE is fired */
		if ((GET_BIT(USART_CH[MUSART3]->USART_SR,TXE))&&(GET_BIT(USART_CH[MUSART3]->USART_CR1,TXEmpty_INT)))
		{
			/* transmit the data */
			USART_CH[MUSART3]->USART_DR = Callback_CH[MUSART3].copy_u8Txdata;
		}

		else if ((GET_BIT(USART_CH[MUSART3]->USART_SR,TC))&&(GET_BIT(USART_CH[MUSART3]->USART_CR1,TXCompelete_INT)))
		{
			/* Clear the TC Flag by software */
			CLR_BIT(USART_CH[MUSART3]->USART_SR, TC);
		}

		/* check if the RXNE is fired */
		else if ((GET_BIT(USART_CH[MUSART3]->USART_SR,RXNE))&&(GET_BIT(USART_CH[MUSART3]->USART_CR1,RXNEmpty_INT)))
		{
			/* receive the data */
			Callback_CH[MUSART3].copy_u8Rxdata = (u8*)USART_CH[MUSART1]->USART_DR ;
		}

		/* check if the parity error Interrupt is fired */
		else if ((GET_BIT(USART_CH[MUSART3]->USART_SR,PE))&&(GET_BIT(USART_CH[MUSART3]->USART_CR1,ParityEror_INT)))
		{

		}

		/* check if the frame error Interrupt is fired */
		else if ((GET_BIT(USART_CH[MUSART3]->USART_SR,FE))&&(GET_BIT(USART_CH[MUSART3]->USART_CR3,Error_INT)))
		{


		}

		/* check if the overrun error Interrupt is fired */
		else if ((GET_BIT(USART_CH[MUSART3]->USART_SR,ORE))&&(GET_BIT(USART_CH[MUSART3]->USART_CR1,RXNEmpty_INT)))
		{

		}

		/* check if the noise error Interrupt is fired */
		else if ((GET_BIT(USART_CH[MUSART3]->USART_SR,NE))&&(GET_BIT(USART_CH[MUSART3]->USART_CR3,Error_INT)))
		{

		}

		/* perform Action Callback */
		Callback_CH[MUSART3].TxRx_callback();
	}
}
