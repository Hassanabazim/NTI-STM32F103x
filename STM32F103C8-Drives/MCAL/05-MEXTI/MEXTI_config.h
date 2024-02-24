/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  MEXTI_config.h
 *         @Module	:  EXTI
 *
 *  Description:  This file provide the pre Configuration of the Module
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HEADER GUARD
 *********************************************************************************************************************/
#ifndef MEXTI_EXTINT_CONFIG_H_
#define MEXTI_EXTINT_CONFIG_H_

/**********************************************************************************************************************
*  LOCAL MACROS CONFIGURATION
 *********************************************************************************************************************/
typedef enum
{
	 MEXTI0_LINE	,
	 MEXTI1_LINE	,
	 MEXTI2_LINE	,
	 MEXTI3_LINE	,
	 MEXTI4_LINE	,
	 MEXTI5_LINE	,
	 MEXTI6_LINE	,
	 MEXTI7_LINE	,
	 MEXTI8_LINE	,
	 MEXTI9_LINE	,
	 MEXTI10_LINE	,
	 MEXTI11_LINE	,
	 MEXTI12_LINE	,
	 MEXTI13_LINE	,
	 MEXTI14_LINE	,
	 MEXTI15_LINE	,
}MEXTI_LINE_t;

typedef enum
{
	MEXTI_RISING_TRIG  = 1 ,
	MEXTI_FAILING_TRIG	   ,
	MEXTI_LOGIC_CHANGE
}MEXTI_MODE_t;

typedef enum
{
	DISABLE, ENABLE
}MEXTI_STATE_t;

typedef struct
{
	MEXTI_LINE_t	EXTI_ID;
	MEXTI_MODE_t	EXTI_MODE;
	MEXTI_STATE_t	EXTI_State;
}MEXTI_CFG_t;



#endif /* MEXTI_EXTINT_CONFIG_H_ */

 /****************************A******************************************************************************************
  *  END OF FILE:	MEXTI_config.h
  *********************************************************************************************************************/
