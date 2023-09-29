#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
#include "MAFIO_int.h"
#include "MSTICK_int.h"
#include "HPB_int.h"
#include "HLEDMRX_int.h"

u8 name[6][8] = {{0, 36, 36, 36, 60, 36, 36, 0},
				{0, 36, 36, 36, 60, 36, 24, 0},
				{0, 0, 28, 32, 24, 4, 56, 0},
				{0, 0, 28, 32, 24, 4, 56, 0},
				{0, 36, 36, 36, 60, 36, 24, 0},
				{0, 0, 36, 52, 44, 36, 0, 0}};

static u8 copy_u8Intflag = 0;

void start(void);
void speedUp(void);
void speedDown(void);
void stop(void);

int main(void)
{
	PB_ST button1 = {PORTB, PIN0, PULL_UP};
	PB_ST button2 = {PORTB, PIN1, PULL_UP};
	PB_ST button3 = {PORTA, PIN9, PULL_UP};
	PB_ST button4 = {PORTA, PIN10, PULL_UP};

	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(IOPA);
	MRCC_enEnablePeripheralCLK(IOPB);
	MRCC_enEnablePeripheralCLK(MAFIO);


	HPB_enInit(&button1);
	HPB_enInit(&button2);
	HPB_enInit(&button3);
	HPB_enInit(&button4);
	HLEDMRX_enInit();
	MAFIO_enSetEXTIConfig(EXTI0_LINE, AFIO_GPIOB);
	MAFIO_enSetEXTIConfig(EXTI1_LINE, AFIO_GPIOB);


	MNVIC_enEnableNVIC();
	MNVIC_enSetPriority(EXT0_INT, 0, 1);
	MNVIC_enSetPriority(EXT1_INT, 1, 1);
	MNVIC_enSetPriority(EXT9_5INT, 2, 1);
	MNVIC_enSetPriority(EXT15_10INT, 3, 1);

	MEXTI_enCallBack(EXTI0_LINE, start);

	MNVIC_enEnableInt(EXT0_INT);
	MNVIC_enEnableInt(EXT1_INT);
	MNVIC_enEnableInt(EXT9_5INT);
	MNVIC_enEnableInt(EXT15_10INT);

	MEXTI_enCallBack(EXTI1_LINE, stop);
	MEXTI_enCallBack(EXTI9_LINE, start);
	MEXTI_enCallBack(EXTI10_LINE,speedDown);

	MEXTI_enInit();
	MEXTI_enSetLatch(EXTI1_LINE, EXTI_FAILING_TRIG);
	MEXTI_enSetLatch(EXTI9_LINE, EXTI_FAILING_TRIG);
	MEXTI_enSetLatch(EXTI10_LINE, EXTI_FAILING_TRIG);

	MEXTI_enEnable(EXTI1_LINE);
	MEXTI_enEnable(EXTI9_LINE);
	MEXTI_enEnable(EXTI10_LINE);

	MSTK_enInit();



	while(1)
	{


		if (copy_u8Intflag == 1)
		{
			for (u8 index = 0; index < 6; index++)
			{
				HLEDMRX_enDisplayMotion(name[index], 5);
			}

		}

		else if (copy_u8Intflag == 2)
		{
			for (u8 index = 0; index < 6; index++)
			{
				for (u8 speed = 0; speed < 200; speed+=50)
				{
					HLEDMRX_enDisplayMotion(name[index], speed);
				}
			}
		}

		else if (copy_u8Intflag == 3)
		{
			for (u8 index = 0; index < 6; index++)
			{
				for (u8 speed = 200; speed >= 0; speed-=50)
				{
					HLEDMRX_enDisplayMotion(name[index], speed);
				}
			}
		}
		/*else if (copy_u8Intflag == 0)
		{
			MGPIO_enSetPortValue(GPIO_CRL_ID, PORTA, HIGH);
			MGPIO_enSetPortValue(GPIO_CRH_ID, PORTB, LOW);
		}*/

		else
		{

		}

	}
}


void start(void)
{
	copy_u8Intflag = 1;
	MNVIC_enClrPendingFlag(EXT0_INT);
}
void speedUp(void)
{
	copy_u8Intflag = 2;
	MNVIC_enClrPendingFlag(EXT9_5INT);
}
void speedDown(void)
{
	copy_u8Intflag = 3;
	MNVIC_enClrPendingFlag(EXT15_10INT);

}
void stop(void)
{
	copy_u8Intflag = 0;
	MNVIC_enClrPendingFlag(EXT1_INT);
}
