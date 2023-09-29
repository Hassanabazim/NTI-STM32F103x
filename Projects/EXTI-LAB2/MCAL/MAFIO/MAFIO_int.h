/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  24/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  AFIO							 			*/
/****************************************************************/

#ifndef MAFIO_MAFIO_INT_H_
#define MAFIO_MAFIO_INT_H_


typedef enum
{
	AFIO_GPIOA,
	AFIO_GPIOB,
	AFIO_GPIOC,
	AFIO_GPIOD,
	AFIO_GPIOE,
	AFIO_GPIOF,
	AFIO_GPIOG,
}AFIOEXTI_t;

ErrorState_t MAFIO_enSetEXTIConfig(u8 copy_u8EXTILineId, AFIOEXTI_t copy_u8PortMap);

#endif /* MAFIO_MAFIO_INT_H_ */
