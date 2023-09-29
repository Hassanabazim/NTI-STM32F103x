/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  11/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  RCC								 		*/
/****************************************************************/

#ifndef MRCC_INT_H_
#define MRCC_INT_H_

/****************************************************************/
/* PLEASE CHOOSE PERIPHEIAL CLK REGISTER FROM THE FOLLOWING :	*/
/*																*/
/* AHB_BUS_ID -- RCC_AHBENR										*/
/* APB1_BUS_ID --RCC_APB2ENR									*/
/* APB2_BUS_ID --RCC_APB1ENR									*/
/****************************************************************/
typedef enum
{
	AHB_BUS_ID,
	APB1_BUS_ID,
	APB2_BUS_ID
}BUS_ID;

/****************************************************************/
/* PLEASE CHOOSE PERIPHEIAL CORRESPONDIING TO IT'S REGISTER :	*/
/* 															    */
/*	DMA1, DMA2, SRAM, FLITF, CRC								*/
/*	TIM2, TIM3, SPI2, USART2, USART3, I2C1, I2C2, USB, CAN		*/
/*  AFIO,  IOPA, IOPB , IOPC, ADC1, ADC2, TIM1, SPI1, USART		*/
/****************************************************************/
typedef enum 
{
	MRCC_DMA1=0, MRCC_DMA2=1, MRCC_SRAM=2, MRCC_FLITF=4, MRCC_CRC=6, MRCC_TIM2=32,
	MRCC_TIM3=33,MRCC_TIM4=34, MRCC_WWD=43, MRCC_SPI2=46, MRCC_USART2=49, MRCC_USART3=50,
	MRCC_I2C1=53,MRCC_I2C2= 54,MRCC_USB=55, MRCC_CAN=57, MRCC_AFIO=64, MRCC_IOPA=66,
	MRCC_IOPB=67, MRCC_IOPC=68, MRCC_ADC1=73, MRCC_ADC2=74, MRCC_TIM1=75, MRCC_SPI1=76, MRCC_USART1=78

}peripheral_ID;


ErrorState_t MRCC_enSysClkINIT(void);
ErrorState_t MRCC_enEnablePeripheralCLK(peripheral_ID copy_u8Periphera);
ErrorState_t MRCC_enDisablePeripheralCLK(peripheral_ID copy_u8Peripheral);

#endif  /* MRCC_INT_H_ */
