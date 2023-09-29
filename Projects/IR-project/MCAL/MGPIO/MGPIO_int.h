/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  13/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  GPIO							 		    */
/****************************************************************/

#ifndef MGPIO_MGPIO_INT_H_
#define MGPIO_MGPIO_INT_H_

typedef enum
{
	GPIO_CRL_ID,
	GPIO_CRH_ID
}GPIO_ID_t;

/****************************************************************/
/* PLEASE CHOOSE GPIO PORT FROM THE FOLLOWING AT RUN-TIME:		*/
/*																*/
/* 			GPIO PORTS[PORTA, PORTB, PORTC]						*									*/
/****************************************************************/
typedef enum
{
	PORTA = 1, PORTB, PORTC
}PORT_t;


/****************************************************************/
/* PLEASE CHOOSE GPIO PIN FROM THE FOLLOWING AT RUN-TIME:		*/
/*																*/
/* 			GPIO PINS[PIN0,....,PIN15]							*/
/****************************************************************/
typedef enum
{
	PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7, PIN8, PIN9,
	PIN10, PIN11, PIN12, PIN13, PIN14, PIN15
}PIN_t;


/****************************************************************/
/* PLEASE CHOOSE GPIO MODE & CNF FROM THE FOLLOWING AT RUNTIME: */
/*																*/
/* IN_ANALOG				0x0 	// 0b0000					*/
/* IN_FLOATING				0x4 	// 0b0100					*/
/* IN_PULL_UP_PULL_DOWN		0x8 	// 0b1000					*/
/* OUT_2MHZ_PUSH_PULL		0x2		// 0b0010					*/
/* OUT_2MHZ_OPEN_DRAIN		0x6		// 0b0110					*/
/* OUT_2MHZ_AF_PUSH_PULL	0xA		// 0b1010					*/
/* OUT_10MHZ_PUSH_PULL		0x1		// 0b0001					*/
/* OUT_10MHZ_OPEN_DRAIN		0x5		// 0b0101					*/
/* OUT_10MHZ_AF_PUSH_PULL	0x9 	// 0b1001					*/
/* OUT_10MHZ_AF_OPEN_DRAIN	0xD 	// 0b1101					*/
/* OUT_2MHZ_AF_OPEN_DRAIN	0xE		// 0b1110					*/
/* OUT_50MHZ_PUSH_PULL		0x3		// 0b0011					*/
/* OUT_50MHZ_OPEN_DRAIN		0x7		// 0b0111					*/
/* OUT_50MHZ_AF_PUSH_PULL	0xB		// 0b1011					*/
/* OUT_50MHZ_AF_OPEN_DRAIN	0xF		// 0b1111					*/
/****************************************************************/
typedef enum
{
	IN_ANALOG,
	OUT_10MHZ_PP,
	OUT_2MHZ_PP,
	OUT_50MHZ_PP,
	IN_FLOATING,
	OUT_10MHZ_OD,
	OUT_2MHZ_OD,
	OUT_50MHZ_OD,
	IN_PU_PD,
	OUT_10MHZ_AF_PP,
	OUT_2MHZ_AF_PP,
	OUT_50MHZ_AF_PP,
	OUT_10MHZ_AF_OD=13,
	OUT_2MHZ_AF_OD,
	OUT_50MHZ_AF_OD
}MODE_t;

typedef enum
{
	LOW, HIGH
}VALUE_t;

typedef enum
{
	GPIO_PIN_RESET,
	GPIO_PIN_SET
}PinMode_t;


ErrorState_t MGPIO_enSetPinDirection(PORT_t copy_u8port, PIN_t copy_u8pin, MODE_t copy_u8Mode);
ErrorState_t MGPIO_enSetPinValue(PORT_t copy_u8port, PIN_t copy_u8pin, VALUE_t copy_u8Value);
ErrorState_t MGPIO_enTogglePin(PORT_t copy_u8port, PIN_t copy_u8pin);
ErrorState_t MGPIO_enGetPinValue(PORT_t copy_u8port, PIN_t copy_u8pin, u8 *pinValue);
ErrorState_t MGPIO_enSetPortDirection(GPIO_ID_t copy_u8CRID,PORT_t copy_u8port,  MODE_t copy_u8Mode);
ErrorState_t MGPIO_enSetPortValue(GPIO_ID_t copy_u8CRID, PORT_t copy_u8port, VALUE_t copy_u8Value);
ErrorState_t MGPIO_enSetResetPin(PORT_t copy_u8port,PIN_t copy_u8pin, PinMode_t copy_u8Mode);
ErrorState_t MGPIO_enLockPin(PORT_t copy_u8port, PIN_t copy_u8pin);



#endif /* MGPIO_MGPIO_INT_H_ */
