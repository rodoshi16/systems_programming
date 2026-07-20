#include <stdio.h>

//declare a fxn to return the address of i 
int *set_i(){
    int i = 5; 
    return &i;
}

//after *set_i returns the stack memory is cleared and the same addresses can be used for other things
int junk(){
    int j = 999; 
    return j; 
}

int main(){
    int i = 5; 
    int *pt = set_i(); 
    junk(); 
    printf("Access i via *pt and we get %d\n", *pt); 
    return 0; 
}

//to have the memory to be accessible after the function has returned

void *malloc(size_t size); 