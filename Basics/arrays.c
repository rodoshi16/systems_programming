int main() {
    float arr[4]; 

    arr[0] = 0.1; 
    arr[1] = 0.2; 
    arr[2] = 0.3; 
    arr[4] = 0.4; 


    float avg = (arr[0] + arr[1] + arr[2] + arr[3]) / 4;

    int A[3] = {12,3,5}; 
    int check = A[0]; 
    //DO NOT do this - this can over write some value in memory used by other variables
    A[5] = 999; 

    //segmentation fault - when u try to access an invalid address

    float avg1; 
    for (int i = 0; i < sizeof(arr); i++) {
        avg += arr[i]; 
        print("The average is %f", avg); 

    }

    //code to return the second oldest age
    int ages[4]; 
    int count; 
    int m = -1;
    int s = -1; 
    for (int i = 0; i < count; i++){
        if (ages[i] > m) {
            s = m; 
            m = ages[i]; 
        }
       
        else if (ages[i] > s && ages[i] != m){
        	s = ages[i]; 
        }
    } 
    printf("%d\n", s);


    return 0; 



}