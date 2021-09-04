/*========================================================================================
===========================   - LCD_program.c		     =============================
===========================   - Created: 9/4/2021	     =============================
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
         #include "TM4C123GH6PM.h"
/*========================================*/	 

/*============= INCLUDE MCAL ==============*/
	#include "LCD_private.h"
	#include "LCD_interface.h"
	#include "LCD_config.h"
        #include "Delay_interface.h"

/*========================================*/	

/*============= INCLUDE HAL ==============*/ 
			

/*========================================*/





/*======================================================== Start_FUNCTION  ========================================================*/
/*
*                        Function Send Command To LCD  
*/
void HLCD_vSendCommand(u8 copy_u8Command)
{
      /*===  Rs and RW  ===*/
 LCD_PORT->DATA &=~((1U<<RS)|(1U<<RW)); 
      /*===  Enable pulse  ===*/
 LCD_PORT->DATA |= (1U<<EN); 
 Delay_vUsIn16MHz(0);
        /*===  Sending upper nibble  ===*/
  LCD_PORT->DATA = (LCD_PORT->DATA & 0x0F) | (copy_u8Command & 0xF0);
  LCD_PORT->DATA = 0;
      /*===  Enable pulse  ===*/
  LCD_PORT->DATA |= (1U<<EN);
  Delay_vUsIn16MHz(0);
  /*===  Sending lower nibble  ===*/
  LCD_PORT->DATA = (LCD_PORT->DATA & 0x0F) | ((copy_u8Command & 0x0F) << 4);
  LCD_PORT->DATA = 0;
  if (copy_u8Command < 4)
    Delay_vMsIn16MHz(2); 
  else
  Delay_vUsIn16MHz(40);
  
}

/*======================================================== END_ FUNCTION   ========================================================*/


/*======================================================== Start_FUNCTION  ========================================================*/
/*
*       Function To Display Char 
*/
void HLCD_vDisplayCharacter(u8 data)
{
    /*===  RS  ===*/
  LCD_PORT->DATA |= (1U<<RS); 
    /*===  RW  ===*/
  LCD_PORT->DATA &=~ (1U<<RW);
   Delay_vMsIn16MHz(1);
    /*===  Enable pulse  ===*/
  LCD_PORT->DATA |= (1U<<EN); 
  Delay_vMsIn16MHz(1);
  /*===  Sending upper nibble  ===*/
  LCD_PORT->DATA = (LCD_PORT->DATA & 0x0F) | (data & 0xF0);	
 Delay_vMsIn16MHz(1);
    /*===  Enable pulse  ===*/
  LCD_PORT->DATA &=~ (1U<<EN);
  Delay_vMsIn16MHz(1);
    /*===  Enable pulse  ===*/
  LCD_PORT->DATA |= (1U<<EN);
  Delay_vMsIn16MHz(1);	
    /*=== Sending lower nibble  ===*/
  LCD_PORT->DATA = (LCD_PORT->DATA & 0x0F) | ((data & 0x0F) << 4);
  Delay_vMsIn16MHz(1);
    /*===  Enable pulse  ===*/
  LCD_PORT->DATA &=~ (1U<<EN);
  Delay_vMsIn16MHz(1);	
  
}

/*======================================================== END_ FUNCTION   ========================================================*/


/*======================================================== Start_FUNCTION  ========================================================*/
/*
*        Function To Initiate LCD Before Init Function :
*                                               - Clock EN to GPIOx 
*                                               - Set PORTB pins as output      
*                                               - Set PORTB pins as Digital
*/
void HLCD_vInit(void)
{
  /*===  Clock EN to GPIOB  ===*/
  SYSCTL->RCGCGPIO |= 0x02; 

  /*===  Set PORTB pins as output  ===*/
  LCD_PORT->DIR = 0xFF; 
  
 /*===  Set PORTB pins as Digital  ===*/
  LCD_PORT->DEN = 0xFF; 

 /*============================================================================
   *                     Initialization Sequence                            *
 ============================================================================*/
  
  /*=== Step 1.   Power on, then delay > 100 ms ===*/
  Delay_vMsIn16MHz(120); 
  /*===  Step 2.   Instruction 0011b (3h), then delay > 4.1 ms ===*/
  HLCD_vSendCommand(0x30);
  Delay_vMsIn16MHz(5);
  /*===  Step 3.   Instruction 0011b (3h), then delay > 100 us ===*/
  HLCD_vSendCommand(0x30);
  Delay_vUsIn16MHz(105);
  /*===  Step 4.   Instruction 0011b (3h), then delay > 100 us ===*/
 HLCD_vSendCommand(0x30);
 Delay_vUsIn16MHz(105);
  /*=== Step 5.   Instruction 0010b (2h), then delay > 100 us ===*/
  HLCD_vSendCommand(0x20);
  Delay_vUsIn16MHz(105); 
  /*===  Step 6.   Instruction 0010b (2h), then 1000b (8h), then delay > 53 us or check BF (4-bit data, 2-line) ===*/
  HLCD_vSendCommand(0x28); 
  /*===  Step 7.   Instruction 0000b (0h), then 1000b (8h) then delay > 53 us or check BF ===*/
  /*===  Step 8.   Instruction 0000b (0h), then 0001b (1h) then delay > 3 ms or check BF ===*/
  /*===  Step 9.   Instruction 0000b (0h), then 0110b (6h), then delay > 53 us or check BF ===*/
  HLCD_vSendCommand(0x06); 
  /*===  Clear screen  ===*/
  HLCD_vSendCommand(0x01);
  /*===  Turn on display and Blink cursor ===*/
  HLCD_vSendCommand(0x0F);
}

/*======================================================== END_ FUNCTION   ========================================================*/


/*======================================================== Start_FUNCTION  ========================================================*/
/*
*  Function To Display String 
*/
void HLCD_vDisplayString(const s8 *Str)
{
  volatile u8 u8Local_Count1 = 0 ; 
	while(Str[u8Local_Count1] != '\0')
	{
		HLCD_vDisplayCharacter(Str[u8Local_Count1]);
		u8Local_Count1++;
	}
  
}

/*======================================================== END_ FUNCTION   ========================================================*/



/*======================================================== Start_FUNCTION  ========================================================*/
/*
*       Function Display Char In Spacifice Place
*/
void HLCD_vGoToRowColumn(u8 row,u8 col)
{
  unsigned char Address;
	
	/*===  first of all calculate the required address ===*/
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
	}					
	/*===  to write to a specific address in the LCD ===*/ 
	/*===  we need to apply the corresponding command 0b10000000|Address  ===*/
	HLCD_vSendCommand(Address | SET_CURSOR_LOCATION); 
}

/*======================================================== END_ FUNCTION   ========================================================*/


/*======================================================== Start_FUNCTION  ========================================================*/
/*
*        Function Display String In Spacifice Place
*/
void HLCD_vDisplayStringRowColumn(u8 row,u8 col,const s8 *Str)
{
        /*===  Go to to the required LCD position ===*/
	HLCD_vGoToRowColumn(row,col); 
         /*===  Display the string ===*/
	HLCD_vDisplayString(Str);
  
}

/*======================================================== END_ FUNCTION   ========================================================*/

/*======================================================== Start_FUNCTION  ========================================================*/
/*
*               Function To Clear LCD
*/
void HLCD_vClear(void)
{     
       /*===  Clear display ===*/
	HLCD_vSendCommand(0x01);		
	 Delay_vMsIn16MHz(2);
       /*===  Cursor at home position ===*/
	HLCD_vSendCommand(SET_CURSOR_LOCATION);		
}
/*======================================================== END_ FUNCTION   ========================================================*/