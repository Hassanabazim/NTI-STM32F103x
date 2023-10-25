/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  APP_prog.c
 *         @Module	:  APP
 *
 *  Description:  This file provide Module APIs code Implementation
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
#include "MAFIO_int.h"
#include "MSYSTICK_int.h"
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



/**********************************************************************************************************************
 *  CALLBACK FUNCTIONS
 *********************************************************************************************************************/
void App(void)
{

}
/*********************************************************************************************************************/
#if (APPLICATION == MNVIC_TEST)
/*********************************************************************************************************************/
void Action1(void)
{
	MGPIO_enSetPinValue(PORTA , PIN0 , HIGH );
	MNVIC_enSetPendingFlag(MNVIC_EXT1_INT);
	MGPIO_enSetPinValue(PORTA , PIN2 , HIGH );
}

void Action2(void)
{
	MGPIO_enSetPinValue(PORTA , PIN1 , HIGH );
}
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void App_voidstartApp(void)
 *
 * \Description     : This Services for start the Application
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 *
 * \Return value:   : None
 *******************************************************************************/
void App_voidstartApp(void)
{
	/*****************************************************************************************************************/
#if (APPLICATION == MRCC_TEST)
	/*****************************************************************************************************************/

	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(MRCC_IOPA);
	MRCC_enDisablePeripheralCLK(MRCC_IOPA);

	while (1)
	{

	}
	/*****************************************************************************************************************/
#elif(APPLICATION == MGPIO_TEST)
	/*****************************************************************************************************************/

	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(MRCC_IOPA);
	MRCC_enEnablePeripheralCLK(MRCC_IOPB);
	MRCC_enEnablePeripheralCLK(MRCC_IOPC);

#if 1
	u8 pinvalue ;
	/* testing SetPinDirection, SetPinValue,GetpinValue and LOCKpin */
	MGPIO_enSetPinDirection(PORTA, PIN0, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(PORTA, PIN1, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(PORTA, PIN2, IN_ANALOG);
	MGPIO_enSetPinDirection(PORTB, PIN8, IN_FLOATING);
	MGPIO_enSetPinDirection(PORTB, PIN0, IN_PULL_UP_PULL_DOWN);

	/* GetPinValue use debugger to see the vari or use setpin value fn */
	MGPIO_enSetPinValue(PORTA, PIN0, HIGH);
	MGPIO_enGetPinValue(PORTA, PIN0, &pinvalue);
	MGPIO_enSetPinValue(PORTA, PIN0, pinvalue);
	MGPIO_enLockPin(PORTA, PIN0);
	MGPIO_enSetPinDirection(PORTA, PIN0, OUT_10MHZ_PUSH_PULL);

#elif 0
	/* test SetPortDirection and SetPortValue */
	MGPIO_enSetPortDirection(GPIO_CRL_ID, PORTA, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPortDirection(GPIO_CRH_ID, PORTA, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPortDirection(GPIO_CRL_ID, PORTB, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPortDirection(GPIO_CRH_ID, PORTB, OUT_2MHZ_PUSH_PULL);

	MGPIO_enSetPortValue(GPIO_CRL_ID, PORTA, HIGH);
	MGPIO_enSetPortValue(GPIO_CRH_ID, PORTA, HIGH);
	MGPIO_enSetPortValue(GPIO_CRL_ID, PORTB, HIGH);
	MGPIO_enSetPortValue(GPIO_CRH_ID, PORTB, HIGH);

#elif 0
		/* testing Set Reset FN with SetPinValue */
		MGPIO_enSetResetPin(PORTA, PIN0, GPIO_PIN_SET);
		MGPIO_enSetResetPin(PORTA, PIN1, GPIO_PIN_RESET);

#endif

	while(1)
	{
#if 0
		/* test toggle function */
		MGPIO_enTogglePin(PORTA, PIN0);
#endif

	}
	/*****************************************************************************************************************/
#elif(APPLICATION == MNVIC_TEST)
	/*****************************************************************************************************************/

	/* test bunch of fuction together and sum alone to verify the result
	 * with debbuger, here i verify functions and normal, nesting interrupt
	 * by changing the prioritry of the ex-interrupt
	 */
	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(MRCC_IOPA);
	MNVIC_enEnableNVIC();

	MGPIO_enSetPinDirection(PORTA, PIN0, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(PORTA, PIN1, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(PORTA, PIN2, OUT_2MHZ_PUSH_PULL);

	MNVIC_enSetPriority(MNVIC_EXT0_INT,2,0);
	MNVIC_enSetPriority(MNVIC_EXT1_INT,1,0);

	MNVIC_enEnableInt(MNVIC_EXT1_INT);
	MNVIC_enEnableInt(MNVIC_EXT0_INT);

	MNVIC_enSetPendingFlag(MNVIC_EXT0_INT);

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
	/*****************************************************************************************************************/
#elif(APPLICATION == MEXTI_TEST)
	/*****************************************************************************************************************/
	while(1)
	{

	}
	/*****************************************************************************************************************/
#elif(APPLICATION == MAFIO_TEST)
	/*****************************************************************************************************************/
	while(1)
	{

	}
	/*****************************************************************************************************************/
#elif(APPLICATION == MSTICK_TEST)
	/*****************************************************************************************************************/
	while(1)
	{

	}
	/*****************************************************************************************************************/
#elif(APPLICATION == MDMA_TEST)
	/*****************************************************************************************************************/
	MDMA_INIT_st vari ;
	u8 state;
	u32 arr1[1000] = {1,1,1,1,1,1,1,1,1,arr1[500]=500, arr1[999]=2};
	u32 arr2[1000];
	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(MRCC_DMA1);
	MRCC_enEnablePeripheralCLK(MRCC_IOPB);
	MGPIO_enSetPinDirection(PORTB, PIN12, OUT_2MHZ_PUSH_PULL);
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
	/*****************************************************************************************************************/
#elif(APPLICATION == MADC_TEST)
	/*****************************************************************************************************************/
	while(1)
	{

	}
	/*****************************************************************************************************************/
#elif(APPLICATION == MUSART_TEST)
	/*****************************************************************************************************************/

	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(MRCC_USART1);
	MRCC_enEnablePeripheralCLK(MRCC_USART2);
	MRCC_enEnablePeripheralCLK(MRCC_USART3);
	MRCC_enEnablePeripheralCLK(MRCC_IOPA);
	MRCC_enEnablePeripheralCLK(MRCC_IOPB);

	MGPIO_enSetPinDirection(MUSART1_TX_PIN, OUT_2MHZ_AF_PUSH_PULL);
	MGPIO_enSetPinDirection(MUSART1_RX_PIN, IN_FLOATING);

	MGPIO_enSetPinDirection(MUSART2_TX_PIN, OUT_2MHZ_AF_PUSH_PULL);
	MGPIO_enSetPinDirection(MUSART2_RX_PIN, IN_FLOATING);

	MGPIO_enSetPinDirection(MUSART3_TX_PIN, OUT_2MHZ_AF_PUSH_PULL);
	MGPIO_enSetPinDirection(MUSART3_RX_PIN, IN_FLOATING);

	MUSART_enInit(MUSART1);
	MUSART_enInit(MUSART2);
	MUSART_enInit(MUSART3);
#if 1 /* test the polling mode */
	u8 data ;
	MUSART_enBusySendString(MUSART1, "Hassan");
	MUSART_enBusySendByte(MUSART1, 'H');

	MUSART_enBusySendString(MUSART2, "Mohamed");
	MUSART_enBusySendByte(MUSART2, 'M');

	MUSART_enBusySendString(MUSART3, "Ali");
	MUSART_enBusySendByte(MUSART3, 'A');

	MUSART_enBusyReceiveByte(MUSART1, &data);
	MUSART_enBusySendByte(MUSART1, data);

	MUSART_enBusyReceiveByte(MUSART2, &data);
	MUSART_enBusySendByte(MUSART2, data);

	MUSART_enBusyReceiveByte(MUSART3, &data);
	MUSART_enBusySendByte(MUSART3, data);
#elif 1
	u8 data[25] ;
	extern u8 Receive_Flag;
	MUSART_enIntCallBack(MUSART1, App);
	MNVIC_enEnableNVIC();
	MNVIC_enEnableInt(MNVIC_USART1_INT);
	MUSART_enEnableInt(MUSART1, TXEmpty_INT);
	MUSART_enEnableInt(MUSART1, RXNEmpty_INT);
	MUSART_enSendMessage(MUSART1, "HASSAN");
	while (Receive_Flag == 0);
	MUSART_enReceieveMessage(MUSART1, data);
	MUSART_enSendMessage(MUSART1, data);
#endif
	while(1)
	{

	}
	/*****************************************************************************************************************/
#elif(APPLICATION == MSPI_TEST)
	/*****************************************************************************************************************/
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
	/*****************************************************************************************************************/
#elif(APPLICATION == HLED_TEST)
	/*****************************************************************************************************************/
	while (1)
	{

	}
	/*****************************************************************************************************************/
#elif(APPLICATION == HPB_TEST)
	/*****************************************************************************************************************/
	while (1)
	{

	}
	/*****************************************************************************************************************/
#elif(APPLICATION == HSSD_TEST)
	/*****************************************************************************************************************/
	while (1)
	{

	}
	/*****************************************************************************************************************/
#elif(APPLICATION == HKEYPAD_TEST)
	/*****************************************************************************************************************/
	while (1)
	{

	}
	/*****************************************************************************************************************/

#elif(APPLICATION == HLCD_TEST)
	/*****************************************************************************************************************/
	while (1)
	{

	}
	/*****************************************************************************************************************/

#elif(APPLICATION == HLEDMRX_TEST)
	/*****************************************************************************************************************/
	while (1)
	{

	}
	/*****************************************************************************************************************/

#else
#error("Wrong Unit Testing");
#endif
}
/**********************************************************************************************************************
 *  END OF FILE: APP_prog.c
 *********************************************************************************************************************/
