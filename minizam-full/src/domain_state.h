#ifndef _DOMAIN_STATE_H
#define _DOMAIN_STATE_H

#include "mlvalues.h"


typedef struct _caml_domain_state {
  /* Stack */
  mlvalue* stack;

  /* Heap */
  mlvalue* heap_start; // Début du tas alloué
  mlvalue* heap_ptr; // Pointeur courant dans le tas, pour les allocations
  
} caml_domain_state;

/* The global state */
extern caml_domain_state* Caml_state;

/* Initialisation function for |Caml_state| */
void caml_init_domain();

#endif
