#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL)
        return NULL;
    int wcnt = mx_count_words(s, c);
    char ** warr = (char **)malloc( sizeof(char *) * (wcnt + 1));
    if (warr == NULL || wcnt == 0)
        return NULL;
    int x = 0;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] != c) {
            int ccnt = 0;
            for (int j = i; s[j] != c && s[j] != 0 ; ccnt++, j++) {  } 

            char * word = mx_strnew(ccnt + 1); 
            int j = 0;
            for ( ; j < ccnt && s[i] != 0 ; j++, i++)
                word[j] = s[i];
            word[++j] = '\0';
            warr[x] = word;
            x++;
            if (s[i] == 0)
                break;
        }
    }
    warr[x] = NULL;
    return warr;
}


