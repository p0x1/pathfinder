#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int count = 0, i = 0, length = mx_strlen(str);
    bool check = true;
    if(str[i] == delimiter && str[i] != '\0')
    {
      while(str[i] == delimiter){
    	i++;
      }
    }
    while(str[i] != '\0'){
    	check =true;
    while(str[i] == delimiter){
      if(str[i] == delimiter && check == true && i != 0){
    	 count++;
    	 check = false;
     }
    	i++;
    }
    	i++;
    }
    if(str[length-1]== delimiter) count--;
    return count+1;
}

