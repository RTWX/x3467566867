#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *) ) {
    if (list == NULL)
        return NULL;
    int x = mx_list_size(list);
    for (int i = 0; i < x; i++) {
        t_list *node = list;
        t_list *prevNode = node;
        for (; node->next != NULL; ) {
            if ( cmp(node->data, node->next->data) ) {
                if ( node == list ) 
                    list = node->next;
                prevNode->next = node->next;
                t_list *tempNode = node;
                t_list *tempNode2 = node->next;
                node->next = node->next->next;
                tempNode2->next = tempNode;
            }
            prevNode = node;
            node = node->next;
        }
    }
    return list;
}


