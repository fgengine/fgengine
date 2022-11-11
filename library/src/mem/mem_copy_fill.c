#include <fge/mem.h>

fge_sz_t fge_mem_copy_fill(
    fge_mem_t dst,
    fge_mem_t src,
    fge_mem_t fill
) {
    fge_sz_t copied = fge_mem_copy(dst, src);
    if (copied < dst.count) {
        fge_sz_t filled = fge_mem_fill((fge_mem_t){
            .ptr = ((fge_u8_pt)dst.ptr) + copied,
            .count = dst.count - copied
        }, fill);
        return copied + filled;
    }
    return copied;
}
