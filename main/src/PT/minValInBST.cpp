#include <iostream>

using namespace std;

/*
    Find the node with minimum value in a Binary Search Tree
*/

struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
};

struct Node* newNode(int data) { 
    struct Node* node = new struct Node;

    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    
    return node; 
}

struct Node* insert(struct Node* node, int data) { 
    if (node == NULL) {
        return(newNode(data)); 
    }else{ 
        if (data <= node->data) {
            node->left = insert(node->left, data); 
        }else{
            node->right = insert(node->right, data); 
        }
        
        return node; 
    } 
} 

int minValue(struct Node* node) { 
    struct Node* current = node; 
    
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
    { 
        current = current->left; 
    }

    return(current->data); 
} 

int main(){
    struct Node* root = NULL; 
    root = insert(root, 4); 
    insert(root, 2); 
    insert(root, 1); 
    insert(root, 3); 
    insert(root, 6); 
    insert(root, 5); 

    cout << "Minimum value in BST is " << minValue(root) << endl; 

    return 0;
}