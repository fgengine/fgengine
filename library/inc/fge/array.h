#ifndef FGE_ARRAY_H
#define FGE_ARRAY_H

#include <fge/allocator.h>
#include <fge/index_range.h>

FGE_DEFINE_TYPE(struct fge_array, fge_array);

struct fge_array {
    fge_allocator_cpt allocator;
    fge_size_t element_size;
    fge_ptr_t ptr;
    fge_size_t count;
    fge_size_t capacity;
};

extern fge_array_t fge_array(
    fge_allocator_cpt allocator,
    fge_size_t element_size
);

extern fge_array_t fge_array_with(
    fge_allocator_cpt allocator,
    fge_size_t element_size,
    fge_ptr_t ptr,
    fge_size_t count
);

extern fge_array_t fge_array_with_array(
    fge_array_cpt array
);

extern void fge_array_free(
    fge_array_pt self
);

extern fge_bool_t fge_array_fit(
    fge_array_pt self
);

extern fge_ptr_t fge_array_pointer(
    fge_array_cpt self
);

extern fge_size_t fge_array_length(
    fge_array_cpt self
);

extern fge_size_t fge_array_element_size(
    fge_array_cpt self
);

extern fge_size_t fge_array_count(
    fge_array_cpt self
);

extern fge_size_t fge_array_capacity(
    fge_array_cpt self
);

extern fge_index_range_t fge_array_range(
    fge_array_cpt self
);

extern fge_index_t fge_array_start_index(
    fge_array_cpt self
);

extern fge_index_t fge_array_end_index(
    fge_array_cpt self
);

extern fge_bool_t fge_array_is_empty(
    fge_array_cpt self
);

extern fge_bool_t fge_array_is_not_empty(
    fge_array_cpt self
);

extern fge_bool_t fge_array_is_equal(
    fge_array_cpt self,
    fge_ptr_t ptr,
    fge_size_t count
);

extern fge_bool_t fge_array_is_equal_array(
    fge_array_cpt self,
    fge_array_cpt array
);

extern fge_index_range_t fge_array_find_start(
    fge_array_cpt self,
    fge_index_range_t range,
    fge_ptr_t ptr,
    fge_size_t count
);

extern fge_index_range_t fge_array_find_start_array(
    fge_array_cpt self,
    fge_index_range_t range,
    fge_array_cpt array
);

extern fge_index_range_t fge_array_find_end(
    fge_array_cpt self,
    fge_index_range_t range,
    fge_ptr_t ptr,
    fge_size_t count
);

extern fge_index_range_t fge_array_find_end_array(
    fge_array_cpt self,
    fge_index_range_t range,
    fge_array_cpt array
);

extern fge_bool_t fge_array_insert(
    fge_array_pt self,
    fge_index_t index,
    fge_ptr_t ptr,
    fge_size_t count
);

extern fge_bool_t fge_array_insert_array(
    fge_array_pt self,
    fge_index_t index,
    fge_array_cpt array
);

extern void fge_array_remove_all(
    fge_array_pt self
);

extern fge_bool_t fge_array_remove_range(
    fge_array_pt self,
    fge_index_range_t range
);

extern fge_bool_t fge_array_remove_first(
    fge_array_pt self,
    fge_index_range_t range,
    fge_ptr_t ptr,
    fge_size_t count
);

extern fge_bool_t fge_array_remove_first_array(
    fge_array_pt self,
    fge_index_range_t range,
    fge_array_cpt array
);

extern fge_bool_t fge_array_remove_last(
    fge_array_pt self,
    fge_index_range_t range,
    fge_ptr_t ptr,
    fge_size_t count
);

extern fge_bool_t fge_array_remove_last_array(
    fge_array_pt self,
    fge_index_range_t range,
    fge_array_cpt array
);

extern fge_size_t fge_array_remove(
    fge_array_pt self,
    fge_index_range_t range,
    fge_ptr_t ptr,
    fge_size_t count
);

extern fge_size_t fge_array_remove_array(
    fge_array_pt self,
    fge_index_range_t range,
    fge_array_cpt array
);

extern fge_bool_t fge_array_replace_range(
    fge_array_pt self,
    fge_index_range_t range,
    fge_ptr_t ptr,
    fge_size_t count
);

extern fge_bool_t fge_array_replace_range_array(
    fge_array_pt self,
    fge_index_range_t range,
    fge_array_cpt array
);

extern fge_bool_t fge_array_replace_first(
    fge_array_pt self,
    fge_index_range_t range,
    fge_ptr_t find_ptr,
    fge_size_t find_count,
    fge_ptr_t replace_ptr,
    fge_size_t replace_count
);

extern fge_bool_t fge_array_replace_first_array(
    fge_array_pt self,
    fge_index_range_t range,
    fge_array_cpt find_array,
    fge_array_cpt replace_array
);

extern fge_bool_t fge_array_replace_last(
    fge_array_pt self,
    fge_index_range_t range,
    fge_ptr_t find_ptr,
    fge_size_t find_count,
    fge_ptr_t replace_ptr,
    fge_size_t replace_count
);

extern fge_bool_t fge_array_replace_last_array(
    fge_array_pt self,
    fge_index_range_t range,
    fge_array_cpt find_array,
    fge_array_cpt replace_array
);

extern fge_size_t fge_array_replace_all(
    fge_array_pt self,
    fge_index_range_t range,
    fge_ptr_t find_ptr,
    fge_size_t find_count,
    fge_ptr_t replace_ptr,
    fge_size_t replace_count
);

extern fge_size_t fge_array_replace_all_array(
    fge_array_pt self,
    fge_index_range_t range,
    fge_array_cpt find_array,
    fge_array_cpt replace_array
);

#endif
