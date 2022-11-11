#include "utf32.h"

fge_bool_t fge_utf32_is_suffix(
    fge_utf32_cpt self,
    fge_utf32_buff_t other
) {
    if (self->count < other.count) {
        return false;
    }
    return fge_mem_is_equal((fge_mem_t){
        .ptr = fge_utf32_pointer(self) + (self->count - other.count),
        .count = other.count * sizeof(fge_utf32_unit_t)
    }, (fge_mem_t){
        .ptr = (fge_ptr_t)other.ptr,
        .count = other.count * sizeof(fge_utf32_unit_t)
    });
}

fge_bool_t fge_utf32_is_suffix_string(
    fge_utf32_cpt self,
    fge_utf32_cpt other
) {
    return fge_utf32_is_suffix(self, (fge_utf32_buff_t){
        .ptr = fge_utf32_pointer(other),
        .count = fge_utf32_count(other)
    });
}
