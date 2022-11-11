#ifndef FGE_TYPES_H
#define FGE_TYPES_H

#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

#ifndef FGE_DEFINE_TYPE
#define FGE_DEFINE_TYPE(RAW, NAME) \
    typedef RAW NAME##_t; \
    typedef const RAW NAME##_ct; \
    typedef NAME##_t* NAME##_pt; \
    typedef NAME##_ct* NAME##_cpt
#endif

FGE_DEFINE_TYPE(void*, fge_ptr);
FGE_DEFINE_TYPE(bool, fge_bool);
FGE_DEFINE_TYPE(uintptr_t, fge_uintptr);
FGE_DEFINE_TYPE(uintptr_t, fge_index);
FGE_DEFINE_TYPE(uintptr_t, fge_size);
FGE_DEFINE_TYPE(int8_t, fge_int8);
FGE_DEFINE_TYPE(uint8_t, fge_uint8);
FGE_DEFINE_TYPE(int16_t, fge_int16);
FGE_DEFINE_TYPE(uint16_t, fge_uint16);
FGE_DEFINE_TYPE(int32_t, fge_int32);
FGE_DEFINE_TYPE(uint32_t, fge_uint32);
FGE_DEFINE_TYPE(int64_t, fge_int64);
FGE_DEFINE_TYPE(uint64_t, fge_uint64);
FGE_DEFINE_TYPE(float, fge_float32);
FGE_DEFINE_TYPE(double, fge_float64);
FGE_DEFINE_TYPE(long double, fge_float80);

#endif
