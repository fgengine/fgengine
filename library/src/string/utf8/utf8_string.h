#ifndef FGE_UTF8_STRING_INTERNAL_H
#define FGE_UTF8_STRING_INTERNAL_H

#include <fge/string/utf8.h>
#include <fge/memory.h>

#include <string.h>

#define FGE_STRING_CALCULATE_CAPACITY(count) (((count) * 2) + 1)

static fge_uint8_ct FGE_STRING_NULL_CHARS[] = { '\0' };

#endif
