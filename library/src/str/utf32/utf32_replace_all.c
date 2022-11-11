#include "utf32.h"

fge_sz_t fge_utf32_replace_all(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t find,
    fge_utf32_buff_t replace
) {
    fge_sz_t replaced = 0;
    while (true) {
        fge_rng_idx_t find_range = fge_utf32_find_start(self, range, find);
        if (find_range.lower >= find_range.upper) {
            break;
        }
        if (fge_utf32_remove_range(self, find_range) == false) {
            break;
        }
        if (fge_utf32_insert(self, find_range.lower, replace) == false) {
            break;
        }
        range.upper -= (find_range.upper - find_range.lower) - replace.count;
        range.lower = find_range.lower + replace.count;
        replaced += 1;
    }
    return replaced;
}

fge_sz_t fge_utf32_replace_all_string(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_cpt find,
    fge_utf32_cpt replace
) {
    return fge_utf32_replace_all(self, range, (fge_utf32_buff_t){
        .ptr = fge_utf32_pointer(find),
        .count = fge_utf32_count(find)
    }, (fge_utf32_buff_t){
        .ptr = fge_utf32_pointer(replace),
        .count = fge_utf32_count(replace)
    });
}
