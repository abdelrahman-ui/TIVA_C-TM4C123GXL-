/*************************************************************/
-pin ( source & sinke ) : 
			*) Source : what it can out in stmf103fxx 25mA active high
			*) Sink   : what pin can bear without damage  Active low.
- Not all port out current like port c in stm32f103 . 
- But better use pin of micro use protaction circuit ( transistor , optocubler , ........)
- 4 Bit 2 for Mode and 2 for Config for pin so Option = 16 for pin_option 4 bit for option . 
- num of pin *option for pin / 32 = num of reg .
- Mode (Input ,Output-->High speed ,Output-->Meduim speed , Output-->Low speed) ---> so i can in outputt control frquancy for pin out .
- Config as Input  : (Analog , Floating, PullUPorDown , Reserved)
- Config as Output : (Pushpull,OpenDrain, ALF(0..15)PushPull ,ALF(0..15)OpenDrain  )

*Input Option Config : 
- Analog Any pin Can be ADC
- Floating_input  : Sensitive For High And Low can be attach by noise Used With  Sensor. we can block noise by schmitt trigger )   
--> when i apply not 0 or 1 it attach by noise 
-->   
- PULL_DOWN : Sensitive For High Only(defulat) ---> Internal Ground . read defualt ground . 
- PULL_UP   : Sensitive For Low Only  ---> Internal vcc good with Avoid Noise .by defult read high .
-----> For Pull Up Or Down -->Anthor REG to choise .

* Output Option Config : 
- Pushpull      : The Normal Mode So 1=3.3V --> High & 0 = 0V -->lOW 
- OpenDrain     : 0 Conect The Ground = 0 But When you Write 1 -->Will be Floating = Disconnect From The MicroController 
 * The benfit of open drain floating  --> You Can Connect Any Volt External So Here 1 Not = 3.3V And Current Not = 25MA bUT Any Value You Can Put It With Out Afrid About Micro
 * 1 = External Power Supply So High Level is Configrable Any value I need without any transistor
 * Must have resistance -> In Case Of Zero Not Make Short Crircuit . 
 * Second Binfet The Open Drain bUS -->  
- ALF PushPull  :Not For GPIO and It's Push Pull
- ALF OpenDrain : Not For GPIO and It's OpenDrain Like CAN And Lin

/****************************************************************/
BSRR reg = ODR --> But Faster in ASSEMBLY Without OR you Can Write pin set or Reseat faster of odr   
BSRR = Zero is no effect and for same pin if set and reseat set here more periority . 
BRR REG --> Reast Only zero no effect fater of bsrr becouse after sheft bit in bsrr must move to reseat region here without move .
Write on ODR on input mode make it Pull_up