#include <stdio.h>
#include <Kernel/sys/_types/_fd_def.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>


#define MAXSIZE 4096

/*

select(numfd, read_fds, NULL, NULL) - block until one of the file desc has data to read 


-write_fds
-time limit on how long select will block
- since select will modify the set for reading, we need to reinitialize everytime


*/


int main(){
    char line[MAXSIZE]; 
    int pipe_child1[2], pipe_child2[2];
    ssize_t r;
    //set of fds
    fd_set read_fds; 
    //empty the set
    FD_ZERO(&read_fds); 
    //fd set now has pipe1 and pipe2 read ends
    FD_SET(pipe_child1[0], &read_fds); 
    FD_SET(pipe_child2[0], &read_fds); 

    int max_fd; 
    if (pipe_child1[0] > pipe_child2[0]){
        max_fd = pipe_child1[0] + 1; 
    } else{
        max_fd = pipe_child2[0] + 1;
    }

    //select returns the NUMBER of file descriptors which are ready
    //doesnt tell us which ones are ready 
    // it will modify the set read_fds 
    if (select(max_fd, &read_fds, NULL, NULL, NULL) != 1){
        perror("select"); 
        exit(1); 
    }

    if (FD_ISSET(pipe_child1[0], &read_fds)){
         if ((r = read(pipe_child2[0], line, MAXSIZE)) < 0) {
                perror("read");
            } else if (r == 0) {
                printf("pipe from child 2 is closed\n");
            } else {
                printf("Read %s from child 2\n", line);
            } 

    }

    if (FD_ISSET(pipe_child2[0], &read_fds)){
        
        if ((r = read(pipe_child2[0], line, MAXSIZE)) < 0) {
                perror("read");
            } else if (r == 0) {
                printf("pipe from child 2 is closed\n");
            } else {
                printf("Read %s from child 2\n", line);
            } 
    }

}