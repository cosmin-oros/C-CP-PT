#include <iostream>

using namespace std;

/*
    Given two lists sorted in increasing order, 
    create and return a new list representing the intersection of the two lists. 
    The new list should be made with its own memory — the original lists should not be changed. 

    Input: 
    First linked list: 1->2->3->4->6
    Second linked list be 2->4->6->8, 
    Output: 2->4->6.
    The elements 2, 4, 6 are common in 
    both the list so they appear in the 
    intersection list. 
*/

// linked list node
struct Node{
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data <<" ";
        node = node->next;
    }
}

Node* sortedIntersect(Node* a, Node* b)
{
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;
 
    /* Once one or the other
    list runs out -- we're done */
    while (a != NULL && b != NULL) {
        if (a->data == b->data) {
            push((&tail->next), a->data);
            tail = tail->next;
            a = a->next;
            b = b->next;
        }
        /* advance the smaller list */
        else if (a->data < b->data){
            a = a->next;
        }
        else{
            b = b->next;
        }
    }
    
    return (dummy.next);
}

int main(){
    Node* a = NULL;
    Node* b = NULL;
    Node* intersect = NULL;

    push(&a, 6);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);

    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);

    intersect = sortedIntersect(a, b);

    cout<<"Linked list containing common items of a & b" << endl;
    printList(intersect);

    return 0;
}