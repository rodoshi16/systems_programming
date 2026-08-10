#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sing(){
    char name[20]; 

    //if you call ctrl + c while this handler is being run, OS will block
    // you will notice that it will wait to finish the song with the first name and then go print the second and after 
    // go back to printing dots

    scanf("%s", name); 

    printf("Happy birthday to you.\n"); 
    usleep(5000000);
    printf("Happy birthday to you.\n"); 
    usleep(5000000);
    printf("Happy birthday dear %s.\n", name); 
    usleep(5000000);
    printf("Happy birthday to you!\n"); 
    usleep(5000000);
    return; 

}

int main(){

    struct sigaction new; 
    new.sa_handler = sing; 
    new.sa_flags = 0; 
    sigemptyset(&new.sa_mask);
    sigaction(SIGUSR1, &new, NULL); 


    int i = 0; 
    while (i < 100){
        printf("."); 
        usleep(1000); 
    }
}