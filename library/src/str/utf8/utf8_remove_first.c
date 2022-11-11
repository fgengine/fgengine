#include "utf8.h"

fge_bool_t fge_utf8_remove_first(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_buff_t find
) {
    fge_rng_idx_t find_range = fge_utf8_find_start(self, range, find);
    if (find_range.lower >= find_range.upper) {
        return false;
    }
    return fge_utf8_remove_range(self, find_range);
}

fge_bool_t fge_utf8_remove_first_string(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_cpt find
) {
    return fge_utf8_remove_first(self, range, (fge_utf8_buff_t){
        .ptr = fge_utf8_pointer(find),
        .count = fge_utf8_count(find)
    });
}
