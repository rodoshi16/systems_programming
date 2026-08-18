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

void insert(int position, int num, Node *front){
    Node *new_node = malloc(sizeof(Node)); 
    int i = 0; 
    while (front != NULL){
        if (i == position-1){
            Node *temp = front -> next; 
            front -> next = new_node; 
            new_node -> next = front; 
            return 0; 
        }
        else{
            i += 1; 
        }
    }

    printf("Position is greater than length"); 

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