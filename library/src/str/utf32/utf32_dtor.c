#include "utf32.h"

void fge_utf32_free(
    fge_utf32_pt self
) {
    if (self->capacity > 0) {
        self->alloc->delete(self->ptr);
    }
    self->ptr = NULL;
    self->count = 0;
    self->capacity = 0;
}
