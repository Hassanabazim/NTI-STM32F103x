/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  24/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  EXT INT							 		*/
/****************************************************************/

#ifndef EXTINT_EXTINT_INT_H_
#define EXTINT_EXTINT_INT_H_



#define EXTI0_LINE		0
#define EXTI1_LINE		1
#define EXTI2_LINE		2
#define EXTI3_LINE		3
#define EXTI4_LINE		4
#define EXTI5_LINE		5
#define EXTI6_LINE		6
#define EXTI7_LINE		7
#define EXTI8_LINE		8
#define EXTI9_LINE		9
#define EXTI10_LINE		10
#define EXTI11_LINE		11
#define EXTI12_LINE		12
#define EXTI13_LINE		13
#define EXTI14_LINE		14
#define EXTI15_LINE		15

#define EXTI_RISING_TRIG	1
#define EXTI_FAILING_TRIG	2
#define EXTI_LOGIC_CHANGE	3

ErrorState_t MEXTI_enInit(void);
ErrorState_t MEXTI_enEnable(u8 Copy_u8LineId);
ErrorState_t MEXTI_enDisable(u8 Copy_u8LineId);
ErrorState_t MEXTI_enCallBack(u8 Copy_u8LineId, void (*ptr) (void));
ErrorState_t MEXTI_enSWInterrupt(u8 Copy_u8LineId);
ErrorState_t MEXTI_enClearPendingBit(u8 Copy_u8LineId);
ErrorState_t MEXTI_enSetLatch(u8 Copy_u8LineId, u8 Copy_u8Mode);


#endif /* EXTINT_EXTINT_INT_H_ */
