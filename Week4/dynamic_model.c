#include <stdio.h>

int *set_i(){
    int i = 5; 
    return &i;
}

int main(){
    int i = 5; 
    int *pt = set_i(); 
    printf("Access i via *pt and we get %d\n", *pt); 
    return 0; 
}