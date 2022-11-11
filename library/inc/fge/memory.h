#ifndef FGE_MEMORY_H
#define FGE_MEMORY_H

#include <fge/index_range.h>

FGE_DEFINE_TYPE(struct fge_memory, fge_memory);

struct fge_memory {
    fge_ptr_t ptr;
    fge_size_t count;
};

extern fge_size_t fge_memory_fill(
    fge_memory_t dst,
    fge_memory_t fill
);

extern fge_size_t fge_memory_copy(
    fge_memory_t dst,
    fge_memory_t src
);

extern fge_size_t fge_memory_copy_fill(
    fge_memory_t dst,
    fge_memory_t src,
    fge_memory_t fill
);

extern fge_size_t fge_memory_copy_repeat(
    fge_memory_t dst,
    fge_memory_t src,
    fge_size_t repeat
);

extern fge_size_t fge_memory_move(
    fge_memory_t dst,
    fge_memory_t src
);

extern fge_bool_t fge_memory_is_equal(
    fge_memory_t lhs,
    fge_memory_t rhs
);

extern fge_index_range_t fge_memory_find_forward(
    fge_memory_t memory,
    fge_memory_t find,
    fge_index_range_ct range
);

extern fge_index_range_t fge_memory_find_backward(
    fge_memory_t memory,
    fge_memory_t find,
    fge_index_range_ct range
);

#endif
