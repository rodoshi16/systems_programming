
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>     
#include <sys/stat.h>   

int main(int argc, char **argv) {

    int file = open(argv[1], O_RDONLY); 
    if (file == -1){
        perror("open"); 
        exit(1); 
    }

    if (dup2(file, fileno(stdin)) == -1){
        perror("dup2"); 

    }

    if (close(file) == -1){
        perror("close"); 
        
    }

    execlp(argv[2], argv[2], NULL); 
    perror("execlp"); 

    return 1; 

} 