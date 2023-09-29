/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  31/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  DMA							 			*/
/****************************************************************/

#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "REGISTERS.h"
#include "BIT_MATH.h"
#include "MRCC_int.h"
#include "MDMA_config.h"
#include "MDMA_int.h"
#include "MDMA_priv.h"

static void (*DMA_CallBack[7]) (void) = {0};


ErrorState_t MDMA_enInit(MDMA_CHANNEL_t copy_u8Channel , MDMA_INIT_st *ptr_u8Value)
{
	ErrorState_t local_u8state = SUCCESS;

	if ((ptr_u8Value != NULL) && (copy_u8Channel <= Channel7))
	{
		switch(ptr_u8Value->Source_Mode)
		{
		case MDAM_Memory_Src:
			SET_BIT(DMA->CHANNEL[copy_u8Channel].DMA_CCR, DIR);
			break;

		case MDMA_Peripheral_Src:
			CLR_BIT(DMA->CHANNEL[copy_u8Channel].DMA_CCR, DIR);
			break;

		default :
			local_u8state = OUT_OF_RANG_ERR;
			break;
		}

		switch(ptr_u8Value->Circular_Mode)
		{
		case MDMA_Circular_ON:
			SET_BIT(DMA->CHANNEL[copy_u8Channel].DMA_CCR, CIRC);
			break;

		case MDMA_Circular_OFF:
			CLR_BIT(DMA->CHANNEL[copy_u8Channel].DMA_CCR, CIRC);
			break;

		default :
			local_u8state = OUT_OF_RANG_ERR;
			break;
		}

		switch(ptr_u8Value->PINK_Mode)
		{
		case MDMA_PINK_ON:
			SET_BIT(DMA->CHANNEL[copy_u8Channel].DMA_CCR, PINC);
			break;

		case MDMA_PINK_OFF:
			CLR_BIT(DMA->CHANNEL[copy_u8Channel].DMA_CCR, PINC);
			break;

		default :
			local_u8state = OUT_OF_RANG_ERR;
			break;
		}

		switch(ptr_u8Value->MINK_Mode)
		{
		case MDMA_MINK_ON:
			SET_BIT(DMA->CHANNEL[copy_u8Channel].DMA_CCR, MINC);
			break;

		case MDMA_MINK_OFF:
			CLR_BIT(DMA->CHANNEL[copy_u8Channel].DMA_CCR, MINC);
			break;

		default :
			local_u8state = OUT_OF_RANG_ERR;
			break;
		}

		DMA->CHANNEL[copy_u8Channel].DMA_CCR &= MDMA_PREIPHERAL_SIZE_MASK;
		switch(ptr_u8Value->Preiphial_SizeElemnet)
		{
		case MDMA_Preiphial_1ByteSize:
			DMA->CHANNEL[copy_u8Channel].DMA_CCR |= MDMA_Preiphial_1ByteSize << MDMA_PREIPHERAL_SIZE_OFFEST;
			break;

		case MDMA_Preiphial_2ByteSize:
			DMA->CHANNEL[copy_u8Channel].DMA_CCR |= MDMA_Preiphial_2ByteSize << MDMA_PREIPHERAL_SIZE_OFFEST;
			break;

		case MDMA_Preiphial_4ByteSize:
			DMA->CHANNEL[copy_u8Channel].DMA_CCR |= MDMA_Preiphial_4ByteSize << MDMA_PREIPHERAL_SIZE_OFFEST;
			break;

		default :
			local_u8state = OUT_OF_RANG_ERR;
			break;
		}

		DMA->CHANNEL[copy_u8Channel].DMA_CCR &= MDMA_MEMORY_SIZE_MASK;
		switch(ptr_u8Value->Memory_SizeElement)
		{
		case MDMA_Memory_1ByteSize:
			DMA->CHANNEL[copy_u8Channel].DMA_CCR |= MDMA_Memory_1ByteSize << MDMA_MEMORY_SIZE_OFFSET;
			break;

		case MDMA_Memory_2ByteSize:
			DMA->CHANNEL[copy_u8Channel].DMA_CCR |= MDMA_Memory_2ByteSize << MDMA_MEMORY_SIZE_OFFSET;
			break;

		case MDMA_Memory_4ByteSize:
			DMA->CHANNEL[copy_u8Channel].DMA_CCR |= MDMA_Memory_4ByteSize << MDMA_MEMORY_SIZE_OFFSET;
			break;

		default :
			local_u8state = OUT_OF_RANG_ERR;
			break;
		}

		DMA->CHANNEL[copy_u8Channel].DMA_CCR &= MDMA_CHANNEL_PRI_MASK;
		switch(ptr_u8Value->Channel_Priority)
		{
		case MDMA_Channel_PRI_LOW:
			DMA->CHANNEL[copy_u8Channel].DMA_CCR |= MDMA_Channel_PRI_LOW << MDMA_CHANNEL_PRI_OFFSET;
			break;

		case MDMA_Channel_PRI_MEDIUM:
			DMA->CHANNEL[copy_u8Channel].DMA_CCR |= MDMA_Channel_PRI_MEDIUM << MDMA_CHANNEL_PRI_OFFSET;
			break;

		case MDMA_Channel_PRI_HIGH:
			DMA->CHANNEL[copy_u8Channel].DMA_CCR |= MDMA_Channel_PRI_HIGH << MDMA_CHANNEL_PRI_OFFSET;
			break;

		case MDMA_Channel_PRI_VeryHIGH:
			DMA->CHANNEL[copy_u8Channel].DMA_CCR |= MDMA_Channel_PRI_VeryHIGH << MDMA_CHANNEL_PRI_OFFSET;
			break;

		default :
			local_u8state = OUT_OF_RANG_ERR;
			break;
		}

		switch(ptr_u8Value->DMA_Mode)
		{
		case MDMA_FRunning_ON:
			SET_BIT(DMA->CHANNEL[copy_u8Channel].DMA_CCR, MEM2MEM);
			break;

		case MDMA_FRunning_OFF:
			CLR_BIT(DMA->CHANNEL[copy_u8Channel].DMA_CCR, MEM2MEM);
			break;

		default :
			local_u8state = OUT_OF_RANG_ERR;
			break;
		}
	}
	else
	{
		local_u8state = OUT_OF_RANG_ERR;
	}

	return local_u8state;
}

ErrorState_t MDMA_enEnableInt(MDMA_CHANNEL_t copy_u8Chennel, MDMA_INT_t copy_u8Interrupt)
{
	ErrorState_t local_u8state = SUCCESS;

	if ((copy_u8Interrupt >= MDMA_TC_INT) && (copy_u8Interrupt <= MDMA_TE_INT) && (copy_u8Chennel <= Channel7))
	{
		SET_BIT(DMA->CHANNEL[copy_u8Chennel].DMA_CCR, copy_u8Interrupt);
	}
	else
	{
		local_u8state = OUT_OF_RANG_ERR;
	}

	return local_u8state;
}

ErrorState_t MDMA_enDisableInt(MDMA_CHANNEL_t copy_u8Chennel, MDMA_INT_t copy_u8Interrupt)
{
	ErrorState_t local_u8state = SUCCESS;

	if ((copy_u8Interrupt >= MDMA_TC_INT) && (copy_u8Interrupt <= MDMA_TE_INT) && (copy_u8Chennel <= Channel7))
	{
		CLR_BIT(DMA->CHANNEL[copy_u8Chennel].DMA_CCR, copy_u8Interrupt);
	}
	else
	{
		local_u8state = OUT_OF_RANG_ERR;
	}

	return local_u8state;
}

ErrorState_t MDMA_enReadIntState(MDMA_CHANNEL_t copy_u8Chennel, MDMA_INT_t copy_u8Interrupt, u8 *ptr_u8state)
{
	ErrorState_t local_u8state = SUCCESS;
	u8 local_u8IntPin;
	if ((copy_u8Chennel <= Channel7 && copy_u8Interrupt <= MDMA_TE_INT) && (ptr_u8state != NULL))
	{
		local_u8IntPin = copy_u8Interrupt + (copy_u8Chennel*MDMA_INT_STATE_OFFSET);
		*ptr_u8state = GET_BIT(DMA->DMA_ISR,local_u8IntPin);
	}

	else
	{
		local_u8state = OUT_OF_RANG_ERR;
	}

	return local_u8state;

}



ErrorState_t MDMA_enIntCallBack(MDMA_CHANNEL_t copy_u8Chennel , void (*ptr)(void))
{
	ErrorState_t local_u8state = SUCCESS ;
	if (ptr != NULL)
	{
		DMA_CallBack[copy_u8Chennel] = ptr ;
	}
	else
	{
		local_u8state = NULL_PTR_ERR;
	}

	return local_u8state;
}

ErrorState_t MDMA_enTranferInit(MDMA_CHANNEL_t copy_u8Chennel, u32 *ptr_u32SrcaAddress, u32 *ptr_u32DestAddress, u16 copy_16BlockLen)
{
	ErrorState_t local_u8state = SUCCESS;
	if ((ptr_u32SrcaAddress != NULL) && (ptr_u32DestAddress != NULL))
	{
		CLR_BIT(DMA->CHANNEL[copy_u8Chennel].DMA_CCR, EN);

		DMA->CHANNEL[copy_u8Chennel].DMA_CPAR = (u32)ptr_u32SrcaAddress;
		DMA->CHANNEL[copy_u8Chennel].DMA_CMAR = (u32)ptr_u32DestAddress;
		DMA->CHANNEL[copy_u8Chennel].DMA_CNDTR = copy_16BlockLen;

		SET_BIT(DMA->CHANNEL[copy_u8Chennel].DMA_CCR, EN);
	}
	else
	{
		local_u8state = OUT_OF_RANG_ERR;
	}

	return local_u8state;
}

ErrorState_t MDMA_enTranferBusyStart(MDMA_CHANNEL_t copy_u8Chennel,MDMA_INT_t copy_u8Interrupt)
{
	ErrorState_t local_state = SUCCESS;
	if (copy_u8Chennel <= Channel7 && copy_u8Interrupt <= MDMA_TE_INT)
	{
		copy_u8Interrupt += (copy_u8Chennel * MDMA_INT_STATE_OFFSET);
		while(!(GET_BIT(DMA->DMA_ISR,copy_u8Interrupt)));
		DMA->DMA_IFCR = (1<< copy_u8Interrupt);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}
	return local_state;
}



void DMA1_Channel1_IRQHandler(void)
{
	if (DMA_CallBack[Channel1] != NULL)
	{
		DMA_CallBack[Channel1]();
	}
}

void DMA1_Channel2_IRQHandler(void)
{
	if (DMA_CallBack[Channel2] != NULL)
	{
		DMA_CallBack[Channel2]();
	}
}

void DMA1_Channel3_IRQHandler(void)
{
	if (DMA_CallBack[Channel3] != NULL)
	{
		DMA_CallBack[Channel3]();
	}
}

void DMA1_Channel4_IRQHandler(void)
{
	if (DMA_CallBack[Channel4] != NULL)
	{
		DMA_CallBack[Channel4]();
	}
}

void DMA1_Channel5_IRQHandler(void)
{
	if (DMA_CallBack[Channel5] != NULL)
	{
		DMA_CallBack[Channel5]();
	}
}

void DMA1_Channel6_IRQHandler(void)
{
	if (DMA_CallBack[Channel6] != NULL)
	{
		DMA_CallBack[Channel6]();
	}
}

void DMA1_Channel7_IRQHandler(void)
{
	if (DMA_CallBack[Channel7] != NULL)
	{
		DMA_CallBack[Channel7]();
	}
}


