/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"




int main(void)
{
	MRCC_voidEnableClock(AHB1, 0);

	MGOIP_voidSetPinMode(GPIOA_PORT ,PIN0 ,MODE_OUTPUT );
	MGOIP_voidSetPinMode(GPIOA_PORT ,PIN1 ,MODE_OUTPUT );
	MGPIO_voidSetOutType(GPIOA_PORT,PIN0,OUTPUT_TYPE_PUSH_PULL );
	MGPIO_voidSetOutType(GPIOA_PORT,PIN1,OUTPUT_TYPE_PUSH_PULL );
	MGPIO_voidSetOutSpeed(GPIOA_PORT,PIN0,OUTPUT_LOW_SPEED)  ;
	MGPIO_voidSetOutSpeed(GPIOA_PORT,PIN1,OUTPUT_LOW_SPEED);

	while(1)
	{
		/*		Function To Write Data At ODR	Value */
		  MGPIO_voidWriteDataOdr(GPIOA_PORT,PIN0 ,HIGH	);
			MGPIO_voidWriteDataOdr(GPIOA_PORT , PIN1 ,LOW );
			/* Delay if volatile not here */
			/* volatile */ u32 L_u8Count = 0 ;
			for( L_u8Count = 0  ; L_u8Count <500000U ; L_u8Count++);
			/*		Function To Write Data At ODR	Value */
		  MGPIO_voidWriteDataOdr(GPIOA_PORT ,PIN0 ,LOW	);
			MGPIO_voidWriteDataOdr(GPIOA_PORT ,PIN1,HIGH );
			/* Delay */
			for(L_u8Count = 0 ; L_u8Count <500000U; L_u8Count++);


	}

}