#include <fge/memory.h>
#include <fge/array.h>

fge_bool_t fge_array_fit(
    fge_array_pt self
) {
    if (self->capacity == 0) {
        return true;
    }
    fge_ptr_t old_ptr = self->ptr;
    fge_size_t size = self->count * self->element_size;
    fge_ptr_t new_ptr = self->allocator->new(size);
    if (new_ptr == NULL) {
        return false;
    }
    fge_memory_copy((fge_memory_t){
        .ptr = new_ptr,
        .count = size
    }, (fge_memory_t){
        .ptr = self->ptr,
        .count = size
    });
    self->ptr = new_ptr;
    self->capacity = size;
    self->allocator->delete(old_ptr);
    return true;
}
