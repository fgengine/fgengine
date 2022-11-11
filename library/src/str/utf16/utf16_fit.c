#include "utf16.h"

fge_bool_t fge_utf16_fit(
    fge_utf16_pt self
) {
    if (self->capacity == 0) {
        return true;
    }
    fge_utf16_unit_cpt old_ptr = fge_utf16_pointer(self);
    if (self->count >= sizeof(fge_ptr_t)) {
        fge_sz_t new_count = self->count + 1;
        fge_utf16_unit_pt new_ptr = self->alloc->new(new_count * sizeof(fge_utf16_unit_t));
        if (new_ptr == NULL) {
            return false;
        }
        fge_mem_copy((fge_mem_t){
            .ptr = new_ptr,
            .count = new_count * sizeof(fge_utf16_unit_t)
        }, (fge_mem_t){
            .ptr = self->ptr,
            .count = self->capacity * sizeof(fge_utf16_unit_t)
        });
        self->ptr = new_ptr;
        self->capacity = new_count;
    } else {
        fge_mem_copy((fge_mem_t){
            .ptr = &self->chars,
            .count = self->count * sizeof(fge_utf16_unit_t)
        }, (fge_mem_t){
            .ptr = self->ptr,
            .count = self->capacity * sizeof(fge_utf16_unit_t)
        });
        self->capacity = 0;
    }
    self->alloc->delete((fge_ptr_t)old_ptr);
    return true;
}
