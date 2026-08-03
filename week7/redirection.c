#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
    int result; 

    result = fork(); 

    if (result == 0){
        //filefd : file descriptor (ID for the file)
        int filefd = open("day.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
        if (filefd == -1) {
			perror("open");
		}
    
    if (dup2(filefd, fileno(stdout)) == -1){
        perror("dup2"); 
    }

    //now stdout already points to day.txt file so we can close the filefd descriptor
    close(filefd); 
    //grep: search program that will match a pattern searches the text file for L10101
    //first grep: program itself
    //second grep: what it recognizes in the terminal
    execlp("grep", "grep", "L0101", "student_list.txt", NULL);
    perror("exec"); 
    exit(1); 
    } else if(result > 0){
        int status; 
        printf("Here\n"); 
        //parent should know if child terminated - after the wait call os can clear off the dead child info
        // if the child hasn't finished running, wait will block until the child hasn't finished
        if (wait(&status) != -1){
            if(WIFEXITED(status)){
                fprintf(stderr, "Process exited with %d\n", WEXITSTATUS(status)); 
            } else{
                fprintf(stderr, "Process terminated\n"); 
            }
        }
    } else{
        perror("fork"); 
        exit(1); 
    }

}