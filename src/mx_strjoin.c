#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    char *res_str;
    if (s1 == NULL && s2 == NULL)
    	return NULL;
    if(s1 == NULL)
        return mx_strdup(s2);
    if(s2==NULL) 
        return mx_strdup(s1);
    res_str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    mx_strcat(mx_strcat(res_str, s1), s2);
    return res_str;
}
