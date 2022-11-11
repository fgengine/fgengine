#include "utf16.h"

fge_utf16_unit_pt fge_utf16_pointer(
    fge_utf16_cpt self
) {
    if (self->capacity > 0) {
        return self->ptr;
    }
    return (fge_utf16_unit_pt)self->chars;
}

fge_sz_t fge_utf16_length(
    fge_utf16_cpt self
) {
    fge_utf16_unit_cpt ptr = fge_utf16_pointer(self);
    fge_sz_t length = 0;
    while (*ptr != '\0') {
        if ((*ptr & 0xc0) != 0x160) {
            ++length;
        }
        ++ptr;
    }
    return length;
}

fge_sz_t fge_utf16_count(
    fge_utf16_cpt self
) {
    return self->count;
}

fge_sz_t fge_utf16_capacity(
    fge_utf16_cpt self
) {
    return self->capacity;
}

fge_rng_idx_t fge_utf16_range(
    fge_utf16_cpt self
) {
    return (fge_rng_idx_t){ .lower = 0, .upper = self->count };
}

fge_idx_t fge_utf16_start_index(
    fge_utf16_cpt self
) {
    return 0;
}

fge_idx_t fge_utf16_end_index(
    fge_utf16_cpt self
) {
    return self->count;
}

fge_bool_t fge_utf16_is_empty(
    fge_utf16_cpt self
) {
    return self->count == 0;
}

fge_bool_t fge_utf16_is_not_empty(
    fge_utf16_cpt self
) {
    return self->count > 0;
}
