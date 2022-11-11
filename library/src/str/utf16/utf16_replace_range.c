#include "utf16.h"

fge_bool_t fge_utf16_replace_range(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_buff_t replace
) {
    if (fge_utf16_remove_range(self, range) == false) {
        return false;
    }
    return fge_utf16_insert(self, range.lower, replace);
}

fge_bool_t fge_utf16_replace_range_string(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_cpt replace
) {
    return fge_utf16_replace_range(self, range, (fge_utf16_buff_t){
        .ptr = fge_utf16_pointer(replace),
        .count = fge_utf16_count(replace)
    });
}
