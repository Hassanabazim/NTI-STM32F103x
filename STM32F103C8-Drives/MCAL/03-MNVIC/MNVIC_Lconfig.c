/*
 * MNVIC_Lconfig.c
 *
 *  Created on: Jan 22, 2024
 *      Author: Hassa
 */


#include "MNVIC_config.h"

MNVIC_CFG_t IRQ_PORT[MNVIC_IRQ_NUM] =
						{{MNVIC_WWDG_INT		,  DISABLE },
						{MNVIC_PVD_INT			,  DISABLE },
						{MNVIC_TAMPER_IN		,  DISABLE },
						{MNVIC_RTC_INT		    ,  DISABLE },
						{MNVIC_FLASH_INT		,  DISABLE },
						{MNVIC_RCC_INT		    ,  DISABLE },
						{MNVIC_EXT0_INT         ,  DISABLE },
						{MNVIC_EXT1_INT         ,  DISABLE },
						{MNVIC_EXT2_INT         ,  DISABLE },
						{MNVIC_EXT3_INT         ,  DISABLE },
						{MNVIC_EXT4_INT         ,  DISABLE },
						{MNVIC_DMA1_CH1_INT     ,  DISABLE },
						{MNVIC_DMA1_CH2_INT     ,  DISABLE },
						{MNVIC_DMA1_CH3_INT     ,  DISABLE },
						{MNVIC_DMA1_CH4_INT     ,  DISABLE },
						{MNVIC_DMA1_CH5_INT     ,  DISABLE },
						{MNVIC_DMA1_CH6_INT     ,  DISABLE },
						{MNVIC_DMA1_CH7_INT     ,  DISABLE },
						{MNVIC_ADC1_2_INT       ,  DISABLE },
						{MNVIC_USBHP_CANTX_INT  ,  DISABLE },
						{MNVIC_USBLP_CANTX_INT  ,  DISABLE },
						{MNVIC_CANRX1_INT       ,  DISABLE },
						{MNVIC_CAN_SCE_INT      ,  DISABLE },
						{MNVIC_EXT9_5INT        ,  DISABLE },
						{MNVIC_TIM1_BRK_INT     ,  DISABLE },
						{MNVIC_TIM1_UP_INT      ,  DISABLE },
						{MNVIC_TIME1_TRG_COM_INT,  DISABLE },
						{MNVIC_TIM1_CC_INT      ,  DISABLE },
						{MNVIC_TIM2_INT         ,  DISABLE },
						{MNVIC_TIM3_INT         ,  DISABLE },
						{MNVIC_TIM4_INT         ,  DISABLE },
						{MNVIC_I2C1_EV_INT      ,  DISABLE },
						{MNVIC_I2C1_ER_INT      ,  DISABLE },
						{MNVIC_I2C2_EV_INT      ,  DISABLE },
						{MNVIC_I2C2_ER_INT      ,  DISABLE },
						{MNVIC_SPI1_INT         ,  DISABLE },
						{MNVIC_SPI2_INT         ,  DISABLE },
						{MNVIC_USART1_INT       ,  DISABLE },
						{MNVIC_USART2_INT       ,  DISABLE },
						{MNVIC_USART3_INT       ,  DISABLE },
						{MNVIC_EXT15_10INT      ,  DISABLE },
						{MNVIC_RTCALARM_INT     ,  DISABLE },
						{MNVIC_USBWAKEUP_INT    ,  DISABLE },
						{MNVIC_FSMC_INT			,  DISABLE },
						{MNVIC_SDIO_INT         ,  DISABLE }};
