/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  APP_config.h
 *         @Module	:  APP
 *
 *  Description:  This file provide the pre Configuration of the Module
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HEADER GUARD
 *********************************************************************************************************************/
#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_


/**********************************************************************************************************************
*  LOCAL MACROS CONFIGURATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
* PLEASE CHOOSE THE APPLICATION TEST FROM THE FOLLOWING :

	*MRCC_TEST
	*MGPIO_TEST
	*MNVIC_TEST
	*MEXTI_TEST
	*MAFIO_TEST
	*MSTICK_TEST
	*MDMA_TEST
	*MADC_TEST
	*MUSART_TEST
	*MSPI_TEST
	*MI2C_TEST
	*HLED_TEST
	*HPB_TEST
	*HBUZZ_TEST
	*HSSD_TEST
	*HKEYPAD_TEST
	*HLCD_TEST
	*HLEDMRX_TEST
 *********************************************************************************************************************/
#define APPLICATION 			MRCC_TEST


#endif /* APP_CONFIG_H_ */

 /**********************************************************************************************************************
  *  END OF FILE:	APP_config.h
  *********************************************************************************************************************/
