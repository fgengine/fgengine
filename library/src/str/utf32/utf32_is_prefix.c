#include "utf32.h"

fge_bool_t fge_utf32_is_prefix(
    fge_utf32_cpt self,
    fge_utf32_buff_t find
) {
    if (self->count < find.count) {
        return false;
    }
    return fge_mem_is_equal((fge_mem_t){
        .ptr = fge_utf32_pointer(self),
        .count = find.count * sizeof(fge_utf32_unit_t)
    }, (fge_mem_t){
        .ptr = (fge_ptr_t)find.ptr,
        .count = find.count * sizeof(fge_utf32_unit_t)
    });
}

fge_bool_t fge_utf32_is_prefix_string(
    fge_utf32_cpt self,
    fge_utf32_cpt find
) {
    return fge_utf32_is_prefix(self, (fge_utf32_buff_t){
        .ptr = fge_utf32_pointer(find),
        .count = fge_utf32_count(find)
    });
}
