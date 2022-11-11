#include "utf16_string.h"

fge_bool_t fge_utf16_replace_range(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_buffer_t replace
) {
    if (fge_utf16_remove_range(self, range) == false) {
        return false;
    }
    return fge_utf16_insert(self, range.lower, replace);
}

fge_bool_t fge_utf16_replace_range_string(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_cpt replace
) {
    return fge_utf16_replace_range(self, range, (fge_utf16_buffer_t){
        .ptr = fge_utf16_pointer(replace),
        .count = fge_utf16_count(replace)
    });
}
