//****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  NVIC							 		    */
/****************************************************************/

#ifndef MNVIC_MNVIC_INT_H_
#define MNVIC_MNVIC_INT_H_


typedef enum
{
	WWDG_INT_, PVD_INT, TAMPER_INT, RTC_INT, FLASH_INT, RCC_INT, EXT0_INT,EXT1_INT, EXT2_INT,
	EXT3_INT, EXT4_INT, DMA1_CH1, DMA1_CH2, DMA1_CH3,DMA1_CH4, DMA1_CH5, DMA1_CH6, DMA1_CH7,
	ADC1_2, USBHP_CANTX, USBLP_CANTX, CANRX1,CAN_SCE, EXT9_5INT, TIM1_BRK, TIM1_UP, TIME1_TRG_COM,
	TIM1_CC, TIM2_INT, TIM3_INT, TIM4_INT,I2C1_EV, I2C1_ER, I2C2_EV, I2C2_ER, SPI1_INT, SPI2_INT,
	USART1_INT, USART2_INT, USART3_INT,EXT15_10INT,RTCALARM, USBWAKEUP, TIM8_BRK, TIM8_UP,
	TIM8_TRG_COM, TIM8_CC, ADC3_INT, FSMC, SDIO, TIM5_INT, SPI3_INT, UART4_INT, UART_INT,
	TIM6_INT, TIM7_INT, DMA2_CH1, DMA2_CH2, DMA2_CH3, DMA2_CH4_5
}VectorTable_t;




ErrorState_t MNVIC_enEnableNVIC(void);
ErrorState_t MNVIC_enEnableInt(VectorTable_t copy_u8IRQnum);
ErrorState_t MNVIC_enDisableInt(VectorTable_t copy_u8IRQnum);
ErrorState_t MNVIC_enSetPendingFlag(VectorTable_t copy_u8IRQnum);
ErrorState_t MNVIC_enClrPendingFlag(VectorTable_t copy_u8IRQnum);
ErrorState_t MNVIC_enGetPendingFlag(VectorTable_t copy_u8IRQnum, u8 *PendingState);
ErrorState_t MNVIC_enGetActiveFlag(VectorTable_t copy_u8IRQnum, u8 *ActiveState);
ErrorState_t MNVIC_enSetPriority(VectorTable_t copy_u8IRQnum, u8 copy_u8Group, u8 copy_u8Sub);

#endif /* MNVIC_MNVIC_INT_H_ */
