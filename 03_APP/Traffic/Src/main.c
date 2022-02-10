
/************** INCLUDE LIB **************/
		 #include "STD_TYPE.h"
		 #include "BIT_MATH.h"
		 #include "Delay_interface.h"
/*****************************************/

/************** INCLUDE MCAL**************/
		#include "RCC_private.h"
		#include "RCC_interface.h"
		#include "GPIO_interface.h"

/*****************************************/

#define GREEN_LED   0
#define RED_LED     1
#define ORANG_LED   2


#define A0           0U
#define A1			 1U
#define A2 			 2U
#define A3           3U
#define A4			 4U
#define A5 			 5U
#define A6 			 6U

void HSEG_vOpen(u8 Copy_u8Val);
void Trafic_Cycle(void);
void PIN_vSet();

int main (void)
{

					/* 			Enable CLK For GPIOG				*/
	MRCC_voidEnableClock(AHB1,PERIPHERAL_EN_GPIOA);
	MRCC_voidEnableClock(AHB1,PERIPHERAL_EN_GPIOB);
	//RCC_AHB1ENR |= (1U<<6);
	PIN_vSet()	;
	    MGOIP_voidSetPinMode(GPIOB,GREEN_LED ,MODE_OUTPUT );
		MGOIP_voidSetPinMode(GPIOB,RED_LED,MODE_OUTPUT );
		MGOIP_voidSetPinMode(GPIOB,ORANG_LED,MODE_OUTPUT );
		MGPIO_voidSetOutType(GPIOB,GREEN_LED,OUTPUT_TYPE_PUSH_PULL );
		MGPIO_voidSetOutType(GPIOB,RED_LED  ,OUTPUT_TYPE_PUSH_PULL );
		MGPIO_voidSetOutType(GPIOB,ORANG_LED,OUTPUT_TYPE_PUSH_PULL );
		MGPIO_voidSetOutSpeed(GPIOB,GREEN_LED,OUTPUT_LOW_SPEED)  ;
		MGPIO_voidSetOutSpeed(GPIOB,RED_LED  ,OUTPUT_LOW_SPEED)  ;
		MGPIO_voidSetOutSpeed(GPIOB,ORANG_LED,OUTPUT_LOW_SPEED)  ;

	while(1)
	{
		MGPIO_voidWriteDataOdr(GPIOB,GREEN_LED,HIGH);
		MGPIO_voidWriteDataOdr(GPIOB,RED_LED ,LOW);
		MGPIO_voidWriteDataOdr(GPIOB,ORANG_LED,LOW);
	    Trafic_Cycle();
		MGPIO_voidWriteDataOdr(GPIOB,GREEN_LED,LOW);
		MGPIO_voidWriteDataOdr(GPIOB,RED_LED ,HIGH);
		MGPIO_voidWriteDataOdr(GPIOB,ORANG_LED,LOW);
	    Trafic_Cycle();
        MGPIO_voidWriteDataOdr(GPIOB,GREEN_LED,LOW);
	    MGPIO_voidWriteDataOdr(GPIOB,ORANG_LED,HIGH);
		MGPIO_voidWriteDataOdr(GPIOB,RED_LED ,LOW);
        Trafic_Cycle();

	}


}






void Trafic_Cycle()
{
	    HSEG_vOpen(9);
		Delay_vMsIn16MHz(1000);
		HSEG_vOpen(8);
		Delay_vMsIn16MHz(1000);
		HSEG_vOpen(7);
		Delay_vMsIn16MHz(1000);
		HSEG_vOpen(6);
	    Delay_vMsIn16MHz(1000);
		HSEG_vOpen(5);
		Delay_vMsIn16MHz(1000);
		HSEG_vOpen(4);
		Delay_vMsIn16MHz(1000);
		HSEG_vOpen(3);
		Delay_vMsIn16MHz(1000);
		HSEG_vOpen(2);
		Delay_vMsIn16MHz(1000);
		HSEG_vOpen(1);
		Delay_vMsIn16MHz(1000);
		HSEG_vOpen(0);
		Delay_vMsIn16MHz(1000);
}





void PIN_vSet()
{

	MGOIP_voidSetPinMode(GPIOA,A0,MODE_OUTPUT );
	MGOIP_voidSetPinMode(GPIOA,A1,MODE_OUTPUT );
	MGOIP_voidSetPinMode(GPIOA,A2,MODE_OUTPUT );
	MGOIP_voidSetPinMode(GPIOA,A3,MODE_OUTPUT );
	MGOIP_voidSetPinMode(GPIOA,A4,MODE_OUTPUT );
	MGOIP_voidSetPinMode(GPIOA,A5,MODE_OUTPUT );
	MGOIP_voidSetPinMode(GPIOA,A6,MODE_OUTPUT );

						/*	The Output Be OUTPUT_TYPE_PUSH_PULL		*/
	MGPIO_voidSetOutType(GPIOA,A0,OUTPUT_TYPE_PUSH_PULL );
	MGPIO_voidSetOutType(GPIOA,A1,OUTPUT_TYPE_PUSH_PULL );
	MGPIO_voidSetOutType(GPIOA,A2,OUTPUT_TYPE_PUSH_PULL );
	MGPIO_voidSetOutType(GPIOA,A3,OUTPUT_TYPE_PUSH_PULL );
	MGPIO_voidSetOutType(GPIOA,A4,OUTPUT_TYPE_PUSH_PULL );
	MGPIO_voidSetOutType(GPIOA,A5,OUTPUT_TYPE_PUSH_PULL );
	MGPIO_voidSetOutType(GPIOA,A6,OUTPUT_TYPE_PUSH_PULL );


						/* The Speed OUTPUT_LOW_SPEED */
	MGPIO_voidSetOutSpeed(GPIOA,A0,OUTPUT_LOW_SPEED)  ;
	MGPIO_voidSetOutSpeed(GPIOA,A1,OUTPUT_LOW_SPEED)  ;
	MGPIO_voidSetOutSpeed(GPIOA,A2,OUTPUT_LOW_SPEED)  ;
	MGPIO_voidSetOutSpeed(GPIOA,A3,OUTPUT_LOW_SPEED)  ;
	MGPIO_voidSetOutSpeed(GPIOA,A4,OUTPUT_LOW_SPEED)  ;
	MGPIO_voidSetOutSpeed(GPIOA,A5,OUTPUT_LOW_SPEED)  ;
	MGPIO_voidSetOutSpeed(GPIOA,A6,OUTPUT_LOW_SPEED)  ;


}


void HSEG_vOpen(u8 Copy_u8Val)
{
	switch(Copy_u8Val)
	{
		case 0 : /* (A : 1) , (B : 1) , (c : 1) , (d : 1), (E : 1) , (f : 1) , (G : 0)  */
				MGPIO_voidWriteDataOdr(GPIOA,A0,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A1,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A2,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A3,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A4,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A5,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A6,LOW);
		break ;
		case 1 : /* (A : 1) , (B : 1) , (c : 1) , (d : 1), (E : 1) , (f : 1) , (G : 0)  */
				MGPIO_voidWriteDataOdr(GPIOA,A0,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A1,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A2,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A3,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A4,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A5,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A6,LOW);
		break ;
		case 2 :/* (A : 1) , (B : 1) , (c : 1) , (d : 1), (E : 1) , (f : 1) , (G : 0)  */
				MGPIO_voidWriteDataOdr(GPIOA,A0,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A1,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A2,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A3,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A4,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A5,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A6,HIGH);
		break ;
		case 3 :  /* (A : 1) , (B : 1) , (c : 1) , (d : 1), (E : 1) , (f : 1) , (G : 0)  */
				MGPIO_voidWriteDataOdr(GPIOA,A0,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A1,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A2,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A3,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A4,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A5,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A6,HIGH);
		break ;
		case 4 : /* (A : 1) , (B : 1) , (c : 1) , (d : 1), (E : 1) , (f : 1) , (G : 0)  */
				MGPIO_voidWriteDataOdr(GPIOA,A0,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A1,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A2,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A3,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A4,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A5,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A6,HIGH);
		break ;
		case 5 : /* (A : 1) , (B : 1) , (c : 1) , (d : 1), (E : 1) , (f : 1) , (G : 0)  */
				MGPIO_voidWriteDataOdr(GPIOA,A0,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A1,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A2,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A3,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A4,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A5,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A6,HIGH);
		break ;
		case 6 :/* (A : 1) , (B : 1) , (c : 1) , (d : 1), (E : 1) , (f : 1) , (G : 0)  */
				MGPIO_voidWriteDataOdr(GPIOA,A0,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A1,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A2,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A3,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A4,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A5,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A6,HIGH);
		break ;
		case 7 :/* (A : 1) , (B : 1) , (c : 1) , (d : 1), (E : 1) , (f : 1) , (G : 0)  */
				MGPIO_voidWriteDataOdr(GPIOA,A0,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A1,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A2,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A3,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A4,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A5,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A6,HIGH);
		break ;
		case 8 :/* (A : 1) , (B : 1) , (c : 1) , (d : 1), (E : 1) , (f : 1) , (G : 0)  */
				MGPIO_voidWriteDataOdr(GPIOA,A0,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A1,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A2,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A3,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A4,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A5,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A6,HIGH);
		break ;
		case 9 :/* (A : 1) , (B : 1) , (c : 1) , (d : 1), (E : 1) , (f : 1) , (G : 0)  */
				MGPIO_voidWriteDataOdr(GPIOA,A0,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A1,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A2,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A3,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A4,LOW);
				MGPIO_voidWriteDataOdr(GPIOA,A5,HIGH);
				MGPIO_voidWriteDataOdr(GPIOA,A6,HIGH);
		break ;


	}


}

