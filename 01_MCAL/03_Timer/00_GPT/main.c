#include "TM4C123GH6PM.h"

void Abdo_Handler(void); 
int Global_FlagOT= 0 ; 

int main()
{
  /*Initialization and Configuration For GPIO Peripheral  LED*/
  /*GPIO Peripheral RCG EN */
  SYSCTL->RCGCGPIO|=(1U<<5);
  /* GPIOF Dir For LED 1 & 2 & 3*/
  GPIOF->DIR |=((1U<<1)|(1U<<2)|(1U<<3));
  /* Digital Functionality Of Pin Digital */
  GPIOF->DEN |=((1U<<1)|(1U<<2)|(1U<<3));
  /* The Frist State Led Off At Programme  */
  GPIOF->Data &=~((1U<<1)|(1U<<2)|(1U<<3));
  
  /*
  Initialization and Configuration For GPT
To use a GPTM, the appropriate TIMER0 bit must be set in the or RCGCWTIMER
register (see page 338 and page 357)*/
SYSCTL->RCGCTIMER|=(1U<<0); 
 
/*1. Ensure the timer is disabled (the TAEN bit in the GPTMCTL register is cleared) before makingany changes.*/
TIMER0->CTL &=~(1U<<0);

//2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000 To Be 32 bit
TIMER0_Type ->CFG = 0x0000.0000 ;

//3. Configure the TAMR field in the GPTM Timer n Mode Register (GPTMTAMR):Periodic_mode
TIMER0->TAMR |= (0X2<<0) ;

//4. Optionally configure the TnSNAPS, TnWOT, TnMTE, and TnCDIR bits in the GPTMTAMR register
//to select whether to capture the value of the free-running timer at time-out, use an external
//trigger to start counting, configure an additional trigger or interrupt, and count up or down.
TIMER0->TAMR &=~(1U<<4);
//5. Load the start value into the GPTM Timer n Interval Load Register (GPTMTAILR
  
/* Toggle Led After 0.5 Sec On Internal Clk 16 000 000
    16000 000 ----------> 1   SEC
    ????????? ----------> 0.5 SEC 
  TAILR = 16000000 / 2
 
*/
TIMER0_Type ->TAILR = (8000000U - 1 ) ;
  
// 6. If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register(GPTMIMR).
/* CMSIS EN Global Interrput */
 __enable_interrupt();
/* EN Interrput Mask Here The TATO */
TIMER0 ->IMR |=(1U<<0);
/* EN NVIC For This Inttterput ( Vector Table in flash)  19  */
NVIC->ISER[0] |=(1U<<19) ;

// 7. Set the TnEN bit in the GPTMCTL register to enable the timer and start counting.
TIMER0_Type ->CTL |=(1U<<0);
// 8. Poll the GPTMRIS register or wait for the interrupt to be generated (if enabled). In both cases the status flags are cleared


  while(1)
  {
   
    /* Polling */
    /* If Not == 0 | If == 1 ATOMIS */
     /*
    if (!(TIMER0_Type ->RIS &(1U<<0)) 
    {
      // Clear Flag By Writting 1 TATOCINT
     TIMER0_Type ->ICR |=(1U<<0);

      // Toogle Led 
     GPIOF->Data ^=((1U<<1)|(1U<<2)|(1U<<3));
     */
      if(Global_FlagOT==1)
      {
        // Toogle Led 
     GPIOF->Data ^=((1U<<1)|(1U<<2)|(1U<<3));
     Global_FlagOT =0 ;
      }
    }
    */    
        
  }
  
  
  
  
  
  return 0;
}


void Abdo_Handler(void)
{
   // Clear Flag By Writting 1 TATOCINT
     TIMER0_Type ->ICR |=(1U<<0);
  Global_FlagOT++;
}
