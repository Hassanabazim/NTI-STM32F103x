/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  LCD						 				*/
/****************************************************************/

#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "BIT_MATH.h"
#include "MGPIO_int.h"
#include "HLCD_int.h"
#include "HLCD_config.h"
#include "HLCD_priv.h"

#include "../../MCAL/MSYSTICK/MSYSTICK_int.h"

ErrorState_t HLCD_enInit(void)
{
	ErrorState_t Local_state = SUCCESS;
	// set direction for pins as output
	MGPIO_enSetPinDirection( HLCD_RS_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection( HLCD_EN_PIN, OUT_2MHZ_PUSH_PULL);

	MGPIO_enSetPinDirection( HLCD_D7_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection( HLCD_D6_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection( HLCD_D5_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection( HLCD_D4_PIN, OUT_2MHZ_PUSH_PULL);
#if(HLCD_MODE == _8BIT_)
	MGPIO_enSetPinDirection( HLCD_D3_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection( HLCD_D2_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection( HLCD_D1_PIN, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection( HLCD_D0_PIN, OUT_2MHZ_PUSH_PULL);
	MSYSTICK_enDelayMS(35);
	HLCD_enSendCommand(HLCD_FUNCTION_SET_8BIT_2LINE);
#elif(HLCD_MODE == _4BIT_)
	MSYSTICK_enDelayMS(35);
	MGPIO_enSetPinValue(HLCD_EN_PIN, LOW);

	// send 0010
	MGPIO_enSetPinValue(HLCD_D7_PIN, 0);
	MGPIO_enSetPinValue(HLCD_D6_PIN, 0);
	MGPIO_enSetPinValue(HLCD_D5_PIN, 1);
	MGPIO_enSetPinValue(HLCD_D4_PIN, 0);

	MGPIO_enSetPinValue(HLCD_EN_PIN, HIGH);
	MSYSTICK_enDelayMS(1);
	MGPIO_enSetPinValue(HLCD_EN_PIN, LOW);
	MSYSTICK_enDelayMS(30);
	HLCD_enSendCommand(HLCD_FUNCTION_SET_4BIT_2LINE);
#endif

	HLCD_enSendCommand(HLCD_DISPLAY_CURSOR_ON_BLINK_OFF);
	HLCD_enSendCommand(HLCD_CLEAR);
	HLCD_enSendCommand(HLCD_ENTRY_MODE_SET_FUNCTION);


	// perform Initialization Sequence

	return Local_state;
}
ErrorState_t HLCD_enSendData(u8 copy_u8Data)
{
	// set RS = 1
	MGPIO_enSetPinValue(HLCD_RS_PIN, HIGH);
	// send data as a byte to Nlatch
	HLCD_voidNLatch(copy_u8Data);

	return SUCCESS;

}
ErrorState_t HLCD_enSendCommand(u8 copy_u8Command)
{
	// set RS = 0
	MGPIO_enSetPinValue(HLCD_RS_PIN, LOW);
	// send Command as a byte to Nlatch
	HLCD_voidNLatch(copy_u8Command);

	return SUCCESS;
}
ErrorState_t HLCD_enSendString(const u8 * str)
{
	while(*str != '\0')
	{
		HLCD_enSendData(*str);
		str++;
	}
	return SUCCESS;
}
ErrorState_t HLCD_enCLearDisplay(void)
{
	//HLCD_CLEAR
	HLCD_enSendCommand(HLCD_CLEAR);
	return SUCCESS;
}
ErrorState_t HLCD_enSendIntNum(s32 copy_u32Num)
{
	s8 i = 0;
	u8 IntArr[10] = {0};
	if(copy_u32Num==0)
	{
		HLCD_enSendData('0');
	}
	else if(copy_u32Num<0)
	{
		HLCD_enSendData('-');
		copy_u32Num	*= -1;

	}
	while(copy_u32Num>0)
	{
		IntArr[i]=copy_u32Num%10;
		copy_u32Num=copy_u32Num/10;
		i++;
	}
	i--;

	while(i>=0)
	{
		HLCD_enSendData(IntArr[i]+'0');
		i--;
	}

return SUCCESS;
}
ErrorState_t HLCD_enGoToXY(u8 copy_u8X , u8 copy_u8Y)
{
	if (copy_u8X == 1 && copy_u8Y < 16)
	{
		HLCD_enSendCommand(copy_u8Y|0x80);
	}
	else if (copy_u8X == 2 && copy_u8Y < 16)
	{
		HLCD_enSendCommand((copy_u8Y + 0x40)|0xC0);
	}
	return SUCCESS;
}

ErrorState_t HLCD_CustomChar(u8 copy_u8loc, u8 *str)
{
	HLCD_enSendCommand(0x40 + (copy_u8loc * 8));

	for (u8 i = 0; i<8; i++)
	{
		HLCD_enSendData(str[i]);
	}
	return SUCCESS;
}

static void HLCD_voidNLatch(u8 copy_u8Byte)
{

#if(HLCD_MODE == _8BIT_)
	u8 Local_u8LcdPinsArr[8][2] =
	{HLCD_D0_PIN, HLCD_D1_PIN, HLCD_D2_PIN, HLCD_D3_PIN,
			HLCD_D4_PIN,HLCD_D5_PIN, HLCD_D6_PIN, HLCD_D7_PIN};

	// Disable En
	MGPIO_enSetPinValue(HLCD_EN_PIN, LOW);
	for (u8 i = 0; i <= 7; i++)
	{
		MGPIO_enSetPinValue(Local_u8LcdPinsArr[i][0],Local_u8LcdPinsArr[i][0], GET_BIT(copy_u8Byte,i));
	}
	MGPIO_enSetPinValue(HLCD_EN_PIN, HIGH);
	MSYSTICK_enDelayMS(1);
	MGPIO_enSetPinValue(HLCD_EN_PIN, LOW);
	MSYSTICK_enDelayMS(30);

#elif(HLCD_MODE == _4BIT_)
	u8 Local_u8LcdPinsArr[4][2] ={{HLCD_D4_PIN},{HLCD_D5_PIN}, {HLCD_D6_PIN}, {HLCD_D7_PIN}};
	/* send higher lcd pins */
	// Disable En
	MGPIO_enSetPinValue(HLCD_EN_PIN, LOW);
	for (u8 i = 0; i <= 3; i++)
	{
		MGPIO_enSetPinValue(Local_u8LcdPinsArr[i][0],Local_u8LcdPinsArr[i][1], GET_BIT(copy_u8Byte,(i+4)));
	}
	MGPIO_enSetPinValue(HLCD_EN_PIN, HIGH);
	MSYSTICK_enDelayMS(1);
	MGPIO_enSetPinValue(HLCD_EN_PIN, LOW);
	MSYSTICK_enDelayMS(30);

	/* send lower lcd pins */
	for (u8 i = 0; i <=3 ; i++)
	{
		MGPIO_enSetPinValue(Local_u8LcdPinsArr[i][0], Local_u8LcdPinsArr[i][0],GET_BIT(copy_u8Byte,i));
	}
	MGPIO_enSetPinValue(HLCD_EN_PIN, HIGH);
	MSYSTICK_enDelayMS(1);
	MGPIO_enSetPinValue(HLCD_EN_PIN, LOW);
	MSYSTICK_enDelayMS(30);

#else
#error ("Wrong LCD mode")
#endif
}
