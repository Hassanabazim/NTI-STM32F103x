#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
#include "MAFIO_int.h"
#include "MSTICK_int.h"
#include "HLED_int.h"
#include "HPB_int.h"

static u8 flag = 0 ;
void state(void);

int main(void)
{
	PB_ST button = {PORTA, PIN0, PULL_UP};
	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(IOPA);
	MRCC_enEnablePeripheralCLK(IOPB);

	MGPIO_enSetPortDirection(GPIO_CRH_ID, PORTB, OUT_2MHZ_PP);
	HPB_enInit(&button);

	MEXTI_enCallBack(EXTI0_LINE, state);
	MNVIC_enEnableNVIC();
	MNVIC_enEnableInt(EXT0_INT);
	MEXTI_enInit();
	MSTK_enInit();

	while (1)
	{
		if (flag == 1)
		{
			for (u8 i = 0; i < 4; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					HLED_enSetON(PORTB, j+8);
					MSTK_enDelayMS(200);
					HLED_enSetOFF(PORTB, j+8);
					if (j+8 == 15)
					{
						for (int k = (j+8)-1; k >= 8; k--)
						{
							HLED_enSetON(PORTB, k);
							MSTK_enDelayMS(200);
							HLED_enSetOFF(PORTB, k);
						}
					}

				}
			}
		}
		else if (flag == 2)
		{
			for (u8 k = 0; k < 4; k++)
			{
				for (u8 i = 0; i < 4; i++)
				{
					HLED_enSetON(PORTB, PIN11 - i);
					HLED_enSetON(PORTB, PIN12 + i);
					MSTK_enDelayMS(200);
					if(i == 3)
					{
						for (u8 j = 0; j < 4; j++)
						{
							HLED_enSetOFF(PORTB, PIN15 - j);
							HLED_enSetOFF(PORTB, PIN8 + j);
							MSTK_enDelayMS(200);
						}
					}
				}
			}
		}


		else if (flag == 3)
		{
			for (u8 i = 0; i<8; i++)

			{
				MGPIO_enSetPortValue(GPIO_CRH_ID, PORTB, HIGH);
				MSTK_enDelayMS(500);
				MGPIO_enSetPortValue(GPIO_CRH_ID, PORTB, LOW);
				MSTK_enDelayMS(500);

			}
		}

		else if (flag == 0)
		{
			MGPIO_enSetPortValue(GPIO_CRH_ID, PORTB, LOW);

		}
	}
}

void state(void)
{
	if (flag == 0)
	{
		flag = 1;
	}

	else if (flag == 1)
	{
		flag = 2;
	}
	else if (flag == 2)
	{
		flag = 3;
	}
	else if (flag == 3)
	{
		flag = 0;
	}
	MEXTI_enClearPendingBit(EXTI0_LINE);
}
