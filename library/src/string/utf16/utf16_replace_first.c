#include "utf16_string.h"

fge_bool_t fge_utf16_replace_first(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_buffer_t find,
    fge_utf16_buffer_t replace
) {
    fge_index_range_t find_range = fge_utf16_find_start(self, range, find);
    if (find_range.lower == find_range.upper) {
        return false;
    }
    if (fge_utf16_remove_range(self, find_range) == false) {
        return false;
    }
    return fge_utf16_insert(self, find_range.lower, replace);
}

fge_bool_t fge_utf16_replace_first_string(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_cpt find,
    fge_utf16_cpt replace
) {
    return fge_utf16_replace_first(self, range, (fge_utf16_buffer_t){
        .ptr = fge_utf16_pointer(find),
        .count = fge_utf16_count(find)
    }, (fge_utf16_buffer_t){
        .ptr = fge_utf16_pointer(replace),
        .count = fge_utf16_count(replace)
    });
}
