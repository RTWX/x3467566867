#include "../inc/libmx.h"

static int mx_cnt_wrds(const char *str) {
    if (str == NULL) 
        return -1;
    int counted = 0;
    int count = 0;
    for (int i = 0; str[i] != 0; i++) {
        if ( !mx_isspace(str[i]) ) {
            if (!counted) {
                count++;
                counted = 1;
            }
        }
        else if ( mx_isspace(str[i]) ) {
            counted = 0;
        }
    }
    return count;
}
static char **mx_split(const char *s) {
    if (s == NULL)
        return NULL;
    int wcnt = mx_cnt_wrds(s);
    char ** warr = (char **)malloc( sizeof(char *) * (wcnt + 1));
    if (warr == NULL || wcnt == 0)
        return NULL;
    int x = 0;
    for (int i = 0; s[i] != 0; i++) {
        if ( !mx_isspace(s[i]) ) {
            int ccnt = 0;
            for (int j = i; !mx_isspace(s[j]) && s[j] != 0 ; ccnt++, j++) {  } 

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

char *mx_del_extra_spaces(const char *str) {
    char **s = mx_split(str);
    int cnt = 0;
    int len = 0;
    for ( ; s[cnt] != 0; cnt++) {
        int i = 0;
        for ( ; s[cnt][i] != 0; i++) {  }
        len += i;
    }
    mx_printint(cnt);
    write(1, " 4\n", 4);
    mx_printint(len);
    char * nstr = (char *)malloc( (len + cnt) * sizeof(char) );
    int n = 0;
    for (int i = 0; i < len + cnt - 1; i++, n++) { 

        for (int j = 0; s[n][j] != 0; j++, i++) {
            nstr[i] = s[n][j];
        }
        nstr[i] = ' ';
    }
    write(1, " 8\n", 4);
    mx_del_strarr(&s);
    nstr[len+cnt-1] = '\0';
    return nstr;
}


