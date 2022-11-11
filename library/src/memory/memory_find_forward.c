#include <fge/memory.h>

fge_index_range_t fge_memory_find_forward(
    fge_memory_t memory,
    fge_memory_t find,
    fge_index_range_ct range
) {
    fge_size_t lower = (range.lower < memory.count) ? range.lower : memory.count;
    fge_size_t upper = (range.upper < memory.count) ? range.upper : memory.count;
    fge_size_t delta = range.upper - range.lower;
    if (delta < find.count) {
        return (fge_index_range_t){
            .lower = 0,
            .upper = 0
        };
    }
    fge_uint8_pt mptr = ((fge_uint8_pt)memory.ptr) + lower;
    fge_uint8_pt fptr = (fge_uint8_pt)find.ptr;
    fge_size_t cnt = (delta - find.count) + 1;
    fge_size_t idx = range.lower;
    while (cnt > 0) {
        if (*mptr == *fptr) {
            fge_memory_t tmp = (fge_memory_t){
                .ptr = mptr,
                .count = find.count
            };
            if (fge_memory_is_equal(tmp, find) == true) {
                return (fge_index_range_t){
                    .lower = idx,
                    .upper = idx + find.count
                };
            }
        }
        mptr++;
        cnt--;
        idx++;
    }
    return (fge_index_range_t){
        .lower = 0,
        .upper = 0
    };
}
