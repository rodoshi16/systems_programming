#include <stdio.h>
#define MAXSIZE 4096
int main(){
    int fd[2]; 
    char line[MAXSIZE]; 

    if (pipe(fd) == -1){
        perror("pipe"); 

    }

    int r = fork(); 

    if (r > 0){

        close(fd[0]); 

        printf("Enter a line > "); 
        while (fgets(line, MAXSIZE, stdin) != NULL){
            printf("[%d] writing to pipe\n", getpid()); 

            //if more data is being written than there is capacity in the pipe - os will block until theres space
            if (write(fd[1]) == -1){
                perror("write to pipe"); 
            }

            printf("[%d] finished writing\n", getpid()); 
            printf("Enter a line > "); 
        }

        close(fd[1]); 
        printf("[%d] stdin has been closed, waiting for child\n", getpid());
    } else if (r == 0){
        close(fd[1]); 
        printf("[%d] child\n", getpid());
        char other[MAXSIZE]; 

        //os blocks the read call when the pipe is empty
        while (read(fd[0], other, MAXSIZE) > 0){
            printf("[%d] child received %s", getpid(), other);
        }
        printf("[%d] child finished reading", getpid());
        close(fd[0]); 
        exit(0); 

    } else{
        perror("fork"); 
        exit(1); 
    }

    /*

    Note that the OS will make sure pipe is never being written to and read from at the same time
    
    */

    return 0; 

}