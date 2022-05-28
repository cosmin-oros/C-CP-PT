#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void printList(Node* head){
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    
}

void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if (!new_node)
    {
        printf("Couldn't allocate mem\n");
        exit(1);
    }
    
    /* put in the data  */
    new_node->data = new_data;
                 
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
         
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void removeDuplicates(Node* head){
    Node* current = head;
    Node* next_next;

    //if the list is empty
    if (current == NULL)
    {
        return;
    }
    
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }else{
            current = current->next;
        }
        
    }
    
}

int main(){
    /* Start with the empty list */
    Node* head = NULL;
   
    /* Let us create a sorted linked list to test the functions
     Created linked list will be 11->11->11->13->13->20 */
    push(&head, 20);
    push(&head, 13);
    push(&head, 13); 
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);  

    printf("The list before removing the duplicates:\n");
    printList(head);

    removeDuplicates(head);

    printf("List after removing the duplicates:\n");
    printList(head);

    return 0;
}