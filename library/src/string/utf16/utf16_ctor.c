#include "utf16_string.h"

fge_utf16_t fge_utf16(
    fge_allocator_cpt allocator
) {
    return (fge_utf16_t){
        .allocator = fge_allocator_safe(allocator),
        .chars = { 0 },
        .count = 0,
        .capacity = 0
    };
}

fge_utf16_t fge_utf16_with(
    fge_allocator_cpt allocator,
    fge_utf16_buffer_t buffer
) {
    fge_utf16_t self = fge_utf16(allocator);
    if (buffer.count >= sizeof(fge_ptr_t)) {
        fge_size_t capacity = buffer.count + 1;
        self.ptr = self.allocator->new(capacity * sizeof(fge_utf16_unit_t));
        if (self.ptr != NULL) {
            fge_memory_copy_fill((fge_memory_t){
                .ptr = self.ptr,
                .count = capacity * sizeof(fge_utf16_unit_t)
            }, (fge_memory_t){
                .ptr = (fge_ptr_t)buffer.ptr,
                .count = buffer.count * sizeof(fge_utf16_unit_t)
            },(fge_memory_t){
                .ptr = (fge_ptr_t)&FGE_STRING_NULL_CHARS,
                .count = sizeof(fge_utf16_unit_t)
            });
            self.count = buffer.count;
            self.capacity = capacity;
        }
    } else {
        fge_memory_copy_fill((fge_memory_t){
            .ptr = self.chars,
            .count = sizeof(fge_ptr_t)
        }, (fge_memory_t){
            .ptr = (fge_ptr_t)buffer.ptr,
            .count = buffer.count * sizeof(fge_utf16_unit_t)
        }, (fge_memory_t){
            .ptr = (fge_ptr_t)&FGE_STRING_NULL_CHARS,
            .count = sizeof(fge_utf16_unit_t)
        });
        self.count = buffer.count;
        self.capacity = 0;
    }
    return self;
}

fge_utf16_t fge_utf16_with_string(
    fge_allocator_cpt allocator,
    fge_utf16_cpt string
) {
    return fge_utf16_with(allocator, (fge_utf16_buffer_t){
        .ptr = fge_utf16_pointer(string),
        .count = fge_utf16_count(string)
    });
}
