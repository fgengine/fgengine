#include <fge/allocator.h>

static fge_allocator_t fge_allocator_default_instance = (fge_allocator_t){
    .new = malloc,
    .delete = free,
};

fge_allocator_cpt fge_allocator_default() {
    return &fge_allocator_default_instance;
}
