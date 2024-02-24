/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  SEVEN SEGEMENT DISPLAY	 				*/
/****************************************************************/

#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MGPIO_int.h"
#include "MSYSTICK_int.h"
#include "HSSD_int.h"
#include "HSSD_config.h"
#include "HSSD_priv.h"


ErrorState_t HSSD_enInit(void)
{
	ErrorState_t Local_state = SUCCESS;

	MGPIO_enSetPinDirection(HSSD_LED_DP_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(HSSD_LED_A_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(HSSD_LED_B_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(HSSD_LED_C_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(HSSD_LED_D_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(HSSD_LED_E_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(HSSD_LED_F_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(HSSD_LED_G_PIN, OUT_2MHZ_PUSH_PULL);

	MGPIO_enSetPinDirection(HSSD_LED_EN1_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(HSSD_LED_EN2_PIN, OUT_2MHZ_PUSH_PULL);

	return Local_state;
}

ErrorState_t HSSD_enDisplayIntegerNumber(u8 copyu8_Number)
{
	ErrorState_t Local_state = SUCCESS;

	if(copyu8_Number > 99)
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	else
	{
		u8 Local_u8Units = copyu8_Number % 10;
		u8 Local_u8Tens  = copyu8_Number / 10;
#if (HSSD_TYPE == HSSD_CC)
		MGPIO_enSetPinValue(HSSD_LED_DP_PIN ,LOW);
#elif(HSSD_TYPE == HSSD_CA)
		MGPIO_enSetPinValue(HSSD_LED_DP_PIN ,HIGH);
#else
#error ("WRONG HSSD TYPE");
#endif

		for(u16 i=0; i< HSSD_DISPLAY_TIME; i++)
		{
			switch(Local_u8Units)
			{
#if (HSSD_TYPE == HSSD_CC)
			case 0:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 1:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 2:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 3:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 4:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 5:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 6:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 7:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 8:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 9:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;
#elif (HSSD_TYPE == HSSD_CA)
			case 0:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 1:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 2:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 3:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 4:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 5:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 6:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 7:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 8:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 9:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;
#else
#error ("WRONG HSSD TYPE");
#endif
			default : break;
			}
#if(HSSD_TYPE == HSSD_CC)
			MGPIO_enSetPinValue(HSSD_LED_EN1_PIN , HIGH);
			MGPIO_enSetPinValue(HSSD_LED_EN2_PIN , LOW);
			// delay for the digit to be ON
			MSYSTICK_enDelayMS(1);
			MGPIO_enSetPinValue(HSSD_LED_EN2_PIN , HIGH);
#elif(HSSD_TYPE == HSSD_CA)
			MGPIO_enSetPinValue(HSSD_LED_EN1_PIN , LOW);
			MGPIO_enSetPinValue(HSSD_LED_EN2_PIN , HIGH);
			// delay for the digit to be ON
			MSYSTICK_enDelayMS(1);
			MGPIO_enSetPinValue(HSSD_LED_EN2_PIN , LOW);
#else
#error ("Wrong HSSD TYPE");
#endif


			switch(Local_u8Tens)
			{
#if(HSSD_TYPE == HSSD_CC)
			case 0:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 1:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 2:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 3:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 4:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 5:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 6:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 7:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 8:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 9:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;
#elif(HSSD_TYPE == HSSD_CA)
			case 0:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 1:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 2:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 3:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 4:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 5:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 6:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 7:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 8:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 9:
				MGPIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MGPIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MGPIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;
#else
#error ("WRONG HSSD TYPE");
#endif
			default : break;
			}
#if(HSSD_TYPE == HSSD_CC)
			MGPIO_enSetPinValue(HSSD_LED_EN1_PIN , LOW);
			MGPIO_enSetPinValue(HSSD_LED_EN2_PIN , HIGH);
			// delay for the digit to be ON
			MSYSTICK_enDelayMS(1);
			//Disable DIG 1
			MGPIO_enSetPinValue(HSSD_LED_EN1_PIN , HIGH);
#elif(HSSD_TYPE == HSSD_CA)
			MGPIO_enSetPinValue(HSSD_LED_EN1_PIN , HIGH);
			MGPIO_enSetPinValue(HSSD_LED_EN2_PIN , LOW);
			// delay for the digit to be ON
			MSYSTICK_enDelayMS(1);
			//Disable DIG 1
			MGPIO_enSetPinValue(HSSD_LED_EN1_PIN , LOW);
#else
#error ("WRONG HSSD_TYPE");
#endif
		}

	}
	return Local_state;
}
