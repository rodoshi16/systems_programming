#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    int result;
    int i, j;

    printf("[%d] Original process (my parent is %d)\n",
            getpid(), getppid());

    for (i = 0; i < 5; i++) {
        result = fork();

        if (result == -1) {
            perror("fork:");
            exit(1);
        } else if (result == 0) { 
            //os scheduler decides how it will create and run processes 
            // each process resumes from where it was left of
            for(j = 0; j < 5; j++) {
                printf("[%d] Child %d %d\n", getpid(), i, j);
                usleep(100);
            }

            if(i == 2) {
                abort();
            }
            exit(i);
        }
    }
	sleep(10);
    for (i = 0; i < 5; i++) {
        pid_t pid;
        //declaring it reserves space in memory
        int status;
        //status returns the pid of the finished child
        // call to wait writes to status
        if( (pid = wait(&status)) == -1) {
            perror("wait");
        } else {
            //WIFEXITED: checks if the child terminated normally  (t/f)
            if (WIFEXITED(status)) {
                printf("Child %d terminated with %d\n",
                    //return the code the child returned 
                    // WEXITSTATUS: 0 is sucess and non zero is failure
                    pid, WEXITSTATUS(status));
            //signal termination: it was interuppted or killed
            } else if(WIFSIGNALED(status)){
                printf("Child %d terminated with signal %d\n",
                    pid, WTERMSIG(status));
            } else {
                printf("Shouldn't get here\n");
            }
        }
    }
    printf("[%d] Parent about to terminate\n", getpid());
    return 0;

}