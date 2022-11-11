#include "utf32.h"

fge_bool_t fge_utf32_fit(
    fge_utf32_pt self
) {
    if (self->capacity == 0) {
        return true;
    }
    fge_utf32_unit_cpt old_ptr = fge_utf32_pointer(self);
    if (self->count >= sizeof(fge_ptr_t)) {
        fge_sz_t new_count = self->count + 1;
        fge_utf32_unit_pt new_ptr = self->alloc->new(new_count * sizeof(fge_utf32_unit_t));
        if (new_ptr == NULL) {
            return false;
        }
        fge_mem_copy((fge_mem_t){
            .ptr = new_ptr,
            .count = new_count * sizeof(fge_utf32_unit_t)
        }, (fge_mem_t){
            .ptr = self->ptr,
            .count = self->capacity * sizeof(fge_utf32_unit_t)
        });
        self->ptr = new_ptr;
        self->capacity = new_count;
    } else {
        fge_mem_copy((fge_mem_t){
            .ptr = &self->chars,
            .count = self->count * sizeof(fge_utf32_unit_t)
        }, (fge_mem_t){
            .ptr = self->ptr,
            .count = self->capacity * sizeof(fge_utf32_unit_t)
        });
        self->capacity = 0;
    }
    self->alloc->delete((fge_ptr_t)old_ptr);
    return true;
}
