#include <iostream>
#include <queue>

using namespace std;

/*
    In the flip operation, the leftmost node becomes the root of the flipped tree and its parent becomes 
    its right child and the right sibling becomes its left child and the same should be done for all left most nodes recursively. 

    root->left->left = root->right;
    root->left->right = root;
    root->left = NULL;
    root->right = NULL; 
*/

struct Node
{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data)
{
    struct Node *temp = new struct Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* flipBinaryTree(Node* root)
{
    // Base cases
    if (root == NULL){
        return root;
    }

    if (root->left == NULL && root->right == NULL){
        return root;
    }
 
    //  recursively call the same method
    Node* flippedRoot = flipBinaryTree(root->left);
 
    //  rearranging main root Node after returning
    // from recursive call
    root->left->left = root->right;
    root->left->right = root;
    root->left = root->right = NULL;
 
    return flippedRoot;
}

void printLevelOrder(Node *root)
{
    // Base Case
    if (root == NULL){
          return;
    }
 
    // Create an empty queue for level order traversal
    queue<Node *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (1)
    {
        // nodeCount (queue size) indicates number
        // of nodes at current level.
        int nodeCount = q.size();
        if (nodeCount == 0){
            break;
        }
 
        // Dequeue all nodes of current level and
        // Enqueue all nodes of next level
        while (nodeCount > 0)
        {
            Node *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL){
                q.push(node->left);
            }
            if (node->right != NULL){
                q.push(node->right);
            }
            nodeCount--;
        }
        cout << endl;
    }
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
 
    cout << "Level order traversal of given tree\n";
    printLevelOrder(root);
 
    root = flipBinaryTree(root);
 
    cout << "\nLevel order traversal of the flipped tree" << endl;
    
    printLevelOrder(root);

    return 0;
}