#include "STD_TYPE.h"
#include "RCC_private.h"
#include "RCC_interface.h"
#include "RCC_config.h" 
#include "DMA_private.h"
#define SIZE 500


/*  DMA_APP : Copy From Memory ( Source )To Memory ( Distination)  */

/* To Transfer Data From Array To Array :
				
				- Using Indirect Method : For Loop -----> DST_Array[index]  = SRC_Array[index] 
				- Using Direct Method ( Pointer ) : while --> *DST_Array++ = *SRC_Array++ 
				- Using DMA (source and destination ) the fast methode 
				
	* DMA Faster then Direct Then Indirect
				*/
				
				
				
#define RCC_EN_DMA_1 22
#define RCC_EN_DMA_2 23

int main (void)
{
	/* I Will Put Data At source Array And Transfer It From */
	u32 Local_u32SRC_Array[SIZE];
	/*Recive Data From Source Array*/
	u32 Local_u32DST_Array[SIZE];
	/*Init Source Array  */
	u32 Local_u32index=0 ;
	for(Local_u32index =0 ; Local_u32index <=SIZE ; Local_u32index ++)
	{
		/*Init Source Array From 0 Too Size {0,1,,2,3,..............,SIZE}*/
		Local_u32SRC_Array[Local_u32index] =Local_u32index ;  
	}
	
	/*1- Enable RCC For DMA_1*/
	
	/*2- EN DMA2 Stream 0 NVIC */
	
	/*3- Init DMA */
	
    /*4- Set Source Address & Distination */
	
	
	
}


/* 	 This ISR Is Called By Any Flag The 5 Flag From  DMA 	*/
static void DMA2_Stream0_IRQHandler (void)
{
	/* Any Action : Indicate That Transfer Complete Comlete Opration Is Done Successfuly */
	
	
	/* Must Clear The Flag Trasfer = 5  */
	(DMA2_BASS_ADDRESS->LIFCR)|=((1U<<0)|(1U<<2)|(1U<<3)|(1U<<4)|(1U<<5));

}