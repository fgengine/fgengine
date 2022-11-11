#include <fge/arr.h>
#include <fge/mem.h>
/*
#define FGE_STR_CALCULATE_CAPACITY(size) (((size) * 2) + 1)

static fge_uint8_ct FGE_NULL_STR_CHARS[] = { '\0' };


fge_arr_t fge_arr(fge_sz_t element_size) {
    fge_arr_t str;
    fge_arr_init_default(&str, element_size);
    return str;
}

void fge_arr_init_default(fge_arr_pt self, fge_sz_t element_size) {
    self->data = NULL;
    self->element_size = element_size;
    self->count = 0;
    self->capacity = 0;
}

fge_bool_t fge_arr_init_arr(fge_arr_pt self, fge_arr_cpt array) {
    self->data = malloc(array->capacity);
    if(self->data != NULL) {
        fge_mem_copy(
            self->data, array->capacity,
            array->data, array->capacity);
        self->element_size = array->element_size;
        self->count = array->count;
        self->capacity = array->capacity;
    } else {
        self->data = NULL;
        self->element_size = 0;
        self->count = 0;
        self->capacity = 0;
    }
    return fge_arr_is_not_empty(self);
}

void fge_arr_free(fge_arr_pt self) {
    if(self->data != NULL) {
        free(self->data);
    }
    self->data = NULL;
    self->element_size = 0;
    self->count = 0;
    self->capacity = 0;
}

fge_bool_t fge_arr_copy(fge_arr_pt self, fge_arr_pt array) {
    fge_arr_free(self);
    return fge_arr_init_arr(self, array);
}

void fge_arr_move(fge_arr_pt self, fge_arr_pt array) {
    fge_arr_free(self);
    self->data = array->data;
    self->element_size = array->element_size;
    self->count = array->count;
    self->capacity = array->capacity;
    fge_arr_init_default(array, self->element_size);
}

fge_bool_t fge_arr_fit(fge_arr_pt self) {
    if(self->count >= self->capacity) {
        return true;
    }
    fge_char_cpt old_ptr = fge_arr_pointer(self);
    if(self->size >= FGE_STR_STATIC_SIZE) {
        fge_char_pt new_ptr = malloc(self->size);
        if(new_ptr == NULL) {
            return false;
        }
        fge_mem_copy(
            new_ptr, self->size,
            self->ptr, self->capacity);
        self->ptr = new_ptr;
        self->capacity = self->size;
    } else {
        fge_mem_copy(
            &self->chars, self->size,
            self->ptr, self->size);
        self->capacity = 0;
    }
    free((fge_ptr_t)old_ptr);
    return true;
}

fge_char_pt fge_arr_pointer(fge_arr_cpt self) {
    if((self->flags & FGE_STR_NEED_COPY) || (self->capacity > 0)) {
        return self->ptr;
    }
    return (fge_char_pt)self->chars;
}

fge_sz_t fge_arr_length(fge_arr_cpt self) {
    fge_char_cpt ptr = fge_arr_pointer(self);
    fge_sz_t length = 0;
    while(*ptr != '\0') {
        if((*ptr & 0xc0) != 0x80) {
            ++length;
        }
        ++ptr;
    }
    return length;
}

fge_sz_t fge_arr_size(fge_arr_cpt self) {
    return self->size;
}

fge_sz_t fge_arr_capacity(fge_arr_cpt self) {
    return self->capacity;
}

fge_arr_range_t fge_arr_range(fge_arr_cpt self) {
    return (fge_arr_range_t){ .lower = 0, .upper = self->size };
}

fge_idx_t fge_arr_start_index(fge_arr_cpt self) {
    return 0;
}

fge_idx_t fge_arr_end_index(fge_arr_cpt self) {
    return self->size;
}

fge_bool_t fge_arr_is_empty(fge_arr_cpt self) {
    return self->size == 0;
}

fge_bool_t fge_arr_is_not_empty(fge_arr_cpt self) {
    return self->size > 0;
}

fge_bool_t fge_arr_is_equal(fge_arr_cpt self, fge_char_cpt chars, fge_sz_t size) {
    if(self->size != size) {
        return false;
    }
    return fge_mem_is_equal(fge_arr_pointer(self), (fge_ptr_t)chars, size);
}

fge_bool_t fge_arr_is_equal_buff(fge_arr_cpt self, fge_char_cpt chars) {
    return fge_arr_is_equal(self, chars, strlen(chars));
}

fge_bool_t fge_arr_is_prefix(fge_arr_cpt self, fge_char_cpt chars, fge_sz_t size) {
    if(self->size < size) {
        return false;
    }
    return fge_mem_is_equal(fge_arr_pointer(self), (fge_ptr_t)chars, size);
}

fge_bool_t fge_arr_is_prefix_buff(fge_arr_cpt self, fge_char_cpt chars) {
    return fge_arr_is_prefix(self, chars, strlen(chars));
}

fge_bool_t fge_arr_is_suffix(fge_arr_cpt self, fge_char_cpt chars, fge_sz_t size) {
    if(self->size < size) {
        return false;
    }
    return fge_mem_is_equal(fge_arr_pointer(self) + (self->size - size), (fge_ptr_t)chars, size);
}

fge_bool_t fge_arr_is_suffix_buff(fge_arr_cpt self, fge_char_cpt chars) {
    return fge_arr_is_suffix(self, chars, strlen(chars));
}

fge_arr_range_t fge_arr_start_find(fge_arr_cpt self, fge_arr_range_t range, fge_char_cpt chars, fge_sz_t size) {
    fge_sz_t lower = (range.lower < self->size) ? range.lower : self->size;
    fge_sz_t upper = (range.upper < self->size) ? range.upper : self->size;
    fge_mem_range_t dst_range = fge_mem_find_forward(
        fge_arr_pointer(self),
        (fge_mem_range_t){ .lower = lower, .upper = upper },
        (fge_ptr_t)chars,
        size);
    return (fge_arr_range_t){ .lower = dst_range.lower, .upper = dst_range.upper };
}

fge_arr_range_t fge_arr_find_buff(fge_arr_cpt self, fge_arr_range_t range, fge_char_cpt chars) {
    return fge_arr_start_find(self, range, chars, strlen(chars));
}

fge_arr_range_t fge_arr_find_end(fge_arr_cpt self, fge_arr_range_t range, fge_char_cpt chars, fge_sz_t size) {
    fge_sz_t lower = (range.lower < self->size) ? range.lower : self->size;
    fge_sz_t upper = (range.upper < self->size) ? range.upper : self->size;
    fge_mem_range_t dst_range = fge_mem_find_backward(
        fge_arr_pointer(self),
        (fge_mem_range_t){ .lower = lower, .upper = upper },
        (fge_ptr_t)chars,
        size);
    return (fge_arr_range_t){ .lower = dst_range.lower, .upper = dst_range.upper };
}

fge_arr_range_t fge_arr_find_end_buff(fge_arr_cpt self, fge_arr_range_t range, fge_char_cpt chars) {
    return fge_arr_find_end(self, range, chars, strlen(chars));
}

fge_bool_t fge_arr_insert(fge_arr_pt self, fge_idx_t index, fge_char_cpt chars, fge_sz_t size) {
    if(fge_arr_is_empty(self) == true) {
        return fge_arr_init(self, 0, chars, size);
    }
    fge_sz_t insert_index = (index <= self->size) ? index : self->size - 1;
    fge_sz_t new_size = self->size + size;
    fge_char_cpt old_ptr = fge_arr_pointer(self);
    fge_sz_t old_capacity = (self->capacity > 0) ? self->size : FGE_STR_STATIC_SIZE;
    if((self->flags & FGE_STR_NEED_COPY) || (self->capacity > 0) || (new_size >= self->capacity)) {
        fge_sz_t new_capacity = FGE_STR_CALCULATE_CAPACITY(new_size);
        fge_char_pt new_ptr = malloc(new_capacity);
        if(new_ptr != NULL) {
            fge_sz_t offset = 0;
            if(insert_index > 0) {
                offset += fge_mem_copy(
                    new_ptr, new_capacity,
                                          (fge_ptr_t)old_ptr, insert_index);
            }
            offset += fge_mem_copy(
                &new_ptr[insert_index], new_capacity - offset,
                (fge_ptr_t)chars, size);
            fge_mem_copy_fill(
                &new_ptr[insert_index + size], new_capacity - offset,
                (fge_ptr_t)&old_ptr[insert_index], old_capacity - insert_index,
                (fge_ptr_t)&FGE_NULL_STR_CHARS, 1);
            if(self->capacity > 0) {
                free(self->ptr);
            }
            self->ptr = new_ptr;
            self->size = new_size;
            self->capacity = new_capacity;
        }
    } else {
        if(insert_index < self->size) {
            fge_mem_move(
                (fge_ptr_t)&old_ptr[insert_index + size],
                (fge_ptr_t)&old_ptr[insert_index],
                old_capacity - size);
        }
        fge_mem_copy(
            (fge_ptr_t)&old_ptr[insert_index], size,
            (fge_ptr_t)chars, size);
        self->size = new_size;
    }
    return self->size == new_size;
}

fge_bool_t fge_arr_insert_buff(fge_arr_pt self, fge_idx_t index, fge_char_cpt chars) {
    return fge_arr_insert(self, index, chars, strlen(chars));
}

void fge_arr_remove_all(fge_arr_pt self) {
    fge_arr_free(self);
}

fge_bool_t fge_arr_remove_range(fge_arr_pt self, fge_arr_range_t range) {
    fge_sz_t lower = (range.lower < self->size) ? range.lower : self->size;
    fge_sz_t upper = (range.upper < self->size) ? range.upper : self->size;
    if(lower >= upper) {
        return false;
    }
    fge_char_cpt old_ptr = fge_arr_pointer(self);
    fge_sz_t delta = upper - lower;
    if(self->flags & FGE_STR_NEED_COPY) {
        fge_sz_t new_capacity = FGE_STR_CALCULATE_CAPACITY(self->size);
        fge_char_pt new_ptr = malloc(new_capacity);
        if(new_ptr == NULL) {
            return false;
        }
        if(lower > 0) {
            fge_mem_copy(
                new_ptr, lower,
                (fge_ptr_t)old_ptr, lower);
        }
        if(upper < self->size) {
            fge_mem_copy(
                &new_ptr[lower], self->size - upper,
                (fge_ptr_t)&old_ptr[upper], self->size - upper);
        }
        self->flags = self->flags & ~FGE_STR_NEED_COPY;
        self->ptr = new_ptr;
        self->capacity = new_capacity;
    } else {
        fge_sz_t size = (self->capacity > 0) ? self->size : FGE_STR_STATIC_SIZE;
        fge_mem_move(
            (fge_ptr_t)&old_ptr[lower],
            (fge_ptr_t)&old_ptr[upper],
            (size - upper) + 1);
    }
    self->size -= delta;
    return true;
}

fge_bool_t fge_arr_remove_first(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt chars, fge_sz_t size) {
    fge_arr_range_t find = fge_arr_start_find(self, range, chars, size);
    if(find.lower >= find.upper) {
        return false;
    }
    return fge_arr_remove_range(self, find);
}

fge_bool_t fge_arr_remove_first_buff(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt chars) {
    return fge_arr_remove_first(self, range, chars, strlen(chars));
}

fge_bool_t fge_arr_remove_last(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt chars, fge_sz_t size) {
    fge_arr_range_t find = fge_arr_find_end(self, range, chars, size);
    if(find.lower == find.upper) {
        return false;
    }
    return fge_arr_remove_range(self, find);
}

fge_bool_t fge_arr_remove_last_buff(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt chars) {
    return fge_arr_remove_last(self, range, chars, strlen(chars));
}

fge_sz_t fge_arr_remove(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt chars, fge_sz_t size) {
    fge_sz_t removed = 0;
    while(true) {
        fge_arr_range_t find_range = fge_arr_start_find(self, range, chars, size);
        if(find_range.lower >= find_range.upper) {
            break;
        }
        if(fge_arr_remove_range(self, find_range) == false) {
            break;
        }
        range.upper -= find_range.upper - find_range.lower;
        range.lower = find_range.lower;
        removed += 1;
    }
    return removed;
}

fge_sz_t fge_arr_remove_buff(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt chars) {
    return fge_arr_remove(self, range, chars, strlen(chars));
}

fge_bool_t fge_arr_replace_range(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt chars, fge_sz_t size) {
    if(fge_arr_remove_range(self, range) == false) {
        return false;
    }
    return fge_arr_insert(self, range.lower, chars, size);
}

fge_bool_t fge_arr_replace_range_buff(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt chars) {
    return fge_arr_replace_range(self, range, chars, strlen(chars));
}

fge_bool_t fge_arr_replace_first(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt find_chars, fge_sz_t find_size, fge_char_cpt replace_chars, fge_sz_t replace_size) {
    fge_arr_range_t find_range = fge_arr_start_find(self, range, find_chars, find_size);
    if(find_range.lower == find_range.upper) {
        return false;
    }
    if(fge_arr_remove_range(self, find_range) == false) {
        return false;
    }
    return fge_arr_insert(self, find_range.lower, replace_chars, replace_size);
}

fge_bool_t fge_arr_replace_first_buff(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt find_chars, fge_char_cpt replace_chars) {
    return fge_arr_replace_first(self, range, find_chars, strlen(find_chars), replace_chars, strlen(replace_chars));
}

fge_bool_t fge_arr_replace_last(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt find_chars, fge_sz_t find_size, fge_char_cpt replace_chars, fge_sz_t replace_size) {
    fge_arr_range_t find_range = fge_arr_find_end(self, range, find_chars, find_size);
    if(find_range.lower == find_range.upper) {
        return false;
    }
    if(fge_arr_remove_range(self, find_range) == false) {
        return false;
    }
    return fge_arr_insert(self, find_range.lower, replace_chars, replace_size);
}

fge_bool_t fge_arr_replace_last_buff(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt find_chars, fge_char_cpt replace_chars) {
    return fge_arr_replace_last(self, range, find_chars, strlen(find_chars), replace_chars, strlen(replace_chars));
}

fge_sz_t fge_arr_replace_all(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt find_chars, fge_sz_t find_size, fge_char_cpt replace_chars, fge_sz_t replace_size) {
    fge_sz_t replaced = 0;
    while(true) {
        fge_arr_range_t find_range = fge_arr_start_find(self, range, find_chars, find_size);
        if(find_range.lower >= find_range.upper) {
            break;
        }
        if(fge_arr_remove_range(self, find_range) == false) {
            break;
        }
        if(fge_arr_insert(self, find_range.lower, replace_chars, replace_size) == false) {
            break;
        }
        range.upper -= (find_range.upper - find_range.lower) - replace_size;
        range.lower = find_range.lower + replace_size;
        replaced += 1;
    }
    return replaced;
}

fge_sz_t fge_arr_replace_all_buff(fge_arr_pt self, fge_arr_range_t range, fge_char_cpt find_chars, fge_char_cpt replace_chars) {
    return fge_arr_replace_all(self, range, find_chars, strlen(find_chars), replace_chars, strlen(replace_chars));
}
*/
