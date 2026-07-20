#include <stdio.h>
int main(){
    FILE *fp; 
    FILE *out; 
    char name[81]; 
    int score; 
    int error; 


    fp = fopen("scores_file.txt", "r"); 
    if (fp == NULL){
        fprintf(stderr, "Error when opening file");
    }

    out = fopen("output.txt", "w"); 
    if (out == NULL){
        fprintf(stderr, "Error when opening output file\n"); 
        fclose(fp); 
        return 1; 
    }


    while (fscanf(fp, "%80s" "%d", name, &score) == 2){
        //only shows it to the screen
        printf("Name: %s, Score: %d\n", name, score);
        //to store in an output file
        fprintf(out, "%s\n", name);

        error = fclose(fp); 
        if (error != 0){
            fprintf(stderr, "fclose failed on input file\n"); 
            return 1; 
        }

        return 0; 

        error = fclose(out); 
        if (error != 0){
            fprintf(stderr, "error when closing output file\n"); 
            return 1; 
        }
    }

    return 0; 

}