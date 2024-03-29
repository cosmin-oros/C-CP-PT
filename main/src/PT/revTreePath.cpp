#include <iostream>
#include <map>

struct Node {
    int data;
    struct Node *left, *right;
};

Node* reverseTreePathUtil(Node* root, int data, std::map<int, int>& temp, int level, int& nextpos) {
    if (root == NULL){
        return NULL;
    }
 
    // Final condition
    // if the node is found then
    if (data == root->data) {
 
        // store the value in it's level
        temp[level] = root->data;
 
        // change the root value with the current
        // next element of the map
        root->data = temp[nextpos];
 
        // increment in k for the next element
        nextpos++;
        return root;
    }
 
    // store the data in particular level
    temp[level] = root->data;
 
    // We go to right only when left does not
    // contain given data. This way we make sure
    // that correct path node is stored in temp[]
    Node *left, *right;
    left = reverseTreePathUtil(root->left, data, temp, level + 1, nextpos);
    if (left == NULL){
        right = reverseTreePathUtil(root->right, data, temp, level + 1, nextpos);
    }
 
    // If current node is part of the path,
    // then do reversing.
    if (left || right) {
        root->data = temp[nextpos];
        nextpos++;
        return (left ? left : right);
    }
 
    return NULL;
}

void reverseTreePath(Node* root, int data) {
    // store per level data
    std::map<int, int> temp;
 
    // it is for replacing the data
    int nextpos = 0;
 
    // reverse tree path
    reverseTreePathUtil(root, data, temp, 0, nextpos);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main() {
    Node* root = newNode(7);
    root->left = newNode(6);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(3);
    root->right->left = newNode(2);
    root->right->right = newNode(1);
 
    /*     7
         /    \
        6       5
       / \     / \
      4  3     2  1          */
 
    int data = 4;
 
    // Reverse Tree Path
    reverseTreePath(root, data);
 
    // Traverse inorder
    inorder(root);

    return 0;
}