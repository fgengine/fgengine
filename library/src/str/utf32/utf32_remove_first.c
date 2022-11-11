#include "utf32.h"

fge_bool_t fge_utf32_remove_first(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t find
) {
    fge_rng_idx_t find_range = fge_utf32_find_start(self, range, find);
    if (find_range.lower >= find_range.upper) {
        return false;
    }
    return fge_utf32_remove_range(self, find_range);
}

fge_bool_t fge_utf32_remove_first_string(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_cpt find
) {
    return fge_utf32_remove_first(self, range, (fge_utf32_buff_t){
        .ptr = fge_utf32_pointer(find),
        .count = fge_utf32_count(find)
    });
}
