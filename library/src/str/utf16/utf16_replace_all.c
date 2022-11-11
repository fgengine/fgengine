#include "utf16.h"

fge_sz_t fge_utf16_replace_all(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_buff_t find,
    fge_utf16_buff_t replace
) {
    fge_sz_t replaced = 0;
    while (true) {
        fge_rng_idx_t find_range = fge_utf16_find_start(self, range, find);
        if (find_range.lower >= find_range.upper) {
            break;
        }
        if (fge_utf16_remove_range(self, find_range) == false) {
            break;
        }
        if (fge_utf16_insert(self, find_range.lower, replace) == false) {
            break;
        }
        range.upper -= (find_range.upper - find_range.lower) - replace.count;
        range.lower = find_range.lower + replace.count;
        replaced += 1;
    }
    return replaced;
}

fge_sz_t fge_utf16_replace_all_string(
    fge_utf16_pt self,
    fge_rng_idx_t range,
    fge_utf16_cpt find,
    fge_utf16_cpt replace
) {
    return fge_utf16_replace_all(self, range, (fge_utf16_buff_t){
        .ptr = fge_utf16_pointer(find),
        .count = fge_utf16_count(find)
    }, (fge_utf16_buff_t){
        .ptr = fge_utf16_pointer(replace),
        .count = fge_utf16_count(replace)
    });
}
