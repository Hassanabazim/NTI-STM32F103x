/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  31/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  DMA							 			*/
/****************************************************************/

#ifndef MDMA_MDMA_PRIV_H_
#define MDMA_MDMA_PRIV_H_



#define EN								0
#define	MINC							7
#define PINC							6
#define CIRC							5
#define DIR								4
#define MEM2MEM							14

#define MDMA_INT_STATE_OFFSET			4
#define MDMA_PREIPHERAL_SIZE_OFFEST		8
#define MDMA_MEMORY_SIZE_OFFSET			10
#define MDMA_CHANNEL_PRI_OFFSET			12
#define MDMA_PREIPHERAL_SIZE_MASK		0x0000FCFF
#define MDMA_MEMORY_SIZE_MASK			0x0000F3FF
#define MDMA_CHANNEL_PRI_MASK			0x0000CFFF

#endif /* MDMA_MDMA_PRIV_H_ */
