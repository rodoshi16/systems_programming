int main(){
    char text[5]; 
    text[0] = 'h'; 
    text[1] = 'e'; 
    //this makes it a string
    text[2] = '\0'; 

    int i; 
    for (i = 0; i < 20; i++){
        printf("%c", text[i]); 
    }
    return 0; 
}