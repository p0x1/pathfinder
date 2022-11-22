#include "../inc/libmx.h"

void mx_printint(int n) {
    int num = n;
    int count = 0;  
    if(num < 0) {
        mx_printchar('-');
        num = num * -1;
    }
    if (num == 0)  mx_printchar('0');
	while( n != 0){
   		n= n / 10;
   		count++;
	}
	char text[count];
	n = num;
	count = 0;
    while( n != 0){
        text[count]= n % 10;
        n= n / 10;
        count++;
    }
    for(int i = count - 1; i >= 0; i--) mx_printchar(text[i] + 48 );
}

