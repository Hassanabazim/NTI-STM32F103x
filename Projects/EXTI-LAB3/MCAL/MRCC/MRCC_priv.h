/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  11/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  RCC								 		*/
/****************************************************************/

#ifndef MRCC_PRIV_H_
#define	MRCC_PRIV_H_

/***********************MOST USED PINS***************************/
#define	HSION					0
#define HSIRDY					1
#define	HSEON					16
#define HSERDY					17
#define HSEBYP					18
#define CSS						19
#define	PLLON					24
#define PLLRDY					25

#define SWC						0
#define PLLXTPRE				16
#define PLLSRC					17

/***********************PINS PRE BULID **************************/
#define RCC_CSS_ON				1
#define RCC_CSS_OFF				0
#define RCC_MCO_ON				2
#define RCC_MCO_OFF				3

/***********************RCC CLOCK TYPE***************************/
#define RCC_HSE_CRYSTAL			1
#define RCC_HSE_RC				2
#define RCC_HSI					3
#define RCC_PLL					4


/********************APB1,APB2 PRESCALER*************************/
#define RCC_HCLK_NOT_DIV 		0
#define RCC_HCLK_DIV_2 			4
#define RCC_HCLK_DIV_4			5
#define RCC_HCLK_DIV_8			6
#define RCC_HCLK_DIV_16			7


/***********************AHB PRESCALER****************************/
#define RCC_SYSCLK_NOT_DIV		0
#define RCC_SYSCLK_DIV_2		8
#define RCC_SYSCLK_DIV_4		9
#define RCC_SYSCLK_DIV_8		10
#define RCC_SYSCLK_DIV_16		11
#define RCC_SYSCLK_DIV_64		12
#define RCC_SYSCLK_DIV_128		13
#define RCC_SYSCLK_DIV_256		14
#define RCC_SYSCLK_DIV_512		15


/****************************MCO MODES***************************/
#define RCC_MCO_NO_CLK			0
#define RCC_MCO_SYS_CLK			4
#define RCC_MCO_HSI_CLK			5
#define RCC_MCO_HSE_CLK			6
#define RCC_MCO_PLL_DIV_2		7


/****************************PLL MUL FACTORS**********************/
#define RCC_PLL_CLK_MUL_2		0x0
#define RCC_PLL_CLK_MUL_3		0x1
#define RCC_PLL_CLK_MUL_4		0x2
#define RCC_PLL_CLK_MUL_5		0x3
#define RCC_PLL_CLK_MUL_6		0x4
#define RCC_PLL_CLK_MUL_7		0x5
#define RCC_PLL_CLK_MUL_8		0x6
#define RCC_PLL_CLK_MUL_9		0x7
#define RCC_PLL_CLK_MUL_10		0x8
#define RCC_PLL_CLK_MUL_11		0x9
#define RCC_PLL_CLK_MUL_12		0xA
#define RCC_PLL_CLK_MUL_13		0xB
#define RCC_PLL_CLK_MUL_14		0xC
#define RCC_PLL_CLK_MUL_15		0xD
#define RCC_PLL_CLK_MUL_16		0xE


/***********************PLL SYSTEM SELECTION*********************/
#define RCC_PLL_HSI_DIV_2			0
#define RCC_PLL_HSE					1
#define RCC_PLL_HSE_DIV_2			2

/*****************SYSTEM REGISTERS MASKING***********************/
#define RCC_SCW_MASK			0xFFFFFFFC
#define RCC_AHB_MASK			0xFFFFFF0F
#define RCC_APB1_MASK			0xFFFFF8FF
#define RCC_APB2_MASK			0xFFFFC7FF
#define RCC_PLL_CLK_MASK		0xFFC3FFFF
#define RCC_MCO_MASK			0xF8FFFFFF






#endif /* MRCC_PRIV_H_ */
