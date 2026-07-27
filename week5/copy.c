#include <stdio.h>
#include <string.h>


int main(){
    char s1[50] = "My university: "; 
    char s2[32] = "University of Toronto"; 

    // this should copy s2 into s1 but notice how it doesnt check if s1 has enough space
    // strcpy is considered unsafe
    // strcpy(s1, s2); 
    // printf("%s\n", s1); 
    // printf("%s\n", s2); 
    //error msg will be trace trap 


    //this method does not add a null character tho - you will defined behaviour
    // strncpy(s1, s2, sizeof(s1)); 
    // to fix this just add the null termi yourself
    // s1[4] = '\0'; 
    // printf("%s\n", s1); 
    // printf("%s\n", s2); 


    //strcat -> s1 must be valid, s1 needs to have enough space
    // it is unsafe
    // strcat(s1, s2); 
    strncat(s1, s2, sizeof(s1) - strlen(s1) -1); 
    printf("%s\n", s1); 
    printf("%s\n", s2); 


    

}