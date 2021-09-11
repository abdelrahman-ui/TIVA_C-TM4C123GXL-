/*=======================================================================================
===========================  - main.c		             ============================
===========================  - Created: 9/11/2021	     ============================
===========================  - Author: Abdelrahman_Magdy     ============================
===========================  - Version : _1_		     ============================
===========================  - Note :
					      *-
					      *-
 =======================================================================================*/



#include "TM4C123GH6PM.h"
#include "UART_interface.h"

int main()
{       
/* 1. Enable UARTx CLK                             */
 SYSCTL ->RCGCUART |=(1U<<UARTx);

/* 2. Enable GPIO CLK                             */
 SYSCTL->RCGCGPIO |=(1U<<GPIO_PORT);
 
/* 3. Set the GPIO AFSEL bits                     */
 GPIOx->AFSEL |=(1U<<PIN_Tx)|(1U<<PIN_Rx);
 
/* 4- Disable Digital pin For pin                 */
 GPIOx->DEN   &=~(1U<<PIN_Rx)|(1U<<PIN_Tx); 
 
/* 5. Configure ALF Pins As UART                  */
 GPIOx->PCTL |=(1U<<(4*PIN_Rx))|(1U<<(4*PIN_Tx));
 
/* 6. Disable UARTx                               */
 MUART_vDisable(UARTx);
 
/* 7.For Init CLK And Buad Rate                   */
 MUART_vInit(UARTx,BaudRate ,F_CP);
 
/* 8.Config UART                                  */
 MUART_vConfig(UARTx, DATA_SIZE , Parity_OFF , ONE_Stop_Bit ,FIFO_DIS );
 
/* 9. Enable UARTx                                 */
 MUART_vEnable(UARTx);
 
 
  return 0;
}
