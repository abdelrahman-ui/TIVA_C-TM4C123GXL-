/*========================================================================================
===========================   - UART_interface.h	     ============================
===========================   - Created: 9/3/2021	     ============================
===========================   - Author: Abdelrahman_Magdy    ============================
===========================   - Version : _1_		     ============================
===========================   - Note :
					  *-
					  *-
========================================================================================*/ 



/*========================================================================================
		
               * What i sell To Customer
               *  The Archictect Give The API :
						 - The Name Of Function 
						 - What is The Input 
						 - What Is The Output
						 - Macro 
						 
========================================================================================*/ 

/*======================================================================================
=======================  guard of file will call on time in .c	========================
========================================================================================*/

/*========================================================================================

* PARITY  : Odd , Even , NotUse

Ideal_State                                                                      Stop 1:2 -> Bit                                            
**************          *************************************************************************
            *           *                                         *           *                                           
            * START_bit *        Data = 8 : 9 --> Bit             * Parity_Bit*  
            *           *                                         *           *
            ********************************************************************
              
========================================================================================*/


#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "STD_TYPE.h"
#include "UART_private.h"
#include "UART_config.h"




  /* ========== Function To Enable UARTx  ========== */
void MUART_vEnable(u8 copy_u8UartNum);

  /* ========== Function To Initiate UART ( Baudrate And CPU Frequancy )  ========== */
void MUART_vInit(u8 copy_u8UartNum ,u32 copy_u32BR ,u32 copy_u32F_CPU );

  /* ========== Function To Config UART   ========== */
void MUART_vConfig(u8 copy_u8UartNum , DATA_SIZE_t DATA_SIZE , PARITY_t PARITY , STOP_BIT_t STOP_BIT_NUM ,FIFO_STATE_t FIFO_STATE  );

/* ========== Function To Config PARITY   ========== */
void MUART_vParityConfig(u8 copy_u8UartNum  ,PARITY_CONFIG_t PARITY_CONFIG);

  /* ========== Function To Send Char  ========== */
void MUART_vWrite(u8 copy_u8Char);

  /* ========== Function To Send String  ========== */
void MUART_vWriteString(u8 const * string);

  /* ========== Function To Write   ========== */
void MUART_vWriteInt(u32 copy_u32Number);

  /* ========== Function To Read From Rx  ========== */
u8 MUART_u8Read(void);


  /* ========== Function To Select UARTx Base Address  ========== */
UARTx_t* MUART_SptrSelect(u8 copy_u8UartNum);

  /* ========== Function To Disable UARTx  ========== */
void MUART_vDisable(u8 copy_u8UartNum);
   



#endif /* UART_INTERFACE_H*/


