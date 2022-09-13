#include <iostream>

using namespace std;

/*
    The idea is to write a recursive function isMirror() that takes two trees as an argument 
    and returns true if trees are the mirror and false if trees are not mirrored.
    The isMirror() function recursively checks two roots and subtrees under the root.
*/

struct Node{
    int key;
    struct Node *left, *right;
};

// function to create a new node
Node* newNode(int key){
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

bool isMirror(struct Node* root1, struct Node* root2){
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 && root2 && (root1->key == root2->key))
    {
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
    
    return false;
    
}

bool isSymmetric(struct Node* root){
    return isMirror(root, root);
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
    {
        cout << "Symmetric" << endl;
    }else{
        cout << "Not symmetric" << endl;
    }
    

    return 0;
}