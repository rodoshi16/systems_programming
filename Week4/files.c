#include <stdio.h>

int main(){
    // mode can be r,w,a
    //w is for writing to beginning of a file
    // a is for appending to the end of the file
    FILE *fopen(const char *filename, const char *mode); 

    FILE *f; 
    f = fopen("scores_file.txt", "r"); 
    if (f == NULL){
        fprintf(stderr, "Error opening file"); 
        return 1; 
    }

    printf("File opened: we can use it there\n"); 
    return 0; 
}