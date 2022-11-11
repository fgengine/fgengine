#include <fge/memory.h>

fge_size_t fge_memory_copy(
    fge_memory_t dst,
    fge_memory_t src
) {
    fge_ptr_t dptr = dst.ptr;
    fge_size_t dcnt = dst.count;
    fge_ptr_t sptr = src.ptr;
    fge_size_t scnt = src.count;
    fge_size_t result = 0;
    while (dcnt >= sizeof(fge_uintptr_t) && scnt >= sizeof(fge_uintptr_t)) {
        *((fge_uintptr_pt)dptr) = *((fge_uintptr_pt)sptr);
        dptr += sizeof(fge_uintptr_t);
        sptr += sizeof(fge_uintptr_t);
        dcnt -= sizeof(fge_uintptr_t);
        scnt -= sizeof(fge_uintptr_t);
        result += sizeof(fge_uintptr_t);
    }
    while (dcnt >= sizeof(fge_uint8_t) && scnt >= sizeof(fge_uint8_t)) {
        *((fge_uint8_pt)dptr) = *((fge_uint8_pt)sptr);
        dptr += sizeof(fge_uint8_t);
        sptr += sizeof(fge_uint8_t);
        dcnt -= sizeof(fge_uint8_t);
        scnt -= sizeof(fge_uint8_t);
        result += sizeof(fge_uint8_t);
    }
    return result;
}
