/***************************************************************************************
 *************************** - EXTI _private.h				 ***************************
***************************   -Created: 2/16/2022			 ***************************
***************************   -Author: Abdelrahman_Magdy     ***************************
***************************   -Version : _1_				 ***************************
***************************   -Note :
									*-
									*-
 **************************************************************************************/ 

/**************************************************************************************

*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	NO
					- Union		:	NO
					- Struct	:	NO

**************************************************************************************/

/*************************************************************************************
******************* guard of file will call on time in .c		   *******************
*************************************************************************************/ 




#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#include "STD_TYPE.h"
/*
AS define 
*/

#define EXTI_BASS_ADDRESS  0x40013C00

#define EXTI_IMR        (*(volatile  u32 *)(EXTI_BASS_ADDRESS+0x00))         
#define EXTI_EMR        (*(volatile  u32 *)(EXTI_BASS_ADDRESS+0x04))
#define EXTI_RTSR       (*(volatile  u32 *)(EXTI_BASS_ADDRESS+0x08))
#define EXTI_FTSR       (*(volatile  u32 *)(EXTI_BASS_ADDRESS+0x0c))
#define EXTI_SWIER      (*(volatile  u32 *)(EXTI_BASS_ADDRESS+0x10))
#define EXTI_PR         (*(volatile  u32 *)(EXTI_BASS_ADDRESS+0x14))





/*
Struct 

*/
typedef struct {
	volatile  u32 IMR   ;  
	volatile  u32 EMR   ;
	volatile  u32 RTSR  ;
	volatile  u32 FTSR  ;
	volatile  u32 SWIER ;
	volatile  u32 PR    ;
}S_EXTI_t;


#define  EXTI        ((S_EXTI_t *)(EXTI_BASS_ADDRESS))
         
#define SYSCFG_Base_Address				    0x40013800

#define SYSCFG_EXTICR1                (*( u32*)(SYSCFG_Base_Address+0x08))
#define SYSCFG_EXTICR2                (*( u32*)(SYSCFG_Base_Address+0x0c))
#define SYSCFG_EXTICR3                (*( u32*)(SYSCFG_Base_Address+0x10))
#define SYSCFG_EXTICR4                (*( u32*)(SYSCFG_Base_Address+0x14))


#endif  //EXTI_PRIVATE_H
