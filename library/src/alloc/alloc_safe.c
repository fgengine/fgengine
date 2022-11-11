#include <fge/alloc.h>

fge_alloc_cpt fge_alloc_safe(
    fge_alloc_cpt alloc
) {
    if (alloc != NULL) {
        return alloc;
    }
    return fge_alloc_default();
}
