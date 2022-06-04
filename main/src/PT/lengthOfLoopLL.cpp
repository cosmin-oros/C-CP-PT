#include <iostream>

using namespace std;

//node for linked list
typedef struct Node{
    int data;
    struct Node* next;
}Node;


//function that adds a new node
Node* newNode(int key){
    Node* temp = (Node*)malloc(sizeof(Node));

    if (!temp)
    {
        cout << "Couldn't allocate mem";
        exit(-1);
    }

    temp->data = key;
    temp->next = NULL;
    return temp;
    
}

// Returns count of nodes present in loop.
int countNodes(Node *n)
{
    int res = 1;
    Node *temp = n;
    while (temp->next != n)
    {
        res++;
        temp = temp->next;
    }
    return res;
}

/* This function detects and counts loop
nodes in the list. If loop is not there
in then returns 0 */
int countNodesinLoop(struct Node *list)
{
    struct Node *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p &&
                     fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
 
        /* If slow_p and fast_p meet at
        some point then there is a loop */
        if (slow_p == fast_p)
            return countNodes(slow_p);
    }
 
    /* Return 0 to indicate that
       there is no loop*/
    return 0;
}

int main(){
    Node* head = newNode(1);

    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next;
 
    cout << countNodesinLoop(head) << endl;

    return 0;
}