#include <fge/mem.h>

fge_bool_t fge_mem_is_equal(
    fge_mem_t lhs,
    fge_mem_t rhs
) {
    if (lhs.count != rhs.count) {
        return false;
    }
    fge_u8_pt lptr = lhs.ptr;
    fge_u8_pt rptr = rhs.ptr;
    fge_sz_t cnt = lhs.count;
    while (cnt > 0) {
        if (*lptr != *rptr) {
            return false;
        }
        lptr++;
        rptr++;
        cnt--;
    }
    return true;
}
