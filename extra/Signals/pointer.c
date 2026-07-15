#include <stdio.h>

//this code has errors - ptr does not point to valid memory and we attempt to access value there
// when the OS finds out, it sends back a seg fault signal to notify
//segmentation violation is when program makes illegal memory access 

int main() {
    int *ptr = NULL; 
    *ptr = 3; 
    printf("Value at ptr is %d\n", *ptr); 
    return 0; 
}


