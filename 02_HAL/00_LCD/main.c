

int main()
{
 /* */
 LCD_voidInitPins(); 
 
 while(1)
 { 
   
   { 
   /* 8-bit bus mode, 2 line display mode, 5x8 dots display mode */
   LCD_voidSendCommand(0X38);
    Delay();
   /* clear display*/
    LCD_voidSendCommand(0X01) ;
      Delay(); 
   /* cursor display shift */
   LCD_voidSendCommand(0X10);
    Delay();
   /* diplay is on*/
    LCD_voidSendCommand(0X0C);
     Delay();
 }
 }
 
     
  return 0;
}

