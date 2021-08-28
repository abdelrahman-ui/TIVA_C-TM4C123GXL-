/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/


#ifndef MACROS_H_
#define MACROS_H_


#define SET_BIT(REG , BITNUM) REG |= 1U<<BITNUM
#define CLR_BIT(REG , BITNUM) REG &= ~(1U<<BITNUM)
#define TOG_BIT(REG , BITNUM) REG ^= 1U<<BITNUM
#define GET_BIT(REG , BITNUM) ( (REG >> BITNUM) & 1U )



#endif /* MACROS_H_ */
