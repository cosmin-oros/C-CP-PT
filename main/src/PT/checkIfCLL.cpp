#include <iostream>

using namespace std;

/*
    Given a singly linked list, find if the linked list is circular or not. 
*/

struct Node{
    int data;
    Node* next;
};

Node* newNode(int new_data){
    struct Node* temp = new Node;
    temp->data = new_data;
    temp->next = NULL;
    return temp;
}

bool isCircular(struct Node* head){
    if (head == NULL)
    {
        return true;
    }

    struct Node* temp = head->next;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    return (temp == head);
    
}

int main(){
    struct Node* head = newNode(1);

    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    isCircular(head) ? cout << "Circular" << endl : cout << "Not circular" << endl;
 
    // Making linked list circular
    head->next->next->next->next = head;
 
    isCircular(head) ? cout << "Circular" << endl : cout << "Not circular" << endl;

    return 0;
}