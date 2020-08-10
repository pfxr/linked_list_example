#include <stdio.h>
#include "twi.h"

int main(){
  twi_init(0, 0x30, 250, 1, 2); 
  twi_print();

  twi_init(1, 0x31, 100, 3, 4);
  twi_print();

  twi_init(1, 0x31, 100, 3, 4);
  twi_print();
  
  return 0;
}
