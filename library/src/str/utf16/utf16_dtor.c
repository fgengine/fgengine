#include "utf16.h"

void fge_utf16_free(
    fge_utf16_pt self
) {
    if (self->capacity > 0) {
        self->alloc->delete(self->ptr);
    }
    self->ptr = NULL;
    self->count = 0;
    self->capacity = 0;
}
