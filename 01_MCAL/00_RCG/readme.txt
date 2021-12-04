( Reseat & Clk control )
0_ clk sourse (RC circuit  ,CRYSTAL , Ceramic)
1- Bus in arm (AHB & APB1 & APB2) 
				*- AHB : That for ARM Core Peripheral like ( RCC , 	DMA , SYSTICK ,  RTC , .........
				*_ APB : That for peripheral by vendor Like ( STM , TEXAS INSTRUMENTS ,.....  


2_clk type :
				*_HSI : High speed internal (
				*_HSE : High Speed External ( RC | Crystal)
				*_PLL : Factor (* or /) in HSE | HSI .
3_ Now peripheral have 2 enable :
								*) one to peripheral enable for peripheral need to check all time so it consum power . 
								*) one for Enable clk to peripheral not core one . (Name (CLK gating ) 
**4_when disable peripheral but enable clk i can config untile peripheral enable .
5_Must know the peripheral connect to which bus .
6_ Memoy map for base address .
7_ so control the clk for the processor & enable or disable clk for peripheral to consum power .
8_defulat rcc if you not chose it is RC internal  hsi .
9_all type of clk can be enale at the same time but which will enter to procesor you chose .
10_have (mco) microconrtroller output that out the clk which processor work in to check so for diagnostic .
11_ MCO --> Can be input for anthor micro ( cascad ) so all wil be synchronous but if one drop all will drop .
12_ MCO can be prescalled . 
13_if ther is a error in clk hse system can change auto the clk to hsi . CSS (CLK security system)  
***14_i can mange error by 4.5% 