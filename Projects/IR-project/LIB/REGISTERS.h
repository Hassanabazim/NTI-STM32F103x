/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  11/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  STM32F103C8						 		*/
/****************************************************************/

#ifndef REGISTERS_H_
#define REGISTERS_H_

#define   EXTI_u32BASE_ADDRESS    0x40010400


typedef struct
{
	volatile u32 EXTI_IMR;
	volatile u32 EXTI_EMR;
	volatile u32 EXTI_RTSR;
	volatile u32 EXTI_FTSR;
	volatile u32 EXTI_SWIER;
	volatile u32 EXTI_PR;

}EXTI_RegDef_t;


#define   EXTI    ((EXTI_RegDef_t *) EXTI_u32BASE_ADDRESS)
/************************** RCC REGISTERS ***********************/
#define RCC_u32BASE_ADDRESS		 0x40021000

typedef struct 
{
	u32 RCC_CR;
	u32 RCC_CFGR;
	u32	RCC_CIR;
	u32 RCC_APB2RSTR;
	u32 RCC_APB1RSTR;
	u32 RCC_AHBENR;
	u32	RCC_APB2ENR;
	u32 RCC_APB1ENR;
	u32	RCC_BDCR;
	u32 RCC_CSR;
}RCC_REG_DEF_t;

#define RCC 	((RCC_REG_DEF_t*)RCC_u32BASE_ADDRESS)


/************************** GPIO REGISTERS **********************/
#define GPIOA_u32BASE_ADDRESS		 0x40010800
#define GPIOB_u32BASE_ADDRESS		 0x40010C00
#define GPIOC_u32BASE_ADDRESS		 0x40011000

typedef struct
{
	u32 GPIO_CRL;
	u32 GPIO_CRH;
	u32	GPIO_IDR;
	u32 GPIO_ODR;
	u32 GPIO_BSRR;
	u32 GPIO_BRR;
	u32	GPIO_LCKR;
}GPIO_REG_DEF_t;

#define GPIOA	((GPIO_REG_DEF_t*)GPIOA_u32BASE_ADDRESS)
#define GPIOB	((GPIO_REG_DEF_t*)GPIOB_u32BASE_ADDRESS)
#define GPIOC	((GPIO_REG_DEF_t*)GPIOC_u32BASE_ADDRESS)



/************************** NVIC REGISTERS **********************/

#define NVIC_u32BASE_ADDRESS		 0xE000E100

typedef struct
{
	u32 NVIC_ISER[3];
	u32 RESERVED1[29];

	u32 NVIC_ICER[3];
	u32 RESERVED2[29];

	u32 NVIC_ISPR[3];
	u32 RESERVED3[29];

	u32 NVIC_ICPR[3];
	u32 RESERVED4[29];

	volatile u32 NVIC_IABR[3];
	u32 RESERVED5[61];

	volatile u8 NVIC_IPR[81];

}NVIC_REG_DEF_t;

#define NVIC 	((NVIC_REG_DEF_t*)NVIC_u32BASE_ADDRESS)


/***************************CSB REGISTERS *************************/

#define CSB_u32BASE_ADDRESS		0xE000ED00
#define CSB_u32OFFSET			0x0C

#define SCB_AIRCR 	*((u32*)NVIC_u32BASE_ADDRESS + CSB_u32OFFSET)


/***************************SYSTICK REGISTERS**********************/
#define STK_u32BASE_ADDRESS		 0xE000E010

typedef struct
{
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;

}STK_REG_DEF_t;

#define STK 	((STK_REG_DEF_t*)STK_u32BASE_ADDRESS)

/***************************DMA REGISTERS**********************/
#define DMA_u32BASE_ADDRESS		 0x40020000

/*typedef struct
{
	u32 DMA_ISR;
	u32 DMA_IFCR;
	u32 DMA_CCR1;
	u32 STK_CALIB;

}STK_REG_DEF_t;

#define STK 	((STK_REG_DEF_t*)STK_u32BASE_ADDRESS)*/


#endif /* REGISTERS_H_ */
