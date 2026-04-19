#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>


/* global variable since sing cant take an argument. name points to the first char in memory */
char *name;  

void sing(int signum){

/*printf prints to stdout always. For name it wil start at the first char and print char by char*/
    printf("Happy birthday to you1.\n"); 
    printf("Happy birthday to you.2\n"); 
    sleep(100); 
    /* %s is the format specifier for string, %c is for char*/
    printf("Happy birthday dear %s\n", name);
    printf("Happy birthday to you4.");
    return; 
}

/*the number of arguments and the arguments array itself*/
int main(int argc, char *argv[]) {
    /*fprint lets us specify the I/0 here we have stderr, Usage is convention of letting users know*/
    if (argc != 2){
        fprintf(stderr, "Usage: %s <name>\n", argv[0]);
        /*if you dont exit, then it will print the message and still print dots*/
        exit(1);  

    }

    name = argv[1]; 

    struct sigaction sa; 
    /*must be init at the start, clears the struct before using it*/
    memset(&sa, 0, sizeof(sa)); 
    sa.sa_handler = sing; 
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask); 
    /* signals you block dont interfere during execution */
    sigaddset(&sa.sa_mask, SIGINT); 

    sigaction(SIGUSR1, &sa, NULL); 

    while(1){
        printf(".\n"); 
        /*fflush forces the output to appear immediately*/
        fflush(stdout); 
        usleep(200000); 
    }
}
