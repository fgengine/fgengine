#include "utf32.h"

fge_bool_t fge_utf32_insert(
    fge_utf32_pt self,
    fge_idx_t index,
    fge_utf32_buff_t insert
) {
    if (fge_utf32_is_empty(self) == true) {
        *self = fge_utf32_with(self->alloc, insert);
        return fge_utf32_is_not_empty(self);
    }
    fge_sz_t insert_index = (index <= self->count) ? index : self->count - 1;
    fge_sz_t new_count = self->count + insert.count;
    fge_utf32_unit_cpt old_ptr = fge_utf32_pointer(self);
    fge_sz_t old_capacity = (self->capacity > 0) ? self->count : sizeof(fge_ptr_t);
    if ((self->capacity > 0) || (new_count >= self->capacity)) {
        fge_sz_t new_capacity = FGE_STR_CALCULATE_CAPACITY(new_count);
        fge_utf32_unit_pt new_ptr = self->alloc->new(new_capacity);
        if (new_ptr != NULL) {
            fge_sz_t offset = 0;
            if (insert_index > 0) {
                offset += fge_mem_copy((fge_mem_t){
                    .ptr = new_ptr,
                    .count = new_capacity * sizeof(fge_utf32_unit_t)
                }, (fge_mem_t){
                    .ptr = (fge_ptr_t)old_ptr,
                    .count = insert_index * sizeof(fge_utf32_unit_t)
                });
            }
            offset += fge_mem_copy((fge_mem_t){
                .ptr = &new_ptr[insert_index],
                .count = (new_capacity - offset) * sizeof(fge_utf32_unit_t)
            }, (fge_mem_t){
                .ptr = (fge_ptr_t)insert.ptr,
                .count = insert.count * sizeof(fge_utf32_unit_t)
            });
            fge_mem_copy_fill((fge_mem_t){
                .ptr = &new_ptr[insert_index + insert.count],
                .count = (new_capacity - offset) * sizeof(fge_utf32_unit_t)
            }, (fge_mem_t){
                .ptr = (fge_ptr_t)&old_ptr[insert_index],
                .count = (old_capacity - insert_index) * sizeof(fge_utf32_unit_t)
            }, (fge_mem_t){
                .ptr = (fge_ptr_t)&FGE_STR_NULL_CHARS,
                .count = sizeof(fge_utf32_unit_t)
            });
            if (self->capacity > 0) {
                self->alloc->delete(self->ptr);
            }
            self->ptr = new_ptr;
            self->count = new_count;
            self->capacity = new_capacity;
        }
    } else {
        if (insert_index < self->count) {
            fge_mem_move((fge_mem_t){
                .ptr = (fge_ptr_t)(&old_ptr[insert_index + insert.count]),
                .count = (old_capacity - insert.count) * sizeof(fge_utf32_unit_t)
            }, (fge_mem_t){
                .ptr = (fge_ptr_t)&old_ptr[insert_index],
                .count = (old_capacity - insert.count) * sizeof(fge_utf32_unit_t)
            });
        }
        fge_mem_copy((fge_mem_t){
            .ptr = (fge_ptr_t)&old_ptr[insert_index],
            .count = insert.count * sizeof(fge_utf32_unit_t)
        }, (fge_mem_t){
            .ptr = (fge_ptr_t)insert.ptr,
            .count = insert.count * sizeof(fge_utf32_unit_t)
        });
        self->count = new_count;
    }
    return self->count == new_count;
}

fge_bool_t fge_utf32_insert_string(
    fge_utf32_pt self,
    fge_idx_t index,
    fge_utf32_cpt string
) {
    return fge_utf32_insert(self, index, (fge_utf32_buff_t){
        .ptr = fge_utf32_pointer(string),
        .count = fge_utf32_count(string)
    });
}
