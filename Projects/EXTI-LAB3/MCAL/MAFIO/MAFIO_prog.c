/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  24/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  AFIO							 			*/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REGISTERS.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
#include "MAFIO_int.h"
#include "MAFIO_config.h"
#include "MAFIO_priv.h"

ErrorState_t MAFIO_enSetEXTIConfig(u8 copy_u8EXTILineId, AFIOEXTI_t copy_u8PortMap)
{
	ErrorState_t local_state ;

	u8 local_u8RegIndex = 0;
	if (copy_u8EXTILineId <= 3)
	{
		local_u8RegIndex = 0;
	}
	else if (copy_u8EXTILineId <= 7)
	{
		local_u8RegIndex = 1;
		copy_u8EXTILineId -= 4;
	}
	else if (copy_u8EXTILineId <= 11)
	{
		local_u8RegIndex = 2;
		copy_u8EXTILineId -= 8;
	}
	else if (copy_u8EXTILineId <= 15)
	{
		local_u8RegIndex = 3;
		copy_u8EXTILineId -= 12;
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	AFIO->AFIO_EXTICR[local_u8RegIndex] &= ~((0xF) <<(copy_u8EXTILineId*4));
	AFIO->AFIO_EXTICR[local_u8RegIndex] |=  ((copy_u8PortMap) << (copy_u8EXTILineId * 4));

	return local_state;
}
