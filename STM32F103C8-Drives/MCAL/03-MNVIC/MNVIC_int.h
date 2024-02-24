/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  MNVIC_int.h
 *         @Module	:  NVIC
 *
 *  Description:  This file Provide the Module APIs and Interfacing MACROS and Data types
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HEADER GUARD
 *********************************************************************************************************************/
#ifndef MNVIC_MNVIC_INT_H_
#define MNVIC_MNVIC_INT_H_

#include "ERROR_STATE.h"
#include "STD_TYPES.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// NVIC Vector Table

typedef enum
{
	MNVIC_WWDG_INT		     ,
	MNVIC_PVD_INT			 ,
	MNVIC_TAMPER_IN		     ,
	MNVIC_RTC_INT		     ,
	MNVIC_FLASH_INT		     ,
	MNVIC_RCC_INT		     ,
	MNVIC_EXT0_INT           ,
	MNVIC_EXT1_INT           ,
	MNVIC_EXT2_INT           ,
	MNVIC_EXT3_INT           ,
	MNVIC_EXT4_INT           ,
	MNVIC_DMA1_CH1_INT       ,
	MNVIC_DMA1_CH2_INT       ,
	MNVIC_DMA1_CH3_INT       ,
	MNVIC_DMA1_CH4_INT       ,
	MNVIC_DMA1_CH5_INT       ,
	MNVIC_DMA1_CH6_INT       ,
	MNVIC_DMA1_CH7_INT       ,
	MNVIC_ADC1_2_INT         ,
	MNVIC_USBHP_CANTX_INT    ,
	MNVIC_USBLP_CANTX_INT    ,
	MNVIC_CANRX1_INT         ,
	MNVIC_CAN_SCE_INT        ,
	MNVIC_EXT9_5INT          ,
	MNVIC_TIM1_BRK_INT       ,
	MNVIC_TIM1_UP_INT        ,
	MNVIC_TIME1_TRG_COM_INT  ,
	MNVIC_TIM1_CC_INT        ,
	MNVIC_TIM2_INT           ,
	MNVIC_TIM3_INT           ,
	MNVIC_TIM4_INT           ,
	MNVIC_I2C1_EV_INT        ,
	MNVIC_I2C1_ER_INT        ,
	MNVIC_I2C2_EV_INT        ,
	MNVIC_I2C2_ER_INT        ,
	MNVIC_SPI1_INT           ,
	MNVIC_SPI2_INT           ,
	MNVIC_USART1_INT         ,
	MNVIC_USART2_INT         ,
	MNVIC_USART3_INT         ,
	MNVIC_EXT15_10INT        ,
	MNVIC_RTCALARM_INT       ,
	MNVIC_USBWAKEUP_INT      ,
	MNVIC_FSMC_INT =  48	 ,
	MNVIC_SDIO_INT           ,
}MNVIC_IRQ_t;

typedef enum
{
	DISABLE, ENABLE
}MNVIC_STATE_t;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
ErrorState_t MNVIC_enIRQInit(void);
ErrorState_t MNVIC_enIRQDeInit(void);
ErrorState_t MNVIC_enSetPendingFlag(MNVIC_IRQ_t copy_u8IRQnum);
ErrorState_t MNVIC_enClrPendingFlag(MNVIC_IRQ_t copy_u8IRQnum);
ErrorState_t MNVIC_enGetPendingFlag(MNVIC_IRQ_t copy_u8IRQnum, u8 *PendingState);
ErrorState_t MNVIC_enGetActiveFlag(MNVIC_IRQ_t copy_u8IRQnum, u8 *ActiveState);
ErrorState_t MNVIC_enSetPriority(MNVIC_IRQ_t copy_u8IRQnum, u8 copy_u8Group, u8 copy_u8Sub);


#endif /* MNVIC_MNVIC_INT_H_ */
/**********************************************************************************************************************
 *  END OF FILE: MNVIC_int.h
 *********************************************************************************************************************/

