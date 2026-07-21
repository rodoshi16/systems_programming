#include <stdio.h>

//Notice that in this piece of code, the heap holds the value 49
//once we return from play, i stored in the stack is terminated but heap still holds 49

//its fine for this code but if we continue to call play in a loop, eventually there will be no memory left since the memory used is never being freed
//this is called a MEMORY LEAK
//eventually you will encounter an out of memory error called ENOMEM

int play(){
    int i; 
    int *pt = malloc(sizeof(int)); 

    i = 15; 
    *pt = 49; 
    free(pt); 

    //after you call free, if no other program overrides that value it will hold the previous
    //it just tells the memory manager that this address is available for use
    print("%d\n", pt); 
    //although now, accessing this pointer AFTER  it has been freed is a DANGLING POINTER and its unsafe
    return 0; 

}

int main(){
    play(); 
    return 0; 
}