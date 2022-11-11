#ifndef FGE_STR_UTF8_H
#define FGE_STR_UTF8_H

#include <fge/alloc.h>
#include <fge/rng_idx.h>

FGE_TYPEDEF(fge_u8_t, fge_utf8_unit);

FGE_TYPEDEF_STRUCT(fge_utf8_buff);
FGE_TYPEDEF_STRUCT(fge_utf8);

struct fge_utf8_buff {
    fge_utf8_unit_cpt ptr;
    fge_sz_t count;
};

struct fge_utf8 {
    fge_alloc_cpt alloc;
    union {
        fge_utf8_unit_t chars[sizeof(fge_ptr_t)];
        fge_utf8_unit_pt ptr;
    };
    fge_sz_t count;
    fge_sz_t capacity;
};

extern fge_utf8_t fge_utf8(
    fge_alloc_cpt alloc
);

extern fge_utf8_t fge_utf8_with(
    fge_alloc_cpt alloc,
    fge_utf8_buff_t buff
);

extern fge_utf8_t fge_utf8_with_string(
    fge_alloc_cpt alloc,
    fge_utf8_cpt buff
);

extern void fge_utf8_free(
    fge_utf8_pt self
);

extern fge_bool_t fge_utf8_fit(
    fge_utf8_pt self
);

extern fge_utf8_unit_pt fge_utf8_pointer(
    fge_utf8_cpt self
);

extern fge_sz_t fge_utf8_length(
    fge_utf8_cpt self
);

extern fge_sz_t fge_utf8_count(
    fge_utf8_cpt self
);

extern fge_sz_t fge_utf8_capacity(
    fge_utf8_cpt self
);

extern fge_rng_idx_t fge_utf8_range(
    fge_utf8_cpt self
);

extern fge_idx_t fge_utf8_start_index(
    fge_utf8_cpt self
);

extern fge_idx_t fge_utf8_end_index(
    fge_utf8_cpt self
);

extern fge_bool_t fge_utf8_is_empty(
    fge_utf8_cpt self
);

extern fge_bool_t fge_utf8_is_not_empty(
    fge_utf8_cpt self
);

extern fge_bool_t fge_utf8_is_equal(
    fge_utf8_cpt self,
    fge_utf8_buff_t other
);

extern fge_bool_t fge_utf8_is_equal_string(
    fge_utf8_cpt self,
    fge_utf8_cpt other
);

extern fge_bool_t fge_utf8_is_prefix(
    fge_utf8_cpt self,
    fge_utf8_buff_t find
);

extern fge_bool_t fge_utf8_is_prefix_string(
    fge_utf8_cpt self,
    fge_utf8_cpt find
);

extern fge_bool_t fge_utf8_is_suffix(
    fge_utf8_cpt self,
    fge_utf8_buff_t find
);

extern fge_bool_t fge_utf8_is_suffix_string(
    fge_utf8_cpt self,
    fge_utf8_cpt find
);

extern fge_rng_idx_t fge_utf8_find_start(
    fge_utf8_cpt self,
    fge_rng_idx_t range,
    fge_utf8_buff_t find
);

extern fge_rng_idx_t fge_utf8_find_start_string(
    fge_utf8_cpt self,
    fge_rng_idx_t range,
    fge_utf8_cpt find
);

extern fge_rng_idx_t fge_utf8_find_end(
    fge_utf8_cpt self,
    fge_rng_idx_t range,
    fge_utf8_buff_t find
);

extern fge_rng_idx_t fge_utf8_find_end_string(
    fge_utf8_cpt self,
    fge_rng_idx_t range,
    fge_utf8_cpt find
);

extern fge_bool_t fge_utf8_insert(
    fge_utf8_pt self,
    fge_idx_t index,
    fge_utf8_buff_t insert
);

extern fge_bool_t fge_utf8_insert_string(
    fge_utf8_pt self,
    fge_idx_t index,
    fge_utf8_cpt insert
);

extern fge_bool_t fge_utf8_remove_range(
    fge_utf8_pt self,
    fge_rng_idx_t range
);

extern fge_bool_t fge_utf8_remove_first(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_buff_t find
);

extern fge_bool_t fge_utf8_remove_first_string(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_cpt find
);

extern fge_bool_t fge_utf8_remove_last(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_buff_t find
);

extern fge_bool_t fge_utf8_remove_last_string(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_cpt find
);

extern fge_sz_t fge_utf8_remove_all(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_buff_t find
);

extern fge_sz_t fge_utf8_remove_all_string(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_cpt find
);

extern fge_bool_t fge_utf8_replace_range(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_buff_t to
);

extern fge_bool_t fge_utf8_replace_range_string(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_cpt to
);

extern fge_bool_t fge_utf8_replace_first(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_buff_t find,
    fge_utf8_buff_t to
);

extern fge_bool_t fge_utf8_replace_first_string(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_cpt find,
    fge_utf8_cpt to
);

extern fge_bool_t fge_utf8_replace_last(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_buff_t find,
    fge_utf8_buff_t to
);

extern fge_bool_t fge_utf8_replace_last_string(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_cpt find,
    fge_utf8_cpt to
);

extern fge_sz_t fge_utf8_replace_all(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_buff_t find,
    fge_utf8_buff_t to
);

extern fge_sz_t fge_utf8_replace_all_string(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_cpt find,
    fge_utf8_cpt to
);

#endif
