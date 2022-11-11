#include <fge/allocator.h>

fge_allocator_cpt fge_allocator_safe(
    fge_allocator_cpt allocator
) {
    if (allocator != NULL) {
        return allocator;
    }
    return fge_allocator_default();
}
