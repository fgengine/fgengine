#include <fge/mem.h>

fge_rng_idx_t fge_mem_find_backward(
    fge_mem_t memory,
    fge_mem_t find,
    fge_rng_idx_ct range
) {
    fge_sz_t lower = (range.lower < memory.count) ? range.lower : memory.count;
    fge_sz_t upper = (range.upper < memory.count) ? range.upper : memory.count;
    fge_sz_t delta = range.upper - range.lower;
    if (delta < find.count) {
        return (fge_rng_idx_t){
            .lower = 0,
            .upper = 0
        };
    }
    fge_u8_pt mptr = ((fge_u8_pt)memory.ptr) + lower + (delta - 1);
    fge_u8_pt fptr = ((fge_u8_pt)find.ptr) + (find.count - 1);
    fge_sz_t cnt = (delta - find.count) + 1;
    fge_sz_t idx = upper - 1;
    while (cnt > 0) {
        if (*mptr == *fptr) {
            fge_mem_t tmp = (fge_mem_t){
                .ptr = mptr - (find.count - 1),
                .count = find.count
            };
            if (fge_mem_is_equal(tmp, find) == true) {
                return (fge_rng_idx_t){
                    .lower = idx - (find.count - 1),
                    .upper = (idx + 1)
                };
            }
        }
        mptr--;
        cnt--;
        idx--;
    }
    return (fge_rng_idx_t){
        .lower = 0,
        .upper = 0
    };
}
