/***********************************************************************************************
 ***************************  - SPI_program.c				 		 ***************************
***************************   - Created: 2/24/2021					 ****************************
***************************   - Author : Abdelrahman_Magdy			 ****************************
***************************   - Version: _1_				 		 ****************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/ 


/****************************************************************************************
***************************   The Foundation Of Function   ***************************** 
****************************************************************************************/


/************** INCLUDE LIB **************/
	
		 #include "STD_TYPES.h"
		 #include "BIT_MATH.h"
/*****************************************/	 

/************** INCLUDE MCAL**************/
		#include "SPI_private.h"
		#include "SPI_interface.h"
		#include "SPI_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/




void (*MUSART1_CallBack)(void);



void MUSART_VidInit ( void ){
	
	/*u32 LOC_u64Mantissa = ( F_CPU ) / ( 16 * USART1_BAUD_RATE ) ;

	u32 LOC_u64Fraction = ( ( ( F_CPU * 100 ) / ( 16 * USART1_BAUD_RATE )  ) % 100 ) * 16 ;

	if( LOC_u64Fraction > 1500 ){ LOC_u64Mantissa += 1 ; LOC_u64Fraction  = 0 ; }*/
     /* -if EN clear all flag from SR */
	#if USART1_STATUS == USART1_ENABLE
         /* 1-if EN clear all flag from SR */
		MUSART1 -> SR = 0 ;
         /* 2-Bit word lenght 8 | 9 */
		#if   USART1_WORD_LENGTH == _8BIT_WORD_LENGTH
            
					CLR_BIT( MUSART1 -> CR1 , 12 );

		#elif USART1_WORD_LENGTH == _9BIT_WORD_LENGTH

					SET_BIT( MUSART1 -> CR1 , 12 );

		#endif
/**********************************************************************************************/
         /* 3-Parity if used or not */
		#if   USART1_PARITY == PARITY_DISABLE

					CLR_BIT( MUSART1 -> CR1 , 10 );

		#elif USART1_PARITY == EVEN_PARITY
					/* Parity control enabled */
					SET_BIT( MUSART1 -> CR1 , 10 );
					/*  Even parity  */
					CLR_BIT( MUSART1 -> CR1 , 11 );

		#elif USART1_PARITY == ODD_PARITY
                    /* Parity control enabled */
					SET_BIT( MUSART1 -> CR1 , 10 );
					/*  Odd parity  */
					SET_BIT( MUSART1 -> CR1 , 11 );

		#endif
/**********************************************************************************************/
        /* 4-To disable INT or EN (TXE , RXNE ,TC) */
		#if  USART1_INTERRUPT == INT_DISABLE

					CLR_BIT( MUSART1 -> CR1 , 5 );
					CLR_BIT( MUSART1 -> CR1 , 6 );
					CLR_BIT( MUSART1 -> CR1 , 7 );

		#elif USART1_INTERRUPT == TXE_INT_ENABLE

					SET_BIT( MUSART1 -> CR1 , 7 );

		#elif USART1_INTERRUPT == TCE_INT_ENABLE

					SET_BIT( MUSART1 -> CR1 , 6 );

		#elif USART1_INTERRUPT == RXNE_INT_ENABLE

					SET_BIT( MUSART1 -> CR1 , 5 );

		#endif
/************************************************************************/
         /* 5-ENABLE OR DISABLE tx */
		#if   USART1_TRANSMITTER == TRANSMITTER_ENABLE

					SET_BIT( MUSART1 -> CR1 , 3 );

		#elif USART1_TRANSMITTER == TRANSMITTER_DISABLE

					CLR_BIT( MUSART1 -> CR1 , 3 );

		#endif
          /* 6-ENABLE OR DISABLE rx */
		#if   USART1_RECEIVER == RECEIVER_ENABLE

					SET_BIT( MUSART1 -> CR1 , 2 );

		#elif USART1_RECEIVER == RECEIVER_DISBLE

					CLR_BIT( MUSART1 -> CR1 , 2 );

		#endif
/************************************************************************/
          /* 7-The Num of Stop Bit */
		#if   USART1_STOP_BITS == ONE_STOP_BIT

					CLR_BIT( MUSART1 -> CR2 , 12 ); CLR_BIT( MUSART1 -> CR2 , 13 );

		#elif USART1_STOP_BITS == HALF_STOP_BIT

					SET_BIT( MUSART1 -> CR2 , 12 ); CLR_BIT( MUSART1 -> CR2 , 13 );

		#elif USART1_STOP_BITS == TWO_STOP_BIT

					CLR_BIT( MUSART1 -> CR2 , 12 ); SET_BIT( MUSART1 -> CR2 , 13 );

		#elif USART1_STOP_BITS == ONE_AND_HALF_STOP_BIT

					SET_BIT( MUSART1 -> CR2 , 12 ); SET_BIT( MUSART1 -> CR2 , 13 );


		#endif
	/************************************************************************/
	#if   OVER_SAMPE_MODE == SMAPLE_MODE_16
	   
				CLR_BIT( MUSART1 -> CR1 , 15U);
		   
	#elif  OVER_SAMPE_MODE == SMAPLE_MODE_8
	            
				SET_BIT( MUSART1 -> CR1 , 15U);
	
	#endif

	/************************************************************************/
         /* 8-Buad Rate in BRR*/
		MUSART1 -> BRR = USART1_BAUD_RATE ;
		//( LOC_u64Mantissa << 4  ) | ( LOC_u64Fraction / 100 ) ;
		 /* 9-Enable Uart */
		SET_BIT( MUSART1 -> CR1 , 13 );
/**************************************************************************************/
    /* Disable Uart */
	#elif USART1_STATUS == USART1_DISABLE
		CLR_BIT( MUSART1 -> CR1 , 0 );

	#endif

}


void MUSART1_VidSendCharSync ( u8 Copy_u8Char ){
	
    /* Write data in DR*/
   	MUSART1 -> DR = Copy_u8Char ;
    /* Wait untile Transmission complete */
	while( GET_BIT( MUSART1 -> SR , 6 ) == 0 );
    /* Clear the flag of transmit Complite */
	CLR_BIT( MUSART1 -> SR , 6 );

}

void MUSART1_VidSendStringSynch ( u8 * Copy_ptrString ){
/* u8 var to ++ ptr */
	u8 LOC_u8Iterator = 0 ;
/* while value not = '\0' */  
	while ( Copy_ptrString[ LOC_u8Iterator ] != '\0' ){
/* send data of ptr[u8 var] */
		MUSART1_VidSendCharSync( Copy_ptrString[ LOC_u8Iterator ] );
/* var ++*/		
		LOC_u8Iterator++ ;

	}

}

u8 MUSART1_u8RecCharSynch ( void ){

    /* CLR Read data register not empty */
	CLR_BIT ( MUSART1 -> SR, 5);
    /* Wait Received data is ready to be read */
	while( ( GET_BIT ( MUSART1 -> SR, 5) == 0 )
    /* return data */
	return (MUSART1 -> DR);

}



void MUSART1_VidSetCallBack( void (*ptr) (void) ){

	MUSART1_CallBack = ptr ;

}

void USART1_IRQHandler(void){

	MUSART1 -> SR = 0 ;
	MUSART1_CallBack();

}


/*
u8 String[20];
u8 * MUSART1_PtrReadStringSynch ( void ){

	u8 LOC_Iterator = 0 , LOC_u8DataCome ;

	while( ( LOC_u8DataCome = MUSART1_u8RecCharSynch() ) != 13 ){

		String[ LOC_Iterator ] = LOC_u8DataCome ;
		LOC_Iterator++;
	}

	String[LOC_Iterator] = '\0';

	return ( String );

}
*/