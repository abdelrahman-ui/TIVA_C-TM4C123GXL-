#include"TM4C123GH6PM.h"

void MADC0_voidInit();
void MADC0_voidConvig();
int main()
{
 
  MADC0_voidInit();
  MADC0_voidConvig();
    while(1)
    {
    unsigned int ADC0_u8ReadValue ;
        

  /*GPIO Peripheral RCG EN */
  SYSCTL->RCGCGPIO|=(1U<<5);
  /* GPIOF Dir For LED 1 & 2 & 3*/
  GPIOF->DIR |=((1U<<1)|(1U<<2)|(1U<<3));
  /* Digital Functionality Of Pin Digital */
  GPIOF->DEN |=((1U<<1)|(1U<<2)|(1U<<3));
  /* The Frist State Led Off At Programme  */
  GPIOF->DATA &=~((1U<<1)|(1U<<2)|(1U<<3));
  
   /*. Enable the sample sequencer logic by setting the corresponding ASENn bit in the ADCACTSS
register.*/
  
     ADC0 ->ACTSS |=(1U<<0) ;   // EN sample sequencer 0
    /*Begin sampling on Sample Sequencer 0, if the sequencer is
          enabled in the ADCACTSS register*/
     ADC0 ->PSSI |=(1U<<0); 
     
     /*6 If interrupts are to be used, set the corresponding MASK bit in the ADCIM register */
  
   ADC0 ->IM |=(1U <<0) ;           //SS0 Interrupt Mask
     
     /* Wait The Flag */
   
   while((ADC0->RIS&8U)==0);
    /* Read Data FROMM FIFO */

  ADC0_u8ReadValue = ADC0->SSFIFO0 ;
   
    /* Clear The Flag */
   ADC0->ISC = 8 ;
   
   /*if ( ADC0_u8ReadValue >=  )
      GPIOF->DATA |=((1U<<1)|(1U<<2)|(1U<<3));
    else 
       GPIOF->DATA |=((1U<<1)|(1U<<2) ;
   */
   
    }
    
    return 0;
  
}


void MADC0_voidInit()
{
  /* 1. Enable the ADC clock using the RCGCADC register (see page 352).*/
  SYSCTL->RCGCADC |=(1U<<0);   // EN ADC 0
 /*2. Enable the clock to the appropriate GPIO modules via the RCGCGPIO register (see page 340).
       To find out which GPIO ports to enable, refer to “Signal Description” on page 801.*/
  SYSCTL->RCGCGPIO |=(1U<<4) ;        // Choise AIN0 The Port E PIN6 
 /*3. Set the GPIO AFSEL bits for the ADC input pins (see page 671). To determine which GPIOs to
          configure, see Table 23-4 on page 1344.*/
  GPIOE->AFSEL |=(1U<<6);             // Pin 6 in GPIOE Will Be Afsel
  
/*4. Configure the AINx signals to be analog inputs by clearing the corresponding DEN bit in the
          GPIO Digital Enable (GPIODEN) register (see page 682).*/
  
   GPIOE->DEN &=~(1U<<6);            // Digital Disable For Pin6
/*5. Disable the analog isolation circuit for all ADC input pins that are to be used by writing a 1 to
the appropriate bits of the GPIOAMSEL register (see page 687) in the associated GPIO block.*/
  
  GPIOE->AMSEL |=(1U<<6);            //The analog function of the pin is enabled, the isolation isdisabled, and the pin is capable of analog functions.
  
}

void MADC0_voidConvig()
{
  
  
  /*1. Ensure that the sample sequencer is disabled by clearing the corresponding ASENn bit in the
ADCACTSS register. Programming of the sample sequencers is allowed without having them
enabled. Disabling the sequencer during programming prevents erroneous execution if a trigger
event were to occur during the configuration process.*/
  
  ADC0 ->ACTSS &=~(1U<<0) ;   // Disable sample sequencer 0

  /*2. Configure the trigger event for the sample sequencer in the ADCEMUX register.*/
  ADC0 ->EMUX |= 0X000 ;       // SS0 Processor (default)
   
  /*4. For each sample in the sample sequence, configure the corresponding input source in the
ADCSSMUXn register.*/
   
  
    ADC0->SSMUX0|= 0X000 ;                         // SS0 1st Sample Input Select
  

}










