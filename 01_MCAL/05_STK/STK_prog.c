#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"



/* Define Callback Global Variable */
 void(*MSTK_CallBack)(void)= NULL;

/* Define Variable for interval mode */
 u8 MSTK_u8ModeOfInterval;

void MSTK_vInit(void)
{
	#if MSTK_CLK_SRC  ==  MSTK_SRC_AHB
	SET_BIT(STK ->CTRL , 2);
	#else
	CLR_BIT(STK ->CTRL , 2);	
	
}

void MSTK_vBusyWait(u32 Copy_u32Tick)
{
	/* Value in load */
	STK -> LOAD =Copy_u32Tick ;
	/* Start timer */
	SET_BIT(STK ->CTRL , 0);
	/* Polling */
	while(!(GET_BIT(STK ->CTRL , 16) );
	/* Stop Timer */
	CLR_BIT(STK ->CTRL , 0);
	STK -> LOAD=0;
	STK -> VAL=0;
}


u32 MSTK_u32ElapedTime(void)
{
	u32 Local_u32ElapsedTime;
	
	Local_u32ElapsedTime = MSTK -> LOAD - MSTK -> VAL ;
	
	return Local_u32ElapsedTime;
	
	
}

u32 MSTK_u32RemaningTime(void)
{
	u32 Local_u32RemainTime;
	
	Local_u32RemainTime = MSTK -> VAL ;
	
	return Local_u32RemainTime;
	
	
}


/*********************************************************************************************************/

/*
 void(*MSTK_CallBack)(void)= NULL;

 u8 MSTK_u8ModeOfInterval;

*/


void MSTK_vIntervalSingle(u32 Copy_u32Tick  , void (*Copy_vPtr)(void))
{
	
	
	/*1) LOAD VALU */
	
	/*2) G_STATE  MSTK_SINGLE_INTERVAL  */
	
	/*3) SET Callback = func  */
	
	/*4) SysTick exception request enable  */

	/*5) Counter enable  */
	

}

void MSTK_vIntervalPeriodic(u32 Copy_u32Tick, void (*Copy_vPtr)(void))
{
	/*1) LOAD VALU */
	
	/*2) G_STATE  MSTK_PERIOD_INTERVAL   */
	
	/*3) SET Callback = fUNC  */
	
	/*4) SysTick exception request enable  */

	/*5) Counter enable  */
	
}



void SysTick_Handler(void)
{
	
/* Callback notification */

/* if single ==  MSTK_SINGLE_INTERVAL  */
 if(MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL )
 {
	/*  */
	
	/* SET Value =0 */
	
	/* SET load =0 */

	
 }
 
/* Clear interrupt flag  to Start agine if exception Come agine */


}