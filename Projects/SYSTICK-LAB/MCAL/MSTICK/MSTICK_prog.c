/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  25/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  SYSTICK						 		    */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REGISTERS.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MSTICK_config.h"
#include "MSTICK_int.h"
#include "MSTICK_priv.h"


void (*STK_Callback)(void) = NULL;
static u8 flag = 0;

ErrorState_t MSTK_enInit(void)
{

#if (STK_PRESCALER == STK_AHB_PRESCALER)
	SET_BIT(STK->STK_CTRL, CLKSOURCE);

#elif(STK_PRESCALER == STK_AHB_DIV8_PRESCALER)
	CLR_BIT(STK->STK_CTRL, CLKSOURCE);

#else
#error ("YOU SELECTED THE WRONG PRESCALER");
#endif

	return SUCCESS;
}

ErrorState_t MSTK_enDelayMS(u16 copy_u16delayMS)
{

	STK->STK_LOAD = copy_u16delayMS  * 1000;
	SET_BIT(STK->STK_CTRL, ENABLE);

	while (!(GET_BIT(STK->STK_CTRL, COUNTFLAG)));

	CLR_BIT(STK->STK_CTRL, ENABLE);
	STK->STK_VAL = 0;

	return SUCCESS;

}

ErrorState_t MSTK_enSetIntervalSingle(u32 copy_u32TicksNum,void(*ptrfn)(void))
{
	ErrorState_t local_state = SUCCESS;
	if (*ptrfn == NULL)
	{
		local_state = NULL_PTR_ERR;
	}
	else
	{
		STK_Callback = ptrfn;
		flag = 1;
		STK->STK_LOAD = copy_u32TicksNum;
		SET_BIT(STK->STK_CTRL, ENABLE);
		SET_BIT(STK->STK_CTRL, TICKINT);
	}
	return local_state;
}

ErrorState_t MSTK_enSetIntervalPeriodic(u32 copy_u32TicksNum,void(*ptrfn)(void))
{
	ErrorState_t local_state = SUCCESS;
	if (*ptrfn == NULL)
	{
		local_state = NULL_PTR_ERR;
	}
	else
	{
		STK_Callback = ptrfn;
		flag = 0;
		STK->STK_LOAD = copy_u32TicksNum;
		SET_BIT(STK->STK_CTRL, ENABLE);
		SET_BIT(STK->STK_CTRL, TICKINT);
	}
	return local_state;
}

ErrorState_t MSTK_enGetElapsedTime(u32 *copy_u32ElapsedValue)
{
	ErrorState_t local_state = SUCCESS;
	if (copy_u32ElapsedValue == NULL)
	{
		local_state = NULL_PTR_ERR;
	}
	else
	{
		*copy_u32ElapsedValue = STK->STK_LOAD - STK->STK_VAL;
	}

	return local_state;
}

ErrorState_t MSTK_enRemainingValue(u32 *copy_u32RemainingValue)
{
	ErrorState_t local_state = SUCCESS;
	if (copy_u32RemainingValue == NULL)
	{
		local_state = NULL_PTR_ERR;
	}
	else
	{
		*copy_u32RemainingValue = STK->STK_VAL;
	}

	return local_state;
}

ErrorState_t STK_enStop(void)
{
	CLR_BIT(STK->STK_CTRL, TICKINT);

	return SUCCESS;
}



void SysTick_Handler(void)
{
	volatile u8 local_temp = 0;
	if (flag == 1)
	{
		CLR_BIT(STK->STK_CTRL, TICKINT);
		CLR_BIT(STK->STK_CTRL, ENABLE);
		STK->STK_VAL = 0;
	}

	if (STK_Callback != NULL)
	{
		STK_Callback();
	}

	local_temp = GET_BIT(STK->STK_CTRL,COUNTFLAG);
}

