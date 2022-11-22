#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -1;
    }
    int length_str = mx_strlen(str);
    int length_sub = mx_strlen(sub);
    int count = 0;
    bool  check =true;
    int k;
    for(int i = 0; i < length_str; i++){
    k=0;
        if(sub[k] == str[i]){
            for(int j = i; j < length_sub + i; j++){
                if(sub[k] != str[j]){
                    check = false; 
                }
                k++;
            }
             if(check == true) count++;
        }
        
    }
    return count;
}


