
#include <stdio.h>
#include <stdlib.h>

/*

slow = head
fast = head 

while fast and fast.next is not None:
    slow = slow.next 
    fast = fast.next.next
*/

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

    Node *fast = a; 
    Node *slow = a; 

    while (fast != NULL && fast->next != NULL){
        slow = slow -> next; 
        fast = fast -> next -> next; 
        
    }
    printf("The middle of list is %d\n", slow ->val); 
    return 0; 


}