#include <stdio.h>
#include <string.h>


int main(){
    // char s1[50] = "My university: "; 
    // char s2[32] = "University of Toronto"; 

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

    // int n -> sizeof teh array - how much its acc storing rn - 1 for the null termi = how many acc left to use (for appending)
    // strncat(s1, s2, sizeof(s1) - strlen(s1) -1); 
    // printf("%s\n", s1); 
    // printf("%s\n", s2); 


    char c1[30] = "OpenAI"; 
    char *p; 
    p = strchr(c1, 'A'); 

    if (p == NULL){
        printf("Character not found\n"); 
    } else{
        printf("Character found at index %ld\n", p - c1); 
    }

    //note that /0 marks the end of the string - this will output University NOT University\0of C Programming
    char s1[30] = "University of C Programming";
    char *p;
    p = strchr(s1, ' ');
    if (p != NULL) {
        *p = '\0';
    }
    printf("%s\n", s1);
    return 0;



    

}