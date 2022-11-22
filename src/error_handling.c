#include "../inc/pathfinder.h"

void error_handling(int argc, char **argv, char* filedata){
    if(argc != 2){
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
    if(open(argv[1], O_RDONLY) == -1){
        mx_printerr("error: file ");
        mx_printstr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(0);
    }
    if(mx_strlen(filedata) == 0){
         mx_printerr("error: file ");
         mx_printstr(argv[1]);
         mx_printerr(" is empty\n");
        exit(0);
    }
    char **arr = mx_strsplit(filedata, '\n');
    int num_of_islands = mx_atoi(arr[0]);
    
    if(num_of_islands <= 0){
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }
    for(int i = 1; arr[i]; i++){
        if(mx_count_substr(arr[i],"-") != 1 || mx_count_substr(arr[i],",") != 1 ){
            mx_printerr("error: line ");
            mx_printint(i + 1);
            mx_printerr(" is  not valid\n");
            exit(0);
        }
    }
    char **temp_arr;
    filedata++;
    filedata++;
    long int sum = 0;
    int n = mx_count_substr(filedata, "-");
    char **arr_of_bridges = (char**)malloc((n + 1)*sizeof(char*));
    int idx = 0;
    
    for(int i = 1; arr[i];i++){
        temp_arr = mx_strsplit(arr[i], ',');
        arr_of_bridges[idx] = temp_arr[0];
        char *temp_str = temp_arr[0];
        while(*temp_str){
            if(!mx_isalpha(*temp_str) && *temp_str != '-'){
                mx_printerr("error: line ");
                mx_printint(i + 1);
                mx_printerr("is  not valid\n");
                exit(0);
            }
            temp_str++;
        }
        if(mx_atoi(temp_arr[1]) <= 0){
            mx_printerr("error: line ");
            mx_printint(i + 1);
            mx_printerr(" is  not valid\n");
            exit(0);
        }
        sum += mx_atoi(temp_arr[1]);
        idx++;
    }
    for(int i = 0;arr_of_bridges[i]; i++){
          temp_arr = mx_strsplit(arr_of_bridges[i], '-');
            if(mx_strcmp(temp_arr[0],  temp_arr[1]) == 0){
            mx_printerr("error: line ");
            mx_printint(i+ 2);
            mx_printerr(" is  not valid\n");
            exit(0);
        }
    }
    int count = 0;
    
    for(int i = 0;i < n; i++){
       char** temp_arr = mx_strsplit(arr_of_bridges[i], '-');
        if(mx_strcmp(temp_arr[0], "\t") != 0 && mx_strcmp(temp_arr[1], " ") != 0) count+=2;
        else if(mx_strcmp(temp_arr[0], "\t") != 0 || mx_strcmp(temp_arr[1], " ") != 0) count++;
        for(int j = i;j < n; j++){
            char **temp_arr1 = mx_strsplit(arr_of_bridges[j], '-');
            if(mx_strcmp(temp_arr[0],  temp_arr1[0]) == 0){
                char *temp_str = arr_of_bridges[j];
               arr_of_bridges[j] = mx_replace_substr(temp_str, temp_arr[0],"\t");
            }
            else if(mx_strcmp(temp_arr[0],  temp_arr1[1]) == 0){
                char *temp_str = arr_of_bridges[j];
                arr_of_bridges[j] = mx_replace_substr(temp_str, temp_arr[0]," ");
            }
            if(mx_strcmp(temp_arr[1],  temp_arr1[0]) == 0){
                char *temp_str = arr_of_bridges[j];
               arr_of_bridges[j] = mx_replace_substr(temp_str, temp_arr[1],"\t");
            }
            else if(mx_strcmp(temp_arr[1],  temp_arr1[1]) == 0){
                char *temp_str = arr_of_bridges[j];
                arr_of_bridges[j] = mx_replace_substr(temp_str, temp_arr[1]," ");
            }
          
        }     
    }

    if(num_of_islands != count){
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
    idx = 0;
    for(int i = 1; arr[i]; i++){
        temp_arr = mx_strsplit(arr[i], ',');
        arr_of_bridges[idx] = temp_arr[0];
        idx++;
    }
    for(int i = 0; i < n - 1; i++){
         temp_arr = mx_strsplit(arr_of_bridges[i], '-');
          for(int j = i+1;arr_of_bridges[j]; j++){
            char **temp_arr1 = mx_strsplit(arr_of_bridges[j], '-');
            if(mx_strcmp(temp_arr[0],  temp_arr1[0]) == 0 && mx_strcmp(temp_arr[1],  temp_arr1[1]) == 0){
                mx_printerr("error: duplicate bridges\n");
                exit(0);
            }
            if(mx_strcmp(temp_arr[1],  temp_arr1[0]) == 0 && mx_strcmp(temp_arr[0],  temp_arr1[1]) == 0){
                mx_printerr("error: duplicate bridges\n");
                exit(0);
            }
        }
    }
    if(sum > 2147483647){
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(0);
    }
    
}
