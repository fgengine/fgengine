#ifndef FGE_ALLOC_H
#define FGE_ALLOC_H

#include <fge/std.h>

FGE_TYPEDEF_STRUCT(fge_alloc);

struct fge_alloc {
    fge_ptr_t (*new)(fge_sz_t);
    void (*delete)(fge_ptr_t);
};

extern fge_alloc_cpt fge_alloc_default();

extern fge_alloc_cpt fge_alloc_safe(
    fge_alloc_cpt alloc
);

#endif
