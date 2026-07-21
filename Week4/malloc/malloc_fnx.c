#include <stdio.h>
#include <stdlib.h>


//declare a fxn to return the address of i 
int *set_i(){
    int* i_pt = malloc(sizeof(int)); 
    *i_pt = 5; 
    return i_pt; 
}

int main(){
    int* pt = set_i(); 
    printf("Access i via *pt and we get %d\n", *pt); 
    return 0; 
}

//to have the memory to be accessible after the function has returned

// void *malloc(size_t size); 
//this remains accessible until the programmer returns it 
