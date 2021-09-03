
#include "TM4C123GH6PM.h"
#include "cstartup_M.c"

void Init_voidSystem();
void SysTick_Handler( void );
int Global_intFlag ;
int main()
{
  Init_voidSystem();
       // The Value To Count 
  SysTick ->LOAD = 8000000U - 1 ;
  while(1)
  {
 
  // Enable And Clk sourse  Start To Count + Mask 
  SysTick ->CTRL |=(1U<<0)|(1U<<2)|(1U<<1);
    if(Global_intFlag==1)
    {
    GPIOF->DATA |=(1U<<1);
    Systick_voidDelay();
     GPIOF->DATA |=(1U<<2);
    Systick_voidDelay();
     
    GPIOF->DATA &=~(1U<<1);
    Systick_voidDelay();
     GPIOF->DATA &=~(1U<<2);
    Systick_voidDelay();
    }
    Global_intFlag=0;
    // Disable 
   SysTick ->CTRL |= 0U;
  }
  return 0;
}



void Init_voidSystem()
{
   /*GPIO Peripheral RCG EN */
  SYSCTL->RCGCGPIO|=(1U<<5);
  /* GPIOF Dir For LED 1 & 2 & 3*/
  GPIOF->DIR |=((1U<<1)|(1U<<2)|(1U<<3));
  /* Digital Functionality Of Pin Digital */
  GPIOF->DEN |=((1U<<1)|(1U<<2)|(1U<<3));
  /* The Frist State Led Off At Programme  */
  GPIOF->DATA &=~((1U<<1)|(1U<<2)|(1U<<3));
  
}

void SysTick_Handler( void )
{
  Global_intFlag++;
  
}
