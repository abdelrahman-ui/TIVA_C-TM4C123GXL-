/*========================================================================================
===========================   - UART_config.h		      ============================
===========================   - Created: 9/3/2021	      ============================
===========================   - Author: Abdelrahman_Magdy     ============================
===========================   - Version : _1_		      ============================
===========================   - Note :
					*-
					*-
========================================================================================*/ 

/*======================================================================================
=======================  guard of file will call on time in .c	========================
========================================================================================*/

/*=======================================================================================
          
            * Configration Type : 
                                  - Prebuilt Config	:	NO
                                  - Link Time Config	:	NO
                                  - Post Build Config	:	NO

=========================================================================================*/

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#include "UART_private.h"

#define  UARTx          2      // UART2
#define  GPIO_PORT      3     // GPIOD
#define  GPIOx          GPIOD 
#define  PIN_Tx         7U      
#define  PIN_Rx         6U
#define  BaudRate       9600    
#define  F_CP           16000000UL
#define  CLK_Config     CLK_Source
#define  DATA_SIZE      DATA_SIZE_8   
#define  PARITY         Parity_OFF 
#define  STOP_BIT_NUM   ONE_Stop_Bit 
#define  FIFI_STATE     FIFO_DIS
#define  ClkDiv         1U
#define  PARITY_CONFIG  PARITY_ODD

#endif /* UART_CONFIG_H_ */



