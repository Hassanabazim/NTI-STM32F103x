/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  9/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  DRIVES UNIT TESTING 					    */
/****************************************************************/
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
#include "MAFIO_int.h"
#include "MSTICK_int.h"
#include "MDMA_int.h"
#include "MUSART_int.h"
#include "MSPI_int.h"
#include "HLED_int.h"
#include "HPB_int.h"
#include "HSSD_int.h"
#include "HKEYPAD_int.h"
#include "HLCD_int.h"
#include "HLEDMRX_int.h"
#include "APP_int.h"
#include "APP_config.h"
#include "APP_priv.h"




void App_voidstartApp(void)
{
#if (APPLICATION == RCC_TEST)

	MRCC_enSysClkINIT();

	/* change the peripherial */
	MRCC_enEnablePeripheralCLK(MRCC_IOPA);
	MRCC_enDisablePeripheralCLK(MRCC_IOPB);

	while (1)

	{

	}

#elif(APPLICATION == GPIO_TEST)

	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(IOPA);
	MRCC_enEnablePeripheralCLK(IOPB);
	MRCC_enEnablePeripheralCLK(IOPC);

#if 0
	/* testing SetPinDirection and SetPinValue */
	MGPIO_enSetPinDirection(PORTA, PIN0, OUT_2MHZ_PP);
	MGPIO_enSetPinDirection(PORTA, PIN1, OUT_2MHZ_PP);
	MGPIO_enSetPinDirection(PORTA, PIN2, IN_ANALOG);
	MGPIO_enSetPinDirection(PORTB, PIN8, IN_FLOATING);
	MGPIO_enSetPinDirection(PORTB, PIN0, IN_PU_PD);

#elif 0
	/* GetPinValue use debugger to see the vari or use setpin value fn */
	u8 pinvalue ;
	MGPIO_enSetPinDirection(PORTA, PIN0, OUT_2MHZ_PP);
	MGPIO_enSetPinValue(PORTA, PIN0, HIGH);
	MGPIO_enGetPinValue(PORTA, PIN0, &pinvalue);
	MGPIO_enSetPinValue(PORTA, PIN0, pinvalue);

#elif 0
	/* test SetPortDirection and SetPortValue */
	MGPIO_enSetPortDirection(GPIO_CRL_ID, PORTA, OUT_2MHZ_PP);
	MGPIO_enSetPortDirection(GPIO_CRH_ID, PORTA, OUT_2MHZ_PP);
	MGPIO_enSetPortDirection(GPIO_CRL_ID, PORTB, OUT_2MHZ_PP);
	MGPIO_enSetPortDirection(GPIO_CRH_ID, PORTB, OUT_2MHZ_PP);

#elif 1
	MGPIO_enSetPinDirection(PORTA, PIN0, OUT_2MHZ_PP);
	MGPIO_enLockPin(PORTA, PIN0);
#endif

	while(1)
	{

#if 0
		/* test toggle function */
		MGPIO_enTogglePin(PORTA, PIN0);
#elif 0
		/* testing Set Reset FN with SetPinValue */
		MGPIO_enSetResetPin(PORTA, PIN0, GPIO_PIN_SET);
		MGPIO_enSetResetPin(PORTA, PIN1, GPIO_PIN_RESET);

#elif 0
		/* testing SetPinValue fun */
		MGPIO_enSetPinValue(PORTA, PIN0, HIGH);
		MGPIO_enSetPinValue(PORTA, PIN1, HIGH);

#elif 0
		MGPIO_enSetPortValue(GPIO_CRL_ID, PORTA, HIGH);
		MGPIO_enSetPortValue(GPIO_CRH_ID, PORTA, HIGH);
		MGPIO_enSetPortValue(GPIO_CRL_ID, PORTB, HIGH);
		MGPIO_enSetPortValue(GPIO_CRH_ID, PORTB, HIGH);

#endif
	}

#elif(APPLICATION == NVIC_TEST)
	/* test bunch of fuction together and sum alone to verify the result
	 * with debbuger, here i verify functions and normal, nesting interrupt
	 * by changing the prioritry of the ex-interrupt
	 */
	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(IOPA);
	MNVIC_enEnableNVIC();
#if 0
	MNVIC_enEnableInt(RCC_INT);
	MNVIC_enDisableInt(RCC_INT);
#endif

	MGPIO_enSetPinDirection(PORTA, PIN0, OUT_2MHZ_PP);
	MGPIO_enSetPinDirection(PORTA, PIN1, OUT_2MHZ_PP);
	MGPIO_enSetPinDirection(PORTA, PIN2, OUT_2MHZ_PP);

	MNVIC_enSetPriority(EXT0_INT,2,0);
	MNVIC_enSetPriority(EXT1_INT,1,0);

	MNVIC_enEnableInt(EXT1_INT);
	MNVIC_enEnableInt(EXT0_INT);

	MNVIC_enSetPendingFlag(EXT0_INT);

#if 0
	u8 pending, active;
	MNVIC_enGetPendingFlag(EXT1_INT, &pending);
	MNVIC_enGetActiveFlag(EXT1_INT, &active);
	MNVIC_enClrPendingFlag(EXT1_INT);
	MNVIC_enGetPendingFlag(EXT1_INT, &pending);
#endif

	while(1)
	{

	}

#elif(APPLICATION == MEXTI_TEST)
#elif(APPLICATION == MAFIO_TEST)
#elif(APPLICATION == MSTICK_TEST)
#elif(APPLICATION == MDMA_TEST)
	MDMA_INIT_st vari ;
	u8 state;
	u32 arr1[1000] = {1,1,1,1,1,1,1,1,1,arr1[500]=500, arr1[999]=2};
	u32 arr2[1000];
	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(MRCC_DMA1);
	MRCC_enEnablePeripheralCLK(MRCC_IOPB);
	MGPIO_enSetPinDirection(PORTB, PIN12, OUT_2MHZ_PP);
	MNVIC_enEnableNVIC();
	MNVIC_enEnableInt(DMA1_CH1);
	vari.Circular_Mode = MDMA_Channel_PRI_HIGH;
	vari.Channel_Priority = MDMA_Channel_PRI_HIGH;
	vari.DMA_Mode = MDMA_FRunning_ON;
	vari.Source_Mode = MDMA_Peripheral_Src;
	vari.MINK_Mode = MDMA_MINK_ON ;
	vari.PINK_Mode = MDMA_PINK_ON;
	vari.Memory_SizeElement = MDMA_Memory_4ByteSize ;
	vari.Preiphial_SizeElemnet = MDMA_Preiphial_4ByteSize;
	MDMA_enInit(Channel1, &vari);
	MDMA_enIntCallBack(Channel1, CallBackAction);
	MDMA_enEnableInt(Channel1, MDMA_TC_INT);
	MDMA_enTranferInit(Channel1, arr1, arr2 , 1000);
	MDMA_enReadIntState(Channel1, MDMA_TC_INT, &state);
	MDMA_enDisableInt(Channel1, MDMA_TC_INT);
	while(1)
	{

	}
#elif(APPLICATION == MADC_TEST)

#elif(APPLICATION == MUSART_TEST)
	//u8 data;
	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(MRCC_USART1);
	MRCC_enEnablePeripheralCLK(MRCC_IOPA);
	MGPIO_enSetPinDirection(PORTA, MUSART_TX_PIN, OUT_50MHZ_AF_PP);
	MGPIO_enSetPinDirection(PORTA, MUSART_RX_PIN, IN_FLOATING);
	MNVIC_enEnableNVIC();
	MNVIC_enEnableInt(USART1_INT);
	context.copy_u8Txdata = 'H';
	context.TxRx_callback = CallBackAction;
	MUSART_enIntCallBack(MUSART1, &context);

	MUSART_enInit(MUSART1);
	MUSART_enEnableInt(MUSART1, TXEmpty_INT);
	//MUSART_enEnableInt(MUSART1, TXCompelete_INT);
	//MUSART_enEnableInt(MUSART1, RXNEmpty_INT);




	//MUSART_enBusySendByte(MUSART1, 'H');
	while(1)
	{
		//MUSART_enBusySendString(MUSART1, "Hassan");
		//MUSART_enBusyReceiveByte(MUSART1, &data);


	}
#elif(APPLICATION == MSPI_TEST)
	u16 data;
	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(MRCC_IOPA);
	MRCC_enEnablePeripheralCLK(MRCC_SPI1);

	// SPI1 GPIO PINS Initialization
	MGPIO_enSetPinDirection(PORTA, MSPI1_NSS_PIN, OUT_10MHZ_PP);
	MGPIO_enSetPinDirection(PORTA, MSPI1_CLK_PIN, OUT_10MHZ_PP);
	MGPIO_enSetPinDirection(PORTA, MSPI1_MISO_PIN,IN_FLOATING);
	MGPIO_enSetPinDirection(PORTA, MSPI1_MOSI_PIN,OUT_10MHZ_PP);

	MSPI_enMasterInit(MSPI1);
	MSPI_enMasterSend(MSPI1, 'H');
	//MSPI_enSlaveReceive(MSPI1, &data);

	while (1)
	{


	}

#elif(APPLICATION == HLED_TEST)
#elif(APPLICATION == HPB_TEST)
#elif(APPLICATION == HSSD_TEST)
#elif(APPLICATION == HKEYPAD_TEST)
#elif(APPLICATION == HLCD_TEST)
#elif(APPLICATION == HLEDMRX_TEST)

#else
#error("Wrong Unit Testing");
#endif
}



#if(APPLICATION == NVIC_TEST)
void EXTI0_IRQHandler(void)
{
	MGPIO_enSetPinValue(PORTA , PIN0 , HIGH );
	MNVIC_enSetPendingFlag(EXT1_INT);
	MGPIO_enSetPinValue(PORTA , PIN2 , HIGH );
}

void EXTI1_IRQHandler(void)
{
	MGPIO_enSetPinValue(PORTA , PIN1 , HIGH );
}
#endif

