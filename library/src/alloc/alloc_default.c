#include <fge/alloc.h>

static fge_alloc_t fge_alloc_default_instance = (fge_alloc_t){
    .new = malloc,
    .delete = free,
};

fge_alloc_cpt fge_alloc_default() {
    return &fge_alloc_default_instance;
}
