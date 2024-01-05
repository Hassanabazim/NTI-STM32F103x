/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  9/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  LED MATRIX LAB						    */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REGISTERS.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MSTICK_int.h"
#include "HLEDMRX_int.h"
u8 name[6][8] = {{0, 36, 36, 36, 60, 36, 36, 0},
				{0, 36, 36, 36, 60, 36, 24, 0},
				{0, 0, 28, 32, 24, 4, 56, 0},
				{0, 0, 28, 32, 24, 4, 56, 0},
				{0, 36, 36, 36, 60, 36, 24, 0},
				{0, 0, 36, 52, 44, 36, 0, 0}};

u8 text[] = "HELLO";

int main(void)
{
	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(IOPA);
	MRCC_enEnablePeripheralCLK(IOPB);

	HLEDMRX_enInit();

	while (1)
	{
		for (u8 i = 0; i < 6; i++)
		{
			HLEDMRX_enDisplayMotion(name[i], 50);

		}
	}

}
