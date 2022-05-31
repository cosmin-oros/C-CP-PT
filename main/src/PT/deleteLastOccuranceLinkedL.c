#include <stdio.h>
#include <stdlib.h>
 
// A linked list Node
typedef struct Node {
    int data;
    struct Node* next;
}Node;
 
//function to delete the last occurance of the element
void deleteLast(Node** head, int x){
    Node** tmp1 = NULL;
    while (*head)
    {
        if ((*head)->data == x)
        {
            tmp1 = head;
        }
        head = &(*head)->next;
        
    }
    if(tmp1){
        struct Node* tmp = *tmp1;
        *tmp1 = tmp->next;
        free(tmp);
    }
    
}

//function to add a new node
Node* newNode(int x){
    Node* node = malloc(sizeof(Node));
    if (!node)
    {
        printf("Couldn't allocate mem\n");
        return;
    }
    
    node->data = x;
    node->next = NULL;
    return node;
}

//function that prints the linked list starting from the given node
void display(Node* head){
    Node* temp = head;
    if (!head)
    {
        return;
    }

    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}

int main()
{
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(4);
    head->next->next->next->next->next->next = newNode(4);

    printf("Created Linked list: ");
    display(head);

    deleteLast(&head, 4);   // Pass the address of the head pointer

    printf("List after deletion of 4: ");
    display(head);
    return 0;
}