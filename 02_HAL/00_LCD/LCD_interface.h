/****************************************************************
 ************  - LCD_interface.h                ******************
 ***********   - Created: 8/26/2021		******************
 ***********   - Author: Abdelrahman_Magdy      ******************
 ***********   - Version : _1_			******************
 ***********   -				******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/ 

/**************  Application Public Interface   **************/
/*****************************************************************
		*  The Archictect Give The API
			- The Name Of Function
			- What is The Input
			- What Is The Output
******************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
	 
#include "STD_TYPE.h"

/*function protoypes */
void LCD_voidInitPins(void);

void LCD_voidSendCommand(unsigned long cmd);

void LCD_voidSendData (char data);

void LCD_voidSendString (char *str);

void LCD_voidClear();

void LCD_voidString_xy (char row, char pos, char *str);

void LCD_voidCustom_Char(unsigned char loc, unsigned char *msg);

void Delay(void) ;

#endif //LCD_INTERFACE_H

	