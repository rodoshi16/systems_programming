#include <stdio.h>
#include <unistd.h>

int main(){

    printf("About to call execl. My PID id %d\n", getpid()); 
    //execl replaces the current program with execl 
    execl("./a.out", NULL); 
    // if something goes wrong - only then it will enter here
    // Process table: PID is not changed, PC and SP is changed
    // address space's code will be changed
    perror("./execl"); 
    return 1; 

}