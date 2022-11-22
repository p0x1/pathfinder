#include "../inc/pathfinder.h"


int main(int argc, char *argv[]){
    char *filedata = mx_file_to_str(argv[1]);
    error_handling(argc, argv,filedata);
    creating_matrix(filedata);
    return 0;
}
