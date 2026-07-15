#include <stdio.h>
int main(){
    int i = 7; 
    double d = 4.8;
    i = d; 

    printf("The value of i is %d\n ", i); 
    printf("The value of i is %f", d); 

    printf("The number of bits stored by i is %ld\n", sizeof(i)); 


    // int max is the largest integer you can have 
    int big = __INT_MAX__; 
    printf("big %d\n", big); 

    // when uu convert to float, it will round to nearest precision so it might not be very accurate
    float f = big; 
    printf("f %f\n", f); 

    char ch = 'A'; 
    printf("char %c", ch); 

    int j = ch;
    printf("j is %c, int %d\n", j, j); 

    printf("The result is %d\n", 35 == 35.0); 
}