#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL)
        return malloc(size);
    if (size < 0) {
        free(ptr);
        ptr = NULL;
        return ptr;
    }
    void *nptr = malloc(size);
    mx_memcpy(nptr, ptr, mx_strlen(ptr) );
    ptr = nptr;
    return ptr;
}


