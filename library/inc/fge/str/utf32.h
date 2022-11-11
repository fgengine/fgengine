#ifndef FGE_STR_UTF32_H
#define FGE_STR_UTF32_H

#include <fge/alloc.h>
#include <fge/rng_idx.h>

FGE_TYPEDEF(fge_u32_t, fge_utf32_unit);

FGE_TYPEDEF_STRUCT(fge_utf32_buff);
FGE_TYPEDEF_STRUCT(fge_utf32);

struct fge_utf32_buff {
    fge_utf32_unit_cpt ptr;
    fge_sz_t count;
};

struct fge_utf32 {
    fge_alloc_cpt alloc;
    union {
        fge_utf32_unit_t chars[sizeof(fge_ptr_t)];
        fge_utf32_unit_pt ptr;
    };
    fge_sz_t count;
    fge_sz_t capacity;
};

extern fge_utf32_t fge_utf32(
    fge_alloc_cpt alloc
);

extern fge_utf32_t fge_utf32_with(
    fge_alloc_cpt alloc,
    fge_utf32_buff_t buff
);

extern fge_utf32_t fge_utf32_with_string(
    fge_alloc_cpt alloc,
    fge_utf32_cpt buff
);

extern void fge_utf32_free(
    fge_utf32_pt self
);

extern fge_bool_t fge_utf32_fit(
    fge_utf32_pt self
);

extern fge_utf32_unit_pt fge_utf32_pointer(
    fge_utf32_cpt self
);

extern fge_sz_t fge_utf32_length(
    fge_utf32_cpt self
);

extern fge_sz_t fge_utf32_count(
    fge_utf32_cpt self
);

extern fge_sz_t fge_utf32_capacity(
    fge_utf32_cpt self
);

extern fge_rng_idx_t fge_utf32_range(
    fge_utf32_cpt self
);

extern fge_idx_t fge_utf32_start_index(
    fge_utf32_cpt self
);

extern fge_idx_t fge_utf32_end_index(
    fge_utf32_cpt self
);

extern fge_bool_t fge_utf32_is_empty(
    fge_utf32_cpt self
);

extern fge_bool_t fge_utf32_is_not_empty(
    fge_utf32_cpt self
);

extern fge_bool_t fge_utf32_is_equal(
    fge_utf32_cpt self,
    fge_utf32_buff_t other
);

extern fge_bool_t fge_utf32_is_equal_string(
    fge_utf32_cpt self,
    fge_utf32_cpt other
);

extern fge_bool_t fge_utf32_is_prefix(
    fge_utf32_cpt self,
    fge_utf32_buff_t find
);

extern fge_bool_t fge_utf32_is_prefix_string(
    fge_utf32_cpt self,
    fge_utf32_cpt find
);

extern fge_bool_t fge_utf32_is_suffix(
    fge_utf32_cpt self,
    fge_utf32_buff_t find
);

extern fge_bool_t fge_utf32_is_suffix_string(
    fge_utf32_cpt self,
    fge_utf32_cpt find
);

extern fge_rng_idx_t fge_utf32_find_start(
    fge_utf32_cpt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t find
);

extern fge_rng_idx_t fge_utf32_find_start_string(
    fge_utf32_cpt self,
    fge_rng_idx_t range,
    fge_utf32_cpt find
);

extern fge_rng_idx_t fge_utf32_find_end(
    fge_utf32_cpt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t find
);

extern fge_rng_idx_t fge_utf32_find_end_string(
    fge_utf32_cpt self,
    fge_rng_idx_t range,
    fge_utf32_cpt find
);

extern fge_bool_t fge_utf32_insert(
    fge_utf32_pt self,
    fge_idx_t index,
    fge_utf32_buff_t insert
);

extern fge_bool_t fge_utf32_insert_string(
    fge_utf32_pt self,
    fge_idx_t index,
    fge_utf32_cpt insert
);

extern fge_bool_t fge_utf32_remove_range(
    fge_utf32_pt self,
    fge_rng_idx_t range
);

extern fge_bool_t fge_utf32_remove_first(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t find
);

extern fge_bool_t fge_utf32_remove_first_string(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_cpt find
);

extern fge_bool_t fge_utf32_remove_last(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t find
);

extern fge_bool_t fge_utf32_remove_last_string(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_cpt find
);

extern fge_sz_t fge_utf32_remove_all(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t find
);

extern fge_sz_t fge_utf32_remove_all_string(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_cpt find
);

extern fge_bool_t fge_utf32_replace_range(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t to
);

extern fge_bool_t fge_utf32_replace_range_string(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_cpt to
);

extern fge_bool_t fge_utf32_replace_first(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t find,
    fge_utf32_buff_t to
);

extern fge_bool_t fge_utf32_replace_first_string(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_cpt find,
    fge_utf32_cpt to
);

extern fge_bool_t fge_utf32_replace_last(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t find,
    fge_utf32_buff_t to
);

extern fge_bool_t fge_utf32_replace_last_string(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_cpt find,
    fge_utf32_cpt to
);

extern fge_sz_t fge_utf32_replace_all(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t find,
    fge_utf32_buff_t to
);

extern fge_sz_t fge_utf32_replace_all_string(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_cpt find,
    fge_utf32_cpt to
);

#endif
