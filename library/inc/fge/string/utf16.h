#ifndef FGE_UTF16_STRING_H
#define FGE_UTF16_STRING_H

#include <fge/allocator.h>
#include <fge/index_range.h>

FGE_DEFINE_TYPE(uint16_t, fge_utf16_unit);
FGE_DEFINE_TYPE(struct fge_utf16_buffer, fge_utf16_buffer);
FGE_DEFINE_TYPE(struct fge_utf16, fge_utf16);

struct fge_utf16_buffer {
    fge_utf16_unit_cpt ptr;
    fge_size_t count;
};

struct fge_utf16 {
    fge_allocator_cpt allocator;
    union {
        fge_utf16_unit_t chars[sizeof(fge_ptr_t)];
        fge_utf16_unit_pt ptr;
    };
    fge_size_t count;
    fge_size_t capacity;
};

extern fge_utf16_t fge_utf16(
    fge_allocator_cpt allocator
);

extern fge_utf16_t fge_utf16_with(
    fge_allocator_cpt allocator,
    fge_utf16_buffer_t buffer
);

extern fge_utf16_t fge_utf16_with_string(
    fge_allocator_cpt allocator,
    fge_utf16_cpt buffer
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

extern fge_size_t fge_utf16_length(
    fge_utf16_cpt self
);

extern fge_size_t fge_utf16_count(
    fge_utf16_cpt self
);

extern fge_size_t fge_utf16_capacity(
    fge_utf16_cpt self
);

extern fge_index_range_t fge_utf16_range(
    fge_utf16_cpt self
);

extern fge_index_t fge_utf16_start_index(
    fge_utf16_cpt self
);

extern fge_index_t fge_utf16_end_index(
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
    fge_utf16_buffer_t other
);

extern fge_bool_t fge_utf16_is_equal_string(
    fge_utf16_cpt self,
    fge_utf16_cpt other
);

extern fge_bool_t fge_utf16_is_prefix(
    fge_utf16_cpt self,
    fge_utf16_buffer_t find
);

extern fge_bool_t fge_utf16_is_prefix_string(
    fge_utf16_cpt self,
    fge_utf16_cpt find
);

extern fge_bool_t fge_utf16_is_suffix(
    fge_utf16_cpt self,
    fge_utf16_buffer_t find
);

extern fge_bool_t fge_utf16_is_suffix_string(
    fge_utf16_cpt self,
    fge_utf16_cpt find
);

extern fge_index_range_t fge_utf16_find_start(
    fge_utf16_cpt self,
    fge_index_range_t range,
    fge_utf16_buffer_t find
);

extern fge_index_range_t fge_utf16_find_start_string(
    fge_utf16_cpt self,
    fge_index_range_t range,
    fge_utf16_cpt find
);

extern fge_index_range_t fge_utf16_find_end(
    fge_utf16_cpt self,
    fge_index_range_t range,
    fge_utf16_buffer_t find
);

extern fge_index_range_t fge_utf16_find_end_string(
    fge_utf16_cpt self,
    fge_index_range_t range,
    fge_utf16_cpt find
);

extern fge_bool_t fge_utf16_insert(
    fge_utf16_pt self,
    fge_index_t index,
    fge_utf16_buffer_t insert
);

extern fge_bool_t fge_utf16_insert_string(
    fge_utf16_pt self,
    fge_index_t index,
    fge_utf16_cpt insert
);

extern fge_bool_t fge_utf16_remove_range(
    fge_utf16_pt self,
    fge_index_range_t range
);

extern fge_bool_t fge_utf16_remove_first(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_buffer_t find
);

extern fge_bool_t fge_utf16_remove_first_string(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_cpt find
);

extern fge_bool_t fge_utf16_remove_last(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_buffer_t find
);

extern fge_bool_t fge_utf16_remove_last_string(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_cpt find
);

extern fge_size_t fge_utf16_remove_all(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_buffer_t find
);

extern fge_size_t fge_utf16_remove_all_string(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_cpt find
);

extern fge_bool_t fge_utf16_replace_range(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_buffer_t to
);

extern fge_bool_t fge_utf16_replace_range_string(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_cpt to
);

extern fge_bool_t fge_utf16_replace_first(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_buffer_t find,
    fge_utf16_buffer_t to
);

extern fge_bool_t fge_utf16_replace_first_string(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_cpt find,
    fge_utf16_cpt to
);

extern fge_bool_t fge_utf16_replace_last(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_buffer_t find,
    fge_utf16_buffer_t to
);

extern fge_bool_t fge_utf16_replace_last_string(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_cpt find,
    fge_utf16_cpt to
);

extern fge_size_t fge_utf16_replace_all(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_buffer_t find,
    fge_utf16_buffer_t to
);

extern fge_size_t fge_utf16_replace_all_string(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_cpt find,
    fge_utf16_cpt to
);

#endif
