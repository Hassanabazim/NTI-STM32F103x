/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  NVIC							 		    */
/****************************************************************/

#ifndef MNVIC_MNVIC_PRIV_H_
#define MNVIC_MNVIC_PRIV_H_

#define CSB_PRIGROUP_MASK		0xFFFFF7FF
#define CSB_AIRCR_LOCK_MASK		0x0000FFFF;
#define NVIC_SETPRI_MASK		0x0F
#define CSB_AIRCR_LOCK_PASS		0x5FA
#define NVIC_GROUP_16_SUB_0		3
#define NVIC_GROUP_8_SUB_2		4
#define NVIC_GROUP_4_SUB_4		5
#define NVIC_GROUP_2_SUB_8		6
#define NVIC_GROUP_0_SUB_16		7







#endif /* MNVIC_MNVIC_PRIV_H_ */
