#include <fge/mem.h>

fge_sz_t fge_mem_copy(
    fge_mem_t dst,
    fge_mem_t src
) {
    fge_ptr_t dptr = dst.ptr;
    fge_sz_t dcnt = dst.count;
    fge_ptr_t sptr = src.ptr;
    fge_sz_t scnt = src.count;
    fge_sz_t result = 0;
    while (dcnt >= sizeof(fge_u8_t) && scnt >= sizeof(fge_u8_t)) {
        *((fge_u8_pt)dptr) = *((fge_u8_pt)sptr);
        dptr += sizeof(fge_u8_t);
        sptr += sizeof(fge_u8_t);
        dcnt -= sizeof(fge_u8_t);
        scnt -= sizeof(fge_u8_t);
        result += sizeof(fge_u8_t);
    }
    return result;
}
