/*****************************************************************************/
/* Author       	: 	Fahd Badi                                            */
/* Origin Date  	: 	25/07/2023                                           */
/* Version      	: 	1.0.0                                                */
/* SWC    	        : 	SysTick (STK) 		                                 */
/*****************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/* Prototype Functions */
void STK_voidInit(void);
void STK_voidStopTimer(void);
u8 STK_u8SetBusyWait(u32 Copy_u32NumberOfTicks);
u8 STK_u8SetIntervalSingle(u32 Copy_u32NumberOfTicks,
                              void(*Copy_pfNotification)(void));
u8 STK_u8SetIntervalPeriodic(u32 Copy_u32NumberOfTicks,
								void(*Copy_pfNotification)(void));						  
u8 STK_u8GetElapsedTime(u32 *Copy_pu32ElapsedTime);
u8 STK_u8GetRemainingTime(u32 *Copy_pu32RemainingTime);
void STK_voidDelay_ms(u32 Copy_u32NumberOfTicks);


#endif
