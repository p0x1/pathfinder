#include "../inc/libmx.h"

char *mx_file_to_str (const char *filename) {
	int fd = open (filename, O_RDONLY);
	if (fd == -1){
	return  NULL;
	}
		
    char temp;
    int count = 0;
    while (read (fd, &temp, 1) > 0)
	count++;
    if (close (fd) != 0)
        return NULL;
    close (fd);
    char *res_str = mx_strnew(count);
    fd = open (filename, O_RDONLY);
    if (read(fd, res_str,count) < 0){
        return NULL;
    }
    close (fd);
    return res_str;
}
