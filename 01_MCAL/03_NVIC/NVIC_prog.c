/****************************************************************************************
 ***************************  - NVIC_program.c				 			 ****************************
***************************   - Created: 5/24/2021					 ****************************
***************************   - Author: Abdelrahman_Magdy    ****************************
***************************   - Version : _1_				 				 ****************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/ 


/****************************************************************************************
***************************   The Foundation Of Function   ***************************** 
****************************************************************************************/


/************** INCLUDE LIB **************/
		 #include "STD_TYPE.h"
		 #include "BIT_MATH.h"
/*****************************************/	 

/************** INCLUDE MCAL**************/
		#include "NVIC_private.h"
		#include "NVIC_interface.h"
		#include "NVIC_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/

											

/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function :	
					Take The Number Of Interrput Number To Enable it At STm ----> 90
						*/
void MNVIC_voidSetEnable(u8 Copy_u8IntNum ) 
{
	if (Copy_u8IntNum <=31  )
	{ /* 0-----> no effect*/
	   NVIC_ISER0= (1U <<Copy_u8IntNum);  
	}
	/* (Copy_u8IntNum <= 32)  always true */
	else if( (Copy_u8IntNum <= 63))
	{
		/* 32 = 0  And So On */
		Copy_u8IntNum-=32 ; 
		NVIC_ISER1= (1U <<Copy_u8IntNum); 
	}
	else if(Copy_u8IntNum <= 84)
	{
		/* 64 = 0  And So On */
		Copy_u8IntNum-=64 ;
		NVIC_ISER2= (1U <<Copy_u8IntNum);
	}
	else 
	{
		/* return error */
	}
	
}



void MNVIC_VidEnablePeripheral ( u8 Copy_u8INTID ){

     /* 6/32 =0 */ /* 6%32 = 6*/
	 if(Copy_u8INTID <=240)
	NVIC_ISER[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;

}

						
/*********************************************************** END_ FUNCTION   ***********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function :	
					Take The Number Of Interrput Number To Disable it At Stm ----> 90
						*/
void MNVIC_voidDisable(u8 Copy_u8IntNum)
{
	if (Copy_u8IntNum <=31 )
	{ /* 0-----> no effect*/
	   NVIC_ICER0 = (1U <<Copy_u8IntNum);  
	}
	else if(Copy_u8IntNum <= 63)
	{
		/* 32 = 0  And So On */
		Copy_u8IntNum-=32 ; 
		NVIC_ICER1= (1U <<Copy_u8IntNum); 
	}
	else if( Copy_u8IntNum <= 84)
	{
		/* 64 = 0  And So On */
		Copy_u8IntNum-=64 ;
		NVIC_ICER2= (1U <<Copy_u8IntNum);
	}
	
	
}

void MNVIC_VidDisablePeripheral ( u8 Copy_u8INTID ){
        if(Copy_u8INTID <=85)
	NVIC_ICER[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;

}

	
/*********************************************************** END_ FUNCTION   ***********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function :	
					SetPending
						*/
void MNVIC_voidSetPending(u8 Copy_u8IntNum)
{
	if (Copy_u8IntNum <=31 )
	{ /* 0-----> no effect*/
	   NVIC_ISPR0= (1U <<Copy_u8IntNum);  
	}
	else if(Copy_u8IntNum <= 63)
	{
		/* 32 = 0  And So On */
		Copy_u8IntNum-=32 ; 
		NVIC_ISPR1= (1U <<Copy_u8IntNum); 
	}
	else if(Copy_u8IntNum <= 84)
	{
		/* 64 = 0  And So On */
		Copy_u8IntNum-=64 ;
		NVIC_ISPR2= (1U <<Copy_u8IntNum);
	}
	
	
}
void MNVIC_VidSetPending ( u8 Copy_u8INTID ){
         if(Copy_u8INTID <=85)
	NVIC_ISPR[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;


}






						
/*********************************************************** END_ FUNCTION   ***********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function :	
					Clear Pending
						*/
void MNVIC_voidClearPending(u8 Copy_u8IntNum)
{
	if (Copy_u8IntNum <=31 )
	{ /* 0-----> no effect*/
	   NVIC_ICPR0= (1U <<Copy_u8IntNum);  
	}
	else if(Copy_u8IntNum <= 63)
	{
		/* 32 = 0  And So On */
		Copy_u8IntNum-=32 ; 
		NVIC_ICPR1= (1U <<Copy_u8IntNum); 
	}
	else if(Copy_u8IntNum <= 84)
	{
		/* 64 = 0  And So On */
		Copy_u8IntNum-=64 ;
		NVIC_ICPR2= (1U <<Copy_u8IntNum);
	}
	
	
}

void MNVIC_VidClearPending ( u8 Copy_u8INTID ){
        if(Copy_u8INTID <=240)
	NVIC_ICPR[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;

}

	

	
/*********************************************************** END_ FUNCTION   ***********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function :	
					Read Active State 
						*/
u8	 MNVIC_voidGetActiveFlag(u8 Copy_u8IntNum)	
{
	u8 Local_u8ActiveState = 0 ;   
	if (Copy_u8IntNum <=31 )
	{ /* 0-----> no effect*/
	  Local_u8ActiveState= (u8) NVIC_IABR0 &(1<<Copy_u8IntNum);  
	}
	else if(Copy_u8IntNum <= 63)
	{
		/* 32 = 0  And So On */
		Copy_u8IntNum-=32;
		Local_u8ActiveState= (u8) NVIC_IABR0 &(1U<<Copy_u8IntNum); 
	}
	else if(Copy_u8IntNum <= 90)
	{
		/* 64 = 0  And So On */
		Copy_u8IntNum-=64;
		Local_u8ActiveState= (u8)NVIC_IABR0 &(1U<<Copy_u8IntNum); 
	}
	return Local_u8ActiveState ;
	
}
	


u8   MNVIC_u8GetActive( u8 Copy_u8INTID ){
        if(Copy_u8INTID <=7)
		{
	     u8 LOC_u8Active = GET_BIT( (NVIC_IAPR[ Copy_u8INTID/32 ]) , ( Copy_u8INTID % 32 ) );
		}
	return LOC_u8Active ;

}



	
/*********************************************************** END_ FUNCTION   ***********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function :	 * Handel Only External Int Priority	
					 * Divide REG From SCB From  And Put Your Priority In IPR Bit  ( 4 , 5 , 6 , 7 ) So Must << 4 bit
					 
		*/
		
		
void MNVIC_vSetGSPriority(u8 Copy_IntID , u8 Copy_u8SubPriority , u8 Copy_u8GroupPriority,u8 Copy_u8GS)	
{
	if(Copy_IntID<=240)
		switch(Copy_u8GS)
		{ 
				          /*  grou */
			case 0:NVIC_IPR[Copy_IntID]=(u8)(Copy_u8GroupPriority<<4);
			case 1:NVIC_IPR[Copy_IntID]=(u8)(Copy_u8GroupPriority<<5 )|(Copy_u8SubPriority<< 4);
			case 2:NVIC_IPR[Copy_IntID]=(u8)(Copy_u8GroupPriority<<6)|(Copy_u8SubPriority<< 4);
			case 3:NVIC_IPR[Copy_IntID]=(u8)(Copy_u8GroupPriority<<7 )|(Copy_u8SubPriority<< 4);
			case 4:NVIC_IPR[Copy_IntID]=(u8)(Copy_u8SubPriority<< 4);
			
			
			
		}
	
	
}
		
	
		
void MNVIC_voidSetPriority(u8 Copy_u8IntNum, u8 Copy_u8GroupPriority , u8 Copy_u8SubGroupPriority , u8 Copy_u8GroupPriorityCFG  )	
{	/* Switch From Private  */
	switch(Copy_u8GroupPriorityCFG)
	{
			/* All For Group */
	   case GROUP_PRIORITY_CFG0:		
						/*		PassWord (0x05FA)+ Case (  (4) For Group  &  (0) For SubGroub		*/	
						SCB_AIRCR =0x05FA0300;
							/*	At IPR[Indx] Put The Four Bit For Group  */	
							/*  Index is The Peripheral ID From Vector Table*/
						NVIC_IPR[Copy_u8IntNum]= (u8)(Copy_u8GroupPriority<<4U);		 
	   break ;
   /**************************/		 
	   case GROUP_PRIORITY_CFG1 :								 
						/*		PassWord + Case (  (3) For Group  &  (1) For SubGroub		*/
						SCB_AIRCR |= 0x05FA0400 ;					 
						NVIC_IPR[Copy_u8IntNum]= (u8) (Copy_u8GroupPriority<<5U)|((u8)(Copy_u8SubGroupPriority << 4U))	;									 
	   	break ;	
   /**************************/			 
	   case GROUP_PRIORITY_CFG2 :								 
						/*		PassWord + Case (  (2) For Group  &  (2) For SubGroub		*/
						SCB_AIRCR =0X05FA0500 ;					 
							NVIC_IPR[Copy_u8IntNum]=(u8) (Copy_u8GroupPriority<<6U)|((u8)(Copy_u8SubGroupPriority << 4U))	;													 
	   	break ;	
   /**************************/			 
	   case GROUP_PRIORITY_CFG3 :								 
						/*		PassWord + Case (  (1) For Group  &  (3) For SubGroub		*/
						SCB_AIRCR=0X05FA0600 ;					 
						NVIC_IPR[Copy_u8IntNum]= (u8)(Copy_u8GroupPriority<<7U)|((u8)(Copy_u8SubGroupPriority << 4U))	;
		 break ;
   /**************************/														 
	   case GROUP_PRIORITY_CFG4 :								 
						/*		PassWord + Case (  (0) For Group  &  (4) For SubGroub		*/
						SCB_AIRCR =0X05FA0700 ;
						NVIC_IPR[Copy_u8IntNum]=(u8)(Copy_u8SubGroupPriority << 4U)	;
		 	 break ;
   /**************************/	

	   default :
	   	break ;			 
	}
	 
}
/*
#define  GROUP_PRIORITY_CFG0						0U 
#define  GROUP_PRIORITY_CFG1						1U 
#define  GROUP_PRIORITY_CFG2						2U
#define  GROUP_PRIORITY_CFG3						3U
#define  GROUP_PRIORITY_CFG4						4U

*/


MNVIC_vSetConf(u8 Copy_u8Conf)
{ /* Safty reseat value */
	SCB_AIRCR=0xFA050000;
	switch|(Copy_u8Conf)
	{
		case GROUP_PRIORITY_CFG0:  SCB_AIRCR = PASS_G4S0         break;
		case GROUP_PRIORITY_CFG1:  SCB_AIRCR = PASS_G3S1         break;
		case GROUP_PRIORITY_CFG2:  SCB_AIRCR = PASS_G2S2         break;
		case GROUP_PRIORITY_CFG3:  SCB_AIRCR = PASS_G1S3         break;
		case GROUP_PRIORITY_CFG4:  SCB_AIRCR = PASS_G0S4         break;
	}
	
	
	
}
	  









/*********************************************************** END_ FUNCTION   ***********************************************************/