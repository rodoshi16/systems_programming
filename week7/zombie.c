#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int result; 
    int i, j; 

    printf("[%d] Original process(my parent is %d)\n", getpid(), getppid()); 

    for(i = 0; i < 5; i++){
        result = fork(); 

        if(result == -1){
            perror("fork:"); 
            exit(1); 
        } else if(result == 0){
            printf("[%d] Child %d %d (parent pid = %d)\n", getpid(), i, j, getpppid()); 
            usleep(100); 
        }

        // after calling exit on the child process - its is dead and becomes a zombie
        // we still keep the zombie process because the os needs to store the information incase we call wait
        //the PCB is still kept 
        // if parent never calls wait
        // if the parent dies before the child - child process becomes an orphan - it is adopted by the init process
        exit(0); 
    }

}