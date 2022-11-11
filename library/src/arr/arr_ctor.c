#include <fge/mem.h>
#include <fge/arr.h>

fge_arr_t fge_arr(
    fge_alloc_cpt alloc,
    fge_sz_t element_size
) {
    return (fge_arr_t){
        .alloc = fge_alloc_safe(alloc),
        .element_size = element_size,
        .ptr = NULL,
        .count = 0,
        .capacity = 0
    };
}

fge_arr_t fge_arr_with(
    fge_alloc_cpt alloc,
    fge_sz_t element_size,
    fge_ptr_t ptr,
    fge_sz_t count
) {
    fge_arr_t self = fge_arr(alloc, element_size);
    fge_sz_t size = element_size * count;
    self.ptr = self.alloc->new(size);
    if (self.ptr != NULL) {
        fge_mem_copy((fge_mem_t){
            .ptr = self.ptr,
            .count = size
        }, (fge_mem_t){
            .ptr = ptr,
            .count = size
        });
        self.count = count;
        self.capacity = count;
    }
    return self;
}

fge_arr_t fge_arr_with_arr(
    fge_arr_cpt array
) {
    fge_arr_t self = fge_arr(array->alloc, array->element_size);
    self.ptr = self.alloc->new(array->capacity);
    if (self.ptr != NULL) {
        fge_sz_t size = array->element_size * array->count;
        fge_mem_copy((fge_mem_t){
            .ptr = self.ptr,
            .count = size
        }, (fge_mem_t){
            .ptr = array->ptr,
            .count = size
        });
        self.count = array->count;
        self.capacity = array->capacity;
    }
    return self;
}
