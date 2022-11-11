#include <fge/memory.h>

fge_size_t fge_memory_move(
    fge_memory_t dst,
    fge_memory_t src
) {
    if (dst.count != src.count) {
        return 0;
    }
    fge_size_t cnt = dst.count;
    fge_size_t result = 0;
    if (dst.ptr <= src.ptr) {
        fge_ptr_t dptr = dst.ptr;
        fge_ptr_t sptr = src.ptr;
        while (cnt >= sizeof(fge_uintptr_t)) {
            *((fge_uintptr_pt)dptr) = *((fge_uintptr_pt)sptr);
            dptr += sizeof(fge_uintptr_t);
            sptr += sizeof(fge_uintptr_t);
            cnt -= sizeof(fge_uintptr_t);
            result += sizeof(fge_uintptr_t);
        }
        while (cnt >= sizeof(fge_uint8_t)) {
            *((fge_uint8_pt)dptr) = *((fge_uint8_pt)sptr);
            dptr += sizeof(fge_uint8_t);
            sptr += sizeof(fge_uint8_t);
            cnt -= sizeof(fge_uint8_t);
            result += sizeof(fge_uint8_t);
        }
    } else {
        fge_ptr_t dptr = (fge_uint8_pt)(dst.ptr) + (cnt - 1);
        fge_ptr_t sptr = (fge_uint8_pt)(src.ptr) + (cnt - 1);
        while (cnt >= sizeof(fge_uintptr_t)) {
            *((fge_uintptr_pt)dptr) = *((fge_uintptr_pt)sptr);
            dptr -= sizeof(fge_uintptr_t);
            sptr -= sizeof(fge_uintptr_t);
            cnt -= sizeof(fge_uintptr_t);
            result += sizeof(fge_uintptr_t);
        }
        while (cnt >= sizeof(fge_uint8_t)) {
            *((fge_uint8_pt)dptr) = *((fge_uint8_pt)sptr);
            dptr -= sizeof(fge_uint8_t);
            sptr -= sizeof(fge_uint8_t);
            cnt -= sizeof(fge_uint8_t);
            result += sizeof(fge_uint8_t);
        }
    }
    return result;
}
