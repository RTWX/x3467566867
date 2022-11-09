#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) {
    if (list == NULL || *list == NULL) {
        t_list *node = mx_create_node(data);
        list = &node;
        return;
    }

    t_list *node = mx_create_node(data);

    node->next = *list;
    
    list = &node;
}

