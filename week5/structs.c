#include <stdio.h>
#include <string.h>

    //arrays: all ele must be same type
    //structs: can be diff types, accessed via dot notation

    struct student{
        char first_name[20]; 
        char last_name[20]; 
        int year;
        float gpa; 
    }; 

    void change(struct student s){
        s.gpa = 4.0; 
    }


    int main(){

        struct student good_student; 

        strcpy(good_student.first_name, "Adrian"); 
        strcpy(good_student.last_name, "John"); 
        good_student.gpa = 3.99; 
        good_student.year = 40; 

        // for the case of structs, functions dont get passed pointers but a copy itself - so no changes to the original copy
        change(good_student); 

        // printf('Name: %s %s\n', good_student.first_name, good_student.last_name); 
        printf("GPA: %f", good_student.gpa); 
        return 0; 

    } 
