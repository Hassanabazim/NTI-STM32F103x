/*****************************************************************************/
/* Author       	: 	Fahd Badi                                            */
/* Origin Date  	: 	25/07/2023                                           */
/* Version      	: 	1.0.0                                                */
/* SWC    	        : 	SysTick (STK) 		                                 */
/*****************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


/* Clock Source Selection */
#define STK_u8CLK_AHB_DIV_8      0
#define STK_u8CLK_AHB		     1

/* Interval Sode */
#define STK_u8SINGLE_MODE     0
#define STK_u8PERIODIC_MODE    1

/*  */
#define  STK_u32LOAD_MAX_VALUE    0x00FFFFFF
#define  STK_u8CLEAR_VALUE        0

/* SysTick control and status register bits */
#define  STK_CTRL_ENABLE       0
#define  STK_CTRL_TICKINT      1
#define  STK_CTRL_CLKSOURCE    2
#define  STK_CTRL_COUNTFLAG    16



#endif
