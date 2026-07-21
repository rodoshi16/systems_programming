#include <stdio.h>
#include <stdlib.h>


int square(int max_val){
    int* result = malloc(max_val*sizeof(int)); 
    int i = 0; 
    for (int i = 1; i < max_val; i++){
        result[i-1] = i*i; 
    }
    return result; 
}



int main(){
    //return the pointer to the first element
    int* sq = squares(10); 

    int i; 
    for (i = 0; i < 10; i++){
        printf("%d\t", sq[i]); 
    }
    printf("\n"); 
    return 0; 
}