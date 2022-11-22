#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
if (str == NULL || sub == NULL) {
         return -2;
    }
     int length_str = mx_strlen(str);
     int length_sub = mx_strlen(sub);
     int res;
     int k;
     if(str && sub){
         for(int i = 0; i < length_str; i++){
         k = 0;
        if(sub[0] == str[i]){
            res = i;
            for(int j = i; j < length_sub + i; j++){
                if(sub[k] != str[j]) return -1;
                k++;
            }
            return res;
        }
        else return -1;
        
    }
      
    }
    return -2;
}

