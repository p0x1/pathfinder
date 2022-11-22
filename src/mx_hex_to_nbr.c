#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    int l = 0;
    unsigned long res = 0;
    unsigned long b = 1;

    if (hex != NULL) {
        while (hex[l])
            l++;
    }
    else {
        return res;
    }

    for (int i = 0; i <= l; i++) {
        if (mx_isdigit(hex[l - i])) {
            res = res + (hex[l - i] - 48) * b;
            b = b * 16;
        }
        if (mx_isupper(hex[l - i])) {
            res = res + (hex[l - i] - 55) * b;
            b = b * 16;
        }
        if (mx_islower(hex[l - i])) {
            res = res + (hex[l - i] - 87) * b;
            b = b * 16;
        }
    }
    return res;
}

