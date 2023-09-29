/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  13/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  GPIO							 		    */
/****************************************************************/

#ifndef MGPIO_MGPIO_PRIV_H_
#define MGPIO_MGPIO_PRIV_H_


/************************GPIO MOST USED PINS*******************/
#define LCKK 			16


/************************GPIO MASK&OFFSETS*********************/
#define GPIO_MASK		0xF
#define GPIO_OFFSET		4


/****************************GPIO VALUES***********************/
#define GPIO_CRL_MAX	8
#define GPIO_CRH_MAX	16
#define PORT_OFFSET		0x11111111
#define PORT_LVALUE		0x00FF
#define PORT_HVALUE		0xFF00
#define PORT_RESET		0x0


#endif /* MGPIO_MGPIO_PRIV_H_ */
