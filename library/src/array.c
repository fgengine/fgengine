#include <fge/array.h>
#include <fge/memory.h>
/*
#define FGE_STRING_CALCULATE_CAPACITY(size) (((size) * 2) + 1)

static fge_uint8_ct FGE_NULL_STRING_CHARS[] = { '\0' };


fge_array_t fge_array(fge_size_t element_size) {
    fge_array_t str;
    fge_array_init_default(&str, element_size);
    return str;
}

void fge_array_init_default(fge_array_pt self, fge_size_t element_size) {
    self->data = NULL;
    self->element_size = element_size;
    self->count = 0;
    self->capacity = 0;
}

fge_bool_t fge_array_init_array(fge_array_pt self, fge_array_cpt array) {
    self->data = malloc(array->capacity);
    if(self->data != NULL) {
        fge_memory_copy(
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
    return fge_array_is_not_empty(self);
}

void fge_array_free(fge_array_pt self) {
    if(self->data != NULL) {
        free(self->data);
    }
    self->data = NULL;
    self->element_size = 0;
    self->count = 0;
    self->capacity = 0;
}

fge_bool_t fge_array_copy(fge_array_pt self, fge_array_pt array) {
    fge_array_free(self);
    return fge_array_init_array(self, array);
}

void fge_array_move(fge_array_pt self, fge_array_pt array) {
    fge_array_free(self);
    self->data = array->data;
    self->element_size = array->element_size;
    self->count = array->count;
    self->capacity = array->capacity;
    fge_array_init_default(array, self->element_size);
}

fge_bool_t fge_array_fit(fge_array_pt self) {
    if(self->count >= self->capacity) {
        return true;
    }
    fge_char_cpt old_ptr = fge_array_pointer(self);
    if(self->size >= FGE_STRING_STATIC_SIZE) {
        fge_char_pt new_ptr = malloc(self->size);
        if(new_ptr == NULL) {
            return false;
        }
        fge_memory_copy(
            new_ptr, self->size,
            self->ptr, self->capacity);
        self->ptr = new_ptr;
        self->capacity = self->size;
    } else {
        fge_memory_copy(
            &self->chars, self->size,
            self->ptr, self->size);
        self->capacity = 0;
    }
    free((fge_ptr_t)old_ptr);
    return true;
}

fge_char_pt fge_array_pointer(fge_array_cpt self) {
    if((self->flags & FGE_STRING_NEED_COPY) || (self->capacity > 0)) {
        return self->ptr;
    }
    return (fge_char_pt)self->chars;
}

fge_size_t fge_array_length(fge_array_cpt self) {
    fge_char_cpt ptr = fge_array_pointer(self);
    fge_size_t length = 0;
    while(*ptr != '\0') {
        if((*ptr & 0xc0) != 0x80) {
            ++length;
        }
        ++ptr;
    }
    return length;
}

fge_size_t fge_array_size(fge_array_cpt self) {
    return self->size;
}

fge_size_t fge_array_capacity(fge_array_cpt self) {
    return self->capacity;
}

fge_array_range_t fge_array_range(fge_array_cpt self) {
    return (fge_array_range_t){ .lower = 0, .upper = self->size };
}

fge_index_t fge_array_start_index(fge_array_cpt self) {
    return 0;
}

fge_index_t fge_array_end_index(fge_array_cpt self) {
    return self->size;
}

fge_bool_t fge_array_is_empty(fge_array_cpt self) {
    return self->size == 0;
}

fge_bool_t fge_array_is_not_empty(fge_array_cpt self) {
    return self->size > 0;
}

fge_bool_t fge_array_is_equal(fge_array_cpt self, fge_char_cpt chars, fge_size_t size) {
    if(self->size != size) {
        return false;
    }
    return fge_memory_is_equal(fge_array_pointer(self), (fge_ptr_t)chars, size);
}

fge_bool_t fge_array_is_equal_buffer(fge_array_cpt self, fge_char_cpt chars) {
    return fge_array_is_equal(self, chars, strlen(chars));
}

fge_bool_t fge_array_is_prefix(fge_array_cpt self, fge_char_cpt chars, fge_size_t size) {
    if(self->size < size) {
        return false;
    }
    return fge_memory_is_equal(fge_array_pointer(self), (fge_ptr_t)chars, size);
}

fge_bool_t fge_array_is_prefix_buffer(fge_array_cpt self, fge_char_cpt chars) {
    return fge_array_is_prefix(self, chars, strlen(chars));
}

fge_bool_t fge_array_is_suffix(fge_array_cpt self, fge_char_cpt chars, fge_size_t size) {
    if(self->size < size) {
        return false;
    }
    return fge_memory_is_equal(fge_array_pointer(self) + (self->size - size), (fge_ptr_t)chars, size);
}

fge_bool_t fge_array_is_suffix_buffer(fge_array_cpt self, fge_char_cpt chars) {
    return fge_array_is_suffix(self, chars, strlen(chars));
}

fge_array_range_t fge_array_start_find(fge_array_cpt self, fge_array_range_t range, fge_char_cpt chars, fge_size_t size) {
    fge_size_t lower = (range.lower < self->size) ? range.lower : self->size;
    fge_size_t upper = (range.upper < self->size) ? range.upper : self->size;
    fge_memory_range_t dst_range = fge_memory_find_forward(
        fge_array_pointer(self),
        (fge_memory_range_t){ .lower = lower, .upper = upper },
        (fge_ptr_t)chars,
        size);
    return (fge_array_range_t){ .lower = dst_range.lower, .upper = dst_range.upper };
}

fge_array_range_t fge_array_find_buffer(fge_array_cpt self, fge_array_range_t range, fge_char_cpt chars) {
    return fge_array_start_find(self, range, chars, strlen(chars));
}

fge_array_range_t fge_array_find_end(fge_array_cpt self, fge_array_range_t range, fge_char_cpt chars, fge_size_t size) {
    fge_size_t lower = (range.lower < self->size) ? range.lower : self->size;
    fge_size_t upper = (range.upper < self->size) ? range.upper : self->size;
    fge_memory_range_t dst_range = fge_memory_find_backward(
        fge_array_pointer(self),
        (fge_memory_range_t){ .lower = lower, .upper = upper },
        (fge_ptr_t)chars,
        size);
    return (fge_array_range_t){ .lower = dst_range.lower, .upper = dst_range.upper };
}

fge_array_range_t fge_array_find_end_buffer(fge_array_cpt self, fge_array_range_t range, fge_char_cpt chars) {
    return fge_array_find_end(self, range, chars, strlen(chars));
}

fge_bool_t fge_array_insert(fge_array_pt self, fge_index_t index, fge_char_cpt chars, fge_size_t size) {
    if(fge_array_is_empty(self) == true) {
        return fge_array_init(self, 0, chars, size);
    }
    fge_size_t insert_index = (index <= self->size) ? index : self->size - 1;
    fge_size_t new_size = self->size + size;
    fge_char_cpt old_ptr = fge_array_pointer(self);
    fge_size_t old_capacity = (self->capacity > 0) ? self->size : FGE_STRING_STATIC_SIZE;
    if((self->flags & FGE_STRING_NEED_COPY) || (self->capacity > 0) || (new_size >= self->capacity)) {
        fge_size_t new_capacity = FGE_STRING_CALCULATE_CAPACITY(new_size);
        fge_char_pt new_ptr = malloc(new_capacity);
        if(new_ptr != NULL) {
            fge_size_t offset = 0;
            if(insert_index > 0) {
                offset += fge_memory_copy(
                    new_ptr, new_capacity,
                                          (fge_ptr_t)old_ptr, insert_index);
            }
            offset += fge_memory_copy(
                &new_ptr[insert_index], new_capacity - offset,
                (fge_ptr_t)chars, size);
            fge_memory_copy_fill(
                &new_ptr[insert_index + size], new_capacity - offset,
                (fge_ptr_t)&old_ptr[insert_index], old_capacity - insert_index,
                (fge_ptr_t)&FGE_NULL_STRING_CHARS, 1);
            if(self->capacity > 0) {
                free(self->ptr);
            }
            self->ptr = new_ptr;
            self->size = new_size;
            self->capacity = new_capacity;
        }
    } else {
        if(insert_index < self->size) {
            fge_memory_move(
                (fge_ptr_t)&old_ptr[insert_index + size],
                (fge_ptr_t)&old_ptr[insert_index],
                old_capacity - size);
        }
        fge_memory_copy(
            (fge_ptr_t)&old_ptr[insert_index], size,
            (fge_ptr_t)chars, size);
        self->size = new_size;
    }
    return self->size == new_size;
}

fge_bool_t fge_array_insert_buffer(fge_array_pt self, fge_index_t index, fge_char_cpt chars) {
    return fge_array_insert(self, index, chars, strlen(chars));
}

void fge_array_remove_all(fge_array_pt self) {
    fge_array_free(self);
}

fge_bool_t fge_array_remove_range(fge_array_pt self, fge_array_range_t range) {
    fge_size_t lower = (range.lower < self->size) ? range.lower : self->size;
    fge_size_t upper = (range.upper < self->size) ? range.upper : self->size;
    if(lower >= upper) {
        return false;
    }
    fge_char_cpt old_ptr = fge_array_pointer(self);
    fge_size_t delta = upper - lower;
    if(self->flags & FGE_STRING_NEED_COPY) {
        fge_size_t new_capacity = FGE_STRING_CALCULATE_CAPACITY(self->size);
        fge_char_pt new_ptr = malloc(new_capacity);
        if(new_ptr == NULL) {
            return false;
        }
        if(lower > 0) {
            fge_memory_copy(
                new_ptr, lower,
                (fge_ptr_t)old_ptr, lower);
        }
        if(upper < self->size) {
            fge_memory_copy(
                &new_ptr[lower], self->size - upper,
                (fge_ptr_t)&old_ptr[upper], self->size - upper);
        }
        self->flags = self->flags & ~FGE_STRING_NEED_COPY;
        self->ptr = new_ptr;
        self->capacity = new_capacity;
    } else {
        fge_size_t size = (self->capacity > 0) ? self->size : FGE_STRING_STATIC_SIZE;
        fge_memory_move(
            (fge_ptr_t)&old_ptr[lower],
            (fge_ptr_t)&old_ptr[upper],
            (size - upper) + 1);
    }
    self->size -= delta;
    return true;
}

fge_bool_t fge_array_remove_first(fge_array_pt self, fge_array_range_t range, fge_char_cpt chars, fge_size_t size) {
    fge_array_range_t find = fge_array_start_find(self, range, chars, size);
    if(find.lower >= find.upper) {
        return false;
    }
    return fge_array_remove_range(self, find);
}

fge_bool_t fge_array_remove_first_buffer(fge_array_pt self, fge_array_range_t range, fge_char_cpt chars) {
    return fge_array_remove_first(self, range, chars, strlen(chars));
}

fge_bool_t fge_array_remove_last(fge_array_pt self, fge_array_range_t range, fge_char_cpt chars, fge_size_t size) {
    fge_array_range_t find = fge_array_find_end(self, range, chars, size);
    if(find.lower == find.upper) {
        return false;
    }
    return fge_array_remove_range(self, find);
}

fge_bool_t fge_array_remove_last_buffer(fge_array_pt self, fge_array_range_t range, fge_char_cpt chars) {
    return fge_array_remove_last(self, range, chars, strlen(chars));
}

fge_size_t fge_array_remove(fge_array_pt self, fge_array_range_t range, fge_char_cpt chars, fge_size_t size) {
    fge_size_t removed = 0;
    while(true) {
        fge_array_range_t find_range = fge_array_start_find(self, range, chars, size);
        if(find_range.lower >= find_range.upper) {
            break;
        }
        if(fge_array_remove_range(self, find_range) == false) {
            break;
        }
        range.upper -= find_range.upper - find_range.lower;
        range.lower = find_range.lower;
        removed += 1;
    }
    return removed;
}

fge_size_t fge_array_remove_buffer(fge_array_pt self, fge_array_range_t range, fge_char_cpt chars) {
    return fge_array_remove(self, range, chars, strlen(chars));
}

fge_bool_t fge_array_replace_range(fge_array_pt self, fge_array_range_t range, fge_char_cpt chars, fge_size_t size) {
    if(fge_array_remove_range(self, range) == false) {
        return false;
    }
    return fge_array_insert(self, range.lower, chars, size);
}

fge_bool_t fge_array_replace_range_buffer(fge_array_pt self, fge_array_range_t range, fge_char_cpt chars) {
    return fge_array_replace_range(self, range, chars, strlen(chars));
}

fge_bool_t fge_array_replace_first(fge_array_pt self, fge_array_range_t range, fge_char_cpt find_chars, fge_size_t find_size, fge_char_cpt replace_chars, fge_size_t replace_size) {
    fge_array_range_t find_range = fge_array_start_find(self, range, find_chars, find_size);
    if(find_range.lower == find_range.upper) {
        return false;
    }
    if(fge_array_remove_range(self, find_range) == false) {
        return false;
    }
    return fge_array_insert(self, find_range.lower, replace_chars, replace_size);
}

fge_bool_t fge_array_replace_first_buffer(fge_array_pt self, fge_array_range_t range, fge_char_cpt find_chars, fge_char_cpt replace_chars) {
    return fge_array_replace_first(self, range, find_chars, strlen(find_chars), replace_chars, strlen(replace_chars));
}

fge_bool_t fge_array_replace_last(fge_array_pt self, fge_array_range_t range, fge_char_cpt find_chars, fge_size_t find_size, fge_char_cpt replace_chars, fge_size_t replace_size) {
    fge_array_range_t find_range = fge_array_find_end(self, range, find_chars, find_size);
    if(find_range.lower == find_range.upper) {
        return false;
    }
    if(fge_array_remove_range(self, find_range) == false) {
        return false;
    }
    return fge_array_insert(self, find_range.lower, replace_chars, replace_size);
}

fge_bool_t fge_array_replace_last_buffer(fge_array_pt self, fge_array_range_t range, fge_char_cpt find_chars, fge_char_cpt replace_chars) {
    return fge_array_replace_last(self, range, find_chars, strlen(find_chars), replace_chars, strlen(replace_chars));
}

fge_size_t fge_array_replace_all(fge_array_pt self, fge_array_range_t range, fge_char_cpt find_chars, fge_size_t find_size, fge_char_cpt replace_chars, fge_size_t replace_size) {
    fge_size_t replaced = 0;
    while(true) {
        fge_array_range_t find_range = fge_array_start_find(self, range, find_chars, find_size);
        if(find_range.lower >= find_range.upper) {
            break;
        }
        if(fge_array_remove_range(self, find_range) == false) {
            break;
        }
        if(fge_array_insert(self, find_range.lower, replace_chars, replace_size) == false) {
            break;
        }
        range.upper -= (find_range.upper - find_range.lower) - replace_size;
        range.lower = find_range.lower + replace_size;
        replaced += 1;
    }
    return replaced;
}

fge_size_t fge_array_replace_all_buffer(fge_array_pt self, fge_array_range_t range, fge_char_cpt find_chars, fge_char_cpt replace_chars) {
    return fge_array_replace_all(self, range, find_chars, strlen(find_chars), replace_chars, strlen(replace_chars));
}
*/
