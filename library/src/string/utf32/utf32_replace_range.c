#include "utf32_string.h"

fge_bool_t fge_utf32_replace_range(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_buffer_t replace
) {
    if (fge_utf32_remove_range(self, range) == false) {
        return false;
    }
    return fge_utf32_insert(self, range.lower, replace);
}

fge_bool_t fge_utf32_replace_range_string(
    fge_utf32_pt self,
    fge_index_range_t range,
    fge_utf32_cpt replace
) {
    return fge_utf32_replace_range(self, range, (fge_utf32_buffer_t){
        .ptr = fge_utf32_pointer(replace),
        .count = fge_utf32_count(replace)
    });
}
