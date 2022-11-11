#ifndef FGE_STR_UTF16_H
#define FGE_STR_UTF16_H

#include <fge/alloc.h>
#include <fge/rng_idx.h>

FGE_TYPEDEF(fge_u16_t, fge_utf16_unit);

FGE_TYPEDEF_STRUCT(fge_utf16_buff);
FGE_TYPEDEF_STRUCT(fge_utf16);

struct fge_utf16_buff {
    fge_utf16_unit_cpt ptr;
    fge_sz_t count;
};

struct fge_utf16 {
    fge_alloc_cpt alloc;
    union {
        fge_utf16_unit_t chars[sizeof(fge_ptr_t)];
        fge_utf16_unit_pt ptr;
    };
    fge_sz_t count;
    fge_sz_t capacity;
};

extern fge_utf16_t fge_utf16(
    fge_alloc_cpt alloc
);

extern fge_utf16_t fge_utf16_with(
    fge_alloc_cpt alloc,
    fge_utf16_buff_t buff
);

extern fge_utf16_t fge_utf16_with_string(
    fge_alloc_cpt alloc,
    fge_utf16_cpt buff
);

extern void fge_utf16_free(
    fge_utf16_pt self
);

extern fge_bool_t fge_utf16_fit(
    fge_utf16_pt self
);

extern fge_utf16_unit_pt fge_utf16_pointer(
    fge_utf16_cpt self
);

extern fge_sz_t fge_utf16_length(
    fge_utf16_cpt self
);

extern fge_sz_t fge_utf16_count(
    fge_utf16_cpt self
);

extern fge_sz_t fge_utf16_capacity(
    fge_utf16_cpt self
);

extern fge_rng_idx_t fge_utf16_range(
    fge_utf16_cpt self
);

extern fge_idx_t fge_utf16_start_index(
    fge_utf16_cpt self
);

extern fge_idx_t fge_utf16_end_index(
    fge_utf16_cpt self
);

extern fge_bool_t fge_utf16_is_empty(
    fge_utf16_cpt self
);

extern fge_bool_t fge_utf16_is_not_empty(
    fge_utf16_cpt self
);

extern fge_bool_t fge_utf16_is_equal(
    fge_utf16_cpt self,
    fge_utf16_buff_t other
);

extern fge_bool_t fge_utf16_is_equal_string(
    fge_utf16_cpt self,
    fge_utf16_cpt other
);

extern fge_bool_t fge_utf16_is_prefix(
    fge_utf16_cpt self,
    fge_utf16_buff_t find
);

extern fge_bool_t fge_utf16_is_prefix_string(
    fge_utf16_cpt self,
    fge_utf16_cpt find
);

extern fge_bool_t fge_utf16_is_suffix(
    fge_utf16_cpt self,
    fge_utf16_buff_t find
);

extern fge_bool_t fge_utf16_is_suffix_string(
    fge_utf16_cpt self,
    fge_utf16_cpt find
);

extern fge_rng_idx_t fge_utf16_find_start(
    fge_utf16_cpt self,
    fge_rng_idx_t range,
    fge_utf16_buff_t find
);

extern fge_rng_idx_t fge_utf16_find_start_string(
    fge_utf16_cpt self,
    fge_rng_idx_t range,
    fge_utf16_cpt find
);

extern fge_rng_idx_t fge_utf16_find_end(
    fge_utf16_cpt self,
    fge_rng_idx_t range,
    fge_utf16_buff_t find
);

extern fge_rng_idx_t fge_utf16_find_end_string(
    fge_utf16_cpt self,
    fge_rng_idx_t range,
    fge_utf16_cpt find
);

extern fge_bool_t fge_utf16_insert(
    fge_utf16_pt self,
    fge_idx_t index,
    fge_utf16_buff_t insert
);

extern fge_bool_t fge_utf16_insert_string(
    fge_utf16_pt self,
    fge_idx_t index,
    fge_utf16_cpt insert
);

extern fge_bool_t fge_utf16_remove_range(
    fge_utf16_pt self,
    fge_rng_idx_t range
);

extern fge_bool_t fge_utf16_remove_first(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_buff_t find
);

extern fge_bool_t fge_utf16_remove_first_string(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_cpt find
);

extern fge_bool_t fge_utf16_remove_last(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_buff_t find
);

extern fge_bool_t fge_utf16_remove_last_string(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_cpt find
);

extern fge_sz_t fge_utf16_remove_all(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_buff_t find
);

extern fge_sz_t fge_utf16_remove_all_string(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_cpt find
);

extern fge_bool_t fge_utf16_replace_range(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_buff_t to
);

extern fge_bool_t fge_utf16_replace_range_string(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_cpt to
);

extern fge_bool_t fge_utf16_replace_first(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_buff_t find,
    fge_utf16_buff_t to
);

extern fge_bool_t fge_utf16_replace_first_string(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_cpt find,
    fge_utf16_cpt to
);

extern fge_bool_t fge_utf16_replace_last(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_buff_t find,
    fge_utf16_buff_t to
);

extern fge_bool_t fge_utf16_replace_last_string(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_cpt find,
    fge_utf16_cpt to
);

extern fge_sz_t fge_utf16_replace_all(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_buff_t find,
    fge_utf16_buff_t to
);

extern fge_sz_t fge_utf16_replace_all_string(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_cpt find,
    fge_utf16_cpt to
);

#endif
