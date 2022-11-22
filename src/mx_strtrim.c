#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) 
        return NULL;
    int first_spaces = 0;
    int last_spaces = 0;
    int length = mx_strlen(str);
    char *temp_str = mx_strnew(length);
    temp_str = mx_strncpy(temp_str, str, length);
    int i=0;
    while(mx_isspace(temp_str[i])){
        first_spaces++;
        i++;
    }
    i = length - 1;
    while(mx_isspace(temp_str[i])){
        last_spaces++;
        i--;
    }
    char *res_str = mx_strnew(length - (first_spaces + last_spaces));
    int j = 0;
    for (int i = first_spaces; i < length - last_spaces; i++) {
        res_str[j++] = temp_str[i];
    }
    mx_strdel(&temp_str);
    return res_str;
}
