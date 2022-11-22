#include "../inc/libmx.h"

t_list *mx_create_node(void *data) {
    t_list *res_node = malloc(sizeof(t_list));
    res_node->next = NULL;
    res_node->data = data;
    return res_node;
}
