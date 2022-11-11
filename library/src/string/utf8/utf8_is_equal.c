#include "utf8_string.h"

fge_bool_t fge_utf8_is_equal(
    fge_utf8_cpt self,
    fge_utf8_buffer_t other
) {
    if (self->count != other.count) {
        return false;
    }
    return fge_memory_is_equal((fge_memory_t) {
        .ptr = fge_utf8_pointer(self),
        .count = self->count * sizeof(fge_utf8_unit_t)
    }, (fge_memory_t){
        .ptr = (fge_ptr_t)other.ptr,
        .count = other.count * sizeof(fge_utf8_unit_t)
    });
}

fge_bool_t fge_utf8_is_equal_string(
    fge_utf8_cpt self,
    fge_utf8_cpt other
) {
    return fge_utf8_is_equal(self, (fge_utf8_buffer_t){
        .ptr = fge_utf8_pointer(other),
        .count = fge_utf8_count(other)
    });
}
