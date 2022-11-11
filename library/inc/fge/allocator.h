#ifndef FGE_ALLOCATOR_H
#define FGE_ALLOCATOR_H

#include <fge/types.h>

FGE_DEFINE_TYPE(struct fge_allocator, fge_allocator);

struct fge_allocator {
    fge_ptr_t (*new)(fge_size_t);
    void (*delete)(fge_ptr_t);
};

extern fge_allocator_cpt fge_allocator_default();

extern fge_allocator_cpt fge_allocator_safe(
    fge_allocator_cpt allocator
);

#endif
