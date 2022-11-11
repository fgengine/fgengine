#include <fge/string.h>

fge_bool_t test_init() {
    {
        fge_string_t str;
        if(fge_string_init_buffer(&str, "H e l l o W o r l d") == false) {
            return false;
        }
        if(fge_string_is_equal_buffer(&str, "H e l l o W o r l d") == false) {
            return false;
        }
        fge_string_free(&str);
    }
    return true;
}

fge_bool_t test_length() {
    {
        fge_string_t str;
        fge_string_init_buffer(&str, "Hello World");
        if(fge_string_length(&str) != 11) {
            return false;
        }
        fge_string_free(&str);
    }
    {
        fge_string_t str;
        fge_string_init_buffer(&str, "Hello World ©");
        if(fge_string_length(&str) != 13) {
            return false;
        }
        fge_string_free(&str);
    }
    return true;
}

fge_bool_t test_check() {
    {
        fge_string_t str;
        fge_string_init_buffer(&str, "Hello W o r l d");
        if(fge_string_is_prefix_buffer(&str, "Hello") == false) {
            return false;
        }
        fge_string_free(&str);
    }
    {
        fge_string_t str;
        fge_string_init_buffer(&str, "H e l l o World");
        if(fge_string_is_suffix_buffer(&str, "World") == false) {
            return false;
        }
        fge_string_free(&str);
    }
    return true;
}

fge_bool_t test_insert() {
    {
        fge_string_t a;
        fge_string_init_buffer(&a, "H e l l o");
        fge_string_t b;
        fge_string_init_buffer(&b, " W o r l d");
        fge_string_insert_string(&a, fge_string_end_index(&a), &b);
        if(fge_string_is_equal_buffer(&a, "H e l l o W o r l d") == false) {
            return false;
        }
        fge_string_free(&a);
        fge_string_free(&b);
    }
    return true;
}

fge_bool_t test_remove() {
    {
        fge_string_t str;
        if(fge_string_init_buffer(&str, "  H e l l o  W o r l d  ") == false) {
            return false;
        }
        if(fge_string_remove_first_buffer(&str, fge_string_range(&str), "  ") == false) {
            return false;
        }
        if(fge_string_is_equal_buffer(&str, "H e l l o  W o r l d  ") == false) {
            return false;
        }
        if(fge_string_fit(&str) == false) {
            return false;
        }
        fge_string_free(&str);
    }
    {
        fge_string_t str;
        if(fge_string_init_buffer(&str, "  H e l l o  W o r l d  ") == false) {
            return false;
        }
        if(fge_string_remove_last_buffer(&str, fge_string_range(&str), "  ") == false) {
            return false;
        }
        if(fge_string_is_equal_buffer(&str, "  H e l l o  W o r l d") == false) {
            return false;
        }
        if(fge_string_fit(&str) == false) {
            return false;
        }
        fge_string_free(&str);
    }
    {
        fge_string_t str;
        if(fge_string_init_buffer(&str, "  H e l l o   W o r l d  ") == false) {
            return false;
        }
        if(fge_string_remove_buffer(&str, fge_string_range(&str), "  ") == 0) {
            return false;
        }
        if(fge_string_is_equal_buffer(&str, "H e l l o W o r l d") == false) {
            return false;
        }
        if(fge_string_fit(&str) == false) {
            return false;
        }
        fge_string_free(&str);
    }
    return true;
}

fge_bool_t test_replace() {
    {
        fge_string_t str;
        if(fge_string_init_buffer(&str, " H e l l o  W o r l d ") == false) {
            return false;
        }
        if(fge_string_replace_all_buffer(&str, fge_string_range(&str), " ", "-") == false) {
            return false;
        }
        if(fge_string_is_equal_buffer(&str, "-H-e-l-l-o--W-o-r-l-d-") == false) {
            return false;
        }
        if(fge_string_fit(&str) == false) {
            return false;
        }
        fge_string_free(&str);
    }
    return true;
}

int main() {
    for(int i = 0; i < 1000000; i++) {
        if(test_init() != true) {
            return EXIT_FAILURE;
        }
        if(test_length() != true) {
            return EXIT_FAILURE;
        }
        if(test_check() != true) {
            return EXIT_FAILURE;
        }
        if(test_insert() != true) {
            return EXIT_FAILURE;
        }
        if(test_remove() != true) {
            return EXIT_FAILURE;
        }
        if(test_replace() != true) {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
