#include <fge/memory.h>

fge_size_t fge_memory_copy_fill(
    fge_memory_t dst,
    fge_memory_t src,
    fge_memory_t fill
) {
    fge_size_t copied = fge_memory_copy(dst, src);
    if (copied < dst.count) {
        fge_size_t filled = fge_memory_fill((fge_memory_t){
            .ptr = ((fge_uint8_pt)dst.ptr) + copied,
            .count = dst.count - copied
        }, fill);
        return copied + filled;
    }
    return copied;
}
