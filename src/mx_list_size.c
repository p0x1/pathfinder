#include "../inc/libmx.h"

int mx_list_size(t_list *list){
    int res = 0;
    while (list != NULL) {
        list = list->next;
        res++;
    }
    return res;
}
