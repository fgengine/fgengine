#include "utf16_string.h"

fge_bool_t fge_utf16_remove_last(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_buffer_t find
) {
    fge_index_range_t find_range = fge_utf16_find_end(self, range, find);
    if (find_range.lower == find_range.upper) {
        return false;
    }
    return fge_utf16_remove_range(self, find_range);
}

fge_bool_t fge_utf16_remove_last_string(
    fge_utf16_pt self,
    fge_index_range_t range,
    fge_utf16_cpt find
) {
    return fge_utf16_remove_last(self, range, (fge_utf16_buffer_t){
        .ptr = fge_utf16_pointer(find),
        .count = fge_utf16_count(find)
    });
}
