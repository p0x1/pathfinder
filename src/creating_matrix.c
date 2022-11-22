#include "../inc/pathfinder.h"

void creating_matrix(char *filedata){
    char** arr = mx_strsplit(filedata, '\n');
    int size = mx_count_substr(filedata,"-");
    char **arr_of_bridges = (char**)malloc((size + 1)*sizeof(char*));
    int num_of_islands = mx_atoi(arr[0]);
    int arr_of_lengths[size];
    int matrix[num_of_islands][num_of_islands];
    char *arr_of_islands[num_of_islands];
    int idx = 0;
    char **temp_arr;
    char *temp_str;
    
    for(int i = 1; arr[i]; i++){
        temp_arr = mx_strsplit(arr[i], ','); 
        arr_of_bridges[idx] = temp_arr[0];
        arr_of_lengths[idx] = mx_atoi(temp_arr[1]);
        idx++;
    }
    
    for(int i = 0;i < size -1; i++){
        temp_arr = mx_strsplit(arr_of_bridges[i], '-');
        for(int j = i+1;arr_of_bridges[j]; j++){
            char **temp_arr1 = mx_strsplit(arr_of_bridges[j], '-');
            if(mx_strcmp(temp_arr[0],  temp_arr1[0]) == 0){
               temp_str = arr_of_bridges[j];
               arr_of_bridges[j] = mx_replace_substr(temp_str, temp_arr[0],"\t");
            }
            else if(mx_strcmp(temp_arr[0],  temp_arr1[1]) == 0){
                temp_str = arr_of_bridges[j];
                arr_of_bridges[j] = mx_replace_substr(temp_str, temp_arr[0]," ");
            }
            if(mx_strcmp(temp_arr[1],  temp_arr1[0]) == 0){
                temp_str = arr_of_bridges[j];
               arr_of_bridges[j] = mx_replace_substr(temp_str, temp_arr[1],"\t");
            }
            else if(mx_strcmp(temp_arr[1],  temp_arr1[1]) == 0){
                temp_str = arr_of_bridges[j];
                arr_of_bridges[j] = mx_replace_substr(temp_str, temp_arr[1]," ");
            }
          
        }     
    }
    
    arr_of_islands[0] = mx_strsplit(arr_of_bridges[0],'-')[0];
    arr_of_islands[1] = mx_strsplit(arr_of_bridges[0],'-')[1];
    idx = 2;
    
    for (int i = 1; arr_of_bridges[i] && idx < num_of_islands; i++){
        temp_arr = mx_strsplit(arr_of_bridges[i],'-');
        if(mx_strcmp(temp_arr[0],"\t") != 0 && mx_strcmp(temp_arr[0]," ") != 0){
            arr_of_islands[idx] = temp_arr[0];
            idx++;
        }
        if(mx_strcmp(temp_arr[1],"\t") != 0 && mx_strcmp(temp_arr[1]," ") != 0){
            arr_of_islands[idx] = temp_arr[1];
            idx++;
        }
    }
    
    idx = 0;
    for(int i = 1; arr[i]; i++){
        temp_arr = mx_strsplit(arr[i], ','); 
        arr_of_bridges[idx] = temp_arr[0];
        idx++;
    }
    
     for(int i = 0; i < num_of_islands; i++){
        for(int j = 0; j < num_of_islands; j++){
            matrix[i][j] = 0;
            
        }
    }
    
    for(int i = 0; i < num_of_islands; i++){
        for(int j = 0; j < num_of_islands; j++){
                for(int k = 0; k < size; k++){
                    if(mx_strcmp(arr_of_islands[i],mx_strsplit(arr_of_bridges[k],'-')[0]) == 0 && mx_strcmp(arr_of_islands[j],mx_strsplit(arr_of_bridges[k],'-')[1]) == 0 ){
                        matrix[i][j] = arr_of_lengths[k];
                    }
                    else if(mx_strcmp(arr_of_islands[j],mx_strsplit(arr_of_bridges[k],'-')[0]) == 0 && mx_strcmp(arr_of_islands[i],mx_strsplit(arr_of_bridges[k],'-')[1]) == 0 ){
                        matrix[i][j] = arr_of_lengths[k];
                    }
                }
        }
    }
    searching_paths(&matrix[0][0],arr_of_islands,arr_of_bridges,filedata,&arr_of_lengths[0]);
    
}
