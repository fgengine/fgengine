#include "utf32.h"

fge_utf32_t fge_utf32(
    fge_alloc_cpt alloc
) {
    return (fge_utf32_t){
        .alloc = fge_alloc_safe(alloc),
        .chars = { 0 },
        .count = 0,
        .capacity = 0
    };
}

fge_utf32_t fge_utf32_with(
    fge_alloc_cpt alloc,
    fge_utf32_buff_t buff
) {
    fge_utf32_t self = fge_utf32(alloc);
    if (buff.count >= sizeof(fge_ptr_t)) {
        fge_sz_t capacity = buff.count + 1;
        self.ptr = self.alloc->new(capacity * sizeof(fge_utf32_unit_t));
        if (self.ptr != NULL) {
            fge_mem_copy_fill((fge_mem_t){
                .ptr = self.ptr,
                .count = capacity * sizeof(fge_utf32_unit_t)
            }, (fge_mem_t){
                .ptr = (fge_ptr_t)buff.ptr,
                .count = buff.count * sizeof(fge_utf32_unit_t)
            },(fge_mem_t){
                .ptr = (fge_ptr_t)&FGE_STR_NULL_CHARS,
                .count = sizeof(fge_utf32_unit_t)
            });
            self.count = buff.count;
            self.capacity = capacity;
        }
    } else {
        fge_mem_copy_fill((fge_mem_t){
            .ptr = self.chars,
            .count = sizeof(fge_ptr_t)
        }, (fge_mem_t){
            .ptr = (fge_ptr_t)buff.ptr,
            .count = buff.count * sizeof(fge_utf32_unit_t)
        }, (fge_mem_t){
            .ptr = (fge_ptr_t)&FGE_STR_NULL_CHARS,
            .count = sizeof(fge_utf32_unit_t)
        });
        self.count = buff.count;
        self.capacity = 0;
    }
    return self;
}

fge_utf32_t fge_utf32_with_string(
    fge_alloc_cpt alloc,
    fge_utf32_cpt string
) {
    return fge_utf32_with(alloc, (fge_utf32_buff_t){
        .ptr = fge_utf32_pointer(string),
        .count = fge_utf32_count(string)
    });
}
