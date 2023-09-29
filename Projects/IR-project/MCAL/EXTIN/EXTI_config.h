/*****************************************************************************/
/* Author       	: 	Fahd Badi                                            */
/* Origin Date  	: 	24/07/2023                                           */
/* Version      	: 	1.0.0                                                */
/* SWC    	        : 	STM32F103C8 		                                 */
/*****************************************************************************/

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H



/* EXTI Lines Options: EXTI_u8LINE0 TO EXTI_u8LINE15 */
#define EXTI_u8LINE_CONFIG    EXTI_u8LINE0

/*****************************************************************************
 EXTI Mode Options:
					1- EXTI_u8RISING_EDGE
					2- EXTI_u8FALLING_EDGE
					3- EXTI_u8ON_CHANGE_EDGE
*****************************************************************************/
#define EXTI_u8MODE       EXTI_u8FALLING_EDGE



#endif
