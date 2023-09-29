/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  NVIC							 		    */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REGISTERS.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MNVIC_int.h"
#include "MNVIC_config.h"
#include "MNVIC_priv.h"

ErrorState_t MNVIC_enEnableNVIC(void)
{
	SCB_AIRCR &= CSB_AIRCR_LOCK_MASK;
	SCB_AIRCR |= CSB_AIRCR_LOCK_PASS << 15;

	SCB_AIRCR &= CSB_PRIGROUP_MASK;
	SCB_AIRCR |= NVIC_GROUPSUB_PRI << 7;

	return SUCCESS;
}


ErrorState_t MNVIC_enEnableInt(u8 copy_u8IRQnum)
{
	ErrorState_t  local_state = SUCCESS;

	if (copy_u8IRQnum <= 31)
	{
		NVIC->NVIC_ISER[0] = (1<<copy_u8IRQnum);
	}
	else if (copy_u8IRQnum <= 63)
	{
		copy_u8IRQnum -= 32;
		NVIC->NVIC_ISER[1] = (1<<copy_u8IRQnum);
	}
	else if (copy_u8IRQnum <= 81)
	{
		copy_u8IRQnum -= 64;
		NVIC->NVIC_ISER[2] = (1<<copy_u8IRQnum);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}
	return local_state;
}

ErrorState_t MNVIC_enDisableInt(u8 copy_u8IRQnum)
{
	ErrorState_t  local_state = SUCCESS;

	if (copy_u8IRQnum <= 31)
	{
		NVIC->NVIC_ICER[0] = (1<<copy_u8IRQnum);
	}
	else if (copy_u8IRQnum <= 63)
	{
		copy_u8IRQnum -= 32;
		NVIC->NVIC_ICER[1] = (1<<copy_u8IRQnum);
	}
	else if (copy_u8IRQnum <= 81)
	{
		copy_u8IRQnum -= 64;
		NVIC->NVIC_ICER[2] = (1<<copy_u8IRQnum);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}
	return local_state;
}

ErrorState_t MNVIC_enSetPendingFlag(u8 copy_u8IRQnum)
{
	ErrorState_t  local_state = SUCCESS;

	if (copy_u8IRQnum <= 31)
	{
		NVIC->NVIC_ISPR[0] = (1<<copy_u8IRQnum);
	}
	else if (copy_u8IRQnum <= 63)
	{
		copy_u8IRQnum -= 32;
		NVIC->NVIC_ISPR[1] = (1<<copy_u8IRQnum);
	}
	else if (copy_u8IRQnum <= 81)
	{
		copy_u8IRQnum -= 64;
		NVIC->NVIC_ISPR[2] = (1<<copy_u8IRQnum);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}
	return local_state;
}
ErrorState_t MNVIC_enClrPendingFlag(u8 copy_u8IRQnum)
{
	ErrorState_t  local_state = SUCCESS;

	if (copy_u8IRQnum <= 31)
	{
		NVIC->NVIC_ICPR[0] = (1<<copy_u8IRQnum);
	}
	else if (copy_u8IRQnum <= 63)
	{
		copy_u8IRQnum -= 32;
		NVIC->NVIC_ICPR[1] = (1<<copy_u8IRQnum);
	}
	else if (copy_u8IRQnum <= 81)
	{
		copy_u8IRQnum -= 64;
		NVIC->NVIC_ICPR[2] = (1<<copy_u8IRQnum);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}
	return local_state;
}
ErrorState_t MNVIC_enGetPendingFlag(u8 copy_u8IRQnum, u8 *PendingState)
{
	ErrorState_t  local_state = SUCCESS;

	if (copy_u8IRQnum <= 31)
	{
		*PendingState = GET_BIT(NVIC->NVIC_ICPR[0],copy_u8IRQnum);
	}
	else if (copy_u8IRQnum <= 63)
	{
		copy_u8IRQnum -= 32;
		*PendingState = GET_BIT(NVIC->NVIC_ICPR[1],copy_u8IRQnum);
	}
	else if (copy_u8IRQnum <= 81)
	{
		copy_u8IRQnum -= 64;
		*PendingState = GET_BIT(NVIC->NVIC_ICPR[2],copy_u8IRQnum);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}
	return local_state;
}

ErrorState_t MNVIC_enGetActiveFlag(u8 copy_u8IRQnum, u8 *ActiveState)
{
	ErrorState_t  local_state = SUCCESS;

	if (copy_u8IRQnum <= 31)
	{
		*ActiveState = GET_BIT(NVIC->NVIC_IABR[0],copy_u8IRQnum);
	}
	else if (copy_u8IRQnum <= 63)
	{
		copy_u8IRQnum -= 32;
		*ActiveState = GET_BIT(NVIC->NVIC_IABR[1],copy_u8IRQnum);
	}
	else if (copy_u8IRQnum <= 81)
	{
		copy_u8IRQnum -= 64;
		*ActiveState = GET_BIT(NVIC->NVIC_IABR[2],copy_u8IRQnum);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}
	return local_state;
}

ErrorState_t MNVIC_enSetPriority(u8 copy_u8IRQnum, u8 copy_u8Priority)
{
	ErrorState_t local_state = SUCCESS;

	if (copy_u8IRQnum <= 81)
	{
		NVIC->NVIC_IPR[copy_u8IRQnum] &= NVIC_SETPRI_MASK;
		NVIC->NVIC_IPR[copy_u8IRQnum] |= copy_u8Priority << 3;
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;


}
