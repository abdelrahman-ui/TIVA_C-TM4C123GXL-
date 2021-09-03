
#include "TM4C123GH6PM.h"

void Init_voidSystem();
void Systick_voidDelay();

int main()
{
  Init_voidSystem();
  while(1)
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

// 0.5 sec == 8000000
void Systick_voidDelay()
{
  
  // The Value To Count 
  SysTick ->LOAD = 8000000U - 1 ;
  // Enable And Clk sourse  Start To Count 
  SysTick ->CTRL |=(1U<<0)|(1U<<2);
  // Pollin Until The Flag 
  while (((SysTick ->CTRL) &(1U<<16))==0);
  // Disable 
   SysTick ->CTRL |= 0U;
}