#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data){
    if (!*list){
        *list = mx_create_node(data);
        return;
    }
    t_list *res = *list;
    while (res->next) {
        res = res->next;
    }
    res->next = mx_create_node(data);
}
