#ifndef FGE_STD_H
#define FGE_STD_H

#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

#define FGE_TYPEDEF(RAW, NAME) \
    typedef RAW NAME##_t; \
    typedef const NAME##_t NAME##_ct; \
    typedef NAME##_t* NAME##_pt; \
    typedef NAME##_ct* NAME##_cpt

#define FGE_TYPEDEF_STRUCT(NAME) \
    FGE_TYPEDEF(struct NAME, NAME)

FGE_TYPEDEF(bool, fge_bool);

FGE_TYPEDEF(void*, fge_ptr);
FGE_TYPEDEF(uintptr_t, fge_uptr);

FGE_TYPEDEF(uintptr_t, fge_idx);
FGE_TYPEDEF(uintptr_t, fge_sz);

FGE_TYPEDEF(int8_t, fge_i8);
FGE_TYPEDEF(int16_t, fge_i16);
FGE_TYPEDEF(int32_t, fge_i32);
FGE_TYPEDEF(int64_t, fge_i64);

FGE_TYPEDEF(uint8_t, fge_u8);
FGE_TYPEDEF(uint16_t, fge_u16);
FGE_TYPEDEF(uint32_t, fge_u32);
FGE_TYPEDEF(uint64_t, fge_u64);

FGE_TYPEDEF(float, fge_f32);
FGE_TYPEDEF(double, fge_f64);
FGE_TYPEDEF(long double, fge_f80);

#endif
