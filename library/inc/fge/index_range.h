#ifndef FGE_INDEX_RANGE_H
#define FGE_INDEX_RANGE_H

#include <fge/types.h>

FGE_DEFINE_TYPE(struct fge_index_range, fge_index_range);

struct fge_index_range {
    fge_index_t lower;
    fge_index_t upper;
};

#endif
