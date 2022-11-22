#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

bool mx_isalpha(const char c);
void error_handling(int argc, char **argv, char* filedata);
int mx_atoi(const char *str);
void mx_printerr(const char *s);
void creating_matrix(char *filedata);
void searching_paths(int *matrix, char **arr_of_islands, char **arr_of_bridges, char *filedata,int *arr_of_lengths);
int searching_index(char *island, char **arr_of_islands);
void print_result(char **arr_of_islands,int* arr_of_lengths, int *matrix_of_paths, int num_of_islands, int size, int *matrix);



#endif 
