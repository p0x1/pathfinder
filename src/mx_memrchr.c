#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char* temp_s =(unsigned char*) s;
    for(size_t i = n - 1; i >= 0; i--){
        if(temp_s[i] == c){
            return &temp_s[i];
        }
    }
    return NULL;
}
