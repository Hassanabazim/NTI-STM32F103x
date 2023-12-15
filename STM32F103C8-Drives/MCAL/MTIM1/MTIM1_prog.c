/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  MTIM1_prog.c
 *         @Module	:  MTIM1
 *
 *  Description:  This file provide Module APIs code Implementation
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "REGISTERS.h"
#include "BIT_MATH.h"
#include "MTIM1_int.h"
#include "MTIM1_config.h"
#include "MTIM1_priv.h"


static void(*ICU_callback)(void) = 0;
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : ErrorState_t MTIMER1_enInit(void)
 *
 * \Description     : This Services for Initialize the timer
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 *
 * \Return value:   : ErrorState_t  -> SUCEESS
 * 									-> OUT_OF_RANG_ERR
 *******************************************************************************/

ErrorState_t MTIMER1_enInit(void)
{
	/*	@brief This API use to choose the TIMER Mode  */

	CLR_BIT(TIM1->TIM1_CCMR1, 0);
	SET_BIT(TIM1->TIM1_CCMR1, 1);
	/* Channel is configured to as input, IC1 on TI1*/
	TIM1->TIM1_CCMR1 |= (3 << 4);   /* Input capture Filter sampling after 8 events */

	SET_BIT(TIM1->TIM1_CCER,0);		/* capture is enabled */

	CLR_BIT(TIM1->TIM1_CCMR1, 2);
	CLR_BIT(TIM1->TIM1_CCMR1, 3);	/* input capture prescaler has no prescaler once event detected */

	CLR_BIT(TIM1->TIM1_CCER,1); 	/* trigger is rising by default */


	return SUCCESS;
}

/******************************************************************************
 * \Syntax          : ErrorState_t MTIMER1_enStart(void)
 *
 * \Description     : This Services for start the timer
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 *
 * \Return value:   : ErrorState_t  -> SUCEESS
 * 									-> OUT_OF_RANG_ERR
 *******************************************************************************/
ErrorState_t MTIMER1_setPrescaler(u16 copy_u16prescaler)
{
	TIM1->TIM1_PSC = copy_u16prescaler;
	return SUCCESS;
}

ErrorState_t MTIMER1_enStart(void)
{

	SET_BIT(TIM1->TIM1_CR1,0);
	return SUCCESS;
}
/******************************************************************************
 * \Syntax          : ErrorState_t MTIMER1_enInit(void)
 *
 * \Description     : This Services for Initialize the timer
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 *
 * \Return value:   : ErrorState_t  -> SUCEESS
 * 									-> OUT_OF_RANG_ERR
 *******************************************************************************/

ErrorState_t MTIMER1_enStop(void)
{
	CLR_BIT(TIM1->TIM1_CR1, 0);

	return SUCCESS;
}

ErrorState_t MTIMER1_enEnableINT(void)
{
	SET_BIT(TIM1->TIM1_DIER, 1);   /* enable Input capture interrupt */
	return SUCCESS;
}
ErrorState_t MTIMER1_enDisableINT(void)
{
	CLR_BIT(TIM1->TIM1_DIER, 1);   /* enable Input capture interrupt */
	return SUCCESS;

}
ErrorState_t MTIMER1_enSetCallBack(void(*ptrfn)(void))
{

	ICU_callback = ptrfn;
	return SUCCESS;

}
ErrorState_t MTIMER1_ICU_enRead(volatile u16 *ptrReadValue)
{
	*ptrReadValue = TIM1->TIM1_CCR1;
	return SUCCESS;
}
ErrorState_t MTIMER1_ICU_enSetTrigger(u8 copy_u8Trigg)
{
	if (copy_u8Trigg == 0)
	{
		CLR_BIT(TIM1->TIM1_CCER,1);   /* trigger is rising by default */
		return SUCCESS;

	}
	else if (copy_u8Trigg == 1)
	{
		SET_BIT(TIM1->TIM1_CCER,1);   /* trigger is rising by default */
	}
	else
	{
		//DO NOTHING
	}
	return SUCCESS;
}

void TIM1_CC_IRQHandler(void)
{
	if (ICU_callback != NULL)
	{
		ICU_callback();
	}

}

/**********************************************************************************************************************
 *  END OF FILE:   MTIM1_prog.c
 *********************************************************************************************************************/
