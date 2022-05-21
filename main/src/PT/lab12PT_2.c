#include <stdio.h>
#include <stdlib.h>

/*
2. Write a function to split a simple linked list into two double linked
lists at a specific point in the original list. The specific point is
provided by the key value.
*/

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct DNode{
    int data;
    struct DNode* next;
    struct DNode* prev;
}DNode;

void push(Node** head_ref,int new_data){
    //allocate mem for new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        printf("Couldn't allocate mem\n");
        exit(-1);
    }
    

    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

//Function to print nodes in a given linked list
void printList(Node* node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void splitList(Node* head_ref,DNode** head_ref1, DNode** head_ref2, int key){
    //insert the first 'key'-1 number of nodes in the first list (we eliminate the 'key' node because we split the list there)
    while (key-1)
    {
        //allocate mem for new node
        DNode* new_node = (DNode*)malloc(sizeof(DNode));
        if (!new_node)
        {
            printf("Couldn't allocate mem\n");
            exit(-1);
        }
        

        new_node->data = head_ref->data;
        new_node->prev = NULL;
        new_node->next = (*head_ref1);   
        if((*head_ref1) !=  NULL){
            (*head_ref1)->prev = new_node ;  
        } 
        (*head_ref1) = new_node;
        head_ref = head_ref->next;

        key--;
    }

    //skips over the Node where we split the original list
    head_ref = head_ref->next;
    
    while (head_ref != NULL)
    {
        DNode* new_node = (DNode*)malloc(sizeof(DNode));
        if (!new_node)
        {
            printf("Couldn't allocate mem\n");
            exit(-1);
        }
        

        new_node->data = head_ref->data;
        new_node->prev = NULL;
        new_node->next = (*head_ref2);   
        if((*head_ref2) !=  NULL){
            (*head_ref2)->prev = new_node ;  
        } 
        (*head_ref2) = new_node;
        head_ref = head_ref->next;
    }
    
    
}

void freeList(Node* head){
    Node* temp;

    while (head != NULL)
    {
      temp = head;
      head = head->next;
      free(temp);
    }
    
}

void freeDList(DNode* head){
    struct DNode* temp;

    while (head != NULL)
    {
      temp = head;
      head = head->next;
      free(temp);
    }
    
}

int main(){
    //empty list
    Node* head = NULL;
    
    //10->8->4->2
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
    push(&head, 12);

    printList(head);

    int key = 3;
    DNode* head1 = NULL;
    DNode* head2 = NULL;

    splitList(head,&head1,&head2,key);

    printf("\nList1: ");
    printList(head1);
    printf("\nList2: ");
    printList(head2);
    printf("\n");

    freeList(head);
    freeDList(head1);
    freeDList(head2);
    return 0;
}