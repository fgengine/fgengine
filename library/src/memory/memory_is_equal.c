#include <fge/memory.h>

fge_bool_t fge_memory_is_equal(
    fge_memory_t lhs,
    fge_memory_t rhs
) {
    if (lhs.count != rhs.count) {
        return false;
    }
    fge_uint8_pt lptr = lhs.ptr;
    fge_uint8_pt rptr = rhs.ptr;
    fge_size_t cnt = lhs.count;
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
