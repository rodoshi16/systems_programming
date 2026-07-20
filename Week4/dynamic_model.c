#include <stdio.h>

int main(){
    int i = 5; 
    int *pt = &i; 
    printf("Access i via *pt and we get %d\n", *pt); 
    return 0; 
}