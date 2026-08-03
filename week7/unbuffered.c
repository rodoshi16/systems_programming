#include <stdio.h>
#include <stdlib.h>
int main(){
    //returns a file pointer
    FILE *outfp = fopen("tmpfile", "w"); 

    //check for errors
    if(outfp == NULL){
        perror("fopen"); 
        exit(1); 
    }

    //fprintf formats everything into text and calls the write system call
    // printf - prints to the terminal
    // fprint - prints to the file that output refers to 
    // fprint is better than write because write will
    fprintf(outfp, "This is "); 
    fprintf(outfp, "One of several "); 
    fprintf(outfp, "calls to fprintf.\n"); 
    fprintf(outfp, "how many write"); 
    fprintf(outfp, "system calls are generated?\n");
    fclose(outfp);
    return 0;
}