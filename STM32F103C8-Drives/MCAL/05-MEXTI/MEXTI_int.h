/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  MEXTI_int.h
 *         @Module	:  EXTI
 *
 *  Description:  This file Provide the Module APIs and Interfacing MACROS and Data types
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HEADER GUARD
 *********************************************************************************************************************/
#ifndef MEXTI_EXTINT_INT_H_
#define MEXTI_EXTINT_INT_H_


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
ErrorState_t MEXTI_enInit(void);
ErrorState_t MEXTI_enSetLatch(u8 Copy_u8LineId, u8 Copy_u8Mode);
ErrorState_t MEXTI_enDisable(u8 Copy_u8LineId);
ErrorState_t MEXTI_enCallBack(u8 Copy_u8LineId, void (*ptr) (void));
ErrorState_t MEXTI_enSWInterrupt(u8 Copy_u8LineId);
ErrorState_t MEXTI_enClearPendingBit(u8 Copy_u8LineId);


#endif /* MEXTI_EXTINT_INT_H_ */
/**********************************************************************************************************************
 *  END OF FILE: MEXTI_int.h
 *********************************************************************************************************************/
