#include <stdio.h>
#include <string.h>


int main(){
    char text[20] = {'h', 'e', 'l', 'l', 'o', '\0'}; 

    printf("%s\n", text); 
    return 0; 

    // the rest will be filled with \0
    char text[20] = "hell0"; 
    //this will allocate enough space for hi + one more for null terminator 
    // the array size is fixed 
    char text[] = "hi"; 

    // text is a pointer NOT a char array
    char *text = "hello"; 

    //sizeof - the length of 
    char weekday[10] = "Monday"; 
    printf("Size of string: %lu\n", sizeof(weekday)); 

    // you cant add two strings with + since we store char arrays and tht will juts add pointers
    printf("Size of string: %lu\n", strlen(weekday)); 

    

}