/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  LCD						 			*/
/****************************************************************/


#ifndef HLCD_HLCD_INT_H_
#define HLCD_HLCD_INT_H_

ErrorState_t HLCD_enInit(void);
ErrorState_t HLCD_enSendData(u8 copy_u8Data);
ErrorState_t HLCD_enSendCommand(u8 copy_u8Command);
ErrorState_t HLCD_enSendString(const u8 * str);
ErrorState_t HLCD_enCLearDisplay(void);
ErrorState_t HLCD_enSendIntNum(s32 copy_32Num);
ErrorState_t HLCD_enGoToXY(u8 copy_u8X , u8 copy_u8Y);
ErrorState_t HLCD_CustomChar(u8 copy_u8loc, u8 *str);


#endif /* HLCD_HLCD_INT_H_ */
