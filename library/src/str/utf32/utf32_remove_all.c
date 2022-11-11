#include "utf32.h"

fge_sz_t fge_utf32_remove_all(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_buff_t find
) {
    fge_sz_t removed = 0;
    while (true) {
        fge_rng_idx_t find_range = fge_utf32_find_start(self, range, find);
        if (find_range.lower >= find_range.upper) {
            break;
        }
        if (fge_utf32_remove_range(self, find_range) == false) {
            break;
        }
        range.upper -= find_range.upper - find_range.lower;
        range.lower = find_range.lower;
        removed += 1;
    }
    return removed;
}

fge_sz_t fge_utf32_remove_all_string(
    fge_utf32_pt self,
    fge_rng_idx_t range,
    fge_utf32_cpt find
) {
    return fge_utf32_remove_all(self, range, (fge_utf32_buff_t){
        .ptr = fge_utf32_pointer(find),
        .count = fge_utf32_count(find)
    });
}
