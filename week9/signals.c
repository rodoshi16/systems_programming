#include <stdio.h>
#include <signal.h>

void handler(int code) {
    fprintf(stderr, "signal %d caught\n", code); 
}


int main(){

    /*

    int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)

    signum - the number of the signal whose behaviour we will change
    *act - a struct we need to define before

    struct sigaction{
        void (*sa_handler)(int); 
        void (*sa_handler)(int, siginfo_t *, void *); 
        sigset_t sa_mask;
        int sa_flags; 
        void (*sa_restorer)(void); 
    }

    2 processes you CANNOT terminate - sig kill and sig stop
    
    */

    int i = 0; 

    struct sigaction new; 
    //sa: signal action
    new.sa_handler = handler; 
    new.sa_flags = 0;
    // if we need to block other signals
    sigemptyset(&new.sa_mask); 
    sigaction(SIGINT, &new, NULL); 


    for (;;){
        if ((i++ % 5000000) == 0){
            fprintf(stderr, "."); 
        }
    }
    return 0; 


}