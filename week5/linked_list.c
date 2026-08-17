#include <stdio.h>

struct Node{
    int value; 
    //next is a pointer to a node
    struct Node *next; 
}; 

int main(){
    struct Node *node_a = malloc(sizeof(struct Node)); 
    struct Node *node_b = malloc(sizeof(struct Node)); 

    //c already deferences the pointer
    node_a -> next = node_b; 

    printf("node_a: %p\n", node_a); 
    printf("node_b: %p\n", node_b); 




}