
/***************************************************************************************
 ***************************  - RCC_interface.h				       ***************************
***************************   - Created: 1/5/2021			       ***************************
***************************   - Author: Abdelrahman_Magdy    ***************************
***************************   - Version : _1_				         ***************************
***************************   - Note :
																		    *-
																			  *-
******************************************************************************/

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


#define LED_GREEN 13U
#define LED_RED   14U

int main (void)
{
	/* 1-Enable CLK for port G in AHB_1 */
	MRCC_voidEnableClock(AHB1_BUS,PERIPHERAL_EN_GPIOG);
	/* 2- Set mode of pin LED GREEN & RED */
	MGOIP_voidSetPinMode(GPIOG ,LED_GREEN,MODE_OUTPUT);
	MGOIP_voidSetPinMode(GPIOG ,LED_RED,MODE_OUTPUT);
	/* 3- SET OUTPUT Type (Pushpull ) */
	MGPIO_voidSetOutType(GPIOG ,LED_GREEN,OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetOutType(GPIOG ,LED_RED, OUTPUT_TYPE_PUSH_PULL);
	/* 4- Set speed low    */
	MGPIO_voidSetOutSpeed(GPIOG ,LED_GREEN,OUTPUT_LOW_SPEED);
	MGPIO_voidSetOutSpeed(GPIOG ,LED_RED,OUTPUT_LOW_SPEED);
	while(1)
	{
		
		MGPIO_voidWriteDataOdr(GPIOG ,LED_GREEN ,HIGH);
		MGPIO_voidWriteDataOdr(GPIOG ,LED_RED ,LOW);
		volatile u32 L_u32Count = 0;
		for(L_u32Count=0;L_u32Count < 500000U ; L_u32Count++);
		MGPIO_voidWriteDataOdr(GPIOG ,LED_GREEN ,LOW);
		MGPIO_voidWriteDataOdr(GPIOG ,LED_RED ,HIGH);
		for(L_u32Count=0;L_u32Count < 500000U ; L_u32Count++);
		
		
		
		
	}
	
}
