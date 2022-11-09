#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    int size = 0;
    for (int i = 0; s1[i] != 0 ; i++) {
        size++;
    }
    char *dub = mx_strnew(size + 1);
    if (dub != NULL)  {
        mx_strcpy(dub, s1);
    }
    return dub;
}

