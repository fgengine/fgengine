#include "utf8_string.h"

void fge_utf8_free(
    fge_utf8_pt self
) {
    if (self->capacity > 0) {
        self->allocator->delete(self->ptr);
    }
    self->ptr = NULL;
    self->count = 0;
    self->capacity = 0;
}
