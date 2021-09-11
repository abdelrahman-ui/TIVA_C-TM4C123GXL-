/*======================================================================================
===========================  - UART_private.h		        ============================
===========================  - Created: 9/3/2021	         ============================
===========================  - Author: Abdelrahman_Magdy     ============================
===========================  - Version : _1_		     ============================
===========================  - Note :
					      *-
					      *-
 ======================================================================================*/ 


/*======================================================================================

          *        Developer can't Edit in it    
          *        Register _ Defination		
          *        Design : 
				- #define	:	NO
				- Union		:	NO
				- Struct	:	YES

======================================================================================*/

/*======================================================================================
=======================  guard of file will call on time in .c	========================
========================================================================================*/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "STD_TYPE.h"
/* ================================================================================ */
/* ================                      UART0                     ================ */
/* ================================================================================ */


/**
  *  Register map for UART0 peripheral (UART0)
  */

typedef struct {                                        /*!< UART0 Structure                                                       */        
   volatile u32  DR;                                    /*!< UART Data                                                             */
                                                        
  union {                                               
    volatile u32  ECR_UART_ALT;                         /*!< UART Receive Status/Error Clear                                       */
    volatile u32  RSR;                                  /*!< UART Receive Status/Error Clear                                       */
  };                                                    
  volatile u32  RESERVED0[4];                           
  volatile u32  FR;                                     /*!< UART Flag                                                             */
  volatile u32  RESERVED1;                              
  volatile u32  ILPR;                                   /*!< UART IrDA Low-Power Register                                          */
  volatile u32  IBRD;                                   /*!< UART Integer Baud-Rate Divisor                                        */
  volatile u32  FBRD;                                   /*!< UART Fractional Baud-Rate Divisor                                     */
  volatile u32  LCRH;                                   /*!< UART Line Control                                                     */
  volatile u32  CTL;                                    /*!< UART Control                                                          */
  volatile u32  IFLS;                                   /*!< UART Interrupt FIFO Level Select                                      */
  volatile u32  IM;                                     /*!< UART Interrupt Mask                                                   */
  volatile u32  RIS;                                    /*!< UART Raw Interrupt Status                                             */
  volatile u32  MIS;                                    /*!< UART Masked Interrupt Status                                          */
  volatile u32  ICR;                                    /*!< UART Interrupt Clear                                                  */
  volatile u32  DMACTL;                                 /*!< UART DMA Control                                                      */
  volatile u32  RESERVED2[22];                          
  volatile u32  _9BITADDR;                              /*!< UART 9-Bit Self Address                                               */
  volatile u32  _9BITAMASK;                             /*!< UART 9-Bit Self Address Mask                                          */
  volatile u32  RESERVED3[965];                         
  volatile u32  PP;                                     /*!< UART Peripheral Properties                                            */
  volatile u32  RESERVED4;                              
  volatile u32  CC;                                     /*!< UART Clock Configuration                                              */
}UARTx_t;




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

#define UARTx0                           ((UARTx_t              *) UART0_BASE)
#define UARTx1                           ((UARTx_t              *) UART1_BASE)
#define UARTx2                           ((UARTx_t              *) UART2_BASE)
#define UARTx3                           ((UARTx_t              *) UART3_BASE)
#define UARTx4                           ((UARTx_t              *) UART4_BASE)
#define UARTx5                           ((UARTx_t              *) UART5_BASE)
#define UARTx6                           ((UARTx_t              *) UART6_BASE)
#define UARTx7                           ((UARTx_t              *) UART7_BASE)
                           
                           
/* ================================================================================ */
/* ================       UARTx CLK Configration                   ================ */
/* ================================================================================ */
 
#define   CLK_Source           0x0                                                 
#define   PIOSC                 0x5                                    
                           
/* ================================================================================ */
/* ================       UARTx Select From 0 To 7                 ================ */
/* ================================================================================ */

typedef enum{
	UART_0=0,
	UART_1,
	UART_2,
	UART_3,
	UART_4,
	UART_5,
	UART_6,
	UART_7
}UART_SEL_t;

/* ================================================================================ */
/* ================       UARTx Select DATA SIZE                   ================ */
/* ================================================================================ */

typedef enum{
  
  DATA_SIZE_5 =0x0 ,
  DATA_SIZE_6 =0x1 ,
  DATA_SIZE_7 =0x2 ,
  DATA_SIZE_8 =0x3 
    
}DATA_SIZE_t;

/* ================================================================================ */
/* ================       UARTx Select PARITY STATUES              ================ */
/* ================================================================================ */

typedef enum{
  
Parity_OFF=0, 
Parity_ON

}PARITY_t;

/* ================================================================================ */
/* ================       UARTx Select STOP BIT  NUM               ================ */
/* ================================================================================ */

typedef enum{
ONE_Stop_Bit =0 ,
TWO_Stop_Bit 
}STOP_BIT_t ;

/* ================================================================================ */
/* ================       UARTx Select FIFO STATUES                ================ */
/* ================================================================================ */

typedef enum{
  
FIFO_DIS=0,
FIFO_EN 

}FIFO_STATE_t ;

/* ================================================================================ */
/* ================       UARTx Select PARITY CONFIGRATION         ================ */
/* ================================================================================ */
typedef enum{
  
PARITY_ODD=0,
PARITY_EVEN

}PARITY_CONFIG_t;

#endif //UART_PRIVATE_H
