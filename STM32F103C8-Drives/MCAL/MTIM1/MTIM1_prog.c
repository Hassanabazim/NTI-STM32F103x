/*
 * MTIM1_prog.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Hassa
 */


ErrorState_t MTIMER1_enInit(void);
ErrorState_t MTIMER1_enStart(void);
ErrorState_t MTIMER1_enStop(void);
ErrorState_t MTIMER1_ICU_enInit(void);
ErrorState_t MTIMER1_enEnableINT(u8 copy_u8Int_ID);
ErrorState_t MTIMER1_enDisableINT(u8 copy_u8Int_ID);
ErrorState_t MTIMER1_enSetCallBack(u8 copy_u8Int_ID, void(*ptrfn)(void));
ErrorState_t MTIMER1_ICU_enRead(volatile u16 *ptrReadValue);
ErrorState_t MTIMER1_ICU_enSetTrigger(u8 copy_u8Trigg);
