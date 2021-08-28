#include "TM4C123GH6PM.h"
#define PERIODIC_MODE 0x2
#define TAMR_FIELD 0
void mina(void);

int main()
{
  int Local_intFristEdge , Local_intSecondEdge , Local_intCalculateTime ; 
 
//Initialization and configuration for led
  /* Enable Clock Gating for GPIOB  */
SYSCTL->RCGCGPIO |= (1U<<1);
/* Set T0CCP0 as Input  */
GPIOB ->DIR &=~(1U<<6);
/* Config pB6 as Digital Pin  */
GPIOB ->DEN |=(1U<<6);
/*Config pB6 as Alternate Fun */
GPIOB ->AFSEL|=(1U<<6);
/* Config PB6 For T0CCOP PCTL Table 23-5. GPIO Pins and Alternate Functions*/
// Insure No Value From 24: 27 as sefty 
GPIOB->PCTL &=~((1U<<24)|(1U<<25)|(1U<<26)|(1U<<27));
// Put Your Value 0111 From 24: 27  
GPIOB->PCTL |=((1U<<24)|(1U<<25)|(1U<<26));

//Initialization and Configuration for GPT
//To use a GPTM, the appropriate TIMER0 bit must be set in the RCGCTIMER
  SYSCTL->RCGCTIMER |= (1u<<0);
//11.4.1 One-Shot/Periodic Timer Mode
//The GPTM is configured for One-Shot and Periodic modes by the following sequence:
//1. Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making
//any changes.
  TIMER0->CTL &=~(1U<<0);
//2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x4. (16bit Half range Timer)
  TIMER0->CFG = 0x04;
//3. Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR): Caputer Mode 0x3
  TIMER0->TAMR |=((1U<<0)|(1U<<1));
/* Capture Will Be Edge-Time mode  */
  TIMER0->TAMR |=(1U<<2);
 /* The timer counts up. When counting up, the timer starts from avalue of 0x0.*/ 
  TIMER0->TAMR |=(1U<<4);         
  /*For Count On Raising Edge  Positive edge 0X00*/ 
  TIMER0->CTL &=~((1U<<2)|(1U<<3));   
  //7. Set the TnEN bit in the GPTMCTL register to enable the timer and start counting.
  TIMER0->CTL |=(1U<<0);

  
  while(1)
  {
    // Clear The Flag ICR Of Capture Event CAERIS
    TIMER0 ->ICR |=(1U<<2) ;
    // Polling Untill == 1 
    while( (TIMER0 ->RIS & (1U<<2))==0);
    // Storage The First Rise Edge Snap TAR Showes The Current Value In Count 
    Local_intFristEdge = TIMER0 ->TAR ; 
     // Clear The Flag ICR Of Capture Event CAERIS
    TIMER0 ->ICR |=(1U<<2) ;
    // Storage The Second Rise Edge Snap TAR Showes The Current Value In Count 
     Local_intSecondEdge= TIMER0 ->TAR ;
     // Calculate The Time Difference
     Local_intCalculateTime=( Local_intSecondEdge - Local_intFristEdge ) ;
  }
  
  return 0;
}

