/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  2.0.0							 		*/
/* SWC				:  SEVEN SEGEMENT DISPLAY	 				*/
/****************************************************************/
#if 0
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MGPIO_int.h"
#include "MSTICK_int.h"
#include "HSSD_int.h"
#include "HSSD_config.h"
#include "HSSD_priv.h"


ErrorState_t HSSD_enInit(void)
{
	ErrorState_t Local_state = SUCCESS;

	MGPIO_enSetPortDirection(GPIO_CRL_ID, PORTA, OUT_2MHZ_PP);
	MGPIO_enSetPinDirection(HSSD_LED_EN1_PIN, OUT_2MHZ_PP);
	MGPIO_enSetPinDirection(HSSD_LED_EN2_PIN, OUT_2MHZ_PP);

	return Local_state;
}

ErrorState_t HSSD_enDisplayIntegerNumber(u8 copyu8_Number)
{
	ErrorState_t Local_state = SUCCESS;

	u8 copy_u8NumrArr[10] = {0x7E, 0x0C, 0xB6, 0x9E, 0xCC,  0xDA, 0xFA, 0x0E, 0xFE, 0xDE};

	if(copyu8_Number > 99)
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	else
	{
		u8 Local_u8Units = copyu8_Number % 10;
		u8 Local_u8Tens  = copyu8_Number / 10;

		for(u16 i=0; i< HSSD_DISPLAY_TIME; i++)
		{

#if (HSSD_TYPE == HSSD_CC)
			MGPIO_enSetPortValue(GPIO_CRL_ID, PORTA, copy_u8NumrArr[Local_u8Units]);

			MGPIO_enSetPinValue(HSSD_LED_EN1_PIN , HIGH);
			MGPIO_enSetPinValue(HSSD_LED_EN2_PIN , LOW);
			// delay for the digit to be ON
			MSTK_enDelayMS(1);
			MGPIO_enSetPinValue(HSSD_LED_EN2_PIN , HIGH);

			MGPIO_enSetPortValue(GPIO_CRL_ID, PORTA,copy_u8NumrArr[Local_u8Tens]);
			MGPIO_enSetPinValue(HSSD_LED_EN1_PIN , LOW);
			MGPIO_enSetPinValue(HSSD_LED_EN2_PIN , HIGH);
			// delay for the digit to be ON
			MSTK_enDelayMS(1);
			//Disable DIG 1
			MGPIO_enSetPinValue(HSSD_LED_EN1_PIN , HIGH);

#elif (HSSD_TYPE == HSSD_CA)
			MGPIO_enSetPortValue(GPIO_CRL_ID, PORTA, ~(copy_u8NumrArr[Local_u8Units]);

			MGPIO_enSetPinValue(HSSD_LED_EN1_PIN , LOW);
			MGPIO_enSetPinValue(HSSD_LED_EN2_PIN , HIGH);
			// delay for the digit to be ON
			MSTK_enDelayMS(1);
			MGPIO_enSetPinValue(HSSD_LED_EN2_PIN , LOW);
			MGPIO_enSetPortValue(GPIO_CRL_ID, PORTA, ~(copy_u8NumrArr[Local_u8Tens]);

			MGPIO_enSetPinValue(HSSD_LED_EN1_PIN , HIGH);
			MGPIO_enSetPinValue(HSSD_LED_EN2_PIN , LOW);
			// delay for the digit to be ON
			MSTK_enDelayMS(1);
			//Disable DIG 1
			MGPIO_enSetPinValue(HSSD_LED_EN1_PIN , LOW);
#else
#error ("WRONG HSSD_TYPE");
#endif
		}

	}
	return Local_state;
}

#endif
