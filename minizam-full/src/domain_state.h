#ifndef _DOMAIN_STATE_H
#define _DOMAIN_STATE_H

#include "mlvalues.h"

typedef struct _gc_root {
    mlvalue* object; // Pointeur vers l'objet
    struct _gc_root* next; // Prochain élément de la liste
} gc_root;

typedef struct _caml_domain_state {
  /* Stack */
  mlvalue* stack;

  /* Heap */
  mlvalue* heap_start; // Début du tas alloué
  mlvalue* heap_ptr; // Pointeur courant dans le tas, pour les allocations
  
  gc_root* gc_roots; // Liste des racines pour le GC

} caml_domain_state;

/* The global state */
extern caml_domain_state* Caml_state;

extern gc_root* Gc_root;

/* Initialisation function for |Caml_state| */
void caml_init_domain();

#endif
