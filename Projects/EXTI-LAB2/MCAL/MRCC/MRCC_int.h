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
	DMA1=0, DMA2=1, SRAM=2, FLITF=4, CRC=6,
	TIM2=32, TIM3=33, TIM4=34, WWD=43, SPI2=46, USART2=49, USART3=50, I2C1=53, I2C2= 54, USB=55, CAN=57,
	MAFIO=64, IOPA=66, IOPB=67, IOPC=68, ADC1=73, ADC2=74, TIM1=75, SPI1=76, USART=78

}peripheral_ID;


ErrorState_t MRCC_enSysClkINIT(void);
ErrorState_t MRCC_enEnablePeripheralCLK(peripheral_ID copy_u8Periphera);
ErrorState_t MRCC_enDisablePeripheralCLK(peripheral_ID copy_u8Peripheral);

#endif  /* MRCC_INT_H_ */
