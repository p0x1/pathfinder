#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    
    if (!arr) {
        return -1;
    }
    int res = 0;
    int i = left;
    int j = right;
    int pivot = mx_strlen(arr[(i + j) / 2]);
    char *temp;
    while (i <= j) {
        while (mx_strlen(arr[i]) < pivot) {
            i++;
        }
        while (mx_strlen(arr[j]) > pivot) {
            j--;
        }
        if (i <= j) {
            if(mx_strlen(arr[j]) != mx_strlen(arr[i])) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                res++;
            }
            i++;
            j--;
        }
    }
    if (j > left) {
        res += mx_quicksort(arr, left, j); 
    }
    if (i < right) {
        res += mx_quicksort(arr, i, right);
    }
    return res;
}


