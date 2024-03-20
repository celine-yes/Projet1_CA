#include "domain_state.h";

void mark(mlvalue obj) {
    // Vérifie si l'objet n'est pas un entier et n'a pas déjà été marqué
    if (Is_block(obj) && Color_hd(Hd_val(obj)) != BLACK) {
        // Marque cet objet comme vivant
        header_t header = Hd_val(obj);
        Hd_val(obj) = Make_header(Size_hd(header), BLACK, Tag_hd(header));
        
        // Parcours récursif pour tous les objets référencés par cet objet
        for (int i = 0; i < Size_hd(header); i++) {
            mark(Field(obj, i));
        }
    }
}

void mark_roots(caml_domain_state* state) {
    gc_root* root = state->gc_roots;
    while (root != NULL) {
        mark(*(root->object));
        root = root->next;
    }
}

/* // A modifier
void calculate_new_addresses(caml_domain_state* state) {
    mlvalue* ptr = state->heap_start;
    mlvalue* end = state->heap_ptr;
    size_t live_size = 0;

    while (ptr < end) {
        header_t header = Hd_val(ptr);
        if (Color_hd(header) == BLACK) {
            size_t size = Size_hd(header);
            // Enregistrez la nouvelle adresse, par exemple dans un champ temporaire
            // ou dans une structure à part si nécessaire
            set_new_address(ptr, live_size);
            live_size += size + 1; // Incluez l'en-tête dans la taille totale
        }
        ptr += Size_hd(header) + 1;
    }
}

void update_pointers(caml_domain_state* state) {
    mlvalue* ptr = state->heap_start;
    mlvalue* end = state->heap_ptr;

    while (ptr < end) {
        header_t header = Hd_val(ptr);
        if (Color_hd(header) == BLACK) {
            for (int i = 0; i < Size_hd(header); i++) {
                mlvalue field = Field(ptr, i);
                if (Is_block(field)) {
                    Field(ptr, i) = get_new_address(field);
                }
            }
        }
        ptr += Size_hd(header) + 1;
    }
}

void compact_heap(caml_domain_state* state) {
    mlvalue* ptr = state->heap_start;
    mlvalue* end = state->heap_ptr;

    while (ptr < end) {
        header_t header = Hd_val(ptr);
        if (Color_hd(header) == BLACK) {
            size_t new_address = get_new_address(ptr);
            move_object(ptr, new_address);
        }
        ptr += Size_hd(header) + 1;
    }
}

*/


void gc_collect(caml_domain_state* state) {
    // Phase de marquage
    mark_roots(state);
    
    // D'autres phases du GC (Nettoyage, Compaction, etc.) suivront ici
}