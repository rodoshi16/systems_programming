#include <stdio.h>

#define LINE_LENGTH 80

int main(){

    FILE *f; 
    int error; 
    char line[LINE_LENGTH+1]; 

    f = fopen("scores_file.txt", "r"); 
    if (f == NULL){
        fprintf(stderr, "error opening file\n");
        return 1; 
    }

    while (fgets(line, LINE_LENGTH+1, f )){
        printf("%s", line); 
    }

    //fgets stops reading after a newline char

    error = fclose(f); 
    if (error != 0){
        fprintf(stderr, "fclose failed\n"); 
        return 1; 
    }

    return 0; 

}