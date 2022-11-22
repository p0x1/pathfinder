#include "../inc/libmx.h"

char *mx_strndup(const char *str, size_t n) {
    char *res = mx_strnew((int)n);
    mx_strcpy(res, str);
    return res;
}
