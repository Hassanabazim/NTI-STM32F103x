/*****************************************************************************/
/* Author       	: 	Fahd Badi                                            */
/* Origin Date  	: 	25/07/2023                                           */
/* Version      	: 	1.0.0                                                */
/* SWC    	        : 	SysTick (STK) 		                                 */
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REGISTERS.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


/* Define Callback Global Variable */
static void(*STK_pfCallBack)(void) = NULL;

/* Define Variable for interval mode */
static u8 STK_u8IntervalMode;


void STK_voidInit(void)
{
    /* Disable STK & Disable STK Interrupt & Set clock source AHB/8 */
	#if STK_u8CLOCK_SOURCE == STK_u8CLK_AHB_DIV_8
		STK->STK_CTRL = 0x00000000;
    /* Disable STK & Disable STK Interrupt & Set clock source AHB */	
	#elif STK_u8CLOCK_SOURCE == STK_u8CLK_AHB
		STK->STK_CTRL = 0x00000004;
	#else
		#error("You Chosed Wrong SysTick Clock Source")	
	#endif
}


u8 STK_u8SetBusyWait(u32 Copy_u32NumberOfTicks){

	u8 Local_u8ErrorState = STD_TYPES_OK;
	
    if(Copy_u32NumberOfTicks <= STK_u32LOAD_MAX_VALUE)
	{
		/* Load ticks to load register */
		STK->STK_LOAD = Copy_u32NumberOfTicks;
		
		/* Start timer */
		SET_BIT(STK->STK_CTRL, STK_CTRL_ENABLE);
	
		/* Read interrupt flag - bit 16 in CTRL register */
		/* Wait till flag is raised */
		while(GET_BIT(STK->STK_CTRL, STK_CTRL_COUNTFLAG) == 0);
	
		/* Stop timer */
		CLR_BIT(STK->STK_CTRL, STK_CTRL_ENABLE);
		STK->STK_LOAD = STK_u8CLEAR_VALUE;
		STK->STK_VAL  = STK_u8CLEAR_VALUE;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}


u8 STK_u8SetIntervalSingle(u32 Copy_u32NumberOfTicks,
                              void(*Copy_pfNotification)(void))
{

	u8 Local_u8ErrorState = STD_TYPES_OK;
	
    if(Copy_u32NumberOfTicks <= STK_u32LOAD_MAX_VALUE 
	   && Copy_pfNotification != NULL)
	{
		/* Save CallBack */
		STK_pfCallBack = Copy_pfNotification;
		
		/* Load ticks to load register */
		STK->STK_LOAD = Copy_u32NumberOfTicks;
		
		/* Start Timer */
		SET_BIT(STK->STK_CTRL, STK_CTRL_ENABLE);
		
		/* Interval Mode to Single */
		STK_u8IntervalMode = STK_u8SINGLE_MODE;
	
		/* Enable SysTick Interrupt */
		SET_BIT(STK->STK_CTRL, STK_CTRL_TICKINT);
		
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
	
}


u8 STK_u8SetIntervalPeriodic(u32 Copy_u32NumberOfTicks,
								void(*Copy_pfNotification)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
    if(Copy_u32NumberOfTicks <= STK_u32LOAD_MAX_VALUE 
	   && Copy_pfNotification != NULL)
	{
		/* Save CallBack */
		STK_pfCallBack = Copy_pfNotification;
		
		/* Load ticks to load register */
		STK->STK_LOAD = Copy_u32NumberOfTicks-1;
		
		/* Start Timer */
		SET_BIT(STK->STK_CTRL, STK_CTRL_ENABLE);
		
		/* Interval Mode to Periodic */
		STK_u8IntervalMode = STK_u8PERIODIC_MODE;
	
		/* Enable SysTick Interrupt */
		SET_BIT(STK->STK_CTRL, STK_CTRL_TICKINT);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
	
}


void STK_voidStopTimer(void)
{
    /* Disable SysTick Interrupt */
	CLR_BIT(STK->STK_CTRL, STK_CTRL_TICKINT);
	
	/* Stop timer */
	CLR_BIT(STK->STK_CTRL, STK_CTRL_ENABLE);
	STK->STK_LOAD = STK_u8CLEAR_VALUE;
	STK->STK_VAL  = STK_u8CLEAR_VALUE;
}  


u8 STK_u8GetElapsedTime(u32 *Copy_pu32ElapsedTime)
{ 
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(Copy_pu32ElapsedTime != NULL)
	{
		*Copy_pu32ElapsedTime = STK->STK_LOAD - STK->STK_VAL;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}

u8 STK_u8GetRemainingTime(u32 *Copy_pu32RemainingTime)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(Copy_pu32RemainingTime != NULL)
	{
		*Copy_pu32RemainingTime = STK->STK_VAL;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}
  
  
void SysTick_Handler(void){

    /* Define Local Variable for Temporary */ 
	u8 Local_u8Temporary = 0;
	
	/* Check on Interval Mode */
	if(STK_u8IntervalMode == STK_u8SINGLE_MODE)
	{
	    /* Disable SysTick Interrupt */
		CLR_BIT(STK->STK_CTRL, STK_CTRL_TICKINT);
		/* Stop Timer */
		CLR_BIT(STK->STK_CTRL, STK_CTRL_ENABLE);
		STK->STK_LOAD = STK_u8CLEAR_VALUE;
		STK->STK_VAL  = STK_u8CLEAR_VALUE;
	}

	if(STK_pfCallBack != NULL)
	{
		/* Callback Notification */
		STK_pfCallBack();
	}

	/* Clear Interrupt Flag */
	Local_u8Temporary = GET_BIT(STK->STK_CTRL, STK_CTRL_COUNTFLAG);
}
  


void STK_voidDelay_ms(u32 Copy_u32NumberOfTicks){

	u32 Local_u32BIT;

	/* Load ticks to load register */
	STK->STK_LOAD = Copy_u32NumberOfTicks * 1000;

	/* Start timer */
	SET_BIT(STK->STK_CTRL, STK_CTRL_ENABLE);

	/* Read interrupt flag - bit 16 in CTRL register */
	Local_u32BIT = GET_BIT(STK->STK_CTRL, STK_CTRL_COUNTFLAG);

	/* Wait till flag is raised */
	while(Local_u32BIT == 0);
	
	/* Stop Timer */
	CLR_BIT(STK->STK_CTRL, STK_CTRL_ENABLE);
	STK->STK_LOAD = STK_u8CLEAR_VALUE;
	STK->STK_VAL  = STK_u8CLEAR_VALUE;
}


