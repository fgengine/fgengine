#ifndef FGE_UTF8_STRING_H
#define FGE_UTF8_STRING_H

#include <fge/allocator.h>
#include <fge/index_range.h>

FGE_DEFINE_TYPE(uint8_t, fge_utf8_unit);
FGE_DEFINE_TYPE(struct fge_utf8_buffer, fge_utf8_buffer);
FGE_DEFINE_TYPE(struct fge_utf8, fge_utf8);

struct fge_utf8_buffer {
    fge_utf8_unit_cpt ptr;
    fge_size_t count;
};

struct fge_utf8 {
    fge_allocator_cpt allocator;
    union {
        fge_utf8_unit_t chars[sizeof(fge_ptr_t)];
        fge_utf8_unit_pt ptr;
    };
    fge_size_t count;
    fge_size_t capacity;
};

extern fge_utf8_t fge_utf8(
    fge_allocator_cpt allocator
);

extern fge_utf8_t fge_utf8_with(
    fge_allocator_cpt allocator,
    fge_utf8_buffer_t buffer
);

extern fge_utf8_t fge_utf8_with_string(
    fge_allocator_cpt allocator,
    fge_utf8_cpt buffer
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

extern fge_size_t fge_utf8_length(
    fge_utf8_cpt self
);

extern fge_size_t fge_utf8_count(
    fge_utf8_cpt self
);

extern fge_size_t fge_utf8_capacity(
    fge_utf8_cpt self
);

extern fge_index_range_t fge_utf8_range(
    fge_utf8_cpt self
);

extern fge_index_t fge_utf8_start_index(
    fge_utf8_cpt self
);

extern fge_index_t fge_utf8_end_index(
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
    fge_utf8_buffer_t other
);

extern fge_bool_t fge_utf8_is_equal_string(
    fge_utf8_cpt self,
    fge_utf8_cpt other
);

extern fge_bool_t fge_utf8_is_prefix(
    fge_utf8_cpt self,
    fge_utf8_buffer_t find
);

extern fge_bool_t fge_utf8_is_prefix_string(
    fge_utf8_cpt self,
    fge_utf8_cpt find
);

extern fge_bool_t fge_utf8_is_suffix(
    fge_utf8_cpt self,
    fge_utf8_buffer_t find
);

extern fge_bool_t fge_utf8_is_suffix_string(
    fge_utf8_cpt self,
    fge_utf8_cpt find
);

extern fge_index_range_t fge_utf8_find_start(
    fge_utf8_cpt self,
    fge_index_range_t range,
    fge_utf8_buffer_t find
);

extern fge_index_range_t fge_utf8_find_start_string(
    fge_utf8_cpt self,
    fge_index_range_t range,
    fge_utf8_cpt find
);

extern fge_index_range_t fge_utf8_find_end(
    fge_utf8_cpt self,
    fge_index_range_t range,
    fge_utf8_buffer_t find
);

extern fge_index_range_t fge_utf8_find_end_string(
    fge_utf8_cpt self,
    fge_index_range_t range,
    fge_utf8_cpt find
);

extern fge_bool_t fge_utf8_insert(
    fge_utf8_pt self,
    fge_index_t index,
    fge_utf8_buffer_t insert
);

extern fge_bool_t fge_utf8_insert_string(
    fge_utf8_pt self,
    fge_index_t index,
    fge_utf8_cpt insert
);

extern fge_bool_t fge_utf8_remove_range(
    fge_utf8_pt self,
    fge_index_range_t range
);

extern fge_bool_t fge_utf8_remove_first(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_buffer_t find
);

extern fge_bool_t fge_utf8_remove_first_string(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_cpt find
);

extern fge_bool_t fge_utf8_remove_last(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_buffer_t find
);

extern fge_bool_t fge_utf8_remove_last_string(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_cpt find
);

extern fge_size_t fge_utf8_remove_all(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_buffer_t find
);

extern fge_size_t fge_utf8_remove_all_string(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_cpt find
);

extern fge_bool_t fge_utf8_replace_range(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_buffer_t to
);

extern fge_bool_t fge_utf8_replace_range_string(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_cpt to
);

extern fge_bool_t fge_utf8_replace_first(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_buffer_t find,
    fge_utf8_buffer_t to
);

extern fge_bool_t fge_utf8_replace_first_string(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_cpt find,
    fge_utf8_cpt to
);

extern fge_bool_t fge_utf8_replace_last(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_buffer_t find,
    fge_utf8_buffer_t to
);

extern fge_bool_t fge_utf8_replace_last_string(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_cpt find,
    fge_utf8_cpt to
);

extern fge_size_t fge_utf8_replace_all(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_buffer_t find,
    fge_utf8_buffer_t to
);

extern fge_size_t fge_utf8_replace_all_string(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_cpt find,
    fge_utf8_cpt to
);

#endif
