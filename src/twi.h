#include <stdbool.h>

typedef struct config{
  int freq ;
  int sda  ;
  int scl  ;
} config_t;

typedef struct instance{
  int       interface ;
  config_t  conf      ;
} instance_t; 

bool twi_init(int instance, int address, int freq, int sda, int scl);
void twi_print(void);
