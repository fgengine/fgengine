#ifndef FGE_arr_H
#define FGE_arr_H

#include <fge/alloc.h>
#include <fge/rng_idx.h>

FGE_TYPEDEF_STRUCT(fge_arr);

struct fge_arr {
    fge_alloc_cpt alloc;
    fge_sz_t element_size;
    fge_ptr_t ptr;
    fge_sz_t count;
    fge_sz_t capacity;
};

extern fge_arr_t fge_arr(
    fge_alloc_cpt alloc,
    fge_sz_t element_size
);

extern fge_arr_t fge_arr_with(
    fge_alloc_cpt alloc,
    fge_sz_t element_size,
    fge_ptr_t ptr,
    fge_sz_t count
);

extern fge_arr_t fge_arr_with_arr(
    fge_arr_cpt array
);

extern void fge_arr_free(
    fge_arr_pt self
);

extern fge_bool_t fge_arr_fit(
    fge_arr_pt self
);

extern fge_ptr_t fge_arr_pointer(
    fge_arr_cpt self
);

extern fge_sz_t fge_arr_length(
    fge_arr_cpt self
);

extern fge_sz_t fge_arr_element_size(
    fge_arr_cpt self
);

extern fge_sz_t fge_arr_count(
    fge_arr_cpt self
);

extern fge_sz_t fge_arr_capacity(
    fge_arr_cpt self
);

extern fge_rng_idx_t fge_arr_range(
    fge_arr_cpt self
);

extern fge_idx_t fge_arr_start_index(
    fge_arr_cpt self
);

extern fge_idx_t fge_arr_end_index(
    fge_arr_cpt self
);

extern fge_bool_t fge_arr_is_empty(
    fge_arr_cpt self
);

extern fge_bool_t fge_arr_is_not_empty(
    fge_arr_cpt self
);

extern fge_bool_t fge_arr_is_equal(
    fge_arr_cpt self,
    fge_ptr_t ptr,
    fge_sz_t count
);

extern fge_bool_t fge_arr_is_equal_arr(
    fge_arr_cpt self,
    fge_arr_cpt array
);

extern fge_rng_idx_t fge_arr_find_start(
    fge_arr_cpt self,
    fge_rng_idx_t range,
    fge_ptr_t ptr,
    fge_sz_t count
);

extern fge_rng_idx_t fge_arr_find_start_arr(
    fge_arr_cpt self,
    fge_rng_idx_t range,
    fge_arr_cpt array
);

extern fge_rng_idx_t fge_arr_find_end(
    fge_arr_cpt self,
    fge_rng_idx_t range,
    fge_ptr_t ptr,
    fge_sz_t count
);

extern fge_rng_idx_t fge_arr_find_end_arr(
    fge_arr_cpt self,
    fge_rng_idx_t range,
    fge_arr_cpt array
);

extern fge_bool_t fge_arr_insert(
    fge_arr_pt self,
    fge_idx_t index,
    fge_ptr_t ptr,
    fge_sz_t count
);

extern fge_bool_t fge_arr_insert_arr(
    fge_arr_pt self,
    fge_idx_t index,
    fge_arr_cpt array
);

extern void fge_arr_remove_all(
    fge_arr_pt self
);

extern fge_bool_t fge_arr_remove_range(
    fge_arr_pt self,
    fge_rng_idx_t range
);

extern fge_bool_t fge_arr_remove_first(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_ptr_t ptr,
    fge_sz_t count
);

extern fge_bool_t fge_arr_remove_first_arr(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_arr_cpt array
);

extern fge_bool_t fge_arr_remove_last(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_ptr_t ptr,
    fge_sz_t count
);

extern fge_bool_t fge_arr_remove_last_arr(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_arr_cpt array
);

extern fge_sz_t fge_arr_remove(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_ptr_t ptr,
    fge_sz_t count
);

extern fge_sz_t fge_arr_remove_arr(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_arr_cpt array
);

extern fge_bool_t fge_arr_replace_range(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_ptr_t ptr,
    fge_sz_t count
);

extern fge_bool_t fge_arr_replace_range_arr(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_arr_cpt array
);

extern fge_bool_t fge_arr_replace_first(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_ptr_t find_ptr,
    fge_sz_t find_count,
    fge_ptr_t replace_ptr,
    fge_sz_t replace_count
);

extern fge_bool_t fge_arr_replace_first_arr(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_arr_cpt find_arr,
    fge_arr_cpt replace_arr
);

extern fge_bool_t fge_arr_replace_last(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_ptr_t find_ptr,
    fge_sz_t find_count,
    fge_ptr_t replace_ptr,
    fge_sz_t replace_count
);

extern fge_bool_t fge_arr_replace_last_arr(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_arr_cpt find_arr,
    fge_arr_cpt replace_arr
);

extern fge_sz_t fge_arr_replace_all(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_ptr_t find_ptr,
    fge_sz_t find_count,
    fge_ptr_t replace_ptr,
    fge_sz_t replace_count
);

extern fge_sz_t fge_arr_replace_all_arr(
    fge_arr_pt self,
    fge_rng_idx_t range,
    fge_arr_cpt find_arr,
    fge_arr_cpt replace_arr
);

#endif
