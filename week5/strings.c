#include <stdio.h>
int main(){
    char text[5]; 
    text[0] = 'h'; 
    text[1] = 'e'; 
    //this makes it a string -  A STRING IS JUST A CHAR ARRAY
    text[2] = '\0'; 

    int i; 
    for (i = 0; i < 20; i++){
        printf("%c", text[i]); 
    }

    printf("\n"); 
    return 0; 

    //this entire block of code prints garbage after 'he' because we only assigned values for the first two characters
}