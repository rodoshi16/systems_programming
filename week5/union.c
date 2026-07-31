# include <stdio.h>

void change(int numbers[]){
    numbers[0] = 80; 
}


int main(void){
    int my_array[5]; 

    my_array[0] = 40; 
    change(my_array); 
    printf("Element at index 0: %d\n", my_array[0]); 

    return 0; 


}