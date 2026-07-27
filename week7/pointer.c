#include <stdio.h>
char * my_func(char * filename) {
        printf("hello"); 
        return filename; 
    
    }

int main(){
    // x is of type char* and my_func is a function, they're not the same type
    char *x = my_func; 
    // x is a func which takes char *x and returns char *
    // my_func is also a function so types match
    char* (*x)(char *x) = my_func; 

}