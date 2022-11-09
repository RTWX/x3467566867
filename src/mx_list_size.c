#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    if (list == NULL)
        return 0;

    t_list *node = list;
    int count = 1;
    
    for ( ; node->next != NULL; ) { 
        count++;
        node = node->next;
    }
    return count;
}

