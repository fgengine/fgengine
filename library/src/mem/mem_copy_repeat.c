#include <fge/mem.h>

fge_sz_t fge_mem_copy_repeat(
    fge_mem_t dst,
    fge_mem_t src,
    fge_sz_t repeat
) {
    fge_u8_pt dptr = dst.ptr;
    fge_sz_t dcnt = dst.count;
    fge_sz_t rpt = repeat;
    fge_sz_t result = 0;
    while (rpt > 0) {
        fge_sz_t cpd = fge_mem_copy((fge_mem_t){
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
