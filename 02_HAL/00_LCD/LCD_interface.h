/*========================================================================================
===========================   - LCD_interface.h              =============================
===========================   - Created: 9/4/2021	     =============================
===========================   - Author: Abdelrahman_Magdy     =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/ 

/*===========================  Application Public Interface   ===========================
		*  The Archictect Give The API
			- The Name Of Function
			- What is The Input
			- What Is The Output
========================================================================================*/

/*========================================================================================
========================   guard of file will call on time in .c  ========================
========================================================================================*/ 

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
	 
#include "STD_TYPE.h"
/*========================================================================================
 *                      Preprocessor Macros                                    *
========================================================================================*/
#define LCD_PORT GPIOB

/*========================================================================================
 *                      Functions Prototypes                                   *
========================================================================================*/


  /* =============       Function Send Command To LCD       ============= */
void HLCD_vSendCommand(u8 copy_u8Command);

   /* =============      Function To Display Char           ============= */
void HLCD_vDisplayCharacter(u8 data);

  /* =============       Function To Initiate LCD           ============= */


/*
*        Function To Initiate LCD Before Init Function :
*                                               - Clock EN to GPIOx 
*                                               - Set PORTB pins as output      
*                                               - Set PORTB pins as Digital
*/
void HLCD_vInit(void);


  /* =============      Function To Display String          ============= */
void HLCD_vDisplayString(const s8 *Str);


  /* ============= Function Display Char In Spacifice Place  ============= */
void HLCD_vGoToRowColumn(u8 row,u8 col);

  /* ============= Function Display String In Spacifice Place ============= */
void HLCD_vDisplayStringRowColumn(u8 row,u8 col,const s8 *Str);
 
 /* ============= Function To Clear LCD  ============= */
void HLCD_vClear(void);

#endif //LCD_INTERFACE_H

	