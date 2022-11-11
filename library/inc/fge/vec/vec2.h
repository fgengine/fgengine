#ifndef FGE_MATH_VECTOR2_H
#define FGE_MATH_VECTOR2_H

#include <fge/std.h>

#define FGE_MATH_VECTOR_2(TYPE) \
    struct fge_vec2_##TYPE { \
        union { \
            struct { \
                fge_##TYPE##_t x; \
                fge_##TYPE##_t y; \
            }; \
            fge_##TYPE##_t v[2]; \
        }; \
    }; \
    typedef struct fge_vec2_##TYPE fge_vec2_##TYPE##_t; \
    typedef const fge_vec2_##TYPE##_t fge_vec2_##TYPE##_ct; \
    typedef fge_vec2_##TYPE##_t* fge_vec2_##TYPE##_pt; \
    typedef fge_vec2_##TYPE##_ct* fge_vec2_##TYPE##_cpt

FGE_MATH_VECTOR_2(i8);
FGE_MATH_VECTOR_2(i16);
FGE_MATH_VECTOR_2(i32);
FGE_MATH_VECTOR_2(i64);

FGE_MATH_VECTOR_2(u8);
FGE_MATH_VECTOR_2(u16);
FGE_MATH_VECTOR_2(u32);
FGE_MATH_VECTOR_2(u64);

FGE_MATH_VECTOR_2(f32);
FGE_MATH_VECTOR_2(f64);
FGE_MATH_VECTOR_2(f80);

#endif
