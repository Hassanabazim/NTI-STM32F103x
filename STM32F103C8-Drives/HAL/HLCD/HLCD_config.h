/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  LCD							 			*/
/****************************************************************/


#ifndef HLCD_HLCD_CONFIG_H_
#define HLCD_HLCD_CONFIG_H_

#define HLCD_MODE   _4BIT_

#define HLCD_RS_PIN   PORTA, PIN1
#define HLCD_EN_PIN   PORTA, PIN2
#define HLCD_RW_PIN


#define HLCD_D4_PIN   PORTA, PIN3
#define HLCD_D5_PIN   PORTA, PIN4
#define HLCD_D6_PIN   PORTA, PIN5
#define HLCD_D7_PIN   PORTA, PIN6

#if(HLCD_MODE == _8BIT_)
#define HLCD_D0_PIN	  PORTB, PIN0
#define HLCD_D1_PIN	  PORTB, PIN1
#define HLCD_D2_PIN	  PORTB, PIN2
#define HLCD_D3_PIN	  PORTB, PIN3
#endif

#endif /* HLCD_HLCD_CONFIG_H_ */
