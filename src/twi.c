#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "twi.h"

typedef struct twi_node{
  instance_t        inst;
  struct twi_node*  next;
} twi_node_t;

twi_node_t *twi_node_head = NULL;

static bool twi_find_interface(int iface){
  twi_node_t *twi = twi_node_head;

  while(twi != NULL){
    if(iface == twi->inst.interface)
      return true;

    twi = twi->next;
  }
  return false;
}

void twi_print(void){
  twi_node_t *twi = twi_node_head;

  while(twi != NULL){
    printf("%d %d %d %d\n", 
            twi->inst.interface, 
            twi->inst.conf.freq, 
            twi->inst.conf.sda, 
            twi->inst.conf.scl
          );

    twi = twi->next;
  }
  printf("\n");
}

bool twi_init(int interface, int address, int freq, int sda, int scl){

  if( twi_find_interface(interface) ){
    printf("ERROR! Interface %d was initialized before.\n\n",interface);
    return false;
  }

  twi_node_t *twi = (twi_node_t *) malloc(sizeof(twi_node_t)); 

  twi->inst.interface  = interface;
  twi->inst.conf.freq  = freq     ;
  twi->inst.conf.sda   = sda      ;
  twi->inst.conf.scl   = scl      ;

  // Save the current head instance as this instance's next
  twi->next         = twi_node_head;

  // This instance is now the new head
  twi_node_head     = twi          ;  
  return true;
}
