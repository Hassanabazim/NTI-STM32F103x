
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MNVIC_int.h"
#include "EXTINT_int.h"
#include "HLED_int.h"
#include "HPB_int.h"

void Action1(void);
void Action2(void);


PB_ST button1 = {PORTA, PIN0, PULL_UP};
PB_ST button2 = {PORTA, PIN1, PULL_UP};

int main(void)
{

	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(IOPA);
	HLED_enInit(PORTA, PIN3);
	HPB_enInit(&button1);
	HPB_enInit(&button2);

	MEXTI_enCallBack(EXTI0_LINE, Action1);
	MEXTI_enCallBack(EXTI1_LINE, Action2);
	MNVIC_enEnableNVIC();

	MNVIC_enEnableInt(EXT0_INT);
	MNVIC_enEnableInt(EXT1_INT);
	MEXTI_enInit();
	MEXTI_enEnable(EXTI1_LINE);
	MEXTI_enSetLatch(EXTI1_LINE, EXTI_RISING_TRIG);

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
	HLED_enSetOFF(PORTA, PIN3);
	MEXTI_enClearPendingBit(EXTI1_LINE);
}



