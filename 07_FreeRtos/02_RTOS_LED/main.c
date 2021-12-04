/*=======================================================================================
===========================  - main.c		             ============================
===========================  - Created: 10/2/2021	     ============================
===========================  - Author: Abdelrahman_Magdy     ============================
===========================  - Version : _1_		     ============================
===========================  - Note :
					      *-
					      *-
 =======================================================================================*/


/*======================================================================================
============================   The Foundation Of Function   ============================
========================================================================================*/




/*============= INCLUDE =============*/
	#include "FreeRTOS.h"
        #include "task.h"
        #include "FreeRTOSConfig.h"
/*=======================================*/


/* Define the strings that will be passed in as the task parameters. These are
defined const and not on the stack to ensure they remain valid when the tasks are
executing. */

static const char *pcTextForTask1 = 1;
static const char *pcTextForTask2 = 2;
static const char *pcTextForTask3 = 3;
/* Prototype */
void vTask( void *pvParameters );

 int main( void )
{
                /* Init Uart */
uart_init (9600,16000000UL);
               /* Creatiation for task  */
/* Create one of the two tasks : { NameO f Fun (app):Is Pointer To Fun , Name , StackSize , String Parameter , Piriority , NoHandeler } */
xTaskCreate (vTask,"Task 1",100,(void*)pcTextForTask1, 1, NULL ); 
/* Create the other task in exactly the same way. Note this time that multiple tasks are being created from the SAME task implementation (vTask). Only the value passed in the parameter is different. Two instances of the same task are being created. */
xTaskCreate (vTask, "Task 2",100, (void*)pcTextForTask2,1 , NULL );
/* Create the other task in exactly the same way. Note this time that multiple tasks are being created from the SAME task implementation (vTask). Only the value passed in the parameter is different. Two instances of the same task are being created. */
xTaskCreate (vTask, "Task 2",100, (void*)pcTextForTask3,1 , NULL );

              /* Start the scheduler so our tasks start executing ---> Enable OS */
vTaskStartScheduler();

/* If all is well then main() will never reach here as the scheduler will
now be running the tasks. If main() does reach here then it is likely that
there was insufficient heap memory available for the idle task to be created.*/



  /*GPIO Peripheral RCG EN */
  SYSCTL->RCGCGPIO|=(1U<<5);
  /* GPIOF Dir For LED 1 & 2 & 3*/
  GPIOF->DIR |=((1U<<1)|(1U<<2)|(1U<<3));
  /* Digital Functionality Of Pin Digital */
  GPIOF->DEN |=((1U<<1)|(1U<<2)|(1U<<3));
  /* The Frist State Led Off At Programme  */
  GPIOF->DATA &=~((1U<<1)|(1U<<2)|(1U<<3));
  
/* while( 1 ) : As Debugging if getout OS for some reason stack here   */
while( 1 ); 

}



/* Task code  take void pointer Task here as APP freeRtos will creat from it some task  */
void vTask( void *pvParameters )
{
      /* local variable To save currnt tick */
 TickType_t pxPreviousWakeTime; 
 
 
char *pcTaskName;                        /* Variable to save element of string at char element by element */ 
pcTaskName = ( char * ) pvParameters;   /* Casting the void pointer to char pointer */


  /* Save excution time for task chanegable */
  pxPreviousWakeTime = xTaskGetTickCount();


/* As per most tasks, this task is implemented in an infinite loop. */
for( ;; )
{

/* Delay for a period. */

  switch(pcTaskName) 
  {
    case 1 :   GPIOF->DATA =(1U<<1);            break ;
    case 2 :   GPIOF->DATA =(1U<<2);            break ;
    case 3 :   GPIOF->DATA =(1U<<3);            break ;
  }
  /* From tick Num pxPreviousWakeTime count until 300 as delay (blocked) */
vTaskDelayUntil(&pxPreviousWakeTime,300);

}
}

