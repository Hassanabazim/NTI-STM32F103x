/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  2.0.0							 		*/
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

#define HSSD_TYPE   HSSD_CC

#define HSSD_LED_EN1_PIN	PORTA, PIN8
#define HSSD_LED_EN2_PIN	PORTA, PIN9

#define HSSD_DISPLAY_TIME  500



#endif /* HSSD_HSSD_CONFIG_H_ */
