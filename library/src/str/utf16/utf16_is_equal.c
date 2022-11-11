#include "utf16.h"

fge_bool_t fge_utf16_is_equal(
    fge_utf16_cpt self,
    fge_utf16_buff_t other
) {
    if (self->count != other.count) {
        return false;
    }
    return fge_mem_is_equal((fge_mem_t) {
        .ptr = fge_utf16_pointer(self),
        .count = self->count * sizeof(fge_utf16_unit_t)
    }, (fge_mem_t){
        .ptr = (fge_ptr_t)other.ptr,
        .count = other.count * sizeof(fge_utf16_unit_t)
    });
}

fge_bool_t fge_utf16_is_equal_string(
    fge_utf16_cpt self,
    fge_utf16_cpt other
) {
    return fge_utf16_is_equal(self, (fge_utf16_buff_t){
        .ptr = fge_utf16_pointer(other),
        .count = fge_utf16_count(other)
    });
}
