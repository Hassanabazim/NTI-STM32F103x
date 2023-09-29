/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  SEVEN SEGEMENT DISPLAY	 				*/
/****************************************************************/

#ifndef HSSD_HSSD_CONFIG_H_
#define HSSD_HSSD_CONFIG_H_

/* Please Configure Pins for 7-Segment LEDS
 * A,B,.....,DP
 *
 * Please Configure Enable pins for both-7Segment
 * EN1, EN2
 *
 * Please Cnfigure 7-Segment MODE
 * HSSD_CC, HSSD_CA
 */

#define HSSD_LED_DP_PIN		PORTA, PIN0
#define HSSD_LED_A_PIN 		PORTA, PIN1
#define HSSD_LED_B_PIN		PORTA, PIN2
#define HSSD_LED_C_PIN		PORTA, PIN3
#define HSSD_LED_D_PIN		PORTA, PIN4
#define HSSD_LED_E_PIN		PORTA, PIN5
#define HSSD_LED_F_PIN		PORTA, PIN6
#define HSSD_LED_G_PIN		PORTA, PIN7

#define HSSD_LED_EN1_PIN	PORTA, PIN8
#define HSSD_LED_EN2_PIN	PORTA, PIN9

#define HSSD_DISPLAY_TIME  500

#define HSSD_TYPE   HSSD_CC

#endif /* HSSD_HSSD_CONFIG_H_ */
