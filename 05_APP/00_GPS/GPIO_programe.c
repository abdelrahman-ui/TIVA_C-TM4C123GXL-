/*========================================================================================
===========================   - GPIO_program.c		     =============================
===========================   - Created: 9/2/2021	     =============================
===========================   - Author: Abdelrahman_Magdy    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
					*-
					*-
========================================================================================*/ 


/*=======================================================================================
=============================   The Foundation Of Function   ============================ 
=========================================================================================*/


/*============= INCLUDE LIB ==============*/
	 #include "STD_TYPE.h"
	 #include "BIT_MATH.h"
/*========================================*/	 

/*============= INCLUDE MCAL ==============*/
	#include "GPIO_private.h"
	#include "GPIO_interface.h"
	#include "GPIO_config.h"
/*========================================*/	

/*============= INCLUDE HAL ==============*/ 
			

/*========================================*/





/*======================================================== Start_FUNCTION  ========================================================*/
/*	 Function Set The Dir Of Pin 	:
*							- DIR_INPUT
*							- DIR_OUT
*/
void MGOIP_voidSetPinDir(u8 copy_u8Port ,u8 copy_u8Pin,u8 copy_Direction)
{
   if(copy_Direction == DIR_OUT )
  { 
    switch(copy_u8Port)
    {
    case GPIOA_PORT :  SET_BIT((GPIOA->DIR),(copy_u8Pin));               break ;
    case GPIOB_PORT :  SET_BIT((GPIOB->DIR),(copy_u8Pin));               break ;
    case GPIOC_PORT :  SET_BIT((GPIOC->DIR),(copy_u8Pin));               break ;
    case GPIOD_PORT :  SET_BIT((GPIOD->DIR),(copy_u8Pin));               break ;
    case GPIOE_PORT :  SET_BIT((GPIOE->DIR),(copy_u8Pin));               break ;
    case GPIOF_PORT :  SET_BIT((GPIOF->DIR),(copy_u8Pin));               break ;
    default :                                                            break ;
    }                   
  }                     
  else                  
  {                     
    switch(copy_u8Port)                 
    {                   
    case GPIOA_PORT :  CLR_BIT((GPIOA->DIR),(copy_u8Pin));               break ;
    case GPIOB_PORT :  CLR_BIT((GPIOB->DIR),(copy_u8Pin));               break ;
    case GPIOC_PORT :  CLR_BIT((GPIOC->DIR),(copy_u8Pin));               break ;
    case GPIOD_PORT :  CLR_BIT((GPIOD->DIR),(copy_u8Pin));               break ;
    case GPIOE_PORT :  CLR_BIT((GPIOE->DIR),(copy_u8Pin));               break ;
    case GPIOF_PORT :  CLR_BIT((GPIOF->DIR),(copy_u8Pin));               break ;
    default :                                                            break ;
    }
  }
  
  
}

/*======================================================== END_ FUNCTION   ========================================================*/

/*======================================================== Start_FUNCTION  ========================================================*/
/*
*               Function Set The corresponding pin's weak pull-up resistor is enabled.	
*/
void MGPIO_voidSetPullUp(u8 copy_u8PORT ,u8 copy_u8Pin)  
{
   switch(copy_u8PORT)
    {
          case GPIOA_PORT :  SET_BIT((GPIOA->PUR),(copy_u8Pin));         break ;
          case GPIOB_PORT :  SET_BIT((GPIOB->PUR),(copy_u8Pin));         break ;
          case GPIOC_PORT :  SET_BIT((GPIOC->PUR),(copy_u8Pin));         break ;
          case GPIOD_PORT :  SET_BIT((GPIOD->PUR),(copy_u8Pin));         break ;
          case GPIOE_PORT :  SET_BIT((GPIOE->PUR),(copy_u8Pin));         break ;
          case GPIOF_PORT :  SET_BIT((GPIOF->PUR),(copy_u8Pin));         break ;
          default :                                                      break ;
    }
  
}

/*======================================================== END_ FUNCTION   ========================================================*/

/*======================================================== Start_FUNCTION  ========================================================*/
/*
*               Function Set The corresponding pin's weak pull-Down resistor is enabled.	
*/
void MGPIO_voidSetPullDown(u8 copy_u8PORT ,u8 copy_u8Pin)
{
     switch(copy_u8PORT)
    {
          case GPIOA_PORT :  SET_BIT((GPIOA->PDR),(copy_u8Pin));         break ;
          case GPIOB_PORT :  SET_BIT((GPIOB->PDR),(copy_u8Pin));         break ;
          case GPIOC_PORT :  SET_BIT((GPIOC->PDR),(copy_u8Pin));         break ;
          case GPIOD_PORT :  SET_BIT((GPIOD->PDR),(copy_u8Pin));         break ;
          case GPIOE_PORT :  SET_BIT((GPIOE->PDR),(copy_u8Pin));         break ;
          case GPIOF_PORT :  SET_BIT((GPIOF->PDR),(copy_u8Pin));         break ;
          default :                                                      break ;
    }
  
  
}
/*======================================================== END_ FUNCTION   ========================================================*/


/*======================================================== Start_FUNCTION  ========================================================*/
/*		Function Set ANALOG :			
*					- The analog function of the pin is enabled, the isolation is
*                                           disabled, and the pin is capable of analog functions.
*		
*/
void MGPIO_voidSetPinAnalog(u8 copy_u8PORT ,u8 copy_u8Pin)  
{
  switch(copy_u8PORT)
    {
          case GPIOA_PORT :  SET_BIT((GPIOA->AMSEL),(copy_u8Pin));       break ;
          case GPIOB_PORT :  SET_BIT((GPIOB->AMSEL),(copy_u8Pin));       break ;
          case GPIOC_PORT :  SET_BIT((GPIOC->AMSEL),(copy_u8Pin));       break ;
          case GPIOD_PORT :  SET_BIT((GPIOD->AMSEL),(copy_u8Pin));       break ;
          case GPIOE_PORT :  SET_BIT((GPIOE->AMSEL),(copy_u8Pin));       break ;
          case GPIOF_PORT :  SET_BIT((GPIOF->AMSEL),(copy_u8Pin));       break ;
          default :                                                      break ;
    }
  
}


/*======================================================== END_ FUNCTION   ========================================================*/

/*======================================================== Start_FUNCTION  ========================================================*/
/*		
*               Function To Write Data At ODR Value :
*                                                       The corresponding pin is configured as open drain.
*/
void MGPIO_voidSetPinOpenDrain(u8 copy_u8PORT ,u8 copy_u8Pin )
{
  switch(copy_u8PORT)
    {
          case GPIOA_PORT :  SET_BIT((GPIOA->ODR),(copy_u8Pin));         break ;
          case GPIOB_PORT :  SET_BIT((GPIOB->ODR),(copy_u8Pin));         break ;
          case GPIOC_PORT :  SET_BIT((GPIOC->ODR),(copy_u8Pin));         break ;
          case GPIOD_PORT :  SET_BIT((GPIOD->ODR),(copy_u8Pin));         break ;
          case GPIOE_PORT :  SET_BIT((GPIOE->ODR),(copy_u8Pin));         break ;
          case GPIOF_PORT :  SET_BIT((GPIOF->ODR),(copy_u8Pin));         break ;
          default :                                                      break ;
    }
  
}
/*======================================================== END_ FUNCTION   ========================================================*/

/*======================================================== Start_FUNCTION  ========================================================*/
/*		
*               Function To : The associated pin functions as a peripheral signal and is
*                              controlled by the alternate hardware function.
*                              The reset value for this register is 0x0000.0000 for GPIO ports
*                              that are not listed in Table 10-1 on page 650.
*/
void MGOIP_voidSetPinALFun(u8 copy_u8Port ,u8 copy_u8Pin)
{
  switch(copy_u8Port)
    {
          case GPIOA_PORT :  SET_BIT((GPIOA->AFSEL),(copy_u8Pin));       break ;
          case GPIOB_PORT :  SET_BIT((GPIOB->AFSEL),(copy_u8Pin));       break ;
          case GPIOC_PORT :  SET_BIT((GPIOC->AFSEL),(copy_u8Pin));       break ;
          case GPIOD_PORT :  SET_BIT((GPIOD->AFSEL),(copy_u8Pin));       break ;
          case GPIOE_PORT :  SET_BIT((GPIOE->AFSEL),(copy_u8Pin));       break ;
          case GPIOF_PORT :  SET_BIT((GPIOF->AFSEL),(copy_u8Pin));       break ;
          default :                                                      break ;
    }
  
  
}

/*======================================================== END_ FUNCTION   ========================================================*/

                         
/*======================================================== Start_FUNCTION  ========================================================*/
/*		
*              Function Set Pin Be Digital :    
*                                               The digital functions for the corresponding pin are enabled.
*                                               The reset value for this register is 0x0000.0000 for GPIO ports
*                                               that are not listed in Table 10-1 on page 650.
*/
void MGOIP_voidSetPinDigital(u8 copy_u8PORT ,u8 copy_u8Pin) 
{
  
   switch(copy_u8PORT)
    {
          case GPIOA_PORT :  SET_BIT((GPIOA->DEN),(copy_u8Pin));         break ;
          case GPIOB_PORT :  SET_BIT((GPIOB->DEN),(copy_u8Pin));         break ;
          case GPIOC_PORT :  SET_BIT((GPIOC->DEN),(copy_u8Pin));         break ;
          case GPIOD_PORT :  SET_BIT((GPIOD->DEN),(copy_u8Pin));         break ;
          case GPIOE_PORT :  SET_BIT((GPIOE->DEN),(copy_u8Pin));         break ;
          case GPIOF_PORT :  SET_BIT((GPIOF->DEN),(copy_u8Pin));         break ;
          default :                                                      break ;
    }

}

/*======================================================== END_ FUNCTION   ========================================================*/


/*======================================================== Start_FUNCTION  ========================================================*/
/*		
*                 Function To Write Data At DATA  = High |  LOW
*/
void MGPIO_voidWriteData(u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8Value )
{
  if(copy_u8Value == HIGH )
  {
     switch (copy_u8PORT)
    {
          case GPIOA_PORT :  SET_BIT((GPIOA ->DATA),(copy_u8PIN));       break ;
          case GPIOB_PORT :  SET_BIT((GPIOB ->DATA),(copy_u8PIN));       break ;
          case GPIOC_PORT :  SET_BIT((GPIOC ->DATA),(copy_u8PIN));       break ;
          case GPIOD_PORT :  SET_BIT((GPIOD ->DATA),(copy_u8PIN));       break ;
          case GPIOE_PORT :  SET_BIT((GPIOE ->DATA),(copy_u8PIN));       break ;
          case GPIOF_PORT :  SET_BIT((GPIOF ->DATA),(copy_u8PIN));       break ;
          default :                                                      break ;
    }           
  }             
  else          
  {             
       switch (copy_u8PORT)             
    {           
          case GPIOA_PORT :  CLR_BIT((GPIOA ->DATA),(copy_u8PIN));       break ;
          case GPIOB_PORT :  CLR_BIT((GPIOB ->DATA),(copy_u8PIN));       break ;
          case GPIOC_PORT :  CLR_BIT((GPIOC ->DATA),(copy_u8PIN));       break ;
          case GPIOD_PORT :  CLR_BIT((GPIOD ->DATA),(copy_u8PIN));       break ;
          case GPIOE_PORT :  CLR_BIT((GPIOE ->DATA),(copy_u8PIN));       break ;
          case GPIOF_PORT :  CLR_BIT((GPIOF ->DATA),(copy_u8PIN));       break ;
          default :                                                      break ;
    }
    
  }
}
/*======================================================== END_ FUNCTION   ========================================================*/


/*======================================================== Start_FUNCTION  ========================================================*/

/*		
*                Function To Read Data From Data REG	
*/
u8 MGPIO_u8ReadData(u8 copy_u8PORT ,u8 copy_u8PIN)
{
  u8 u8Local_Data = 0 ;
  switch (copy_u8PORT)
  {
        case GPIOA_PORT : u8Local_Data = GET_BIT((GPIOA ->DATA),(copy_u8PIN));  break ;
        case GPIOB_PORT : u8Local_Data = GET_BIT((GPIOB ->DATA),(copy_u8PIN));  break ;
        case GPIOC_PORT : u8Local_Data = GET_BIT((GPIOC ->DATA),(copy_u8PIN));  break ;
        case GPIOD_PORT : u8Local_Data = GET_BIT((GPIOD ->DATA),(copy_u8PIN));  break ;
        case GPIOE_PORT : u8Local_Data = GET_BIT((GPIOE ->DATA),(copy_u8PIN));  break ;
        case GPIOF_PORT : u8Local_Data = GET_BIT((GPIOF ->DATA),(copy_u8PIN));  break ;
        default :                                                               break ;
  }
  return u8Local_Data ;
}
     
     
/*======================================================== END_ FUNCTION   ========================================================*/


/*======================================================== Start_FUNCTION  ========================================================*/
/*
*              	
*/
void MGOIP_voidPinSetAltFn(u8 copy_u8Port ,u8 copy_u8Pin,u8 copy_u8AlT)
{
  switch (copy_u8Port)
  {
     case GPIOA_PORT :GPIOA ->PCTL |= ((copy_u8AlT) << (4U*copy_u8Pin)); break ; 
     case GPIOB_PORT :GPIOB ->PCTL |= ((copy_u8AlT) << (4U*copy_u8Pin)); break ;  
     case GPIOC_PORT :GPIOC ->PCTL |= ((copy_u8AlT) << (4U*copy_u8Pin)); break ;  
     case GPIOD_PORT :GPIOD ->PCTL |= ((copy_u8AlT) << (4U*copy_u8Pin)); break ;  
     case GPIOE_PORT :GPIOE ->PCTL |= ((copy_u8AlT) << (4U*copy_u8Pin)); break ;  
     case GPIOF_PORT :GPIOF ->PCTL |= ((copy_u8AlT) << (4U*copy_u8Pin)); break ;  
     default :                                                           break ;
  }
  
}
/*======================================================== END_ FUNCTION   ========================================================*/





