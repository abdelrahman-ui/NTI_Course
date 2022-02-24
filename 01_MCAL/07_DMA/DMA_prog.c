





void ( *DMA_CallBackChannel1 )( void );

void MDMA_vInit(u8 Copy_u8SreamID )
{
     /* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/
	/* Use Stream NUM = 0 */
	/* If Enable Bit == 1 */
	if((DMA_2->StreamID[Copy_u8SreamID].CR) == 1 ) 
	{
		/* Disable It*/
		(DMA_2->StreamID[Copy_u8SreamID].CR) &=~(1U<<0);
		/*It Take Time To Be Disable So Wait Time */
		while((DMA_2->StreamID[Copy_u8SreamID].CR) == 1){} 
			
	}
	else {/* Not used Misra*/}
	
  /* 2- Select The Channel(Used For Conect Peripheral To Memory) In stream  But From Mermoery To Memory Not Use*/
	
	/* 3-SoftWare Priority Stream :{ LOW , Medium , High , VeryHigh} BIT(16 , 17)---> VeryHigh  */
	(DMA_2->StreamID[Copy_u8SreamID]|=((1U<<16)| (1U<<17)) ;
	
	/* 4- Set DIR Mode :{ (MTM) ,PTM ,MTP} BIT (6,7) */
	(DMA_2->StreamID[Copy_u8SreamID].CR)|=(1U<<7);
	(DMA_2->StreamID[Copy_u8SreamID].CR)&=~(1U<<6);
	
	/* 5- Set M & M SIZE BIT(13,14) ,(11,12) :{Byte , HaveWord , (Word)}*/
	/* 	As Word 32 For Source	*/ 
	(DMA_2->StreamID[Copy_u8SreamID].CR)|=(1U<<12);
	(DMA_2->StreamID[Copy_u8SreamID].CR)&=~(1U<<11);
		/* 	As Word 32 For Distination	*/ 
	(DMA_2->StreamID[Copy_u8SreamID].CR)|=(1U<<14);
	(DMA_2->StreamID[Copy_u8SreamID].CR)&=~(1U<<13);
	
	/* 6- Disable Direct Mode to used fifo  */
	(DMA_2->StreamID[Copy_u8SreamID].FCR)|=(1U<<2);
	
	/* 7-Set FIFO Threshold {(1/4),(1/2),(3/4),full} */
	/* Use (1/2)*/
	DMA_2->StreamID[Copy_u8SreamID].FCR|=(1U<<0);
	DMA_2->StreamID[Copy_u8SreamID].FCR&=~(1U<<1);
	/* 8-SRC & DIS Increament For Both */
    DMA_2->StreamID[Copy_u8SreamID].CR|=(1U<<9);
	DMA_2->StreamID[Copy_u8SreamID].CR|=(1U<<10);
	/* 9- EN Interrput Of Transfer Complete */
	DMA_2->StreamID[Copy_u8SreamID].CR|=(1U<<4);

}






void MDMA_vSetAddress(u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u32 Copy_u32Size ,u8 Copy_u8SreamID )
{
	
	DMA_2->StreamID[Copy_u8SreamID].PAR= (u32)Ptr_u32SrcAdd;
	DMA_2->StreamID[Copy_u8SreamID].M0AR=(u32)Ptr_u32DistAdd;
	DMA_2->StreamID[Copy_u8SreamID].NDTR=Copy_u32Size;

}

void MDMA_vStreamEnable(u8 Copy_u8SreamID )
{
	/* All Flag == 0 or make them =0 */
	(DMA2_BASS_ADDRESS->LIFCR)|=((1U<<0)|(1U<<2)|(1U<<3)|(1U<<4)|(1U<<5));
	
	DMA_2->StreamID[Copy_u8SreamID].CR=(1U<<0);
	
}
void MDMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) ){

	DMA_CallBackChannel1 = Ptr ;

}

void DMA1_Channel1_IRQHandler(void){

	DMA_CallBackChannel1();

}
