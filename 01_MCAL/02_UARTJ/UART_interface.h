/****************************************************************
 ************   - UART_interface.h                  ******************
 ***********   -Created: 8/21/2021		    ******************
 ***********   -Author: Abdelrahman_Magdy           ******************
 ***********   -Version : _1_			    ******************
 ***********  -					    ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/ 

/**************		The Archictect Give The API		**************/
/**************  Application Public Interface   **************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H
	 
#include "STD_TYPE.h"
#define USART1_DISABLE          0U
#define USART1_ENABLE           1U

#define _8BIT_WORD_LENGTH       0U
#define _9BIT_WORD_LENGTH       1U

#define PARITY_DISABLE          0U
#define EVEN_PARITY             1U
#define ODD_PARITY              2U

#define INT_DISABLE             0U
#define TXE_INT_ENABLE          1U
#define TCE_INT_ENABLE          3U
#define RXNE_INT_ENABLE         5U

#define TRANSMITTER_DISABLE     0U
#define TRANSMITTER_ENABLE      1U

#define RECEIVER_DISBLE         0U
#define RECEIVER_ENABLE         1U

#define ONE_STOP_BIT            0U
#define HALF_STOP_BIT           1U
#define TWO_STOP_BIT            2U
#define ONE_AND_HALF_STOP_BIT   3U	


    /*              */
void MUSART_VidInit             ( void                ) ;
    /*              */
void MUSART1_VidSendCharSync    ( u8 Copy_u8Char      ) ;
   /*              */
void MUSART1_VidSendStringSynch ( u8 * Copy_ptrString ) ;
   /*              */
u8   MUSART1_u8RecCharSynch     ( void                ) ;
   /*              */
u8 * MUSART1_PtrReadStringSynch ( void                ) ;
   /*              */
void MUSART1_VidSetCallBack     ( void (*ptr) (void)  ) ;





#endif //UART_INTERFACE_H