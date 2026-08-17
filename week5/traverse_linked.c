#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val; 
    struct Node *next; 
}Node; 


Node* create_node(int n, Node *next){
    Node *new_node = malloc(sizeof(Node)); 
    new_node -> val = n; 
    new_node -> next = next; 
    return new_node; 
}

int main(){
    Node *front = NULL; 
    Node * c = create_node(3, front); 
    Node * b = create_node(2, c); 
    Node * a = create_node(1, b); 

    Node *curr = a; 
    while (curr != NULL){
        printf("The value of Node: %d\n",curr->val); 
        curr = curr -> next; 
    }

}