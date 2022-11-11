#include <fge/mem.h>

fge_sz_t fge_mem_move(
    fge_mem_t dst,
    fge_mem_t src
) {
    if (dst.count != src.count) {
        return 0;
    }
    fge_sz_t cnt = dst.count;
    fge_sz_t result = 0;
    if (dst.ptr <= src.ptr) {
        fge_ptr_t dptr = dst.ptr;
        fge_ptr_t sptr = src.ptr;
        while (cnt >= sizeof(fge_u8_t)) {
            *((fge_u8_pt)dptr) = *((fge_u8_pt)sptr);
            dptr += sizeof(fge_u8_t);
            sptr += sizeof(fge_u8_t);
            cnt -= sizeof(fge_u8_t);
            result += sizeof(fge_u8_t);
        }
    } else {
        fge_ptr_t dptr = (fge_u8_pt)(dst.ptr) + (cnt - 1);
        fge_ptr_t sptr = (fge_u8_pt)(src.ptr) + (cnt - 1);
        while (cnt >= sizeof(fge_u8_t)) {
            *((fge_u8_pt)dptr) = *((fge_u8_pt)sptr);
            dptr -= sizeof(fge_u8_t);
            sptr -= sizeof(fge_u8_t);
            cnt -= sizeof(fge_u8_t);
            result += sizeof(fge_u8_t);
        }
    }
    return result;
}
