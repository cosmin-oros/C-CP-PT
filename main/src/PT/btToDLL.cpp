#include <iostream>

using namespace std;

/*
    Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
    The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
    The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
    The first node of Inorder traversal (left most node in BT) must be head node of the DLL.
*/

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void btToDLL(Node* root, Node*& head)
{
    // Base cases
    if (root == NULL){
        return;
    }
 
    // Recursively convert right subtree
    btToDLL(root->right, head);
 
    // insert root into DLL
    root->right = head;
 
    // Change left pointer of previous head
    if (head != NULL){
        head->left = root;
    }
 
    // Change head of Doubly linked list
    head = root;
 
    // Recursively convert left subtree
    btToDLL(root->left, head);
}

void printList(Node* head)
{
    cout << "DLL: " << endl;
    
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    
    cout << endl;
}

int main(){
    Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->right = newNode(8);
    root->left->left->left = newNode(0);
    root->left->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(9);
 
    Node* head = NULL;

    btToDLL(root, head);
 
    printList(head);

    return 0;
}