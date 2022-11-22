#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL)
		return malloc(size);
	if (size == 0) {
		free(ptr);
		return NULL;
	}
	size_t len;
    void *res;
    res = malloc(size);
    len = malloc_usable_size(ptr);
    if(size < len) len = size;
    mx_memcpy(res, ptr, len);
    free(ptr);
    return res;
}
