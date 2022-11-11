#ifndef FGE_STR_UTF8_INTERNAL_H
#define FGE_STR_UTF8_INTERNAL_H

#include <fge/str/utf8.h>
#include <fge/mem.h>

#include <string.h>

#define FGE_STR_CALCULATE_CAPACITY(count) (((count) * 2) + 1)

static fge_u8_ct FGE_STR_NULL_CHARS[] = { '\0' };

#endif
