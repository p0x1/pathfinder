#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n){
    unsigned char *temp_dst = (unsigned char *)dst;
    unsigned char *temp_src = (unsigned char *)src;
    for(size_t i = 0; i < n; i++){
        temp_dst[i] = temp_src[i];
    }
    return dst;
}
