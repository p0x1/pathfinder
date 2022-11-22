#include "../inc/libmx.h"

char *mx_del_extra_whitespaces(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    char *temp_str = mx_strtrim(str);
    int num_of_spaces = 0;
    int length = mx_strlen(temp_str);
    bool check = true;
    int i = 0;
    while (temp_str[i] != '\0') {
     if (check == true && mx_isspace(temp_str[i])) {
            check = false;
            num_of_spaces++;
        }
        if (!mx_isspace(temp_str[i]))  check = true;
        i++;
    }
    int j = 0;
    check = true;
    char *res_str = mx_strnew(length - num_of_spaces);
    for (int i = 0; i < length; i++){
       if (!mx_isspace(temp_str[i])) {
            res_str[j++] = temp_str[i];
             check = true;
        }
        if (check == true && mx_isspace(temp_str[i])) {
            res_str[j++] = ' ';
              check = false;
        }
    }
    mx_strdel(&temp_str);
    return res_str;
}

