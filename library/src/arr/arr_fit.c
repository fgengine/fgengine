#include <fge/mem.h>
#include <fge/arr.h>

fge_bool_t fge_arr_fit(
    fge_arr_pt self
) {
    if (self->capacity == 0) {
        return true;
    }
    fge_ptr_t old_ptr = self->ptr;
    fge_sz_t size = self->count * self->element_size;
    fge_ptr_t new_ptr = self->alloc->new(size);
    if (new_ptr == NULL) {
        return false;
    }
    fge_mem_copy((fge_mem_t){
        .ptr = new_ptr,
        .count = size
    }, (fge_mem_t){
        .ptr = self->ptr,
        .count = size
    });
    self->ptr = new_ptr;
    self->capacity = size;
    self->alloc->delete(old_ptr);
    return true;
}
