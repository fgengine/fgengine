#ifndef FGE_UTF32_STRING_H
#define FGE_UTF32_STRING_H

#include <fge/allocator.h>
#include <fge/index_range.h>

FGE_DEFINE_TYPE(uint32_t, fge_utf32_unit);
FGE_DEFINE_TYPE(struct fge_utf32_buffer, fge_utf32_buffer);
FGE_DEFINE_TYPE(struct fge_utf32, fge_utf32);

struct fge_utf32_buffer {
    fge_utf32_unit_cpt ptr;
    fge_size_t count;
};

struct fge_utf32 {
    fge_allocator_cpt allocator;
    union {
        fge_utf32_unit_t chars[sizeof(fge_ptr_t)];
        fge_utf32_unit_pt ptr;
    };
    fge_size_t count;
    fge_size_t capacity;
};

extern fge_utf32_t fge_utf32(
    fge_allocator_cpt allocator
);

extern fge_utf32_t fge_utf32_with(
    fge_allocator_cpt allocator,
    fge_utf32_buffer_t buffer
);

extern fge_utf32_t fge_utf32_with_string(
    fge_allocator_cpt allocator,
    fge_utf32_cpt buffer
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

extern fge_size_t fge_utf32_length(
    fge_utf32_cpt self
);

extern fge_size_t fge_utf32_count(
    fge_utf32_cpt self
);

extern fge_size_t fge_utf32_capacity(
    fge_utf32_cpt self
);

extern fge_index_range_t fge_utf32_range(
    fge_utf32_cpt self
);

extern fge_index_t fge_utf32_start_index(
    fge_utf32_cpt self
);

extern fge_index_t fge_utf32_end_index(
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
    fge_utf32_buffer_t other
);

extern fge_bool_t fge_utf32_is_equal_string(
    fge_utf32_cpt self,
    fge_utf32_cpt other
);

extern fge_bool_t fge_utf32_is_prefix(
    fge_utf32_cpt self,
    fge_utf32_buffer_t find
);

extern fge_bool_t fge_utf32_is_prefix_string(
    fge_utf32_cpt self,
    fge_utf32_cpt find
);

extern fge_bool_t fge_utf32_is_suffix(
    fge_utf32_cpt self,
    fge_utf32_buffer_t find
);

extern fge_bool_t fge_utf32_is_suffix_string(
    fge_utf32_cpt self,
    fge_utf32_cpt find
);

extern fge_index_range_t fge_utf32_find_start(
    fge_utf32_cpt self,
    fge_index_range_t range,
    fge_utf32_buffer_t find
);

extern fge_index_range_t fge_utf32_find_start_string(
    fge_utf32_cpt self,
    fge_index_range_t range,
    fge_utf32_cpt find
);

extern fge_index_range_t fge_utf32_find_end(
    fge_utf32_cpt self,
    fge_index_range_t range,
    fge_utf32_buffer_t find
);

extern fge_index_range_t fge_utf32_find_end_string(
    fge_utf32_cpt self,
    fge_index_range_t range,
    fge_utf32_cpt find
);

extern fge_bool_t fge_utf32_insert(
    fge_utf32_pt self,
    fge_index_t index,
    fge_utf32_buffer_t insert
);

extern fge_bool_t fge_utf32_insert_string(
    fge_utf32_pt self,
    fge_index_t index,
    fge_utf32_cpt insert
);

extern fge_bool_t fge_utf32_remove_range(
    fge_utf32_pt self,
    fge_index_range_t range
);

extern fge_bool_t fge_utf32_remove_first(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_buffer_t find
);

extern fge_bool_t fge_utf32_remove_first_string(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_cpt find
);

extern fge_bool_t fge_utf32_remove_last(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_buffer_t find
);

extern fge_bool_t fge_utf32_remove_last_string(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_cpt find
);

extern fge_size_t fge_utf32_remove_all(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_buffer_t find
);

extern fge_size_t fge_utf32_remove_all_string(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_cpt find
);

extern fge_bool_t fge_utf32_replace_range(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_buffer_t to
);

extern fge_bool_t fge_utf32_replace_range_string(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_cpt to
);

extern fge_bool_t fge_utf32_replace_first(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_buffer_t find,
    fge_utf32_buffer_t to
);

extern fge_bool_t fge_utf32_replace_first_string(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_cpt find,
    fge_utf32_cpt to
);

extern fge_bool_t fge_utf32_replace_last(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_buffer_t find,
    fge_utf32_buffer_t to
);

extern fge_bool_t fge_utf32_replace_last_string(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_cpt find,
    fge_utf32_cpt to
);

extern fge_size_t fge_utf32_replace_all(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_buffer_t find,
    fge_utf32_buffer_t to
);

extern fge_size_t fge_utf32_replace_all_string(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_cpt find,
    fge_utf32_cpt to
);

#endif
