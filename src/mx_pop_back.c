#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if (*head == NULL || head == NULL)
        return;
    t_list *node = *head;
    t_list *prevNode = node;
    for ( ; node->next != NULL; ) { 
        prevNode = node;
        node = node->next;
    }
    if (node == prevNode) {
        free(node);
        head = NULL;
    }
    else {
        prevNode->next = NULL;
        free(node);
    }
}


