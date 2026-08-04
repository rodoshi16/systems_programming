#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    int pipe_fd[argc][2];

    for (int i = 1; i < argc; i++) {

        if (pipe(pipe_fd[i]) == -1) {
            perror("pipe");
            exit(1);
        }

        int result = fork();

        if (result < 0) {
            perror("fork");
            exit(1);

        } else if (result == 0) {

            if (close(pipe_fd[i][0]) == -1) {
                perror("close reading end from inside child");
                exit(1);
            }

            for (int child_no = 1; child_no < i; child_no++) {
                if (close(pipe_fd[child_no][0]) == -1) {
                    perror("close reading ends of previously forked children");
                    exit(1);
                }
            }

            int len = strlen(argv[i]);

            if (write(pipe_fd[i][1], &len, sizeof(int)) != sizeof(int)) {
                perror("write from child to pipe");
                exit(1);
            }

            if (close(pipe_fd[i][1]) == -1) {
                perror("close pipe after writing");
                exit(1);
            }

            exit(0);

        } else {

            if (close(pipe_fd[i][1]) == -1) {
                perror("close writing end of pipe in parent");
                exit(1);
            }
        }
    }

    int sum = 0;
    int contribution;

    for (int i = 1; i < argc; i++) {

        if (read(pipe_fd[i][0], &contribution, sizeof(int)) != sizeof(int)) {
            perror("reading from pipe from a child");
            exit(1);
        }

        printf("I just read a %d from child %d\n", contribution, i);

        sum += contribution;

        if (close(pipe_fd[i][0]) == -1) {
            perror("close reading end in parent");
            exit(1);
        }
    }

    printf("The length of all the args is %d\n", sum);

    return 0;
}