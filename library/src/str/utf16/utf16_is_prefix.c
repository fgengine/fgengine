#include "utf16.h"

fge_bool_t fge_utf16_is_prefix(
    fge_utf16_cpt self,
    fge_utf16_buff_t find
) {
    if (self->count < find.count) {
        return false;
    }
    return fge_mem_is_equal((fge_mem_t){
        .ptr = fge_utf16_pointer(self),
        .count = find.count * sizeof(fge_utf16_unit_t)
    }, (fge_mem_t){
        .ptr = (fge_ptr_t)find.ptr,
        .count = find.count * sizeof(fge_utf16_unit_t)
    });
}

fge_bool_t fge_utf16_is_prefix_string(
    fge_utf16_cpt self,
    fge_utf16_cpt find
) {
    return fge_utf16_is_prefix(self, (fge_utf16_buff_t){
        .ptr = fge_utf16_pointer(find),
        .count = fge_utf16_count(find)
    });
}
