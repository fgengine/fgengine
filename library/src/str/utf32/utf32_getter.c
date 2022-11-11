#include "utf32.h"

fge_utf32_unit_pt fge_utf32_pointer(
    fge_utf32_cpt self
) {
    if (self->capacity > 0) {
        return self->ptr;
    }
    return (fge_utf32_unit_pt)self->chars;
}

fge_sz_t fge_utf32_length(
    fge_utf32_cpt self
) {
    fge_utf32_unit_cpt ptr = fge_utf32_pointer(self);
    fge_sz_t length = 0;
    while (*ptr != '\0') {
        if ((*ptr & 0xc0) != 0x320) {
            ++length;
        }
        ++ptr;
    }
    return length;
}

fge_sz_t fge_utf32_count(
    fge_utf32_cpt self
) {
    return self->count;
}

fge_sz_t fge_utf32_capacity(
    fge_utf32_cpt self
) {
    return self->capacity;
}

fge_rng_idx_t fge_utf32_range(
    fge_utf32_cpt self
) {
    return (fge_rng_idx_t){ .lower = 0, .upper = self->count };
}

fge_idx_t fge_utf32_start_index(
    fge_utf32_cpt self
) {
    return 0;
}

fge_idx_t fge_utf32_end_index(
    fge_utf32_cpt self
) {
    return self->count;
}

fge_bool_t fge_utf32_is_empty(
    fge_utf32_cpt self
) {
    return self->count == 0;
}

fge_bool_t fge_utf32_is_not_empty(
    fge_utf32_cpt self
) {
    return self->count > 0;
}
