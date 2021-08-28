#include "TM4C123GH6PM.h"
#define PERIODIC_MODE 0x2
#define TAMR_FIELD 0
int Global_intFlatOT =0;
void Abdo_Handelar(void);


int main()
{
 
//Initialization and configuration for led
  /* Enable Clock Gating for GPIOF */
SYSCTL->RCGCGPIO |= (1U<<5);
/* Set LED pins(1) as output */
GPIOF->DIR |= (1U<<1);
/* Enable digital functionality for LED pins(1) in GPIOF */
GPIOF->DEN |= (1U<<1);
/* Init all leds to zero */
GPIOF->DATA &=~ (1U<<1);

//Initialization and Configuration for GPT
//To use a GPTM, the appropriate TIMER0 bit must be set in the RCGCTIMER
  SYSCTL->RCGCTIMER |= (1u<<0);
//11.4.1 One-Shot/Periodic Timer Mode
//The GPTM is configured for One-Shot and Periodic modes by the following sequence:
//1. Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making
//any changes.
  TIMER0->CTL &=~(1U<<0);
//2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000. (16bit Half range Timer)
  TIMER0->CFG = 0x4;

//3. Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
  TIMER0->TAMR |= (PERIODIC_MODE<<TAMR_FIELD);
//4. Optionally configure the TnSNAPS, TnWOT, TnMTE, and TnCDIR bits in the GPTMTnMR register
//to select whether to capture the value of the free-running timer at time-out, use an external
//trigger to start counting, configure an additional trigger or interrupt, and count up or down.
  TIMER0->TAMR &=~ (1U<<4);
//5. Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR).
  /* For 1 Sec After Prescaller 250 */
  TIMER0->TAILR = 6400U-1;
  /* Config Prescaller With 250 */
  TIMER0->TAPR = 250U - 1;
//6. If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register
//(GPTMIMR).
  //6.1 Enable to the global interrupt from CMSIS library
 __enable_interrupt();
  //6.2 Enable to the interrupt mask
 TIMER0->IMR |= (1U<<0);
  //6.3 Enable NVIC for this Interrupt 
 NVIC->ISER[0] |= (1U<<19);
 
//7. Set the TnEN bit in the GPTMCTL register to enable the timer and start counting.
  TIMER0->CTL |=(1U<<0);
//8. Poll the GPTMRIS register or wait for the interrupt to be generated (if enabled). In both cases,
//the status flags are cleared by writing a 1 to the appropriate bit of the GPTM Interrupt Clear
//Register (GPTMICR)
  
  while(1)
  {
  //Toogle led
      GPIOF->DATA ^= (1U<<1);
      if(Global_intFlatOT==1)
      {
        GPIOF->DATA ^= (1U<<1);
        Global_intFlatOT=0;
      }
  }
  
  return 0;
}

void Abdo_Handelar(void)
{
      //Clear Tout flag
      TIMER0->ICR |=(1U<<0);
      Global_intFlatOT ++ ;
  
}