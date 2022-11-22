#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char* temp_s =(unsigned char*) s;
    for(size_t i = 0; i < n; i++){
        if(temp_s[i] == c){
            return &temp_s[i];
        }
    }
    return NULL;
}

