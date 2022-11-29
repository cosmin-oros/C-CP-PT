#include <iostream>

// choose the nr of elements for the linked list
#define N 5

typedef struct Node{
    int data;
    struct Node* next;
}Node;

// remove nth from end
void removeNthNode(Node* head, int n) {
    if (n > N) 
    {
        return;
    }

    // move the Node pointer to the nth node
    while (n)
    {
        head = head->next;
        n--;
    }
    head->next = head->next->next;
    
}

// function to create a random linked list with n elements
Node* createLinkedList(int n) {
    Node* head = NULL;
    Node* temp = NULL;
    Node* p = NULL;

    for(int i = 0; i < n; i++){
        temp = (Node*)malloc(sizeof(Node));
        temp->data = rand() % 10;
        temp->next = NULL;

        if(head == NULL) {
            head = temp;
        } else{
            p = head;
            while (p->next!=NULL) {
                p = p->next;
            }
            p->next = temp;
            
        }
    }
    return head;
}

// function to print the elements of the linked list
void printLL(Node* head) {
    while (head != NULL)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
    
}

int main() {
    Node* head = createLinkedList(N);

    std::cout << "Linked list before removing nth node:\n";
    printLL(head);

    removeNthNode(head, 2);

    std::cout << "Linked list after removing nth node:\n";
    printLL(head);

    return 0;
}