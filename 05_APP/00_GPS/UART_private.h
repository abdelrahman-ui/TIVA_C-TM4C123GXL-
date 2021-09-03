/***************************************************************************************
 ***************************  - UART_private.h		     ***************************
***************************   - Created: 9/2/2021	     ***************************
***************************   - Author: Abdelrahman_Magdy    ***************************
***************************   - Version : _1_		     ***************************
***************************   - Note :
					      *-
					      *-
 **************************************************************************************/ 

/**************************************************************************************

*	  - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	NO
					- Union		:	NO
					- Struct	:	YES

**************************************************************************************/

/*************************************************************************************
******************* guard of file will call on time in .c          *******************
*************************************************************************************/ 

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "STD_TYPE.h"
/* ================================================================================ */
/* ================                      UART0                     ================ */
/* ================================================================================ */


/**
  *  Register map for UART0 peripheral (UART0)
  */

typedef struct {                                    /*!< UART0 Structure                      */
  volatile u32  DR;                                /*!< UART Data                            */
  
  union {
    volatile u32 ECR_UART_ALT;                    /*!< UART Receive Status/Error Clear      */
    volatile u32 RSR;                             /*!< UART Receive Status/Error Clear      */
  };
  volatile u32  RESERVED0[4];                      /*!< 4 Reserved of u32             
  volatile u32  FR;                                /*!< UART Flag                            */
  volatile u32  RESERVED1;
  volatile u32  ILPR;                              /*!< UART IrDA Low-Power Register         */
  volatile u32  IBRD;                              /*!< UART Integer Baud-Rate Divisor       */
  volatile u32  FBRD;                              /*!< UART Fractional Baud-Rate Divisor    */
  volatile u32  LCRH;                              /*!< UART Line Control                    */
  volatile u32  CTL;                               /*!< UART Control                         */
  volatile u32  IFLS;                              /*!< UART Interrupt FIFO Level Select     */
  volatile u32  IM;                                /*!< UART Interrupt Mask                  */
  volatile u32  RIS;                               /*!< UART Raw Interrupt Status            */
  volatile u32  MIS;                               /*!< UART Masked Interrupt Status         */
  volatile u32  ICR;                               /*!< UART Interrupt Clear                 */
  volatile u32  DMACTL;                            /*!< UART DMA Control                     */
  volatile u32  RESERVED2[22];
  volatile u32  _9BITADDR;                         /*!< UART 9-Bit Self Address              */
  volatile u32  _9BITAMASK;                        /*!< UART 9-Bit Self Address Mask         */
  volatile u32  RESERVED3[965];
  volatile u32  PP;                                /*!< UART Peripheral Properties           */
  volatile u32  RESERVED4;
  volatile u32  CC;                                /*!< UART Clock Configuration             */
} UART0_Type;



/* ================================================================================ */

/* 	-----> Macros
			 * Base_Address ------> 	UARTx		*/	
/* ================================================================================ */

#define UART0_BASE                      0x4000C000UL
#define UART1_BASE                      0x4000D000UL
#define UART2_BASE                      0x4000E000UL
#define UART3_BASE                      0x4000F000UL
#define UART4_BASE                      0x40010000UL
#define UART5_BASE                      0x40011000UL
#define UART6_BASE                      0x40012000UL
#define UART7_BASE                      0x40013000UL

/* ================================================================================ */
/* ================       UARTx Peripheral declaration             ================ */
/* ================================================================================ */

#define UART0                           ((UART0_Type              *) UART0_BASE)
#define UART1                           ((UART0_Type              *) UART1_BASE)
#define UART2                           ((UART0_Type              *) UART2_BASE)
#define UART3                           ((UART0_Type              *) UART3_BASE)
#define UART4                           ((UART0_Type              *) UART4_BASE)
#define UART5                           ((UART0_Type              *) UART5_BASE)
#define UART6                           ((UART0_Type              *) UART6_BASE)
#define UART7                           ((UART0_Type              *) UART7_BASE)



#endif //UART_PRIVATE_H
