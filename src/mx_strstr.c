#include "../inc/libmx.h"

char* mx_strstr(const char* haystack, const char* needle){
    int length_hay = mx_strlen(haystack);
     int length_nee = mx_strlen(needle);
     char *temp_haystack = mx_strdup(haystack);
     char* res;
     int k;
    for(int i = 0; i < length_hay; i++){
    k=0;
        if(needle[i] == temp_haystack[i]){
            res = &temp_haystack[i];
            for(int j = i; j < length_nee + i; j++){
                if(needle[k] != temp_haystack[j]) return NULL;
                k++;
            }
        }
    }
    return res;
}
