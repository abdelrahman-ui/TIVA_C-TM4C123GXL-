/****************************************************************
 ************   -LCD_program.c                ******************
 ***********   -Created: 2/9/2021	      ******************
 ***********   -Author: Abdelrahman_Magdy     ******************
 ***********   -Version : _1_		      ******************
 ***********  -				      ******************
 ****************************************************************/ 
#include "STD_TYPE.h"
#include "BIT_MATH.h"


#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#include "TM4C123GH6PM.h"

 
 /*********************************************************** Start_FUNCTION  ***********************************************************/


//short delay function
void Delay(void) {
 volatile u32 Local_u32Count=0;
 for( Local_u32Count; Local_u32Count<12000U ; Local_u32Count++);
                
}
/*********************************************************** END_ FUNCTION   ***********************************************************/

/*********************************************************** Start_FUNCTION  ***********************************************************/
/*
this function will initate the LCD it initializes 
the portA5-6-7 as the control pins  for the LCD and portB0-7 
as the data pins
*/
void LCD_voidInitPins(void)
{
  /*for the LCD and portB0-7 as the data pins*/
  
  /*Enable and provide a clock to GPIO Port B in Run mode.*/
  SYSCTL ->RCGCGPIO |=(1U<<2) ;
  /* Delay*/
   Delay() ;
  /*disable alternative functions for portB*/
  GPIOB->AFSEL &=~ 0XFF ;
  /*disable analogue function*/
   GPIOB->AMSEL &=~ 0XFF ;
  /* regular digital pins */  
   GPIOB->PCTL &=~ 0XFF ;
  /*Set the direction of PB0-7 as ---> output*/
   GPIOB ->DIR |=0XFF ;
   /*Enable digital portB*/
   GPIOB ->DEN |=0XFF ;

   /*LCD it initializes the portA5-6-7 as the control pins*/
   
   /* Allow the clock for PA5,6,7*/
    SYSCTL ->RCGCGPIO |=(1U<<1) ;
    /* Delay*/
    Delay();
    /*disable alternative functions for PA5,6,7*/
    GPIOA->AFSEL &=~0XE0 ;
    /*disable analogue function for PA5,6,7*/
    GPIOA->AMSEL &=~0XE0 ;
    /* regular digital pins */  
    GPIOA->PCTL &=~ 0XE0 ;
    /*set the direction of PA5,6,7 as output*/
     GPIOA->DIR |=0XE0;
     /*enable digital PA5,6,7*/
     GPIOA->DEN |=0XE0;
    
}

/*********************************************************** END_ FUNCTION   ***********************************************************/


/*********************************************************** Start_FUNCTION  ***********************************************************/
/*
  this function passes the command to the LCD
*/
void LCD_voidSendCommand(unsigned long cmd)
{
  /* set PB7-0 as the passed command to the function */
  GPIOB->DATA |= cmd ;
  /* set PA7 register select pin to low*/
  LCD_RS = 0x00; 
  /* set PA5 r/w pin to low*/
    LCD_RW = 0x00;
  /*set enable pin to high*/
  LCD_EN = 0x40 ;
  /* short delay */
   Delay();
  /* set enable pin to low  */
  LCD_EN = 0x00;
  
}


/*********************************************************** END_ FUNCTION   ***********************************************************/


/*********************************************************** Start_FUNCTION  ***********************************************************/

void LCD_voidSendData(char data)
{
  /* write the data to PB7-0 */
   GPIOB->DATA |= data ;
  /* set PA7 to high*/
   LCD_RS = 0x00; 
  /* set pA5 to low*/
    LCD_RW = 0x00;
  /*set the enable pin high*/
    LCD_EN = 0x40 ;
  /* short delay */
   Delay();
  /* set enable pin to low  */
   LCD_EN = 0x00;
 
}


/*********************************************************** END_ FUNCTION   ***********************************************************/

/*********************************************************** Start_FUNCTION  ***********************************************************/


void LCD_String(char *str)
{
  
  int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_voidSendData (str[i]);
	}
}

/*********************************************************** END_ FUNCTION   ***********************************************************/





void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_voidSendCommand((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_voidSendCommand((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_String(str);		/* Call LCD string function */
}




void LCD_Clear()
{
	LCD_voidSendCommand(0x01);		/* Clear display */
	/* short delay */
        Delay();
	LCD_voidSendCommand(0x80);		/* Cursor at home position */
}



void LCD_Custom_Char(unsigned char loc, unsigned char *msg)
{
	unsigned char i;
	if(loc<8)
	{
		LCD_voidSendCommand(0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		LCD_voidSendData(msg[i]);
	}
}









