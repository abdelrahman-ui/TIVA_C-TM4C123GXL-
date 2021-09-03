/*========================================================================================
===========================   - GPIO_interface.h	     ============================
===========================   - Created: 9/2/2021	     ============================
===========================   - Author: Abdelrahman_Magdy    ============================
===========================   - Version : _1_		     ============================
===========================   - Note :
					  *-
					  *-
========================================================================================*/ 



/*========================================================================================
		
               * What i sell To Customer
               *  The Archictect Give The API :
						 - The Name Of Function 
						 - What is The Input 
						 - What Is The Output
						 - Macro 
						 
========================================================================================*/ 

/*======================================================================================
=======================  guard of file will call on time in .c	========================
========================================================================================*/


#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "STD_TYPE.h"


/*=============================  Function Prototypes  =============================  */

	/* ============= Function Set The Dir Of Pin ============= */
void MGOIP_voidSetPinDir(u8 copy_u8Port ,u8 copy_u8Pin,u8 copy_Direction); 

	/* ============= Function Enable The Alternate Function ============= */
void MGOIP_voidSetPinALFun(u8 copy_u8Port ,u8 copy_u8Pin); 

	/*============= Function Set  OpenDrain = 0 	 ============= */
void MGPIO_voidSetPinOpenDrain(u8 copy_u8PORT ,u8 copy_u8Pin ); 

	/* ============= Function Set Pin Be Digital ============= */
void MGOIP_voidSetPinDigital(u8 copy_u8PORT ,u8 copy_u8PIN); 

	/* ============= Function To Read Data From Data ============= */
u8 MGPIO_u8ReadData(u8 copy_u8PORT ,u8 copy_u8PIN);

	/* ============= Function To Write Data At DATA	Value = High , LOW ============= */
void MGPIO_voidWriteData(u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8Value )  ;

	/* ============= Function Set Pin As Analog Pin ============= */
void MGPIO_voidSetPinAnalog(u8 copy_u8PORT ,u8 copy_u8Pin); 

	/* ============= Function Set The PULL  UP  ============= */
void MGPIO_voidSetPullUp(u8 copy_u8PORT ,u8 copy_u8Pin);

        /* ============= Function Set The PULL  Down  ============= */
void MGPIO_voidSetPullDown(u8 copy_u8PORT ,u8 copy_u8Pin);

	/* ============= Function Set The AltFn	 ============= */
void MGOIP_voidPinSetAltFn(u8 copy_u8Port ,u8 copy_u8Pin,u8 copy_u8AlT)  ;

			/* Macros Of Port */
			
#define  GPIOA_PORT			0U       
#define  GPIOB_PORT			1U
#define  GPIOC_PORT			2U
#define  GPIOD_PORT			3U
#define  GPIOE_PORT			4U
#define  GPIOF_PORT			5U


			/* Macros Of Pins */

#define  PIN0				0U
#define  PIN1				1U
#define  PIN2				2U
#define  PIN3				3U
#define  PIN4				4U
#define  PIN5				5U
#define  PIN6				6U
#define  PIN7				7U

#define  DIR_OUT                        1U
#define  DIR_IN                         0U


#endif /* GPIO_INTERFACE_H*/