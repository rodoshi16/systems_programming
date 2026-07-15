void read_ints(int *fds, int num_fds, int max_fd){

    char data; 
    fd_set set; 
    FD_SET(&set); 
    while (1){
        FD_ZERO(&set)
        for(int i=0; i < num_fds, i++){
            FD_SET(fds[i], &set); 
        }
    }

    int ready = select(max_fd+1, &set, NULL, NULL); 

    if (ready <= 0) break; 

    for (int i = 0; i < num_fds; i++){
        if (FD_ISSET(fds[i], &set)){
            if(read(fds[i], &data, 1) > 0){
                printf("%c\n", data); 
            }
        }
    }

} 