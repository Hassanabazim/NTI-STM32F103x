  /****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  11/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  RCC								 		*/
/****************************************************************/

#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_


/****************************************************************/
/* PLEASE CHOOSE RCC CLOCK TYPE FROM THE FOLLOWING:
*
*	 RCC_HSE_CRYSTAL
* 	 RCC_HSE_RC
* 	 RCC_HSI
* 	 RCC_PLL
*/
/****************************************************************/
#define RCC_CLK_TYPE	RCC_HSI

/****************************************************************/
/* PLEASE CHOOSE CSS MODE FROM THE FOLLOWING:					*/
/*																*/
/*	RCC_CSS_ON													*/
/* 	RCC_CSS_OFF													*/
/*	MCO_ON														*/
/* 	MCO_OFF														*/
/****************************************************************/
#define RCC_CSS_EN	RCC_CSS_OFF
#define RCC_MCO_EN	RCC_MCO_OFF

/****************************************************************/
/* PLEASE CHOOSE FROM THE FOLLOWING AHB PRESCALER :				*/
/* 												    			*/
/* RCC_SYSCLK_NOT_DIV 											*/
/* RCC_SYSCLK_DIV_2 											*/
/* RCC_SYSCLK_DIV_4												*/
/* RCC_SYSCLK_DIV_8												*/
/* RCC_SYSCLK_DIV_16											*/
/* RCC_SYSCLK_DIV_64											*/
/* RCC_SYSCLK_DIV_128											*/
/* RCC_SYSCLK_DIV_256											*/
/* RCC_SYSCLK_DIV_512											*/
/****************************************************************/
#define RCC_AHB_PRESCALER	RCC_SYSCLK_NOT_DIV << 4

/****************************************************************/
/* PLEASE CHOOSE FROM THE FOLLOWING APB1, APB2 PRESCALER		*/
/* 												    			*/
/* RCC_HCLK_NOT_DIV 											*/
/* RCC_HCLK_DIV_2 												*/
/* RCC_HCLK_DIV_4												*/
/* RCC_HCLK_DIV_8												*/
/* RCC_HCLK_DIV_16												*/
/****************************************************************/
#define RCC_APB1_PRESCALER_MODE	RCC_HCLK_NOT_DIV << 8
#define RCC_APB2_PRESCALER_MODE	RCC_HCLK_NOT_DIV << 11

/****************************************************************/
/* PLEASE CHOOSE FROM THE FOLLOWING MCO MODES:					*/
/*																*/
/*  RCC_MCO_NO_CLK												*/
/* 	RCC_MCO_SYS_CLK												*/
/*	RCC_MCO_HSI_CLK												*/
/* 	RCC_MCO_HSE_CLK												*/
/* 	RCC_MCO_PLL_DIV_2											*/
/****************************************************************/
#define RCC_MCO_MODE		RCC_MCO_SYS_CLK << 24

/****************************************************************/
/*PLEASE CHOOSE FROM THE FOLLOWING PLL MUL FACTORS:				*/
/*																*/
/*	RCC_PLL_CLK_MUL_2											*/
/*	RCC_PLL_CLK_MUL_3											*/
/*	RCC_PLL_CLK_MUL_4											*/
/*	RCC_PLL_CLK_MUL_5											*/
/*	RCC_PLL_CLK_MUL_6											*/
/*	RCC_PLL_CLK_MUL_7											*/
/*	RCC_PLL_CLK_MUL_8											*/
/*	RCC_PLL_CLK_MUL_9											*/
/*	RCC_PLL_CLK_MUL_10											*/
/*	RCC_PLL_CLK_MUL_11											*/
/*	RCC_PLL_CLK_MUL_12											*/
/*	RCC_PLL_CLK_MUL_13											*/
/*	RCC_PLL_CLK_MUL_14											*/
/*	RCC_PLL_CLK_MUL_15											*/
/*	RCC_PLL_CLK_MUL_16											*/
/****************************************************************/
#define RCC_PLL_MUL_FAC		RCC_PLL_CLK_MUL_2<< 18

/****************************************************************/
/* PLEASE CHOOSE FROM THE FOLLOWING PLL INPUT SELECTION MODES:	*/
/*																*/
/*  RCC_PLL_HSI_DIV_2											*/
/* 	RCC_PLL_HSE													*/
/*	RCC_PLL_HSE_DIV_2											*/
/****************************************************************/
#define RCC_PLL_INPUT_MODE 	RCC_PLL_HSI_DIV_2

#endif  /* MRCC_CONFIG_H_ */
