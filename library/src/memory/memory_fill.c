#include <fge/memory.h>

fge_size_t fge_memory_fill(
    fge_memory_t dst,
    fge_memory_t fill
) {
    fge_ptr_t dptr = dst.ptr;
    fge_size_t dcnt = dst.count;
    fge_size_t result = 0;
    while (dcnt > 0) {
        fge_ptr_t fptr = fill.ptr;
        fge_size_t fcnt = fill.count;
        while (dcnt >= sizeof(fge_uintptr_t) && fcnt >= sizeof(fge_uintptr_t)) {
            *((fge_uintptr_pt)dptr) = *((fge_uintptr_pt)fptr);
            dptr += sizeof(fge_uintptr_t);
            fptr += sizeof(fge_uintptr_t);
            dcnt -= sizeof(fge_uintptr_t);
            fcnt -= sizeof(fge_uintptr_t);
            result += sizeof(fge_uintptr_t);
        }
        while (dcnt >= sizeof(fge_uint8_t) && fcnt >= sizeof(fge_uint8_t)) {
            *((fge_uint8_pt)dptr) = *((fge_uint8_pt)fptr);
            dptr += sizeof(fge_uint8_t);
            fptr += sizeof(fge_uint8_t);
            dcnt -= sizeof(fge_uint8_t);
            fcnt -= sizeof(fge_uint8_t);
            result += sizeof(fge_uint8_t);
        }
    }
    return result;
}
