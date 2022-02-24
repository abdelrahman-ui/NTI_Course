#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* Define Callback Global Variable */
 void(*MSTK_CallBack)(void)= 0;

/* Define Variable for interval mode */
 u8 MSTK_u8ModeOfInterval;

void MSTK_vInit(void)
{
	// Enable Systick Interrupt  -  Clock = AHB / 8 - Stop Systic
	MSTK->CTRL = 0x00000002;
}

void MSTK_vBusyWait(u32 Copy_u32Tick)
{
	/* Value in load */
	STK -> LOAD =Copy_u32Tick ;
	/* Start timer */
	SET_BIT(STK ->CTRL , 0);
	/* Polling */
	while( (GET_BIT(STK->CTRL,16)) == 0);
	/* Stop Timer */
	CLR_BIT(STK ->CTRL , 0);
	STK -> LOAD=0;
	STK -> VAL=0;
}


u32 MSTK_u32ElapedTime(void)
{
	u32 Local_u32ElapsedTime;
	
	Local_u32ElapsedTime = STK -> LOAD - STK -> VAL ;
	
	return Local_u32ElapsedTime;
	
	
}

u32 MSTK_u32RemaningTime(void)
{
	u32 Local_u32RemainTime;
	
	Local_u32RemainTime = STK -> VAL ;
	
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
	STK-> LOAD =Copy_u32Tick;
	/*2) G_STATE  MSTK_SINGLE_INTERVAL  */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	/*3) SET Callback = func  */
	MSTK_CallBack=Copy_vPtr;
	/*4) SysTick exception request enable  */
     SET_BIT( STK-> CTRL ,1U);
	/*5) Counter enable  */
     SET_BIT( STK-> CTRL ,0U);

}

void MSTK_vIntervalPeriodic(u32 Copy_u32Tick, void (*Copy_vPtr)(void))
{
	/*1) LOAD VALU */
	STK-> LOAD =Copy_u32Tick;
	/*2) G_STATE  MSTK_PERIOD_INTERVAL   */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL ;
	/*3) SET Callback = fUNC  */
	MSTK_CallBack=Copy_vPtr;
	/*4) SysTick exception request enable  */
	SET_BIT( STK-> CTRL ,1U);
     /*5) Counter enable  */
	 SET_BIT( STK-> CTRL ,0U);
}

void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK->CTRL, 1U);
	/* STOP Timer  */
   CLR_BIT( STK-> CTRL ,0U);
	/* SET Value =0 */
	STK-> VAL= 0U ;
	/* SET load =0 */
   STK-> LOAD = 0U ;

}

void SysTick_Handler(void)
{
	
/* Callback notification */
	MSTK_CallBack();
/* if single ==  MSTK_SINGLE_INTERVAL  */
 if(MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL )
 {
	/* STOP Timer  */
	 CLR_BIT( STK-> CTRL ,0U);
	/* SET Value =0 */
	 STK-> VAL= 0U ;
	/* SET load =0 */
	 STK-> LOAD = 0U ;
	
 }
 
/* Clear interrupt flag  to Start agine if exception Come agine */
 CLR_BIT( STK-> CTRL ,16U);

}
u8 MSTK_u8ReadFlag( void ){

	return ( GET_BIT( STK->CTRL , 16 ) );

}
