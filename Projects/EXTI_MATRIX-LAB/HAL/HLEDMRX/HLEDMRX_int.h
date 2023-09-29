/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  26/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  LED MATRIX							 	*/
/****************************************************************/
#ifndef HLEDMRX_HLEDMRX_INT_H_
#define HLEDMRX_HLEDMRX_INT_H_


ErrorState_t HLEDMRX_enInit(void);
ErrorState_t HLEDMRX_enDisplay( u8 *copy_pu8Data);
ErrorState_t HLEDMRX_enDisplayMotion(u8 *Copy_u8DataLarge, u32 Copy_u32Speed);




#endif /* HLEDMRX_HLEDMRX_INT_H_ */
