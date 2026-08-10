#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sing(){
    char name[20]; 

    scanf("%s", name); 

    printf("Happy birthday to you.\n"); 
    printf("Happy birthday to you.\n"); 
    printf("Happy birthday dear %s.\n", name); 
    printf("Happy birthday to you!\n"); 
    return; 

}

int main(){

    struct sigaction new; 
    new.sa_handler = sing; 
    new.sa_flags = 0; 
    sigemptyset(&new.sa_mask);
    sigaction(SIGINT, &new, NULL); 


    int i = 0; 
    while (i < 100){
        printf("."); 
        usleep(1000); 
    }
}