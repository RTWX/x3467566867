#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    int size = 0;
    for (int i = 0; s1[i] != 0 ; i++) {
        size++;
    }
    char *dub = mx_strnew(n + 1);
    if (dub != NULL)  {
        mx_strncpy(dub, s1, n);
    }
    return dub;
}


