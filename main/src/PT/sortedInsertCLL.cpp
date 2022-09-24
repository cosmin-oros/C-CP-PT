#include <iostream>

using namespace std;

/*
    1) Linked List is empty:  
    a)  since new_node is the only node in CLL, make a self loop.      
          new_node->next = new_node;  
    b) change the head pointer to point to new node.
          *head_ref = new_node;
    2) New node is to be inserted just before the head node:    
    (a) Find out the last node using a loop.
            while(current->next != *head_ref)
                current = current->next;
    (b) Change the next of last node. 
            current->next = new_node;
    (c) Change next of new node to point to head.
            new_node->next = *head_ref;
    (d) change the head pointer to point to new node.
            *head_ref = new_node;
    3) New node is to be  inserted somewhere after the head: 
    (a) Locate the node after which new node is to be inserted.
            while ( current->next!= *head_ref && 
                current->next->data < new_node->data)
            {   current = current->next;   }
    (b) Make next of new_node as next of the located pointer
            new_node->next = current->next;
    (c) Change the next of the located pointer
            current->next = new_node;
*/

class Node{
public:
    int data;
    Node* next;
};

void sortedInsert(Node** head_ref, Node* new_node){
    Node* current = *head_ref; 

    if (current == NULL) 
    { 
        new_node->next = new_node; 
        *head_ref = new_node; 
    }else if (current->data >= new_node->data) 
    { 
        /* If value is smaller than head's value then 
        we need to change next of last node */
        while(current->next != *head_ref){
            current = current->next; 
        }

        current->next = new_node; 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    }else
    { 
        /* Locate the node before the point of insertion */
        while (current->next!= *head_ref && current->next->data < new_node->data) {
            current = current->next; 
        }
      
        new_node->next = current->next; 
        current->next = new_node; 
    } 


}

void printList(Node* head){
    Node* temp;

    if (head != NULL)
    {
        temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        
        cout << endl;
    }
    
}

int main(){
    int arr[] = {3, 4, 9, 2, 12, 59, 10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    Node* head = NULL;
    Node* temp;

    for (int i = 0; i < arrSize; i++)
    {
        temp = new Node();
        temp->data = arr[i];
        sortedInsert(&head, temp); 
    }
    
    printList(head);

    return 0;
}