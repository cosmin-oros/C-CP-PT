#include <iostream>

/* Link list node */
class LNode 
{ 
public:
    int data; 
    LNode* next; 
}; 
  
/* A Binary Tree node */
class TNode 
{ 
public:
    int data; 
    TNode* left; 
    TNode* right; 
}; 

int countLNodes(LNode* head){
    int count = 0;
    LNode* temp = head;
    while (temp)
    {
        temp = temp->next;
        count++;
    }

    return count;
    
}

void push(LNode** head_ref, int data){
    LNode* newNode = new LNode();
    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

void printList(LNode* head){
    while (head != NULL)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    
}

TNode* newNode(int data) 
{ 
    TNode* node = new TNode();
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return node; 
} 

void preOrder(TNode* node) 
{ 
    if (node == NULL) {
        return; 
    }
    std::cout<<node->data<<" "; 
    preOrder(node->left); 
    preOrder(node->right); 
} 

TNode* sortedListToBSTRecursive(LNode** head_ref, int n){
    if (n <= 0)
    {
        return NULL;
    }

    // left subtree
    TNode* left = sortedListToBSTRecursive(head_ref, n/2);

    TNode* root = newNode((*head_ref)->data);
    root->left = left;
    *head_ref = (*head_ref)->next; 

    // right subtree
    root->right = sortedListToBSTRecursive(head_ref, n-n/2-1); 
  
    return root;
    
}

TNode* sortedListToBST(LNode *head) 
{ 
    int n = countLNodes(head); 

    return sortedListToBSTRecursive(&head, n); 
}

int main(){
    LNode* head = NULL;
    // linked list 1->2->3->...->7
    push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 

    std::cout<<"Given Linked List "; 
    printList(head); 
  
    /* Convert List to BST */
    TNode *root = sortedListToBST(head); 
    std::cout << "\nPreOrder Traversal of constructed BST "; 
    preOrder(root); 

    return 0;
}