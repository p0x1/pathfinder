#include  "../inc/pathfinder.h"

void print_result(char **arr_of_islands,int* arr_of_lengths, int *matrix_of_paths, int num_of_islands, int size, int *matrix){
    char *old_path[num_of_islands];
    char *new_path[num_of_islands];
    int length_of_path = 0;
    int index = 0;
    int visited[num_of_islands];
      for(int i = 0; i < num_of_islands - 1; i++){
        for(int j = i + 1; j < num_of_islands;j++){
            if(matrix_of_paths[i+num_of_islands*j] - matrix[i+num_of_islands*j] == matrix_of_paths[i+num_of_islands*i]){
                 mx_printstr("========================================");
                        mx_printstr("\n");
                        mx_printstr("Path: ");
                        mx_printstr(arr_of_islands[i]);
                        mx_printstr(" -> ");
                        mx_printstr(arr_of_islands[j]);
                        mx_printstr("\n");
                        mx_printstr("Route: ");
                        mx_printstr(arr_of_islands[i]);
                        mx_printstr(" -> ");
                        mx_printstr(arr_of_islands[j]);
                        mx_printstr("\n");
                        mx_printstr("Distance: ");
                        mx_printint(matrix_of_paths[i+num_of_islands*j]);
                        mx_printstr("\n");
                        mx_printstr("========================================");
                        mx_printstr("\n");
            }
            else{
                 for(int r = 0; r < num_of_islands; r++){
                    visited[r] = 1;
                }
                    visited[i] = 0;
                for(int idx = 0; idx < num_of_islands; idx++){
                    for(int t = idx; t < num_of_islands; t++){
                        if (matrix_of_paths[i+num_of_islands*j] - matrix_of_paths[idx+num_of_islands*i] == matrix_of_paths[idx+num_of_islands*j] && idx != i && visited[idx] == 1){
                        bool check = false;
                        int length = matrix_of_paths[i+num_of_islands*j];
                        int save_i = i;
                        int k = idx;
                        int temp_len = 0;
                        while(length - matrix_of_paths[k+num_of_islands*save_i] != 0 && k < num_of_islands){
                            if((length - matrix_of_paths[k+num_of_islands*save_i] == matrix_of_paths[k+num_of_islands*j]) && matrix_of_paths[k+num_of_islands*save_i] != 0 && k != i && visited[k] == 1){
                                length = length - matrix_of_paths[k+num_of_islands*save_i];
                                new_path[temp_len] = arr_of_islands[k];
                                temp_len++;
                                if(k < i){
                                    save_i = k;
                                }
                                else save_i++;
                                index = k;
                            }
                            k++;
                        }
                        int count = 0;
                        if(length_of_path == temp_len){
                            int idx2 = 0;
                            while(idx2 < temp_len){
                                if(mx_strcmp(old_path[idx2], new_path[idx2]) != 0) check = true;
                                idx2++;
                            }
                        }
                        else check = true;
                        for(int iter = 0; iter < size; iter++){
                            if(matrix_of_paths[index+num_of_islands*j] == arr_of_lengths[iter]) count++;
                        } 
                        if(check == true && count != 0){
                        length = matrix_of_paths[i+num_of_islands*j];
                        save_i = i;
                        k = idx;
                        while(length - matrix_of_paths[k+num_of_islands*save_i] != 0 && k < num_of_islands){
                            if(length - matrix_of_paths[k+num_of_islands*save_i] == matrix_of_paths[k+num_of_islands*j] && matrix_of_paths[k+num_of_islands*save_i] != 0 && k != i && visited[k] == 1){
                                if(k == idx){
                                    mx_printstr("========================================");
                                    mx_printstr("\n");
                                    mx_printstr("Path: ");
                                    mx_printstr(arr_of_islands[i]);
                                    mx_printstr(" -> ");
                                    mx_printstr(arr_of_islands[j]);
                                    mx_printstr("\n");
                                    mx_printstr("Route: ");
                                    mx_printstr(arr_of_islands[i]);
                                    mx_printstr(" -> ");
                                }
                                length = length - matrix_of_paths[k+num_of_islands*save_i];
                                mx_printstr(arr_of_islands[k]);
                                mx_printstr(" -> ");
                                if(k < i){
                                    save_i = k;
                                }
                                else save_i++;
                            }
                            k++;
                        }
                        length = matrix_of_paths[i+num_of_islands*j];
                        save_i = i;
                        k = idx;
                        while(length - matrix_of_paths[k+num_of_islands*save_i] != 0 && k < num_of_islands){
                              if((length - matrix_of_paths[k+num_of_islands*save_i] == matrix_of_paths[k+num_of_islands*j]) && matrix_of_paths[k+num_of_islands*save_i] != 0 && k != i && visited[k] == 1){
                                    if(k == idx){
                                        mx_printstr(arr_of_islands[j]);
                                        mx_printstr("\n");
                                        mx_printstr("Distance: ");
                                    }
                                length = length - matrix_of_paths[k+num_of_islands*save_i];
                                mx_printint(matrix_of_paths[k+num_of_islands*save_i]);
                                mx_printstr(" + ");
                                if(k < i){
                                    save_i = k;
                                } 
                                else save_i++;
                                index = k;
                            }
                             k++;
                        }
                        length = matrix_of_paths[i+num_of_islands*j];
                        save_i = i;
                        k = idx;
                        while(length - matrix_of_paths[k+num_of_islands*save_i] != 0 && k < num_of_islands){
                            if((length - matrix_of_paths[k+num_of_islands*save_i] == matrix_of_paths[k+num_of_islands*j]) && matrix_of_paths[k+num_of_islands*save_i] != 0 && k != i && visited[k] == 1){
                                if(k == idx){
                                    mx_printint(matrix_of_paths[index+num_of_islands*j]);
                                    mx_printstr(" = ");
                                    mx_printint(matrix_of_paths[i+num_of_islands*j]);
                                    mx_printstr("\n");
                                    mx_printstr("========================================");
                                    mx_printstr("\n");
                                }
                            }
                            k++;
                        }
                        length = matrix_of_paths[i+num_of_islands*j];
                        save_i = i;
                        k = idx;
                        length_of_path = 0;
                        while(length - matrix_of_paths[k+num_of_islands*save_i] != 0 && k < num_of_islands){
                            if((length - matrix_of_paths[k+num_of_islands*save_i] == matrix_of_paths[k+num_of_islands*j]) && matrix_of_paths[k+num_of_islands*save_i] != 0 && k != i && visited[k] == 1){
                                length = length - matrix_of_paths[k+num_of_islands*save_i];
                                old_path[length_of_path] = arr_of_islands[k];
                                length_of_path++;
                                if(k < i){
                                    save_i = k;
                                }
                                else save_i++;
                            }
                            k++;
                        }
                          visited[index] = 0;
                    }
                }
                
            }
        }    
    }
}
}
}
