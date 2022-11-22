#include "../inc/libmx.h"

char *mx_strncat(char *restrict s1, const char *restrict s2, int n) {
    int i = mx_strlen(s1);
    
    for (int j = 0; j < n; j++) 
        s1[i + j] = s2[j];
    return s1;
}
