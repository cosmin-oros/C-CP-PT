#include <iostream>
#include <cstdlib>
#include <cinttypes>
 
using namespace std;
 
// Class 1
// Helper class(Node structure)
class Node {
    public : int data;
    // Xor of next node and previous node
    Node* xnode;
};
 
// Method 1
// It returns Xored value of the node addresses
Node* Xor(Node* x, Node* y)
{
    return reinterpret_cast<Node*>(
        reinterpret_cast<uintptr_t>(x)
        ^ reinterpret_cast<uintptr_t>(y));
}
 
// Method 2
// Insert a node at the start of the Xored LinkedList and
// mark the newly inserted node as head
void insert(Node** head_ref, int data)
{
    // Allocate memory for new node
    Node* new_node = new Node();
    if (!new_node)
    {
        cout << "Couldn't allocate memory for the node" << endl;
        exit(1);
    }
    
    new_node -> data = data;
 
    // Since new node is inserted at the
    // start , xnode of new node will always be
    // Xor of current head and NULL
    new_node -> xnode = *head_ref;
 
    // If linkedlist is not empty, then xnode of
    // present head node will be Xor of new node
    // and node next to current head */
    if (*head_ref != NULL) {
        // *(head_ref)->xnode is Xor of (NULL and next).
        // If we Xor Null with next we get next
        (*head_ref)
            -> xnode = Xor(new_node, (*head_ref) -> xnode);
    }
 
    // Change head
    *head_ref = new_node;
}
 
// Method 3
// It simply prints contents of doubly linked
// list in forward direction
void printList(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
 
    cout << "The nodes of Linked List are: \n";
 
    // Till condition holds true
    while (curr != NULL) {
        // print current node
        cout << curr -> data << " ";
 
        // get address of next node: curr->xnode is
        // next^prev, so curr->xnode^prev will be
        // next^prev^prev which is next
        next = Xor(prev, curr -> xnode);
 
        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
}

void deleteList(Node** head_ref)
{
 
    /* deref head_ref to get the real head */
    Node* current = *head_ref;
    Node* next = NULL;
 
    while (current != NULL)
    {
        next = current->xnode;
        free(current);
        current = next;
    }
 
    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = NULL;
}
 
int main()
{
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 100);
    insert(&head, 1000);
    insert(&head, 10000);
 
    // Printing the created list
    printList(head);
 
    // deleteList(&head);
    return (0);
}