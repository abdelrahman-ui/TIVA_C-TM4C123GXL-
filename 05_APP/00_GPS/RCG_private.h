/***************************************************************************************
 ***************************  - RCG_private.h		     ***************************
***************************   - Created: 9/2/2021	     ***************************
***************************   - Author: Abdelrahman_Magdy    ***************************
***************************   - Version : _1_		     ***************************
***************************   - Note :
					      *-
					      *-
 **************************************************************************************/ 

/**************************************************************************************

*	  - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	NO
					- Union		:	NO
					- Struct	:	YES

**************************************************************************************/

/*************************************************************************************
******************* guard of file will call on time in .c          *******************
*************************************************************************************/ 


#ifndef RCG_PRIVATE_H
#define RCG_PRIVATE_H


/* ================================================================================ */
/* ================                     SYSCTL                     ================ */
/* ================================================================================ */


/**
  *  Register map for SYSCTL peripheral (SYSCTL)
  */

#include "STD.TYPE.h"

typedef struct {                                    /*!< SYSCTL Structure                                                      */
 volatile u32  DID0;                              /*!< Device Identification 0                                               */
 volatile u32  DID1;                              /*!< Device Identification 1                                               */
 volatile u32  DC0;                               /*!< Device Capabilities 0                                                 */
 volatile u32  RESERVED0;
 volatile u32  DC1;                               /*!< Device Capabilities 1                                                 */
 volatile u32  DC2;                               /*!< Device Capabilities 2                                                 */
 volatile u32  DC3;                               /*!< Device Capabilities 3                                                 */
 volatile u32  DC4;                               /*!< Device Capabilities 4                                                 */
 volatile u32  DC5;                               /*!< Device Capabilities 5                                                 */
 volatile u32  DC6;                               /*!< Device Capabilities 6                                                 */
 volatile u32  DC7;                               /*!< Device Capabilities 7                                                 */
 volatile u32  DC8;                               /*!< Device Capabilities 8 ADC Channels                                    */
 volatile u32  PBORCTL;                           /*!< Brown-Out Reset Control                                               */
 volatile u32  RESERVED1[3];
 volatile u32  SRCR0;                             /*!< Software Reset Control 0                                              */
 volatile u32  SRCR1;                             /*!< Software Reset Control 1                                              */
 volatile u32  SRCR2;                             /*!< Software Reset Control 2                                              */
 volatile u32  RESERVED2;
 volatile u32  RIS;                               /*!< Raw Interrupt Status                                                  */
 volatile u32  IMC;                               /*!< Interrupt Mask Control                                                */
 volatile u32  MISC;                              /*!< Masked Interrupt Status and Clear                                     */
 volatile u32  RESC;                              /*!< Reset Cause                                                           */
 volatile u32  RCC;                               /*!< Run-Mode Clock Configuration                                          */
 volatile u32  RESERVED3[2];
 volatile u32  GPIOHBCTL;                         /*!< GPIO High-Performance Bus Control                                     */
 volatile u32  RCC2;                              /*!< Run-Mode Clock Configuration 2                                        */
 volatile u32  RESERVED4[2];
 volatile u32  MOSCCTL;                           /*!< Main Oscillator Control                                               */
 volatile u32  RESERVED5[32];
 volatile u32  RCGC0;                             /*!< Run Mode Clock Gating Control Register 0                              */
 volatile u32  RCGC1;                             /*!< Run Mode Clock Gating Control Register 1                              */
 volatile u32  RCGC2;                             /*!< Run Mode Clock Gating Control Register 2                              */
 volatile u32  RESERVED6;
 volatile u32  SCGC0;                             /*!< Sleep Mode Clock Gating Control Register 0                            */
 volatile u32  SCGC1;                             /*!< Sleep Mode Clock Gating Control Register 1                            */
 volatile u32  SCGC2;                             /*!< Sleep Mode Clock Gating Control Register 2                            */
 volatile u32  RESERVED7;
 volatile u32  DCGC0;                             /*!< Deep Sleep Mode Clock Gating Control Register 0                       */
 volatile u32  DCGC1;                             /*!< Deep-Sleep Mode Clock Gating Control Register 1                       */
 volatile u32  DCGC2;                             /*!< Deep Sleep Mode Clock Gating Control Register 2                       */
 volatile u32  RESERVED8[6];
 volatile u32  DSLPCLKCFG;                        /*!< Deep Sleep Clock Configuration                                        */
 volatile u32  RESERVED9;
 volatile u32  SYSPROP;                           /*!< System Properties                                                     */
 volatile u32  PIOSCCAL;                          /*!< Precision Internal Oscillator Calibration                             */
 volatile u32  PIOSCSTAT;                         /*!< Precision Internal Oscillator Statistics                              */
 volatile u32  RESERVED10[2];
 volatile u32  PLLFREQ0;                          /*!< PLL Frequency 0                                                       */
 volatile u32  PLLFREQ1;                          /*!< PLL Frequency 1                                                       */
 volatile u32  PLLSTAT;                           /*!< PLL Status                                                            */
 volatile u32  RESERVED11[9];
 volatile u32  DC9;                               /*!< Device Capabilities 9 ADC Digital Comparators                         */
 volatile u32  RESERVED12[3];
 volatile u32  NVMSTAT;                           /*!< Non-Volatile Memory Information                                       */
 volatile u32  RESERVED13[87];
 volatile u32  PPWD;                              /*!< Watchdog Timer Peripheral Present                                     */
 volatile u32  PPTIMER;                           /*!< Timer Peripheral Present                                              */
 volatile u32  PPGPIO;                            /*!< General-Purpose Input/Output Peripheral Present                       */
 volatile u32  PPDMA;                             /*!< Micro Direct Memory Access Peripheral Present                         */
 volatile u32  RESERVED14;
 volatile u32  PPHIB;                             /*!< Hibernation Peripheral Present                                        */
 volatile u32  PPUART;                            /*!< Universal Asynchronous Receiver/Transmitter Peripheral Present        */
 volatile u32  PPSSI;                             /*!< Synchronous Serial Interface Peripheral Present                       */
 volatile u32  PPI2C;                             /*!< Inter-Integrated Circuit Peripheral Present                           */
 volatile u32  RESERVED15;
 volatile u32  PPUSB;                             /*!< Universal Serial Bus Peripheral Present                               */
 volatile u32  RESERVED16[2];
 volatile u32  PPCAN;                             /*!< Controller Area Network Peripheral Present                            */
 volatile u32  PPADC;                             /*!< Analog-to-Digital Converter Peripheral Present                        */
 volatile u32  PPACMP;                            /*!< Analog Comparator Peripheral Present                                  */
 volatile u32  PPPWM;                             /*!< Pulse Width Modulator Peripheral Present                              */
 volatile u32  PPQEI;                             /*!< Quadrature Encoder Interface Peripheral Present                       */
 volatile u32  RESERVED17[4];
 volatile u32  PPEEPROM;                          /*!< EEPROM Peripheral Present                                             */
 volatile u32  PPWTIMER;                          /*!< Wide Timer Peripheral Present                                         */
 volatile u32  RESERVED18[104];
 volatile u32  SRWD;                              /*!< Watchdog Timer Software Reset                                         */
 volatile u32  SRTIMER;                           /*!< Timer Software Reset                                                  */
 volatile u32  SRGPIO;                            /*!< General-Purpose Input/Output Software Reset                           */
 volatile u32  SRDMA;                             /*!< Micro Direct Memory Access Software Reset                             */
 volatile u32  RESERVED19;
 volatile u32  SRHIB;                             /*!< Hibernation Software Reset                                            */
 volatile u32  SRUART;                            /*!< Universal Asynchronous Receiver/Transmitter Software Reset            */
 volatile u32  SRSSI;                             /*!< Synchronous Serial Interface Software Reset                           */
 volatile u32  SRI2C;                             /*!< Inter-Integrated Circuit Software Reset                               */
 volatile u32  RESERVED20;
 volatile u32  SRUSB;                             /*!< Universal Serial Bus Software Reset                                   */
 volatile u32  RESERVED21[2];
 volatile u32  SRCAN;                             /*!< Controller Area Network Software Reset                                */
 volatile u32  SRADC;                             /*!< Analog-to-Digital Converter Software Reset                            */
 volatile u32  SRACMP;                            /*!< Analog Comparator Software Reset                                      */
 volatile u32  SRPWM;                             /*!< Pulse Width Modulator Software Reset                                  */
 volatile u32  SRQEI;                             /*!< Quadrature Encoder Interface Software Reset                           */
 volatile u32  RESERVED22[4];
 volatile u32  SREEPROM;                          /*!< EEPROM Software Reset                                                 */
 volatile u32  SRWTIMER;                          /*!< Wide Timer Software Reset                                             */
 volatile u32  RESERVED23[40];
 volatile u32  RCGCWD;                            /*!< Watchdog Timer Run Mode Clock Gating Control                          */
 volatile u32  RCGCTIMER;                         /*!< Timer Run Mode Clock Gating Control                                   */
 volatile u32  RCGCGPIO;                          /*!< General-Purpose Input/Output Run Mode Clock Gating Control            */
 volatile u32  RCGCDMA;                           /*!< Micro Direct Memory Access Run Mode Clock Gating Control              */
 volatile u32  RESERVED24;
 volatile u32  RCGCHIB;                           /*!< Hibernation Run Mode Clock Gating Control                             */
 volatile u32  RCGCUART;                          /*!< Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating
                                                      Control                                                               */
 volatile u32  RCGCSSI;                           /*!< Synchronous Serial Interface Run Mode Clock Gating Control            */
 volatile u32  RCGCI2C;                           /*!< Inter-Integrated Circuit Run Mode Clock Gating Control                */
 volatile u32  RESERVED25;
 volatile u32  RCGCUSB;                           /*!< Universal Serial Bus Run Mode Clock Gating Control                    */
 volatile u32  RESERVED26[2];
 volatile u32  RCGCCAN;                           /*!< Controller Area Network Run Mode Clock Gating Control                 */
 volatile u32  RCGCADC;                           /*!< Analog-to-Digital Converter Run Mode Clock Gating Control             */
 volatile u32  RCGCACMP;                          /*!< Analog Comparator Run Mode Clock Gating Control                       */
 volatile u32  RCGCPWM;                           /*!< Pulse Width Modulator Run Mode Clock Gating Control                   */
 volatile u32  RCGCQEI;                           /*!< Quadrature Encoder Interface Run Mode Clock Gating Control            */
 volatile u32  RESERVED27[4];
 volatile u32  RCGCEEPROM;                        /*!< EEPROM Run Mode Clock Gating Control                                  */
 volatile u32  RCGCWTIMER;                        /*!< Wide Timer Run Mode Clock Gating Control                              */
 volatile u32  RESERVED28[40];
 volatile u32  SCGCWD;                            /*!< Watchdog Timer Sleep Mode Clock Gating Control                        */
 volatile u32  SCGCTIMER;                         /*!< Timer Sleep Mode Clock Gating Control                                 */
 volatile u32  SCGCGPIO;                          /*!< General-Purpose Input/Output Sleep Mode Clock Gating Control          */
 volatile u32  SCGCDMA;                           /*!< Micro Direct Memory Access Sleep Mode Clock Gating Control            */
 volatile u32  RESERVED29;
 volatile u32  SCGCHIB;                           /*!< Hibernation Sleep Mode Clock Gating Control                           */
 volatile u32  SCGCUART;                          /*!< Universal Asynchronous Receiver/Transmitter Sleep Mode Clock
                                                      Gating Control                                                        */
 volatile u32  SCGCSSI;                           /*!< Synchronous Serial Interface Sleep Mode Clock Gating Control          */
 volatile u32  SCGCI2C;                           /*!< Inter-Integrated Circuit Sleep Mode Clock Gating Control              */
 volatile u32  RESERVED30;
 volatile u32  SCGCUSB;                           /*!< Universal Serial Bus Sleep Mode Clock Gating Control                  */
 volatile u32  RESERVED31[2];
 volatile u32  SCGCCAN;                           /*!< Controller Area Network Sleep Mode Clock Gating Control               */
 volatile u32  SCGCADC;                           /*!< Analog-to-Digital Converter Sleep Mode Clock Gating Control           */
 volatile u32  SCGCACMP;                          /*!< Analog Comparator Sleep Mode Clock Gating Control                     */
 volatile u32  SCGCPWM;                           /*!< Pulse Width Modulator Sleep Mode Clock Gating Control                 */
 volatile u32  SCGCQEI;                           /*!< Quadrature Encoder Interface Sleep Mode Clock Gating Control          */
 volatile u32  RESERVED32[4];
 volatile u32  SCGCEEPROM;                        /*!< EEPROM Sleep Mode Clock Gating Control                                */
 volatile u32  SCGCWTIMER;                        /*!< Wide Timer Sleep Mode Clock Gating Control                            */
 volatile u32  RESERVED33[40];
 volatile u32  DCGCWD;                            /*!< Watchdog Timer Deep-Sleep Mode Clock Gating Control                   */
 volatile u32  DCGCTIMER;                         /*!< Timer Deep-Sleep Mode Clock Gating Control                            */
 volatile u32  DCGCGPIO;                          /*!< General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control     */
 volatile u32  DCGCDMA;                           /*!< Micro Direct Memory Access Deep-Sleep Mode Clock Gating Control       */
 volatile u32  RESERVED34;
 volatile u32  DCGCHIB;                           /*!< Hibernation Deep-Sleep Mode Clock Gating Control                      */
 volatile u32  DCGCUART;                          /*!< Universal Asynchronous Receiver/Transmitter Deep-Sleep Mode
                                                        Clock Gating Control                                                  */
 volatile u32  DCGCSSI;                           /*!< Synchronous Serial Interface Deep-Sleep Mode Clock Gating Control     */
 volatile u32  DCGCI2C;                           /*!< Inter-Integrated Circuit Deep-Sleep Mode Clock Gating Control         */
 volatile u32  RESERVED35;
 volatile u32  DCGCUSB;                           /*!< Universal Serial Bus Deep-Sleep Mode Clock Gating Control             */
 volatile u32  RESERVED36[2];
 volatile u32  DCGCCAN;                           /*!< Controller Area Network Deep-Sleep Mode Clock Gating Control          */
 volatile u32  DCGCADC;                           /*!< Analog-to-Digital Converter Deep-Sleep Mode Clock Gating Control      */
 volatile u32  DCGCACMP;                          /*!< Analog Comparator Deep-Sleep Mode Clock Gating Control                */
 volatile u32  DCGCPWM;                           /*!< Pulse Width Modulator Deep-Sleep Mode Clock Gating Control            */
 volatile u32  DCGCQEI;                           /*!< Quadrature Encoder Interface Deep-Sleep Mode Clock Gating Control     */
 volatile u32  RESERVED37[4];
 volatile u32  DCGCEEPROM;                        /*!< EEPROM Deep-Sleep Mode Clock Gating Control                           */
 volatile u32  DCGCWTIMER;                        /*!< Wide Timer Deep-Sleep Mode Clock Gating Control                       */
 volatile u32  RESERVED38[104];
 volatile u32  PRWD;                              /*!< Watchdog Timer Peripheral Ready                                       */
 volatile u32  PRTIMER;                           /*!< Timer Peripheral Ready                                                */
 volatile u32  PRGPIO;                            /*!< General-Purpose Input/Output Peripheral Ready                         */
 volatile u32  PRDMA;                             /*!< Micro Direct Memory Access Peripheral Ready                           */
 volatile u32  RESERVED39;
 volatile u32  PRHIB;                             /*!< Hibernation Peripheral Ready                                          */
 volatile u32  PRUART;                            /*!< Universal Asynchronous Receiver/Transmitter Peripheral Ready          */
 volatile u32  PRSSI;                             /*!< Synchronous Serial Interface Peripheral Ready                         */
 volatile u32  PRI2C;                             /*!< Inter-Integrated Circuit Peripheral Ready                             */
 volatile u32  RESERVED40;
 volatile u32  PRUSB;                             /*!< Universal Serial Bus Peripheral Ready                                 */
 volatile u32  RESERVED41[2];
 volatile u32  PRCAN;                             /*!< Controller Area Network Peripheral Ready                              */
 volatile u32  PRADC;                             /*!< Analog-to-Digital Converter Peripheral Ready                          */
 volatile u32  PRACMP;                            /*!< Analog Comparator Peripheral Ready                                    */
 volatile u32  PRPWM;                             /*!< Pulse Width Modulator Peripheral Ready                                */
 volatile u32  PRQEI;                             /*!< Quadrature Encoder Interface Peripheral Ready                         */
 volatile u32  RESERVED42[4];
 volatile u32  PREEPROM;                          /*!< EEPROM Peripheral Ready                                               */
 volatile u32  PRWTIMER;                          /*!< Wide Timer Peripheral Ready                                           */
} SYSCTL_Type;

/* ================================================================================ */
/* 	-----> Macros
			 * Base_Address ------> 	RCG		            */	
/* ================================================================================ */

#define SYSCTL_BASE                     0x400FE000UL

/* ================================================================================ */
/* ================          RCG Peripheral declaration            ================ */
/* ================================================================================ */
#define SYSCTL                          ((SYSCTL_Type             *) SYSCTL_BASE)


#endif //RCG_PRIVATE_H











