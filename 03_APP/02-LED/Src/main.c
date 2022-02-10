/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdelrahman Magdy
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/*****  LIB  *******/
#include "STD_TYPE.h"
#include "BIT_MATH.h"

/*****  MCAL *****/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "GPIO_interface.h"


#define LED_A0   0U
#define LED_A1   1U



int main(void)
{
    /* 1 - EN CLK PORT_A BUS -->  , NUM -->  */
	MRCC_voidEnableClock(AHB1, 0);
	/* 2 - Set pin as output   */
	MGOIP_voidSetPinMode(GPIOA_PORT,LED_A0,MODE_OUTPUT);
	MGOIP_voidSetPinMode(GPIOA_PORT,LED_A1,MODE_OUTPUT);
	/* 3 - Output Type for pin A0 */
	MGPIO_voidSetOutType(GPIOA_PORT,LED_A0, OUTPUT_TYPE_PUSH_PULL) ;
	MGPIO_voidSetOutType(GPIOA_PORT,LED_A1, OUTPUT_TYPE_PUSH_PULL) ;
	/* 4- Set Speed ---> */
	MGPIO_voidSetOutSpeed(GPIOA_PORT,LED_A0,OUTPUT_LOW_SPEED) ;
	MGPIO_voidSetOutSpeed(GPIOA_PORT,LED_A1,OUTPUT_LOW_SPEED) ;


	while(1)
	{
	/* APP */
	MGPIO_voidWriteDataOdr(GPIOA_PORT, LED_A0, HIGH);
	MGPIO_voidWriteDataOdr(GPIOA_PORT, LED_A1, LOW);
	volatile u32 L_u32Count ;
	for(L_u32Count =0;L_u32Count <500000 ;L_u32Count ++);
	MGPIO_voidWriteDataOdr(GPIOA_PORT, LED_A0, LOW);
	MGPIO_voidWriteDataOdr(GPIOA_PORT, LED_A1, HIGH);
	for(L_u32Count =0;L_u32Count <500000 ;L_u32Count ++);

	}

}





