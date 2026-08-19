#include <stdio.h>
#include <Kernel/sys/_types/_fd_def.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>

/*

select(numfd, read_fds, NULL, NULL) - block until one of the file desc has data to read 

*/


int main(){
    int pipe_child1[2], pipe_child2[2];
    //set of fds
    fd_set read_fds; 
    //empty the set
    FD_ZERO(&read_fds); 
    //fd set now has pipe1 and pipe2 read ends
    FD_SET(pipe_child1[0], &read_fds); 
    FD_SET(pipe_child2[0], &read_fds); 

    int max_fd; 
    if (pipe_child1[0] > pipe_child2[0]){
        max_fd = pipe_child1 + 1; 
    } else{
        max_fd = pipe_child2 + 1;
    }

    if (select(max_fd, &read_fds, NULL, NULL, NULL) != 1){
        perror("select"); 
        exit(1); 
    }
}