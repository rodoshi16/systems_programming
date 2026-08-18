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
    new_node -> val = num; 
    int i = 0; 
    while (front != NULL){
        if (i == position-1){
            Node *temp = front -> next; 
            front -> next = new_node; 
            new_node -> next = temp; 
        }
        front = front -> next;
        i += 1; 
    }

}

int main(){
    Node *front = NULL; 
    Node * c = create_node(3, front); 
    Node * b = create_node(2, c); 
    Node * a = create_node(1, b); 

    Node *curr = a; 
    insert(1, 7, a); 
    while (curr != NULL){
        printf("The value of Node: %d\n",curr->val); 
        curr = curr -> next; 
    }

}