#include <fge/memory.h>
#include <fge/array.h>

fge_array_t fge_array(
    fge_allocator_cpt allocator,
    fge_size_t element_size
) {
    return (fge_array_t){
        .allocator = fge_allocator_safe(allocator),
        .element_size = element_size,
        .ptr = NULL,
        .count = 0,
        .capacity = 0
    };
}

fge_array_t fge_array_with(
    fge_allocator_cpt allocator,
    fge_size_t element_size,
    fge_ptr_t ptr,
    fge_size_t count
) {
    fge_array_t self = fge_array(allocator, element_size);
    fge_size_t size = element_size * count;
    self.ptr = self.allocator->new(size);
    if (self.ptr != NULL) {
        fge_memory_copy((fge_memory_t){
            .ptr = self.ptr,
            .count = size
        }, (fge_memory_t){
            .ptr = ptr,
            .count = size
        });
        self.count = count;
        self.capacity = count;
    }
    return self;
}

fge_array_t fge_array_with_array(
    fge_array_cpt array
) {
    fge_array_t self = fge_array(array->allocator, array->element_size);
    self.ptr = self.allocator->new(array->capacity);
    if (self.ptr != NULL) {
        fge_size_t size = array->element_size * array->count;
        fge_memory_copy((fge_memory_t){
            .ptr = self.ptr,
            .count = size
        }, (fge_memory_t){
            .ptr = array->ptr,
            .count = size
        });
        self.count = array->count;
        self.capacity = array->capacity;
    }
    return self;
}
