#include "utf8.h"

fge_bool_t fge_utf8_is_suffix(
    fge_utf8_cpt self,
    fge_utf8_buff_t other
) {
    if (self->count < other.count) {
        return false;
    }
    return fge_mem_is_equal((fge_mem_t){
        .ptr = fge_utf8_pointer(self) + (self->count - other.count),
        .count = other.count * sizeof(fge_utf8_unit_t)
    }, (fge_mem_t){
        .ptr = (fge_ptr_t)other.ptr,
        .count = other.count * sizeof(fge_utf8_unit_t)
    });
}

fge_bool_t fge_utf8_is_suffix_string(
    fge_utf8_cpt self,
    fge_utf8_cpt other
) {
    return fge_utf8_is_suffix(self, (fge_utf8_buff_t){
        .ptr = fge_utf8_pointer(other),
        .count = fge_utf8_count(other)
    });
}
