/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  NVIC							 		    */
/****************************************************************/

#ifndef MNVIC_MNVIC_PRIV_H_
#define MNVIC_MNVIC_PRIV_H_


/****************************NVIC MASK*************************/
#define NVIC_SETPRI_MASK		0x0F


/****************************NVIC VALUES***********************/
#define CSB_AIRCR_LOCK_PASS		0x05FA


/**************************NVIC PRIORITRY**********************/
#define NVIC_GROUP_16_SUB_0		0x05FA0300
#define NVIC_GROUP_8_SUB_2		0x05FA0400
#define NVIC_GROUP_4_SUB_4		0x05FA0500
#define NVIC_GROUP_2_SUB_8		0x05FA0600
#define NVIC_GROUP_0_SUB_16		0x05FA0700







#endif /* MNVIC_MNVIC_PRIV_H_ */
