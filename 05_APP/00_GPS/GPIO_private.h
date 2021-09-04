/*======================================================================================
===========================   - GPIO_private.h		     ============================
===========================   - Created: 9/2/2021	     ============================
===========================   - Author: Abdelrahman_Magdy    ============================
===========================   - Version : _1_		     ============================
===========================   - Note :
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

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/* ================================================================================ */
/* ================                      GPIOA                     ================ */
/* ================================================================================ */


/**
  * Register map for GPIOA peripheral (GPIOA)
  */

typedef struct {                                    /*!< GPIOA Structure                                                      */
  volatile u32  RESERVED0[255];
  volatile u32  DATA;                              /*!< GPIO Data                                                             */
  volatile u32  DIR;                               /*!< GPIO Direction                                                        */
  volatile u32  IS;                                /*!< GPIO Interrupt Sense                                                  */
  volatile u32  IBE;                               /*!< GPIO Interrupt Both Edges                                             */
  volatile u32  IEV;                               /*!< GPIO Interrupt Event                                                  */
  volatile u32  IM;                                /*!< GPIO Interrupt Mask                                                   */
  volatile u32  RIS;                               /*!< GPIO Raw Interrupt Status                                             */
  volatile u32  MIS;                               /*!< GPIO Masked Interrupt Status                                          */
  volatile u32  ICR;                               /*!< GPIO Interrupt Clear                                                  */
  volatile u32  AFSEL;                             /*!< GPIO Alternate Function Select                                        */
  volatile u32  RESERVED1[55];
  volatile u32  DR2R;                              /*!< GPIO 2-mA Drive Select                                                */
  volatile u32  DR4R;                              /*!< GPIO 4-mA Drive Select                                                */
  volatile u32  DR8R;                              /*!< GPIO 8-mA Drive Select                                                */
  volatile u32  ODR;                               /*!< GPIO Open Drain Select                                                */
  volatile u32  PUR;                               /*!< GPIO Pull-Up Select                                                   */
  volatile u32  PDR;                               /*!< GPIO Pull-Down Select                                                 */
  volatile u32  SLR;                               /*!< GPIO Slew Rate Control Select                                         */
  volatile u32  DEN;                               /*!< GPIO Digital Enable                                                   */
  volatile u32  LOCK;                              /*!< GPIO Lock                                                             */
  volatile u32  CR;                                /*!< GPIO Commit                                                           */
  volatile u32  AMSEL;                             /*!< GPIO Analog Mode Select                                               */
  volatile u32  PCTL;                              /*!< GPIO Port Control                                                     */
  volatile u32  ADCCTL;                            /*!< GPIO ADC Control                                                      */
  volatile u32  DMACTL;                            /*!< GPIO DMA Control                                                      */
} GPIOA_Type;



/* ================================================================================ */
/* 	-----> Macros
			 * Base_Address ------> 	GPIOx		            */	
/* ================================================================================ */

#define GPIOA_BASE                      0x40004000UL
#define GPIOB_BASE                      0x40005000UL
#define GPIOC_BASE                      0x40006000UL
#define GPIOD_BASE                      0x40007000UL
#define GPIOE_BASE                      0x40024000UL
#define GPIOF_BASE                      0x40025000UL


/* ================================================================================ */
/* ================        GPIOx Peripheral declaration            ================ */
/* ================================================================================ */


#define GPIOA                           ((GPIOA_Type              *) GPIOA_BASE)
#define GPIOB                           ((GPIOA_Type              *) GPIOB_BASE)
#define GPIOC                           ((GPIOA_Type              *) GPIOC_BASE)
#define GPIOD                           ((GPIOA_Type              *) GPIOD_BASE)
#define GPIOE                           ((GPIOA_Type              *) GPIOE_BASE)
#define GPIOF                           ((GPIOA_Type              *) GPIOF_BASE)

#endif //GPIO_PRIVATE_H



