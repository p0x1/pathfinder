#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char* temp_dst = (unsigned char*)dst;
    unsigned char* temp_src = (unsigned char*)src;
    for(size_t i = 0; i < n; i++){
        temp_dst[i] = temp_src[i];
        if(temp_dst[i] == c){
            return &temp_dst[i+1];
        }
    }
    return NULL;
}
