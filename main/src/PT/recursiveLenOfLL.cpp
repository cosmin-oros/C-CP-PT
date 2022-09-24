#include <iostream>

using namespace std;

/*
    A recursive approach for finding the length of the linked list:
    Follow the given steps to solve the problem:

    If the head is NULL, return 0.
    Otherwise, return 1 + getCount(head->next) 
*/

class Node{
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();

    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int getCount(Node* head){
    return head == NULL ? 0 : (1 + getCount(head->next));
}

int main(){
    Node* head = NULL;

    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);

    cout << "The number of nodes is: " << getCount(head) << endl;

    return 0;
}