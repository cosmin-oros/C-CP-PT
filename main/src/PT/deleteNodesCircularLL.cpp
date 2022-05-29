#include <iostream>
#include <cstdlib>

using namespace std;

//structure for a node
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//function to insert a node at the beginning of a circular linked list
void push(Node** head_ref, int data){
    Node* ptr1 = (Node*)malloc(sizeof(Node));
    Node* temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next = ptr1;
        
    }else{
        ptr1->next = ptr1;  //for the first node 
    }
    *head_ref = ptr1;
    
}

void printList(Node* head){
    Node* temp = head;
    if (head != NULL)
    {
        do{
            cout << temp->data <<" ";
            temp = temp->next;
        }while (temp != head);
    }
    
}

void deleteNode(Node* head_ref, Node* del){
    Node* temp = head_ref;

    if (head_ref == del)
    {
        head_ref = del->next;
    }

    while (temp->next != del)
    {
        temp = temp->next;
    }

    temp->next = del->next;

    free(del);
    
}

void deleteOddNodes(Node* head){
    Node* ptr = head;
    Node* next;
    do
    {
        if ((ptr->data % 2) == 1)
        {
            deleteNode(head, ptr);
        }
        next = ptr->next;
        ptr = next;
        
    } while (ptr != head);
    
}

int main(){
    // Initialize lists as empty
    struct Node* head = NULL;
 
    // Created linked list will be 56->61->57->11->12->2
    push(&head, 2);
    push(&head, 12);
    push(&head, 11);
    push(&head, 57);
    push(&head, 61);
    push(&head, 56);
 
    cout << "\nList after deletion : ";
    deleteOddNodes(head);
    printList(head);

    return 0;
}