#include "utf16_string.h"

fge_index_range_t fge_utf16_find_end(
    fge_utf16_cpt self,
    fge_index_range_t range,
    fge_utf16_buffer_t find
) {
    fge_index_range_t founded = fge_memory_find_backward((fge_memory_t){
        .ptr = (fge_ptr_t)fge_utf16_pointer(self),
        .count = self->count * sizeof(fge_utf16_unit_t)
    }, (fge_memory_t){
        .ptr = (fge_ptr_t)find.ptr,
        .count = find.count * sizeof(fge_utf16_unit_t)
    }, range);
    return (fge_index_range_t){
        .lower = founded.lower / sizeof(fge_utf16_unit_t),
        .upper = founded.upper / sizeof(fge_utf16_unit_t)
    };
}

fge_index_range_t fge_utf16_find_end_string(
    fge_utf16_cpt self,
    fge_index_range_t range,
    fge_utf16_cpt find
) {
    return fge_utf16_find_end(self, range, (fge_utf16_buffer_t){
        .ptr = fge_utf16_pointer(find),
        .count = fge_utf16_count(find)
    });
}
