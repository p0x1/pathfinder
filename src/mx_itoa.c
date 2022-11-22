#include "../inc/libmx.h"

char *mx_itoa(int number){
    if(number == 0) return "0";
    if (number == -2147483648) return "-2147483648";
    int length = 0;
    int number_save = number;
    if(number_save < 0){
        length++;
        number_save *= -1;
    }
    while(number_save != 0){
        number_save /= 10;
         length++;
    }
    char *res = mx_strnew(length);
    res[length--] = '\0';
    if(number < 0){
       res[0] = '-';
       number *= -1;
    }
    while(number != 0){
        res[length--] = (number % 10) + '0';
        number /= 10;
    }
    return res;
}

