/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  LCD							 			*/
/****************************************************************/


#ifndef HLCD_HLCD_PRIV_H_
#define HLCD_HLCD_PRIV_H_

#define _4BIT_    0
#define _8BIT_    1


static void HLCD_voidNLatch(u8 copy_u8Byte);

#define HLCD_CLEAR  						0x01
#define HLCD_FUNCTION_SET_8BIT_2LINE  		0x38
#define HLCD_FUNCTION_SET_4BIT_2LINE  		0x28
#define HLCD_DISPLAY_CURSOR_ON_BLINK_OFF 	0x0E
#define HLCD_ENTRY_MODE_SET_FUNCTION 		0x06



#endif /* HLCD_HLCD_PRIV_H_ */
