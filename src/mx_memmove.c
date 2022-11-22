#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len){
    unsigned char *temp_dst = (unsigned char*)dst;
    unsigned char *temps_src = (unsigned char*)src;
    for (size_t i = 0; i < len; i++) {
        temp_dst[i] = temps_src[i];
    }
    dst = temp_dst;
    return dst;
}
