#include <stdio.h>
int main(){
    //arrays: all ele must be same type
    //structs: can be diff types, accessed via dot notation

    struct student{
        char first_name[20]; 
        char last_name[20]; 
        int year;
        float gpa; 
    }; 

    struct student good_student; 

    strcpy(good_student.first_name, "Adrian"); 
    strcpy(good_student.last_name, "John"); 
    good_student.gpa = 3.99; 
    good_student.year = 40; 

    printf('Name: %s %s\n', good_student.first_name, good_student.last_name); 
    printf("Year: %d, GPA: %d", good_student.year, good_student.gpa); 
    return 0; 



}