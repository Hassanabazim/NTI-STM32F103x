/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  31/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  DMA							 			*/
/****************************************************************/

#ifndef MDMA_MDMA_INT_H_
#define MDMA_MDMA_INT_H_

typedef enum
{
	MDMA_CG_INT,
	MDMA_TC_INT,
	MDMA_HT_INT,
	MDMA_TE_INT
}MDMA_INT_t;

typedef enum
{
	Channel1, Channel2, Channel3, Channel4, Channel5, Channel6, Channel7
}MDMA_CHANNEL_t;


typedef enum
{
	MDMA_Peripheral_Src ,
	MDAM_Memory_Src,
	MDMA_Circular_ON ,
	MDMA_Circular_OFF,
	MDMA_PINK_ON ,
	MDMA_PINK_OFF,
	MDMA_MINK_ON ,
	MDMA_MINK_OFF,
	MDMA_FRunning_OFF,
	MDMA_FRunning_ON,
	MDMA_Preiphial_1ByteSize = 0,
	MDMA_Preiphial_2ByteSize = 1,
	MDMA_Preiphial_4ByteSize = 2,
	MDMA_Memory_1ByteSize = 0,
	MDMA_Memory_2ByteSize = 1,
	MDMA_Memory_4ByteSize = 2,
	MDMA_Channel_PRI_LOW = 0,
	MDMA_Channel_PRI_MEDIUM = 1,
	MDMA_Channel_PRI_HIGH = 2,
	MDMA_Channel_PRI_VeryHIGH = 3,
}MDMA_CONFIG_t;


typedef struct
{
	MDMA_CONFIG_t Source_Mode;
	MDMA_CONFIG_t Circular_Mode;
	MDMA_CONFIG_t PINK_Mode;
	MDMA_CONFIG_t MINK_Mode;
	MDMA_CONFIG_t Preiphial_SizeElemnet;
	MDMA_CONFIG_t Memory_SizeElement;
	MDMA_CONFIG_t Channel_Priority;
	MDMA_CONFIG_t DMA_Mode;
}MDMA_INIT_st;


ErrorState_t MDMA_enInit(MDMA_CHANNEL_t copy_u8Channel, MDMA_INIT_st *ptr_u8Value);
ErrorState_t MDMA_enEnableInt(MDMA_CHANNEL_t copy_u8Chennel, MDMA_INT_t copy_u8Interrupt);
ErrorState_t MDMA_enDisableInt(MDMA_CHANNEL_t copy_u8Chennel, MDMA_INT_t copy_u8Interrupt);
ErrorState_t MDMA_enReadIntState(MDMA_CHANNEL_t copy_u8Chennel, MDMA_INT_t copy_u8Interrupt, u8 *ptr_u8state);
ErrorState_t MDMA_enIntCallBack(MDMA_CHANNEL_t copy_u8Chennel, void (*ptr)(void));
ErrorState_t MDMA_enTranferInit(MDMA_CHANNEL_t copy_u8Chennel, u32 *ptr_u32SrcaAddress, u32 *ptr_u32DestAddress, u16 copy_16BlockLen);
ErrorState_t MDMA_enBusyTranferStart(MDMA_CHANNEL_t copy_u8Chennel, MDMA_INT_t copy_u8Interrupt);



#endif /* MDMA_MDMA_INT_H_ */
