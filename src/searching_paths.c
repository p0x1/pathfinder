#include "../inc/pathfinder.h"

void searching_paths(int matrix[], char **arr_of_islands, char **arr_of_bridges, char *filedata, int arr_of_lengths[]){
    char **arr = mx_strsplit(filedata, '\n');
    int size  = mx_count_substr(filedata, "-");
    int num_of_islands = mx_atoi(arr[0]);
    int visited[num_of_islands];
    int matrix_of_paths[num_of_islands][num_of_islands];
    int first_index, second_index;
    int save_second = 0; 
    for(int i= 0; i < num_of_islands; i++){
            for(int j = 0; j < num_of_islands; j++){
                if(i == j)
                matrix_of_paths[i][j] = 0;
                if(i != j)
                matrix_of_paths[i][j] = 2147483647;
            }
    }
    for(int i = 0; i < num_of_islands; i++){
        for(int r = 0; r < num_of_islands; r++){
            visited[r] = 1;
        }
        visited[i] = 0;
        for(int j = 0; j < num_of_islands; j++){
        first_index = i;
        char *temp_str = arr_of_islands[i];
        
        for(int k = 0; k < size; k++){
            save_second = first_index;   
            
            for(int idx = 0; idx < size;idx++){
                if(mx_strcmp(temp_str, mx_strsplit(arr_of_bridges[idx], '-')[0]) == 0 && visited[searching_index(mx_strsplit(arr_of_bridges[idx], '-')[1], arr_of_islands)] == 1){
                second_index = searching_index(mx_strsplit(arr_of_bridges[idx], '-')[1], arr_of_islands);
                
                if(matrix_of_paths[i][second_index] > matrix_of_paths[i][save_second] + matrix[first_index+num_of_islands*second_index]){
                    
                    matrix_of_paths[i][second_index] = matrix_of_paths[i][save_second] + matrix[first_index+num_of_islands*second_index];
                    first_index = second_index;
                    save_second = second_index;
                    temp_str = mx_strsplit(arr_of_bridges[idx], '-')[1];
                }
                
            }
            else if(mx_strcmp(temp_str, mx_strsplit(arr_of_bridges[idx], '-')[1]) == 0  && visited[searching_index(mx_strsplit(arr_of_bridges[idx], '-')[0], arr_of_islands)] == 1){
                second_index = searching_index(mx_strsplit(arr_of_bridges[idx], '-')[0], arr_of_islands);
                
                if(matrix_of_paths[i][second_index] > matrix_of_paths[i][save_second] + matrix[first_index+num_of_islands*second_index]){
                    
                    matrix_of_paths[i][second_index] = matrix_of_paths[i][save_second] + matrix[first_index+num_of_islands*second_index];
                    first_index = second_index;
                    save_second = second_index;
                    temp_str = mx_strsplit(arr_of_bridges[idx], '-')[0];
                    }
                }
            }
        }
     }
    
  }
    for(int i = 0; i < num_of_islands; i++){
        for( int j = 0; j < num_of_islands; j++){
            if(matrix_of_paths[j][i] > matrix_of_paths[i][j]) matrix_of_paths[j][i] = matrix_of_paths[i][j];
        }
    }
    print_result(arr_of_islands,&arr_of_lengths[0], &matrix_of_paths[0][0], num_of_islands, size, &matrix[0]);
}

