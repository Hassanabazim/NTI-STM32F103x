/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  25/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  SYSTICK						 		    */
/****************************************************************/

#ifndef SYSTICK_SYSTICK_INT_H_
#define SYSTICK_SYSTICK_INT_H_


ErrorState_t MSTK_enInit(void);
ErrorState_t MSTK_enDelayMS(u16 copy_u16delayMS);
ErrorState_t MSTK_enSetIntervalSingle(u32 copy_u32TicksNum,void(*ptrfn)(void));
ErrorState_t MSTK_enSetIntervalPeriodic(u32 copy_u32TicksNum,void(*ptrfn)(void));
ErrorState_t MSTK_enGetElapsedTime(u32 *copy_u32ElapsedValue);
ErrorState_t MSTK_enRemainingValue(u32 *copy_u32RemainingValue);
ErrorState_t MSTK_enStop(void);

#endif /* SYSTICK_SYSTICK_INT_H_ */
