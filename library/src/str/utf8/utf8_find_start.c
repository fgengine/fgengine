#include "utf8.h"

fge_rng_idx_t fge_utf8_find_start(
    fge_utf8_cpt self,
    fge_rng_idx_t range,
    fge_utf8_buff_t find
) {
    fge_rng_idx_t founded = fge_mem_find_forward((fge_mem_t){
        .ptr = (fge_ptr_t)fge_utf8_pointer(self),
        .count = self->count * sizeof(fge_utf8_unit_t)
    }, (fge_mem_t){
        .ptr = (fge_ptr_t)find.ptr,
        .count = find.count * sizeof(fge_utf8_unit_t)
    }, range);
    return (fge_rng_idx_t){
        .lower = founded.lower / sizeof(fge_utf8_unit_t),
        .upper = founded.upper / sizeof(fge_utf8_unit_t)
    };
}

fge_rng_idx_t fge_utf8_find_start_string(
    fge_utf8_cpt self,
    fge_rng_idx_t range,
    fge_utf8_cpt find
) {
    return fge_utf8_find_start(self, range, (fge_utf8_buff_t){
        .ptr = fge_utf8_pointer(find),
        .count = fge_utf8_count(find)
    });
}
