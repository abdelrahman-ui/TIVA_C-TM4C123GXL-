/*=======================================================================================
===========================  - GPIO_program.c		     ============================
===========================  - Created: 9/3/2021	     ============================
===========================  - Author: Abdelrahman_Magdy     ============================
===========================  - Version : _1_		     ============================
===========================  - Note :
					      *-
					      *-
 =======================================================================================*/


/*======================================================================================
============================   The Foundation Of Function   ============================
========================================================================================*/


/*============= INCLUDE LIB =============*/

	 #include "STD_TYPE.h"
	 #include "BIT_MATH.h"
/*=======================================*/

/*============= INCLUDE MCAL =============*/
	#include "UART_private.h"
	#include "UART_interface.h"
	#include "UART_config.h"
/*=======================================*/

/*============= INCLUDE HAL =============*/


/*=======================================*/

/*=============  INCLUDEAPP =============*/


/*=======================================*/



/*======================================================== Start_FUNCTION  ========================================================*/
/*
*   Function To Select UARTx Base Address
*/

UARTx_t* MUART_SptrSelect(u8 copy_u8UartNum)
{
  UARTx_t* ptr ;
  /*    ptr equal Base Address     */
  switch(copy_u8UartNum)
  {
        case UART_0 : ptr = UARTx0;      break ;
        case UART_1 : ptr = UARTx1;      break ; 
        case UART_2 : ptr = UARTx2;      break ;  
        case UART_3 : ptr = UARTx3;      break ;
        case UART_4 : ptr = UARTx4;      break ;
        case UART_5 : ptr = UARTx5;      break ;
        case UART_6 : ptr = UARTx6;      break ;
        case UART_7 : ptr = UARTx7;      break ;
        default :                            break ;
  }
  return ptr ;
}
/*======================================================== END_ FUNCTION   ========================================================*/



/*======================================================== Start_FUNCTION  ========================================================*/
/*
*   Function To Disable UARTx
*/
void MUART_vDisable(u8 copy_u8UartNum)
{
    UARTx_t* ptr ;
    ptr=MUART_SptrSelect(copy_u8UartNum);
    CLR_BIT(ptr->CTL,0);      

}
/*======================================================== END_ FUNCTION   ========================================================*/

/*======================================================== Start_FUNCTION  ========================================================*/
/*
*   Function To Enable UARTx
*/
void MUART_vEnable(u8 copy_u8UartNum)
{
    UARTx_t* ptr ;
    ptr=MUART_SptrSelect(copy_u8UartNum);
    SET_BIT(ptr->CTL,0);      
}

/*======================================================== END_ FUNCTION   ========================================================*/



/*======================================================== Start_FUNCTION  ========================================================*/
/*
*  Function To Initiate UART ( Baudrate And CPU Frequancy 
* DIV is value of REG ( Mantisa + fraction )
*/
void MUART_vInit(u8 copy_u8UartNum ,u32 copy_u32BR ,u32 copy_u32F_CPU )
{
   UARTx_t* ptr ;
   ptr=MUART_SptrSelect(copy_u8UartNum);
    
   /* local Variable Defination                           */
  double BRD ,temp; 
  u32 L_u32BRDI, L_u32BRDF ;
   /*  Calculate UART Integer Baud-Rate Divisor           */
  BRD = copy_u32F_CPU / (ClkDiv * copy_u32BR );
  L_u32BRDI = (u32)BRD ;
  /*  Calculate UART Fractional Baud-Rate Divisor        */
  temp= BRD - L_u32BRDI;
  L_u32BRDF =(u32)(temp*64+0.5);
  
      /*   UART Clock Configuration            */
  ptr->CC= CLK_Config ;
      /*   Integer Baud-Rate Divisor          */
  ptr->IBRD=L_u32BRDI ;
      /*   Fractional Baud-Rate Divisor       */
   ptr->FBRD =L_u32BRDF  ;
 
  
}

/*======================================================== END_ FUNCTION   ========================================================*/


/*======================================================== Start_FUNCTION  ========================================================*/
/*
*  Function To Config UARTx {	                - DATA_SIZE_{5..8}   .
						- Parity_ON     , Parity_OFF   .
						- ONE_Stop_Bit  , TWO_Stop_Bit .
						- FIFO_EN       , FIFI_DIS     . 
					  }
*/
void MUART_vConfig(u8 copy_u8UartNum , DATA_SIZE_t DATA_SIZE , PARITY_t PARITY , STOP_BIT_t STOP_BIT_NUM ,FIFO_STATE_t FIFO_STATE  )
{
     
    UARTx_t* ptr ;
    ptr=MUART_SptrSelect(copy_u8UartNum);
    ptr->LCRH|=(DATA_SIZE<<5U);
    ptr->LCRH|=(PARITY<<1U);
    ptr->LCRH|=(STOP_BIT_NUM<<3U);
    ptr->LCRH|=(FIFO_STATE<<4U);
 
}

/*======================================================== END_ FUNCTION   ========================================================*/


/*======================================================== Start_FUNCTION  ========================================================*/
/*
*  Function To Config Parity :
*                               - PARITY_ODD
*                               - PARITY_EVEN
*/
void MUART_vParityConfig(u8 copy_u8UartNum  ,PARITY_CONFIG_t PARITY_CONFIG)
{
  UARTx_t* ptr ;
  ptr=MUART_SptrSelect(copy_u8UartNum);
  ptr->LCRH|=(PARITY_CONFIG<<2U);
  
}
                               
                               
/*======================================================== END_ FUNCTION   ========================================================*/
                                                          

/*======================================================== Start_FUNCTION  ========================================================*/
/*

*/
void UART_voidWriteChar(u8 copy_u8UartNum  , u8 copy_u8Char)
{
  UARTx_t* ptr ;
  ptr=MUART_SptrSelect(copy_u8UartNum);
  /* Wait for transmitter buffer to be free  */
  while((ptr->FR & (1U<<7))==0);
  /* Write Data  */
  ptr->DR =copy_u8Char;
  
}

/*======================================================== END_ FUNCTION   ========================================================*/

/*======================================================== Start_FUNCTION  ========================================================*/
/*

*/
void UART_voidWriteString(u8 copy_u8UartNum , u8 const * string)
{
  while(*string != '\0')
  {
    UART_voidWriteChar(copy_u8UartNum,*string);
    string++;
  }
  
}

/*======================================================== END_ FUNCTION   ========================================================*/

/*======================================================== Start_FUNCTION  ========================================================*/
/*

*/
u8 UART_u8Read(u8 copy_u8UartNum)
{
   UARTx_t* ptr ;
   ptr=MUART_SptrSelect(copy_u8UartNum);
   
   u8 data;
   /* Wait for reciever buffer to have data */
  while((ptr->FR & (1U<<6))==0);  
  /*  Read Data                             */
  data = ptr->DR;
  /*  Return Data                            */
  return data;
  
}


/*======================================================== END_ FUNCTION   ========================================================*/







