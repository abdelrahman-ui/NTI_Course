




/************** INCLUDE LIB **************/
		 #include "STD_TYPE.h"
		 #include "BIT_MATH.h"
/*****************************************/	 

/************** INCLUDE MCAL**************/
		#include "RCC_interface.h"
		#include "RCC_private.h"
		#include "GPIO_interface.h"
/*****************************************/

/************** INCLUDE HALL**************/


/* At Port G */
#define LED_GREEN  13U
#define LED_RED    14U

int main (void)
{
	/* 1- Enable CLK for port G (AHP1) BIT --> 6  */
	MRCC_voidEnableClock (AHB1_BUS ,PERIPHERAL_EN_GPIOG);
	/* 2- Set The Mode Of Pin LED_GREEN & LED_RED --> OUTPUT	*/
	MGOIP_voidSetPinMode(GPIOG ,LED_GREEN,MODE_OUTPUT);
	MGOIP_voidSetPinMode(GPIOG ,LED_RED  ,MODE_OUTPUT);
	/* 3- Set The Type Of OutPut PushPull 	*/
	MGPIO_voidSetOutType(GPIOG ,LED_GREEN ,OUTPUT_TYPE_PUSH_PULL); 
	MGPIO_voidSetOutType(GPIOG ,LED_RED   ,OUTPUT_TYPE_PUSH_PULL);
	/*4- Set The Speed Of output pin  LOW 		*/
  MGPIO_voidSetOutSpeed(GPIOG ,LED_GREEN ,OUTPUT_LOW_SPEED	);
	MGPIO_voidSetOutSpeed(GPIOG ,LED_RED   ,OUTPUT_LOW_SPEED	);
	while(1)
	{
	/*		Function To Write Data At ODR	Value */
  MGPIO_voidWriteDataOdr(GPIOG ,LED_GREEN ,HIGH	);
	MGPIO_voidWriteDataOdr(GPIOG ,LED_RED ,LOW );
	/* Delay if volatile not here */
	/* volatile */ u32 L_u8Count = 0 ;
	for( L_u8Count = 0  ; L_u8Count <500000U ; L_u8Count++);
	/*		Function To Write Data At ODR	Value */
  MGPIO_voidWriteDataOdr(GPIOG ,LED_GREEN ,LOW	);
	MGPIO_voidWriteDataOdr(GPIOG ,LED_RED,HIGH );
	/* Delay */
	for(L_u8Count = 0 ; L_u8Count <500000U; L_u8Count++);	
		
	}
}

