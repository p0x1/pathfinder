#include "../inc/pathfinder.h"

int mx_atoi(const char *str) {
    long int res = 0;
    if(str == NULL) return -5;
    if(*str == '-') return -5;
    while (*str) {
        if(mx_isdigit(*str)){
        res = res * 10;
        res = res + (*str - 48);
        }
        else return -5;
        str++;
    }
    return res;
}
