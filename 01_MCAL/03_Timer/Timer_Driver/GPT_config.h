/***************************************************************************************
 ***************************  - GPT_config.h		     ***************************
***************************   - Created: 8/6/2021	     ***************************
***************************   - Author: Abdelrahman_Magdy     ***************************
***************************   - Version : _1_		     ***************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/ 


/**************************************************************************************
	- The Optiones Which Developer Choose From Which What Is Appropriate To App
 **************************************************************************************/

/**************************************************************************************
******************* guard of file will call on time in .c	   ********************
**************************************************************************************/


#ifndef GPT_CONFIG_H_
#define GPT_CONFIG_H_

//GPTM Configuration

#define Timer_FULL_BIT         0x0
#define Timer_RTC_BIT          0x1
#define Timer_HALF_BIT         0x4

//GPTM Timer A Mode

#define One-Shot-Timer_mode    0X1
#define Periodic-Timer_mode    0X2
#define Capture_mode           0X3

//GPTM Timer A Capture Mode
#define Edge-Count_mode         0U
#define Edge-Time_mode          1U

//GPTM Timer A Alternate Mode Select
#define Capture_or_compare_mode_is_enabled.         0U
#define Edge_Time_mode                              1U

#endif /*GPT_CONFIG_H_ */


