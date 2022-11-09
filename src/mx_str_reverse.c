#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int j = 0;
    for ( ; s[j] != 0; j++) {
    }
    j--;
    for (int i = 0; s[i] != 0 && i <= j; i++) {
        mx_swap_char(&s[i], &s[j]);
        j--;
    }
}

