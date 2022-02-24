
/*****  LIB  *******/
#include "STD_TYPE.h"
#include "BIT_MATH.h"

/*****  MCAL *****/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"


/* MACRO */
#define A0   0U
#define A1   1U
#define A2   2U
#define A3   3U



/*  Prototype  */
void Set_vPin(void);
void abdo (void);
void (* EXTI0_CallBack) (void) = 0 ;
void MEXTI_voidSetCallBack(void (*ptr) (void));

volatile u32 test =0 ;

int main(void)
{

	/* Init RCC  AHB --> 8000000						*/



    /* EN CLK PORT_A BUS -->  , NUM -->  */
	MRCC_voidEnableClock(AHB1, 0U);

	/*  Set Pines      */
	Set_vPin();

	/* Set Call Back EXTI0,1 */
	MEXTI_voidSetCallBack(abdo);



	 /* Enable Line ( A0....H0) & (A1...H1) */
	 MEXTI_vEnableLine(0);

     /* */

    /* Select (PIN0,1) PORT  A */
	MEXTI_voidSelectPort(  0 , 0b0000 );

    /* State FALL  */
	MEXTI_vTriggerTyp(0,RAISE);



	/* Enable  EXT0  from NVIC  */
		 MNVIC_voidSetEnable(6);
	while(1)
	{

		if(test == 1)
		{
			test =0 ;
			MNVIC_VidSetPending(6);

		}
    }

	return 0;

}

void MEXTI_voidSetCallBack(void (*ptr) (void)) // abdo
{
		EXTI0_CallBack = ptr ;
}

void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 0);

}



void abdo (void)
{
	MGPIO_voidWriteDataOdr(GPIOA_PORT ,A2, HIGH);
	/*Delay for 1 Sec		*/
	MSTK_vBusyWait(1000000);

	MGPIO_voidWriteDataOdr(GPIOA_PORT ,A2, HIGH);
	/*Delay for 1 Sec		*/
	MSTK_vBusyWait(1000000);

}



void Set_vPin(void)
{

	    /* 2 - Set pin as INPUT   */
		MGOIP_voidSetPinMode(GPIOA_PORT,A0,MODE_INPUT);

		/* 3 - PULL DOWEN  */
		MGPIO_voidSetPull(GPIOA_PORT,A0,PULL_DOWN)  ;


		/* 4 - Set pin as INPUT   */
		MGOIP_voidSetPinMode(GPIOA_PORT , A2 , MODE_OUTPUT);

		/* 5 - Set pin as INPUT   */
		MGPIO_voidSetOutType(GPIOA_PORT , A2, OUTPUT_TYPE_PUSH_PULL );

		/* 6 - Set pin as INPUT   */
		MGPIO_voidSetOutSpeed(GPIOA_PORT , A2 , OUTPUT_LOW_SPEED);


}









