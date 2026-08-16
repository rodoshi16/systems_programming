#include <stdio.h>

//preprocessor check which checks if apple exists as a defined macro
int main(){
    #ifdef __APPLE__
    printf("i'm on apple"); 

#else
    printf("i'm not on apple"); 

#endif

}
