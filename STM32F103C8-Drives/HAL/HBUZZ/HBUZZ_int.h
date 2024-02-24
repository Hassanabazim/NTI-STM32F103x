/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  BUZZER						 			*/
/****************************************************************/


#ifndef HBUZZ_HBUZZ_INT_H_
#define HBUZZ_HBUZZ_INT_H_


ErrorState_t HBUZZ_enSetON(u8 copy_u8port, u8 copy_u8pin);
ErrorState_t HBUZZ_enSetOFF(u8 copy_u8port, u8 copy_u8pin);
ErrorState_t HBUZZ_enSetONCE(u8 copy_u8port, u8 copy_u8pin);
ErrorState_t HBUZZ_enSetNum(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8num);




#endif /* HBUZZ_HBUZZ_INT_H_ */
