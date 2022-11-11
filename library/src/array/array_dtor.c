#include <fge/memory.h>
#include <fge/array.h>

void fge_array_free(
    fge_array_pt self
) {
    if (self->ptr != NULL) {
        self->allocator->delete(self->ptr);
    }
    self->ptr = NULL;
    self->count = 0;
    self->capacity = 0;
}
