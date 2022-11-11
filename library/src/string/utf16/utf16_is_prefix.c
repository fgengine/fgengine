#include "utf16_string.h"

fge_bool_t fge_utf16_is_prefix(
    fge_utf16_cpt self,
    fge_utf16_buffer_t find
) {
    if (self->count < find.count) {
        return false;
    }
    return fge_memory_is_equal((fge_memory_t){
        .ptr = fge_utf16_pointer(self),
        .count = find.count * sizeof(fge_utf16_unit_t)
    }, (fge_memory_t){
        .ptr = (fge_ptr_t)find.ptr,
        .count = find.count * sizeof(fge_utf16_unit_t)
    });
}

fge_bool_t fge_utf16_is_prefix_string(
    fge_utf16_cpt self,
    fge_utf16_cpt find
) {
    return fge_utf16_is_prefix(self, (fge_utf16_buffer_t){
        .ptr = fge_utf16_pointer(find),
        .count = fge_utf16_count(find)
    });
}
