
#include "GPIO_interface.h"

/* For Debug */
int main()
{
  MGOIP_voidSetPinDir(GPIOA_PORT,PIN0,DIR_OUT) ;
  MGOIP_voidSetPinDir(GPIOA_PORT,PIN0,DIR_IN) ;
  MGOIP_voidSetPinALFun(GPIOA_PORT,PIN0);
    
  return 0;
}
