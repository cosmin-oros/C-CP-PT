#include <iostream>
#include <cstdlib>

using namespace std;

/*
    Write a function to construct and return a simple circular linked list
    that is the reverse of a given double linked list. The original list 
    provided as parameter remains unchanged
*/

//doubly linked list Node
typedef struct Node{
    int data;
    struct Node* next;  //pointer to next node
    struct Node* prev;  //pointer to previous node
}Node;

//circular linked list Node
typedef struct CNode{
    int data;
    struct CNode* next;
}CNode;

void push(Node** head_ref, int new_data){
    //allocate mem
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        cout << "Couldn't allocate mem" << endl;
        return;
    }

    new_node->data = new_data;

    //next of the next node is the head
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    //change previous of head node
    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }
    
    //move head to new node
    (*head_ref) = new_node;
}

//print doubly linked list
void printDLL(Node* head){
    cout << "Doubly linked list:" << endl;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    
}

CNode* addToCLL(CNode* chead,int data){
    //allocate mem for the CNode
    CNode* temp = (CNode*)malloc(sizeof(CNode));
    CNode* ctemp;
    if (!temp)
    {
        cout << "Couldn't allocate mem" << endl;
        exit(1);
    }

    temp->data = data;

    if (chead == NULL)
    {
        chead = temp;
        temp->next = chead;
    }else{
        ctemp = chead;
        while (ctemp->next != chead)
        {
            ctemp = ctemp->next;
        }
        ctemp->next = temp;
        temp->next = chead;
    }
    return temp;
}

//function that returns a reversed DLL put into a CLL
CNode* reverseList(Node* head){
    //empty circular linked list
    CNode* chead = NULL;

    while (head != NULL)
    {
        chead = addToCLL(chead, head->data);
        head = head->next;
    }

    return chead;
    
}

//print circular linked list
void printCLL(CNode* head){
    CNode* temp = head;
    cout << endl << "Circular linked list:" << endl;

    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next; 
        } while (temp != head);
        
    }
    cout << endl;
}

int main(int argc, char** argv){
    //empty list
    Node* head = NULL;

    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);

    //print doubly linked list
    printDLL(head);

    //create a circular linked list that is the reverse of the DLL
    CNode* chead = reverseList(head);

    printCLL(chead);

    return 0;
}