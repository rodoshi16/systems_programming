#include <stdio.h>

#define max_len 4096
#include <sys/select.h>

void pass(int *fds, int size){

    char line[max_len]; 
    int n = 0; 
    int max_fd = 0; 
    int temp = 0; 

    int num_con = size; 

    while (num_con > 0){

        fd_set all; 
        FD_ZERO(&all); 

        for (int i = 0; i < size; i++){
            if(fds[i] != -1){
                FD_SET(fds[i], &all); 

                if (max_fd < fds[i]){
                    max_fd = fds[i]; 
                }
            }
        }


        //read must not block
        //select will only keep the file descriptors that are ready 
        if (select(max_fd +1, &all, NULL, NULL, NULL) == -1){
            perror("select"); 
        }

        for (int i = 0; i < size; i++){
        //file descriptor itself doesnt tell you the state 
        if (fds[i] != -1){

            if(FD_ISSET(fds[i], &all)){
                temp = read(fds[i], line, max_len); 

                if (temp == 0){
                    close(fds[i]);
                        fds[i] = -1; 
                        close(fds[i]); 
                        //remove it from set, decrement size
                        FD_CLR(fds[i], &all);
                        num_con -= 1; 
                    } else{
                        n = temp; 
                    }
                
                int next = (i+1)%size; 

                if(fds[next] != -1){
                    write(fds[next], line, n); 

            }

        }

            }

    }

    }

}