int main() {

    int i = 5; 
    int j = 10; 

    int k = i / j; 
    
    double half = 0.5; 

    // k is stored as an int so to assign a double to int, truncated
    k = half; 
    printf("%d", k); 

    double d = i/j; 
    printf("double d is %f\n", d);


    //dividing a double by an int is a double

    d = (double) i/j;
    printf("double d is %f\n", d); 


}