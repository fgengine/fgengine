#include "utf16_string.h"

void fge_utf16_free(
    fge_utf16_pt self
) {
    if (self->capacity > 0) {
        self->allocator->delete(self->ptr);
    }
    self->ptr = NULL;
    self->count = 0;
    self->capacity = 0;
}
