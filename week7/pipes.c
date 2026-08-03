#include <stdio.h>
//pipes : sends data between processes
// one process writes data to the pipe 
// other process reads data out of pipe 
int main(){
    int fd[2]; 

    pipe(fd); 

    int r = fork(); 

    if (r > 0){
        //closing read end: parent will only write
        close(fd[0]); 
    } else if (r == 0){
        //closing write end: child will only read
        close(fd[1]); 

        /*

        NOTE that this is a single pipe - parent only writes to child
        if we wanted the child to write to the parent (reply back) - we would need
        another pipe
        
        */
    }




}