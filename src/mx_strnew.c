#include "../inc/libmx.h"

char *mx_strnew(const int size) {
    int str_size = size;
    if (str_size < 0) {
        return NULL;
    }
    if (str_size == 0) {
        str_size = 1;
    }
    char *c = malloc((str_size * sizeof(char)) + 1);

    if (c != NULL) {
        int i = 0;
        for (; i < str_size; i++)
        {
            c[i] = '\0';
        }
        c[++i] = '\0';
    }
    return c;
}

