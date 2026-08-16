#include <stdio.h>

typedef unsigned int size_t; 
typedef unsigned int age_t; 
typedef unsigned int shoe_size_t; 

void print_boot_size(shoe_size_t shoe_size){

}

typedef struct {
    char first_name[20]; 
    char last_name[20]; 
    int year; 
    float gpa; 
} Student; 


int main(){
    age_t my_age = 5; 
    print_boot_size(my_age); 
    //see that compiler doesn't complain as long it can be read an type
    print_boot_size("5"); 

    //the name student now recognizes the struct - we can just use this
    Student s; 
    Student *p; 
    return 0; 
}
