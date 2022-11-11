#include "utf8.h"

fge_bool_t fge_utf8_replace_range(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_buff_t replace
) {
    if (fge_utf8_remove_range(self, range) == false) {
        return false;
    }
    return fge_utf8_insert(self, range.lower, replace);
}

fge_bool_t fge_utf8_replace_range_string(
    fge_utf8_pt self,
    fge_rng_idx_t range,
    fge_utf8_cpt replace
) {
    return fge_utf8_replace_range(self, range, (fge_utf8_buff_t){
        .ptr = fge_utf8_pointer(replace),
        .count = fge_utf8_count(replace)
    });
}
