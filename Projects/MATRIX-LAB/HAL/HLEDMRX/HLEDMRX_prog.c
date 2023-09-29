/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  26/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  LED MATRIX							 	*/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REGISTERS.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MSTICK_int.h"
#include "HLEDMRX_int.h"
#include "HLEDMRX_config.h"
#include "HLEDMRX_priv.h"


ErrorState_t HLEDMRX_enInit(void)
{
	/* 1. set Row direction to Output 2MHz PushPull */
	MGPIO_enSetPortDirection(GPIO_CRL_ID, PORTA, OUT_2MHZ_PP);

	/* 2. set Col direction to Output 2MHz PushPull */
	MGPIO_enSetPortDirection(GPIO_CRH_ID, PORTB, OUT_2MHZ_PP);

	return SUCCESS;
}

ErrorState_t HLEDMRX_enDisplay(u8 *copy_pu8Data)
{
	for (u8 pinNum = 0; pinNum < 8; pinNum++)
	{
		/* 1. Disable All col pins by writing High */
		MGPIO_enSetPortValue(GPIO_CRH_ID, PORTB, LOW);

		/* 2. Get data and stored in ROWS */
		HLEDMRX_voidSetRowValue(copy_pu8Data[pinNum]);

		/* 3. Enable col0 by writing low */
		MGPIO_enSetPinValue(PORTB, (PIN8 + pinNum), HIGH);

		/* 4. delay of the opreation */
		MSTK_enDelayMS(2500);
	}

	return SUCCESS;
}

static void HLEDMRX_voidSetRowValue(u8 copy_u8data)
{
	u8 local_temp ;
	for (u8 pinNum = 0; pinNum < 8; pinNum++)
	{
		local_temp = GET_BIT(copy_u8data, pinNum);
		if (local_temp == 0)
			MGPIO_enSetPinValue(PORTA, pinNum, HIGH);
		else
			MGPIO_enSetPinValue(PORTA, pinNum, LOW);
	}
}

ErrorState_t HLEDMRX_enDisplayMotion(u8 *Copy_u8DataLarge, u32 Copy_u32Speed)
{
	for (u32 x =0 ; x < Copy_u32Speed; x++)
	{
		for (u8 pinNum = 0; pinNum < 8; pinNum++)
		{
			/* 1. Disable All col pins by writing High */
			MGPIO_enSetPortValue(GPIO_CRH_ID, PORTB, LOW);

			/* 2. Get data and stored in ROWS */
			HLEDMRX_voidSetRowValue(Copy_u8DataLarge[pinNum]);

			/* 3. Enable col0 by writing low */
			MGPIO_enSetPinValue(PORTB, (PIN8 + pinNum), HIGH);


			/* 4. delay of the opreation */
			MSTK_enDelayMS(2500);
		}
		MSTK_enDelayMS(1000);
	}


	return SUCCESS;
}

