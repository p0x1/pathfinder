#include "../inc/pathfinder.h"

int searching_index(char *island, char **arr_of_islands){
        for(int i =0 ;arr_of_islands[i]; i++){
            if(mx_strcmp(island, arr_of_islands[i]) == 0) return i;
        }
        return 0;
}
