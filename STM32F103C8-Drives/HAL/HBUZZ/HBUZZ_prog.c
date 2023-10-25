/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  BUZZER						 			*/
/****************************************************************/

#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MGPIO_int.h"
#include "HBUZZ_int.h"
#include "HBUZZ_config.h"
#include "HBUZZ_priv.h"

#include "../../MCAL/MSYSTICK/MSYSTICK_int.h"

ErrorState_t HBUZZ_enInit(u8 copy_u8port, u8 copy_u8pin)
{
	ErrorState_t Local_state = SUCCESS;
	if (copy_u8port <= PORTC && copy_u8pin <= PIN15)
	{
		MGPIO_enSetPinDirection(copy_u8port, copy_u8pin, OUT_2MHZ_PUSH_PULL);
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

ErrorState_t HBUZZ_enSetON(u8 copy_u8port, u8 copy_u8pin)
{
	ErrorState_t Local_state = SUCCESS;
	if (copy_u8port <= PORTC && copy_u8pin <= PIN15)
	{
		MGPIO_enSetPinValue(copy_u8port, copy_u8pin, HIGH);
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

ErrorState_t HBUZZ_enSetOFF(u8 copy_u8port, u8 copy_u8pin)
{
	ErrorState_t Local_state = SUCCESS;
	if (copy_u8port <= PORTC && copy_u8pin <= PIN15)
	{
		MGPIO_enSetPinValue(copy_u8port, copy_u8pin, LOW);
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

ErrorState_t HBUZZ_enSetONCE(u8 copy_u8port, u8 copy_u8pin)
{
	ErrorState_t Local_state = SUCCESS;
	if (copy_u8port <= PORTC && copy_u8pin <= PIN15)
	{
		MGPIO_enSetPinValue(copy_u8port, copy_u8pin, HIGH);
		MSYSTICK_enDelayMS(1000);
		MGPIO_enSetPinValue(copy_u8port, copy_u8pin, LOW);
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

ErrorState_t HBUZZ_enSetNum(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8num)
{
	ErrorState_t Local_state = SUCCESS;
	if (copy_u8port <= PORTC && copy_u8pin <= PIN15)
	{
		for (u8 i = 0; i < copy_u8num; i++)
		{
			MGPIO_enSetPinValue(copy_u8port, copy_u8pin, HIGH);
			MSYSTICK_enDelayMS(1000);
			MGPIO_enSetPinValue(copy_u8port, copy_u8pin, LOW);
			MSYSTICK_enDelayMS(1000);
		}
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}
