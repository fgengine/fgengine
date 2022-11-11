#include <fge/mem.h>

fge_sz_t fge_mem_fill(
    fge_mem_t dst,
    fge_mem_t fill
) {
    fge_ptr_t dptr = dst.ptr;
    fge_sz_t dcnt = dst.count;
    fge_sz_t result = 0;
    while (dcnt > 0) {
        fge_ptr_t fptr = fill.ptr;
        fge_sz_t fcnt = fill.count;
        while (dcnt >= sizeof(fge_u8_t) && fcnt >= sizeof(fge_u8_t)) {
            *((fge_u8_pt)dptr) = *((fge_u8_pt)fptr);
            dptr += sizeof(fge_u8_t);
            fptr += sizeof(fge_u8_t);
            dcnt -= sizeof(fge_u8_t);
            fcnt -= sizeof(fge_u8_t);
            result += sizeof(fge_u8_t);
        }
    }
    return result;
}
