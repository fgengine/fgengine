#include <fge/string.h>

fge_bool_t test_init() {
    {
        fge_STR_t str;
        if(fge_STR_init_buff(&str, "H e l l o W o r l d") == false) {
            return false;
        }
        if(fge_STR_is_equal_buff(&str, "H e l l o W o r l d") == false) {
            return false;
        }
        fge_STR_free(&str);
    }
    return true;
}

fge_bool_t test_length() {
    {
        fge_STR_t str;
        fge_STR_init_buff(&str, "Hello World");
        if(fge_STR_length(&str) != 11) {
            return false;
        }
        fge_STR_free(&str);
    }
    {
        fge_STR_t str;
        fge_STR_init_buff(&str, "Hello World ©");
        if(fge_STR_length(&str) != 13) {
            return false;
        }
        fge_STR_free(&str);
    }
    return true;
}

fge_bool_t test_check() {
    {
        fge_STR_t str;
        fge_STR_init_buff(&str, "Hello W o r l d");
        if(fge_STR_is_prefix_buff(&str, "Hello") == false) {
            return false;
        }
        fge_STR_free(&str);
    }
    {
        fge_STR_t str;
        fge_STR_init_buff(&str, "H e l l o World");
        if(fge_STR_is_suffix_buff(&str, "World") == false) {
            return false;
        }
        fge_STR_free(&str);
    }
    return true;
}

fge_bool_t test_insert() {
    {
        fge_STR_t a;
        fge_STR_init_buff(&a, "H e l l o");
        fge_STR_t b;
        fge_STR_init_buff(&b, " W o r l d");
        fge_STR_insert_string(&a, fge_STR_end_index(&a), &b);
        if(fge_STR_is_equal_buff(&a, "H e l l o W o r l d") == false) {
            return false;
        }
        fge_STR_free(&a);
        fge_STR_free(&b);
    }
    return true;
}

fge_bool_t test_remove() {
    {
        fge_STR_t str;
        if(fge_STR_init_buff(&str, "  H e l l o  W o r l d  ") == false) {
            return false;
        }
        if(fge_STR_remove_first_buff(&str, fge_STR_range(&str), "  ") == false) {
            return false;
        }
        if(fge_STR_is_equal_buff(&str, "H e l l o  W o r l d  ") == false) {
            return false;
        }
        if(fge_STR_fit(&str) == false) {
            return false;
        }
        fge_STR_free(&str);
    }
    {
        fge_STR_t str;
        if(fge_STR_init_buff(&str, "  H e l l o  W o r l d  ") == false) {
            return false;
        }
        if(fge_STR_remove_last_buff(&str, fge_STR_range(&str), "  ") == false) {
            return false;
        }
        if(fge_STR_is_equal_buff(&str, "  H e l l o  W o r l d") == false) {
            return false;
        }
        if(fge_STR_fit(&str) == false) {
            return false;
        }
        fge_STR_free(&str);
    }
    {
        fge_STR_t str;
        if(fge_STR_init_buff(&str, "  H e l l o   W o r l d  ") == false) {
            return false;
        }
        if(fge_STR_remove_buff(&str, fge_STR_range(&str), "  ") == 0) {
            return false;
        }
        if(fge_STR_is_equal_buff(&str, "H e l l o W o r l d") == false) {
            return false;
        }
        if(fge_STR_fit(&str) == false) {
            return false;
        }
        fge_STR_free(&str);
    }
    return true;
}

fge_bool_t test_replace() {
    {
        fge_STR_t str;
        if(fge_STR_init_buff(&str, " H e l l o  W o r l d ") == false) {
            return false;
        }
        if(fge_STR_replace_all_buff(&str, fge_STR_range(&str), " ", "-") == false) {
            return false;
        }
        if(fge_STR_is_equal_buff(&str, "-H-e-l-l-o--W-o-r-l-d-") == false) {
            return false;
        }
        if(fge_STR_fit(&str) == false) {
            return false;
        }
        fge_STR_free(&str);
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
