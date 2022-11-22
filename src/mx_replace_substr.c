#include "../inc/libmx.h"

char* mx_replace_substr(const char* str, const char* sub, const char* replace) {
    if (str == NULL  || sub == NULL || replace == NULL)
        return NULL;
    int count_sub_str = mx_count_substr(str, sub);
    int src_str_size = mx_strlen(str);
    int sub_str_size = mx_strlen(sub);
    int replace_str_size = mx_strlen(replace);
    int res_str_size = src_str_size - sub_str_size * count_sub_str + count_sub_str * replace_str_size;
    if (count_sub_str == 0) {
        char* cpy_str = mx_strnew(src_str_size);
        mx_strcpy(cpy_str, str);
        return cpy_str;
    }
    char* res_str = mx_strnew(res_str_size);
    int sub_indx = 0;
    int count = 0;
    while (*str && count < res_str_size) {
        sub_indx = mx_get_substr_index(str, sub);

        if (sub_indx == 0) {
            for (int i = 0; i < replace_str_size; i++) {
                res_str[count] = replace[i];
                count++;
            }
            str += sub_str_size;
            continue;
        }
        res_str[count] = str[0];
        count++;
        str++;
    }

    return res_str;
}
