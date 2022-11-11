#include <fge/mem.h>
#include <fge/arr.h>

void fge_arr_free(
    fge_arr_pt self
) {
    if (self->ptr != NULL) {
        self->alloc->delete(self->ptr);
    }
    self->ptr = NULL;
    self->count = 0;
    self->capacity = 0;
}
