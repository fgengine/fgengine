#include "utf32_string.h"

fge_bool_t fge_utf32_is_suffix(
    fge_utf32_cpt self,
    fge_utf32_buffer_t other
) {
    if (self->count < other.count) {
        return false;
    }
    return fge_memory_is_equal((fge_memory_t){
        .ptr = fge_utf32_pointer(self) + (self->count - other.count),
        .count = other.count * sizeof(fge_utf32_unit_t)
    }, (fge_memory_t){
        .ptr = (fge_ptr_t)other.ptr,
        .count = other.count * sizeof(fge_utf32_unit_t)
    });
}

fge_bool_t fge_utf32_is_suffix_string(
    fge_utf32_cpt self,
    fge_utf32_cpt other
) {
    return fge_utf32_is_suffix(self, (fge_utf32_buffer_t){
        .ptr = fge_utf32_pointer(other),
        .count = fge_utf32_count(other)
    });
}
