#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    int sfile = open(file, O_RDONLY);
    if (sfile < 0)
        return NULL;
    char c;
    int strLenght = 0;
    for (int err = 2; err > 0; ) {
        err = read(sfile, (void *)&c, 1);
        if (err != 2)
            strLenght++;
    }
    close(sfile);
    sfile = open(file, O_RDONLY);
    if (sfile < 0)
        return NULL;
    char *str = mx_strnew(strLenght + 1);
    int i = 0;
    for (int err = 2; err > 0; i++) 
        err = read(sfile, (void *)&str[i], 1);
    str[strLenght] = '\0';
    close(sfile);
    return str;
}

