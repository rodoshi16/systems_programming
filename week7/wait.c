#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
    int result; 
    int i, j; 

    for(i=0; i < 5; i++){
        result = fork(); 

        if (result == -1){
            perror("fork:"); 
            exit(1); 
        } else if(result == 0){
            for (j = 0; j < 5; j++){
                printf("[%d] Child %d %d\n", getpid(), i, j); 
                usleep(100); 
            }

            exit(0); 
        }


    }
    for (i = 0; i < 5; i++){
        //pid_t : type to store process ID
        pid_t pid;
        int status; 


        if ((pid == wait(&status)) == -1){
            perror("wait"); 
        } else{
            printf("Child %d terminated with %d\n", pid, status); 
        }
    }

    printf("[%d] Parent about to terminate\n", getpid()); 


}