#include <fge/memory.h>

fge_size_t fge_memory_copy_repeat(
    fge_memory_t dst,
    fge_memory_t src,
    fge_size_t repeat
) {
    fge_uint8_pt dptr = dst.ptr;
    fge_size_t dcnt = dst.count;
    fge_size_t rpt = repeat;
    fge_size_t result = 0;
    while (rpt > 0) {
        fge_size_t cpd = fge_memory_copy((fge_memory_t){
            .ptr = dptr,
            .count = dcnt
        }, src);
        dptr += cpd;
        dcnt -= cpd;
        rpt--;
        result += cpd;
    }
    return result;
}
