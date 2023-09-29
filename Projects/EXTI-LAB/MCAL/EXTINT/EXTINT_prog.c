/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  24/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  EXT INT							 		*/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REGISTERS.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MNVIC_int.h"
#include "EXTINT_int.h"
#include "EXTINT_config.h"
#include "EXTINT_priv.h"

void (*EXTI_CALLBACK[16])(void) = {0};


ErrorState_t MEXTI_enInit(void)
{
#if (EXTI_MODE == EXTI_RISING_TRIG)
	SET_BIT(EXTI->EXTI_RTSR,EXTI_LINE);

#elif(EXTI_MODE == EXTI_FAILING_TRIG)
	SET_BIT(EXTI->EXTI_FTSR,EXTI_LINE);

#elif(EXTI_MODE == EXTI_LOGIC_CHANGE)
	SET_BIT(EXTI->EXTI_RTSR,EXTI_LINE);
	SET_BIT(EXTI->EXTI_FTSR,EXTI_LINE);

#else
#error("Wrong EXTI MODE!");
#endif

	SET_BIT(EXTI->EXTI_IMR, EXTI_LINE);

	return SUCCESS;
}

ErrorState_t MEXTI_enEnable(u8 Copy_u8LineId)
{
	ErrorState_t local_state = SUCCESS ;

	if (Copy_u8LineId <= 15)
	{
		SET_BIT(EXTI->EXTI_IMR, Copy_u8LineId);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}

ErrorState_t MEXTI_enDisable(u8 Copy_u8LineId)
{
	ErrorState_t local_state = SUCCESS ;

	if (Copy_u8LineId <= 15)
	{
		CLR_BIT(EXTI->EXTI_IMR, Copy_u8LineId);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}

ErrorState_t MEXTI_enCallBack(u8 Copy_u8LineId, void (*ptr) (void))
{
	ErrorState_t local_state = SUCCESS ;
	if (ptr == NULL)
	{
		local_state = NULL_PTR_ERR;
	}
	else
	{
		EXTI_CALLBACK[Copy_u8LineId] = ptr;
	}

	return local_state ;
}

ErrorState_t MEXTI_enSWInterrupt(u8 Copy_u8LineId)
{
	ErrorState_t local_state = SUCCESS ;

	if (Copy_u8LineId <= 15)
	{
		SET_BIT(EXTI->EXTI_SWIER, Copy_u8LineId);
		CLR_BIT(EXTI->EXTI_PR, Copy_u8LineId);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}

ErrorState_t MEXTI_enClearPendingBit(u8 Copy_u8LineId)
{
	ErrorState_t local_state = SUCCESS ;

	if (Copy_u8LineId <= 15)
	{
		SET_BIT(EXTI->EXTI_PR, Copy_u8LineId);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}

ErrorState_t MEXTI_enSetLatch(u8 Copy_u8LineId, u8 Copy_u8Mode)
{
	ErrorState_t local_state = SUCCESS ;

	if (Copy_u8LineId <= 15)
	{
		switch (Copy_u8Mode)
		{
		case EXTI_RISING_TRIG:
			SET_BIT(EXTI->EXTI_RTSR,Copy_u8LineId);
			break;

		case EXTI_FAILING_TRIG:
			SET_BIT(EXTI->EXTI_FTSR,Copy_u8LineId);
			break;

		case EXTI_LOGIC_CHANGE:
			SET_BIT(EXTI->EXTI_RTSR,Copy_u8LineId);
			SET_BIT(EXTI->EXTI_FTSR,Copy_u8LineId);
			break;

		default:
			local_state = OUT_OF_RANG_ERR;
			break;
		}
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}


void EXTI0_IRQHandler(void)
{
	if (EXTI_CALLBACK[EXTI0_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI0_LINE]();
	}

}

void EXTI1_IRQHandler(void)
{
	if (EXTI_CALLBACK[EXTI1_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI1_LINE]();
	}

}
void EXTI2_IRQHandler(void)
{
	if (EXTI_CALLBACK[EXTI2_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI2_LINE]();
	}
}
void EXTI3_IRQHandler(void)
{
	if (EXTI_CALLBACK[EXTI3_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI3_LINE]();
	}
}
void EXTI4_IRQHandler(void)
{
	if (EXTI_CALLBACK[EXTI4_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI4_LINE]();
	}
}
void EXTI9_5_IRQHandler(void)
{
	if (EXTI_CALLBACK[EXTI5_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI5_LINE]();
	}
	else if (EXTI_CALLBACK[EXTI6_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI6_LINE]();

	}
	else if (EXTI_CALLBACK[EXTI7_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI7_LINE]();

	}
	else if (EXTI_CALLBACK[EXTI8_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI8_LINE]();

	}
	else if (EXTI_CALLBACK[EXTI9_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI9_LINE]();

	}
}

void EXTI15_10_IRQHandler(void)
{
	if (EXTI_CALLBACK[EXTI10_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI10_LINE]();
	}
	else if (EXTI_CALLBACK[EXTI11_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI11_LINE]();

	}
	else if (EXTI_CALLBACK[EXTI12_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI12_LINE]();

	}
	else if (EXTI_CALLBACK[EXTI13_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI13_LINE]();

	}
	else if (EXTI_CALLBACK[EXTI14_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI14_LINE]();

	}
	else if (EXTI_CALLBACK[EXTI15_LINE] != NULL)
	{
		EXTI_CALLBACK[EXTI15_LINE]();

	}
}
