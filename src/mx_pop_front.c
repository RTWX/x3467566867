#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
    if (head == NULL || *head == NULL)
        return;

    t_list *node = *head;

    t_list *node2 = node->next;

    head = &node2;
    free(node);
}

