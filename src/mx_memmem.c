#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned char *temp_big = (unsigned char *)big;
    unsigned char *temp_little =(unsigned char *)little;
	if (big_len >= little_len && big_len > 0 && little_len > 0) {
		for(size_t i = 0; i < big_len; i++){
			if (mx_memcmp(&temp_big[i], temp_little, little_len) == 0) {
				return &temp_big[i];
            }
		}
	}
	return NULL;
}

