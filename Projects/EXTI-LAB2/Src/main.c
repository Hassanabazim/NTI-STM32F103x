
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MNVIC_int.h"
#include "EXTINT_int.h"
#include "MAFIO_int.h"
#include "HLED_int.h"
#include "HPB_int.h"

void Action1(void);
void Action2(void);
void Action3(void);


PB_ST button1 = {PORTA, PIN0, PULL_UP};
PB_ST button2 = {PORTA, PIN1, PULL_UP};
PB_ST button3 = {PORTB, PIN3, PULL_UP};

int main(void)
{

	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(IOPA);
	MRCC_enEnablePeripheralCLK(IOPB);
	MRCC_enEnablePeripheralCLK(MAFIO);

	HLED_enInit(PORTA, PIN3);
	HLED_enInit(PORTA, PIN4);
	HLED_enInit(PORTA, PIN5);

	HPB_enInit(&button1);
	HPB_enInit(&button2);
	HPB_enInit(&button3);

	MAFIO_enSetEXTIConfig(EXTI3_LINE, AFIO_GPIOB);
	MEXTI_enCallBack(EXTI0_LINE, Action1);
	MEXTI_enCallBack(EXTI1_LINE, Action2);
	MEXTI_enCallBack(EXTI3_LINE, Action3);

	MNVIC_enEnableNVIC();
	MNVIC_enEnableInt(EXT0_INT);
	MNVIC_enEnableInt(EXT1_INT);
	MNVIC_enEnableInt(EXT3_INT);

	MEXTI_enInit();
	MEXTI_enEnable(EXTI1_LINE);
	MEXTI_enEnable(EXTI3_LINE);
	MEXTI_enSetLatch(EXTI1_LINE, EXTI_RISING_TRIG);
	MEXTI_enSetLatch(EXTI3_LINE, EXTI_RISING_TRIG);


	while(1)
	{

	}
}




void Action1(void)
{
	HLED_enSetON(PORTA, PIN3);
	MEXTI_enClearPendingBit(EXTI0_LINE);
}

void Action2(void)
{
	HLED_enSetON(PORTA, PIN4);
	MEXTI_enClearPendingBit(EXTI1_LINE);
}

void Action3(void)
{
	HLED_enSetON(PORTA, PIN5);
	MEXTI_enClearPendingBit(EXTI3_LINE);
}



