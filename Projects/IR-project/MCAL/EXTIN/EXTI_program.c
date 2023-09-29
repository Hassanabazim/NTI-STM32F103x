/*****************************************************************************/
/* Author       	: 	Fahd Badi                                            */
/* Origin Date  	: 	24/07/2023                                           */
/* Version      	: 	1.0.0                                                */
/* SWC    	        : 	STM32F103C8 		                                 */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REGISTERS.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void (*EXTI0_CallBack) (void);
void (*EXTI1_CallBack) (void);


void EXTI_voidInit(void)
{    
	#if EXTI_u8MODE == EXTI_u8RISING_EDGE
		SET_BIT(EXTI->EXTI_RTSR, EXTI_u8LINE_CONFIG);
		
	#elif EXTI_u8MODE == EXTI_u8FALLING_EDGE
		SET_BIT(EXTI->EXTI_FTSR, EXTI_u8LINE_CONFIG);
	
	#elif EXTI_u8MODE == EXTI_u8ON_CHANGE_EDGE
		SET_BIT(EXTI->EXTI_RTSR, EXTI_u8LINE_CONFIG);
		SET_BIT(EXTI->EXTI_FTSR, EXTI_u8LINE_CONFIG);
	
	#else
		#error("Wrong Mode and Line Choice")
	#endif
	
	// Enable interrupt
	SET_BIT(EXTI->EXTI_IMR, EXTI_u8LINE_CONFIG);
}


u8 EXTI_u8Enable(u8 Copy_u8LineId)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(Copy_u8LineId <= 15)
	{
		SET_BIT(EXTI->EXTI_IMR, Copy_u8LineId);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;

}


u8 EXTI_u8Disable(u8 Copy_u8LineId)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(Copy_u8LineId <= 15)
	{
		CLR_BIT(EXTI->EXTI_IMR, Copy_u8LineId);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
	
}


u8 EXTI_u8SoftWareTrigger(u8 Copy_u8LineId)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(Copy_u8LineId <= 15)
	{
		SET_BIT(EXTI->EXTI_SWIER, Copy_u8LineId);
		CLR_BIT( EXTI->EXTI_PR , Copy_u8LineId);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
	
}

void EXTI_ClearPendingBit(u8 Copy_u8LineId)
{
	SET_BIT( EXTI->EXTI_PR , Copy_u8LineId);
}


u8 EXTI_u8SetSignalLatch(u8 Copy_u8LineId,
                            u8 Copy_u8Mode)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(Copy_u8LineId <= 15)
	{
		switch(Copy_u8Mode)		
		{
			case EXTI_u8RISING_EDGE   :     SET_BIT(EXTI->EXTI_RTSR, Copy_u8LineId);  	break;
			case EXTI_u8FALLING_EDGE  :     SET_BIT(EXTI->EXTI_FTSR, Copy_u8LineId);    break;
			case EXTI_u8ON_CHANGE_EDGE:     SET_BIT(EXTI->EXTI_RTSR, Copy_u8LineId);
											SET_BIT(EXTI->EXTI_FTSR, Copy_u8LineId);	break;
			default                   :     Local_u8ErrorState = STD_TYPES_NOK;  	    break;
		
		}	
	}
	else
	{
		 Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	SET_BIT(EXTI->EXTI_IMR, Copy_u8LineId);
	
	return Local_u8ErrorState;		
}


//////////////////////////////////////////////////// ISR 0 ///////////////////////////////////////////////////////////
void EXTI0_VidSetCallBack( void (*ptr) (void)){

	EXTI0_CallBack = ptr;

}
void EXTI0_IRQHandler(void){

	EXTI0_CallBack();
	EXTI_ClearPendingBit(EXTI_u8LINE0);
	//SET_BIT( EXTI->EXTI_PR , 0 );

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////// ISR 1 ///////////////////////////////////////////////////////////
void EXTI1_VidSetCallBack( void (*ptr) (void) ){

	EXTI1_CallBack = ptr;

}
void EXTI1_IRQHandler(void){

	EXTI1_CallBack();
	EXTI_ClearPendingBit(EXTI_u8LINE1);
	//SET_BIT( EXTI->EXTI_PR, 1 );

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
