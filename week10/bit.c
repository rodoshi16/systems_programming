#include <stdio.h>

int main(){
    //0b - binary : usually very large and easy to translate hex to binary
    // 0x13 - hexadecimal
    char c = 0b00010011; 
    //unsigned means: only represents positive numbers (0 -255)
    unsigned char a = 0x13; 
    unsigned char b = 0x14; 

    //00010011 - 11101100 ffff

    printf("result of negating %x is %x hex\n", a, ~a); 
    printf("result of negating %x is %x hex\n", b, ~b); 
    printf("result of negating %x is %x hex\n", c, ~c); 
    

    return 0; 
}