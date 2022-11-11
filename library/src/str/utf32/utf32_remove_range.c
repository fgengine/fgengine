#include "utf32.h"

fge_bool_t fge_utf32_remove_range(
    fge_utf32_pt self,
    fge_rng_idx_t range
) {
    fge_sz_t lower = (range.lower < self->count) ? range.lower : self->count;
    fge_sz_t upper = (range.upper < self->count) ? range.upper : self->count;
    if (lower >= upper) {
        return false;
    }
    fge_utf32_unit_cpt old_ptr = fge_utf32_pointer(self);
    fge_sz_t delta = upper - lower;
    if (self->capacity > 0) {
        fge_sz_t new_capacity = FGE_STR_CALCULATE_CAPACITY(self->count);
        fge_utf32_unit_pt new_ptr = self->alloc->new(new_capacity);
        if (new_ptr == NULL) {
            return false;
        }
        if (lower > 0) {
            fge_mem_copy((fge_mem_t){
                .ptr = new_ptr,
                .count = lower * sizeof(fge_utf32_unit_t)
            }, (fge_mem_t){
                .ptr = (fge_ptr_t)old_ptr,
                .count = lower * sizeof(fge_utf32_unit_t)
            });
        }
        if (upper < self->count) {
            fge_mem_copy((fge_mem_t){
                .ptr = &new_ptr[lower],
                .count = (self->count - upper) * sizeof(fge_utf32_unit_t)
            }, (fge_mem_t){
                .ptr = (fge_ptr_t)&old_ptr[upper],
                .count = (self->count - upper) * sizeof(fge_utf32_unit_t)
            });
        }
        self->ptr = new_ptr;
        self->capacity = new_capacity;
    } else {
        fge_mem_move((fge_mem_t){
            .ptr = (fge_ptr_t)&old_ptr[lower],
            .count = ((sizeof(fge_ptr_t) - upper) + 1) * sizeof(fge_utf32_unit_t)
        }, (fge_mem_t){
            .ptr = (fge_ptr_t)&old_ptr[upper],
            .count = ((sizeof(fge_ptr_t) - upper) + 1) * sizeof(fge_utf32_unit_t)
        });
    }
    self->count -= delta;
    return true;
}
