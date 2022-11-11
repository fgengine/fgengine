#include "utf8_string.h"

fge_bool_t fge_utf8_replace_first(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_buffer_t find,
    fge_utf8_buffer_t replace
) {
    fge_index_range_t find_range = fge_utf8_find_start(self, range, find);
    if (find_range.lower == find_range.upper) {
        return false;
    }
    if (fge_utf8_remove_range(self, find_range) == false) {
        return false;
    }
    return fge_utf8_insert(self, find_range.lower, replace);
}

fge_bool_t fge_utf8_replace_first_string(
    fge_utf8_pt self,
    fge_index_range_t range,
    fge_utf8_cpt find,
    fge_utf8_cpt replace
) {
    return fge_utf8_replace_first(self, range, (fge_utf8_buffer_t){
        .ptr = fge_utf8_pointer(find),
        .count = fge_utf8_count(find)
    }, (fge_utf8_buffer_t){
        .ptr = fge_utf8_pointer(replace),
        .count = fge_utf8_count(replace)
    });
}
