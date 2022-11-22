#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int nbr_copy = nbr;
    int length = 0;
    int temp;

    while (nbr != 0) {
        nbr /= 16;
        length++;
    }
    if (length == 0)
        return 0;
        
    char *res = mx_strnew(length);
    for (int i = length - 1; i >= 0; i--){
        temp = nbr_copy % 16;

        if (temp < 10)
            res[i] = temp + 48;
        else
            res[i] = temp + 87;

        nbr_copy /= 16;
    }
    return res;
}

