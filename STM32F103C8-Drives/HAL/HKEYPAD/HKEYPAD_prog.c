/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  KEYPAD						 			*/
/****************************************************************/


#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MGPIO_int.h"
#include "MSYSTICK_int.h"
#include "HKEYPAD_int.h"
#include "HKEYPAD_priv.h"
#include "HKEYPAD_config.h"


ErrorState_t HKEYPAD_enInit(void)
{
	ErrorState_t Local_state = SUCCESS;

	//intallize
	MGPIO_enSetPinDirection(HKEYPAD_R0_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(HKEYPAD_R1_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(HKEYPAD_R2_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(HKEYPAD_R3_PIN, OUT_2MHZ_PUSH_PULL);

	MGPIO_enSetPinDirection(HKEYPAD_C0_PIN, IN_PULL_UP_PULL_DOWN);
	MGPIO_enSetPinDirection(HKEYPAD_C1_PIN, IN_PULL_UP_PULL_DOWN);
	MGPIO_enSetPinDirection(HKEYPAD_C2_PIN, IN_PULL_UP_PULL_DOWN);
	MGPIO_enSetPinDirection(HKEYPAD_C3_PIN, IN_PULL_UP_PULL_DOWN);

	MGPIO_enSetPinValue(HKEYPAD_R0_PIN, HIGH);
	MGPIO_enSetPinValue(HKEYPAD_R1_PIN, HIGH);
	MGPIO_enSetPinValue(HKEYPAD_R2_PIN, HIGH);
	MGPIO_enSetPinValue(HKEYPAD_R3_PIN, HIGH);

#if(HKEYPAD_MODE == HKEYPAD_PULL_UP)
	MGPIO_enSetPinValue(HKEYPAD_C0_PIN, HIGH);
	MGPIO_enSetPinValue(HKEYPAD_C1_PIN, HIGH);
	MGPIO_enSetPinValue(HKEYPAD_C2_PIN, HIGH);
	MGPIO_enSetPinValue(HKEYPAD_C3_PIN, HIGH);
#endif

	return Local_state;
}
ErrorState_t HKEYPAD_enGetPressedKey(u8 *ptrKey)
{
	u8 Local_u8PressedKey = HKEYPAD_NO_KEY_PRESSED;
	u8 Local_u8Read;
	u8 local_u8ArrKeys[4][4] = HKEYPAD_KEYS;

	u8 rowArr[4][2] = {{HKEYPAD_R0_PIN}, {HKEYPAD_R1_PIN}, {HKEYPAD_R2_PIN}, {HKEYPAD_R3_PIN}};
	u8 colArr[4][2] = {{HKEYPAD_C0_PIN},{HKEYPAD_C1_PIN},{HKEYPAD_C2_PIN},{HKEYPAD_C3_PIN}};

	for (u8 row_index = 0; row_index <= 3 ; row_index++)
	{
		//Activate row (set LOW on the Row pins)
		MGPIO_enSetPinValue(rowArr[row_index][0],rowArr[row_index][1], LOW);

		for(u8 col_index = 0; col_index <= 3  ; col_index++)
		{
			// Read the value of the col (HIGH OR LOW)
			MGPIO_enGetPinValue(colArr[col_index][0],colArr[col_index][1], &Local_u8Read); // 0
			// for debouncing
			if (Local_u8Read == HKEYPAD_KEY_PRESSED)
			{
				MSYSTICK_enDelayMS(20);
				// Read the col Pin again to check that's not noise
				MGPIO_enGetPinValue(colArr[col_index][0], colArr[col_index][0],&Local_u8Read);
				if (Local_u8Read == HKEYPAD_KEY_PRESSED)
				{
					// for single read to ignore multi-press
					while(Local_u8Read == HKEYPAD_KEY_PRESSED)
					{
						MGPIO_enGetPinValue(colArr[col_index][0],colArr[col_index][1], &Local_u8Read);
					}
					Local_u8PressedKey = local_u8ArrKeys[row_index][col_index];
				}
				else
				{

				}

			}//deboncing if
			else
			{

			}

		} // col for loop

		//De-Activate row (set HIGH on the Row pins)
		MGPIO_enSetPinValue(rowArr[row_index][0],rowArr[row_index][1], HIGH);
	}// row for loop

	*ptrKey = Local_u8PressedKey;
	return SUCCESS;

}
