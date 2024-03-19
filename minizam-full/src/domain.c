#include <stdlib.h>

#include "domain_state.h"
#include "config.h"
#include "mlvalues.h"


caml_domain_state* Caml_state;

void caml_init_domain() {

  Caml_state = malloc(sizeof(caml_domain_state));

  Caml_state->stack = malloc(Stack_size);
  
  Caml_state->heap_start = malloc(32 * 1024);
  Caml_state->heap_ptr = Caml_state->heap_start;
  }
