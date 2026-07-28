#include <stdio.h>
#include <time.h>

void bubble_sort(int *, int); 
void insertion_sort(int *, int); 
void selection_sort(int *, int); 


void check_sort(int *arr, int size){
    for (int i = 1; i < size; i++){
        if (arr[i-1] > arr[i]){
            printf("Mis sorted at index %d\n", i); 
            return; 
        }
    }
}

void random_init(int *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = rand(); 
    }
}

double time_sort(int size, void(*sort_func)(int *, int)){
    int arr[size]; 
    random_init(arr, size); 


    clock_t begin = clock(); 
    clock_t end = clock(); 
    //if we want to change the sorting algo - we need to change the code here which isnt standard
    // bubble_sort(arr, size);

    //instead we use the func pointer passed in as the parameter
    sort_func(arr, size); 
    check_sort(arr, size); 

    return (double)(end - begin) / CLOCKS_PER_SEC; 

}

int main(int argc, char **argv){
    srand(time(NULL)); 

    int sort; 

    for (int size = 1; size < 4096; size *=2){
        //calling the func as the parameter
        double time_spent = time_sort(size, bubble_sort); 

    }

    return 0; 

}