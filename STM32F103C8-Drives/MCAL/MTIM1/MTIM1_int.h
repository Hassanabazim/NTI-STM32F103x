/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  MTIM1_int.h
 *         @Module	:  MTIM1
 *
 *  Description:  This file Provide the Module APIs and Interfacing MACROS and Data types
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HEADER GUARD
 *********************************************************************************************************************/
#ifndef MTIM1_MTIM1_INT_H_
#define MTIM1_MTIM1_INT_H_

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
ErrorState_t MTIMER1_enInit(void);
ErrorState_t MTIMER1_enStart(void);
ErrorState_t MTIMER1_setPrescaler(u16 copy_u16prescaler);
ErrorState_t MTIMER1_enStop(void);
ErrorState_t MTIMER1_enEnableINT(void);
ErrorState_t MTIMER1_enDisableINT(void);
ErrorState_t MTIMER1_enSetCallBack(void(*ptrfn)(void));
ErrorState_t MTIMER1_ICU_enRead(volatile u16 *ptrReadValue);
ErrorState_t MTIMER1_ICU_enSetTrigger(u8 copy_u8Trigg);

#endif /* MTIM1_MTIM1_INT_H_ */

/**********************************************************************************************************************
 *  END OF FILE:   MTIM1_int.h
 *********************************************************************************************************************/
