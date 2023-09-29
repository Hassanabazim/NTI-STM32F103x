/*****************************************************************************/
/* Author       	: 	Fahd Badi                                            */
/* Origin Date  	: 	24/07/2023                                           */
/* Version      	: 	1.0.0                                                */
/* SWC    	        : 	STM32F103C8 		                                 */
/*****************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/* EXTI Lines Options: */
#define  EXTI_u8LINE0     0
#define  EXTI_u8LINE1     1
#define  EXTI_u8LINE2     2
#define  EXTI_u8LINE3     3
#define  EXTI_u8LINE4     4
#define  EXTI_u8LINE5     5
#define  EXTI_u8LINE6     6
#define  EXTI_u8LINE7     7
#define  EXTI_u8LINE8     8
#define  EXTI_u8LINE9     9
#define  EXTI_u8LINE10    10
#define  EXTI_u8LINE11    11
#define  EXTI_u8LINE12    12
#define  EXTI_u8LINE13    13
#define  EXTI_u8LINE14    14
#define  EXTI_u8LINE15    15


#define EXTI_u8RISING_EDGE      1
#define EXTI_u8FALLING_EDGE     2
#define EXTI_u8ON_CHANGE_EDGE   3




void EXTI_voidInit(void);
u8 EXTI_u8Enable(u8 Copy_u8LineId);
u8 EXTI_u8Disable(u8 Copy_u8LineId);
u8 EXTI_u8SoftWareTrigger(u8 Copy_u8LineId);
u8 EXTI_u8SetSignalLatch(u8 Copy_u8LineId, u8 Copy_u8Mode);
void EXTI_ClearPendingBit(u8 Copy_u8LineId);
void EXTI0_VidSetCallBack( void (*ptr) (void) );
void EXTI1_VidSetCallBack( void (*ptr) (void) );




#endif
