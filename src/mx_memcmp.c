#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n){
    unsigned char *temp_str1 = (unsigned char *) s1;
    unsigned char *temp_str2 = (unsigned char *) s2;
    for (size_t i = 0; i < n; i++) {
        if (temp_str1[i] != temp_str2[i]) 
            return temp_str1[i] - temp_str2[i];
    }
    return 0;
}
