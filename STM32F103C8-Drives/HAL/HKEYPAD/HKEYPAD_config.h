/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  KEYPAD						 			*/
/****************************************************************/


#ifndef HKEYPAD_HKEYPAD_CONFIG_H_
#define HKEYPAD_HKEYPAD_CONFIG_H_

#define HKEYPAD_R0_PIN	PORTB, PIN4
#define HKEYPAD_R1_PIN	PORTB, PIN5
#define HKEYPAD_R2_PIN	PORTB, PIN6
#define HKEYPAD_R3_PIN	PORTB, PIN7

#define HKEYPAD_C0_PIN	PORTA, PIN2
#define HKEYPAD_C1_PIN	PORTA, PIN3
#define HKEYPAD_C2_PIN	PORTA, PIN4
#define HKEYPAD_C3_PIN	PORTA, PIN5

/*  Here you can choose your KEYPAD Mapping */
#define HKEYPAD_KEYS {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{' ','0','=','+'}}


#define HKEYPAD_MODE 	HKEYPAD_PULL_UP

#endif /* HKEYPAD_HKEYPAD_CONFIG_H_ */
