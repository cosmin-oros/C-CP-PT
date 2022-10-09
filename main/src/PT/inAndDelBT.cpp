#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int new_data){
    Node* new_node = new Node();
    // check if the memory was allocated successfully
    if (!new_node)
    {
        cout << "Couldn't allocate mem" << endl;
        return NULL;
    }

    new_node->data = new_data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insertNode(Node* root, int data){
    // if tree is empty
    if (!root)
    {
        root = createNode(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }else{
            temp->left = createNode(data);
            return root;
        }

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }else{
            temp->right = createNode(data);
            return root;
        }
        
    }
       
}

void deleteDeepest(Node* root, Node* d_node)
{
    queue<Node*> q;
    q.push(root);
 
    // Do level order traversal until last node
    Node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }else{
                q.push(temp->right);
            }
        }
 
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }else{
                q.push(temp->left);
            }
        }
    }
}

Node* deleteNode(Node* root, int key){
    if (!root)
    {
        return NULL;
    }

    if (!root->left && !root->right)
    {
        if (root->data == key)
        {
            return NULL;
        }else{
            return root;
        }
        
    }
    
    queue<Node*> q;
    q.push(root);

    Node* temp;
    Node* key_node = NULL;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == key)
        {
            key_node = temp;
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        
    }
    
    if (key_node != NULL)
    {
        int x = temp->data;
        deleteDeepest(root, temp);
        key_node->data = x;
    }
    
    return root;
    
}

void inorderTrav(Node* root){
    if (!root)
    {
        return;
    }

    inorderTrav(root->left);
    cout << root->data << " ";
    inorderTrav(root->right);
    
}

int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->left = createNode(5);

    cout << "Inorder traversal: ";
    inorderTrav(root);
    cout << endl;

    root = insertNode(root, 6);

    cout << "Inorder traversal: ";
    inorderTrav(root);
    cout << endl;

    root = deleteNode(root, 2);

    cout << "Inorder traversal: ";
    inorderTrav(root);
    cout << endl;

    return 0;
}