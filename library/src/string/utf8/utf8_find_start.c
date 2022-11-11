#include "utf8_string.h"

fge_index_range_t fge_utf8_find_start(
    fge_utf8_cpt self,
    fge_index_range_t range,
    fge_utf8_buffer_t find
) {
    fge_index_range_t founded = fge_memory_find_forward((fge_memory_t){
        .ptr = (fge_ptr_t)fge_utf8_pointer(self),
        .count = self->count * sizeof(fge_utf8_unit_t)
    }, (fge_memory_t){
        .ptr = (fge_ptr_t)find.ptr,
        .count = find.count * sizeof(fge_utf8_unit_t)
    }, range);
    return (fge_index_range_t){
        .lower = founded.lower / sizeof(fge_utf8_unit_t),
        .upper = founded.upper / sizeof(fge_utf8_unit_t)
    };
}

fge_index_range_t fge_utf8_find_start_string(
    fge_utf8_cpt self,
    fge_index_range_t range,
    fge_utf8_cpt find
) {
    return fge_utf8_find_start(self, range, (fge_utf8_buffer_t){
        .ptr = fge_utf8_pointer(find),
        .count = fge_utf8_count(find)
    });
}
