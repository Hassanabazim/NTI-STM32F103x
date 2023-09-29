//****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  NVIC							 		    */
/****************************************************************/

#ifndef MNVIC_MNVIC_INT_H_
#define MNVIC_MNVIC_INT_H_






ErrorState_t MNVIC_enEnableNVIC(void);
ErrorState_t MNVIC_enEnableInt(u8 copy_u8IRQnum);
ErrorState_t MNVIC_enDisableInt(u8 copy_u8IRQnum);
ErrorState_t MNVIC_enSetPendingFlag(u8 copy_u8IRQnum);
ErrorState_t MNVIC_enClrPendingFlag(u8 copy_u8IRQnum);
ErrorState_t MNVIC_enGetPendingFlag(u8 copy_u8IRQnum, u8 *PendingState);
ErrorState_t MNVIC_enGetActiveFlag(u8 copy_u8IRQnum, u8 *ActiveState);
ErrorState_t MNVIC_enSetPriority(u8 copy_u8IRQnum, u8 copy_u8Priority);

#endif /* MNVIC_MNVIC_INT_H_ */
