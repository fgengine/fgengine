#ifndef FGE_MEM_H
#define FGE_MEM_H

#include <fge/rng_idx.h>

FGE_TYPEDEF_STRUCT(fge_mem);

struct fge_mem {
    fge_ptr_t ptr;
    fge_sz_t count;
};

extern fge_sz_t fge_mem_fill(
    fge_mem_t dst,
    fge_mem_t fill
);

extern fge_sz_t fge_mem_copy(
    fge_mem_t dst,
    fge_mem_t src
);

extern fge_sz_t fge_mem_copy_fill(
    fge_mem_t dst,
    fge_mem_t src,
    fge_mem_t fill
);

extern fge_sz_t fge_mem_copy_repeat(
    fge_mem_t dst,
    fge_mem_t src,
    fge_sz_t repeat
);

extern fge_sz_t fge_mem_move(
    fge_mem_t dst,
    fge_mem_t src
);

extern fge_bool_t fge_mem_is_equal(
    fge_mem_t lhs,
    fge_mem_t rhs
);

extern fge_rng_idx_t fge_mem_find_forward(
    fge_mem_t memory,
    fge_mem_t find,
    fge_rng_idx_ct range
);

extern fge_rng_idx_t fge_mem_find_backward(
    fge_mem_t memory,
    fge_mem_t find,
    fge_rng_idx_ct range
);

#endif
