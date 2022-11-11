#include "utf32.h"

fge_rng_idx_t fge_utf32_find_end(
    fge_utf32_cpt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t find
) {
    fge_rng_idx_t founded = fge_mem_find_backward((fge_mem_t){
        .ptr = (fge_ptr_t)fge_utf32_pointer(self),
        .count = self->count * sizeof(fge_utf32_unit_t)
    }, (fge_mem_t){
        .ptr = (fge_ptr_t)find.ptr,
        .count = find.count * sizeof(fge_utf32_unit_t)
    }, range);
    return (fge_rng_idx_t){
        .lower = founded.lower / sizeof(fge_utf32_unit_t),
        .upper = founded.upper / sizeof(fge_utf32_unit_t)
    };
}

fge_rng_idx_t fge_utf32_find_end_string(
    fge_utf32_cpt self,
    fge_rng_idx_t range,
    fge_utf32_cpt find
) {
    return fge_utf32_find_end(self, range, (fge_utf32_buff_t){
        .ptr = fge_utf32_pointer(find),
        .count = fge_utf32_count(find)
    });
}
