#include "../inc/libmx.h"

void mx_pop_back(t_list **list){
    if (list == NULL || *list == NULL)
        return;
    t_list *temp_node = *list;
    if (temp_node->next == NULL){
        free(*list);
        *list = NULL;
        return;
    }
    while (temp_node->next->next) {
        temp_node = temp_node->next;
    }
    free(temp_node->next);
    temp_node->next = NULL;
}
