#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

/* Function to delete the entire linked list */
void deleteList(Node** head_ref)
{
   /* deref head_ref to get the real head */
   Node* current = *head_ref;
   Node* next;
  
   while (current != NULL) 
   {
       next = current->next;
       free(current);
       current = next;
   }
    
   /* deref head_ref to affect the real head back
      in the caller. */
   *head_ref = NULL;
}
  
/* Given a reference (pointer to pointer) to the head
  of a list and an int, push a new node on the front
  of the list. */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  
    if (!new_node)
    {
        cout << "Couldn't allocate mem\n";
        exit(1);
    }
    
    /* put in the data  */
    new_node->data  = new_data;
     
    /* link the old list off the new node */
    new_node->next = (*head_ref);
     
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
  
void printReversed(Node* head)
{
    if (!head){
        return;
    }
 
    printReversed(head->next);
    cout << head->data << " ";
}

int main(){
    //start with an empty list
    Node* head = NULL;

    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);

    printReversed(head);

    return 0;
}