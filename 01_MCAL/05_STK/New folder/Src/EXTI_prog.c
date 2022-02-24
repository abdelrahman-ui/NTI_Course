/***********************************************************************************************
 ***************************  - EXTI_program.c				 		 ***************************
***************************   - Created: 2/16/2022					 ****************************
***************************   - Author: Abdelrahman_Magdy			 ****************************
***************************   - Version : _1_				 		 ****************************
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
		#include "EXTI_private.h"
		#include "EXTI_interface.h"
		#include "EXTI_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/

/*static*/ //void (* EXTI0_CallBack) (void) = 0 ;

/********************************************************** Start_FUNCTION  **********************************************************/
/**/
void MEXTI_vEnableLine(u8 Copy_u8LineNum)
{
	/* */
	EXTI_IMR|=(1U<<Copy_u8LineNum);
	
}

/*
void MEXTI_vEnableLine(u8 Copy_u8LineNum)
{
	SET_BIT(EXTI->IMR,Copy_u8LineNum);
	EXTI->IMR |= (1U<<opy_u8LineNum);
}
*/

/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

/*
void MEXTI_vDisableLine(u8 Copy_u8LineNum)
{


	EXTI_IMR &=~(1U<<opy_u8LineNum);
	
}
*/
void MEXTI_vDisableLine(u8 Copy_u8LineNum)
{
	
	EXTI->IMR &=~(1U<<Copy_u8LineNum);
	
}






/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
void MEXTI_vTriggerTyp(u8 Copy_u8LineNum , u8 Copy_u8State)
{
	switch (Copy_u8State)
	{
	case RAISE     :
	  
	  /*
	    EXTI->RTSR |=(1U<<Copy_u8LineNum);
 	  */
	  EXTI_RTSR |=(u32)(1U<<Copy_u8LineNum);
	  CLR_BIT(EXTI->FTSR,Copy_u8LineNum);
	break ;
	
	
	case FALL      :
	      EXTI_FTSR |=(u32)(1U<<Copy_u8LineNum);
		  CLR_BIT(EXTI->RTSR,Copy_u8LineNum);
	break ;
	
	case ON_CHANGE :
	       EXTI_FTSR |=(u32)(1U<<Copy_u8LineNum);
	       EXTI_RTSR |=(u32)(1U<<Copy_u8LineNum);
	break ;
	}
	
}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

void MEXTI_vEventType(u8 Copy_u8LineNum )
{
#if EventType == RAISE
EXTI_RTSR |=(u32)(1U<<Copy_u8LineNum);
CLR_BIT(EXTI->FTSR,Copy_u8LineNum);
#elif EventType == FALL
EXTI_FTSR |=(u32)(1U<<Copy_u8LineNum);
CLR_BIT(EXTI->RTSR,Copy_u8LineNum);
#elif EventType == ON_CHANGE
EXTI_FTSR |=(u32)(1U<<Copy_u8LineNum);
EXTI_RTSR |=(u32)(1U<<Copy_u8LineNum);
#endif 
}








/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

void MEXTI_vTrigFlag(u8 Copy_u8LineNum)
{
	SET_BIT(EXTI->SWIER,Copy_u8LineNum);
	
}





/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

void MEXTI_voidSelectPort(  u8 Copy_u8LineNum  , u8 Copy_u8PortID  )
{
	
	/* For Port From 0 To 3 We Have SYSCFG_EXTICR1	*/
	if(Copy_u8LineNum <= 3 )
	{
		/* Make The Place =0000 -----> Safty*/
		SYSCFG_EXTICR1 &=~(u8)(0b1111<<(4*Copy_u8LineNum )) ;
		/* Sheft By 4 Bit */
		SYSCFG_EXTICR1 |= (u8)(Copy_u8PortID <<(4*Copy_u8LineNum )) ;
	}
	/* For Port From 4 To 7 We Have SYSCFG_EXTICR2	*/
	else if(Copy_u8LineNum <= 7)
	{
		/* Map (4,5,6,7) To (0,1,2,3)*/
		Copy_u8LineNum -=4 ; 
		/* Make The Place =0000 -----> Safty*/
		SYSCFG_EXTICR2 &=~ (u8)(0b1111<<(4*Copy_u8LineNum )) ;
		SYSCFG_EXTICR2 |= (u8)(Copy_u8PortID <<(4*Copy_u8LineNum )) ;
		
	}
	/* For Port From 8 To 11 We Have SYSCFG_EXTICR3	*/
	else if(Copy_u8LineNum <= 11)
	{
		/* Map (8,9,10,11) To (0,1,2,3)*/
		Copy_u8LineNum -= 8 ;
		/* Make The Place =0000 -----> Safty*/
		SYSCFG_EXTICR3 &=~ (u8)(0b1111<<(4*Copy_u8LineNum )) ;
		
		SYSCFG_EXTICR3 |= (u8)(Copy_u8PortID <<(4*Copy_u8LineNum )) ;
	}
	/* For Port From 12 To 15 We Have SYSCFG_EXTICR4	*/
	else if(Copy_u8LineNum <= 15)
	{
		/* Map (12,13,14,15) To (0,1,2,3)*/
		Copy_u8LineNum -= 12 ;
		/* Make The Place =0000 -----> Safty*/
		SYSCFG_EXTICR4 &=~ (0b1111<<(4*Copy_u8LineNum )) ;
		SYSCFG_EXTICR4 |= (Copy_u8PortID <<(4*Copy_u8LineNum )) ;
	}
}


/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
/*
void MEXTI_voidSetCallBack(void (*ptr) (void)) // abdo
{
		EXTI0_CallBack = ptr ;
}*/
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
/*
void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	//	Clear pending Bit
	SET_BIT(EXTI -> PR , 0);

}
*/
/*********************************************************** END_ FUNCTION   *********************************************************/
