#include "utf8_string.h"

fge_bool_t fge_utf8_is_prefix(
    fge_utf8_cpt self,
    fge_utf8_buffer_t find
) {
    if (self->count < find.count) {
        return false;
    }
    return fge_memory_is_equal((fge_memory_t){
        .ptr = fge_utf8_pointer(self),
        .count = find.count * sizeof(fge_utf8_unit_t)
    }, (fge_memory_t){
        .ptr = (fge_ptr_t)find.ptr,
        .count = find.count * sizeof(fge_utf8_unit_t)
    });
}

fge_bool_t fge_utf8_is_prefix_string(
    fge_utf8_cpt self,
    fge_utf8_cpt find
) {
    return fge_utf8_is_prefix(self, (fge_utf8_buffer_t){
        .ptr = fge_utf8_pointer(find),
        .count = fge_utf8_count(find)
    });
}
