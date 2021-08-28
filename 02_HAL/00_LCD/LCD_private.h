/****************************************************************
 ************  -LCD_private.h                  ******************
 ***********				       ******************
 ***********   -Created: 8/28/2021	       ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_		       ******************
 ***********				       ******************
 ****************************************************************/

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/



#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H




#include "STD_TYPE.h"
#define LCD_RS (*((volatile unsigned long *)0x40004200))    //PA.7 for register select pin
#define LCD_EN  (*((volatile unsigned long *)0x40004100))   //PA.6 for enable  pin
#define LCD_RW  (*((volatile unsigned long *)0x40004080))   //PA.5 for rw pin









#endif //LCD_PRIVATE.H

