/***************************************************************************************
 *************************** - EXTI _interface.h			 ***************************
***************************   -Created: 2/18/2022			 ***************************
***************************   -Author: Abdelrahman_Magdy	 ***************************
***************************   -Version : _1_				 ***************************
***************************   -Note :
									*-
									*-
 **************************************************************************************/ 



/*************************************************************************************
		* What i sell To Customer
		*  The Archictect Give The API	
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
						- Macro 
						 
*************************************************************************************/ 

/*************************************************************************************
******************* guard of file will call on time in .c		   *******************
*************************************************************************************/



#ifndef EXI_INTERFACE_H
#define EXI_INTERFACE_H

#include "STD_TYPE.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/*Choise line  */
void MEXTI_vEnableLine(u8 Copy_u8LineNum);


void MEXTI_vMaskLine(u8 Copy_u8LineNum);

void MEXTI_vTriggerTyp(u8 Copy_u8LineNum , u8 Copy_u8State);


#define RAISE         0U
#define FALL          1U
#define ON_CHANGE     2U

void MEXTI_vTrigSW(u8 Copy_u8LineNum);


void MEXTI_voidSelectPort(  u8 Copy_u8LineNum  , u8 Copy_u8PortID  );





#endif //EXI_INTERFACE_H



