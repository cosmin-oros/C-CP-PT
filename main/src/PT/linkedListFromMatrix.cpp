#include <iostream>
#include <vector>

using namespace std;

/*
    Given a matrix. Convert it into a linked list matrix such that each node is connected to its next right and down node.

    Input : 2D matrix 
    1 2 3
    4 5 6
    7 8 9
    Output :
    1 -> 2 -> 3 -> NULL
    |        |     |
    v       v    v
    4 -> 5 -> 6 -> NULL
    |        |     |
    v      v     v
    7 -> 8 -> 9 -> NULL
    |       |       |
    v     v       v
    NULL NULL NULL
*/

struct Node{
    int data;
    Node* right, *down;
};

Node* construct(int arr[][4], int i, int j, int m, int n, vector<vector<Node*>> &visited){
    // return if i or j is out of bounds
    if (i > m - 1 || j > n - 1){
        return NULL;
    }
    // Check if node is previously created then,
    // don't need to create new/
    if(visited[i][j]){
        return visited[i][j];
    }

    // create a new node for current i and j
    // and recursively allocate its down and
    // right pointers
    Node* temp = new Node();
    visited[i][j] = temp;
    temp->data = arr[i][j];
    temp->right = construct(arr, i, j + 1, m, n, visited);
    temp->down = construct(arr, i + 1, j, m, n, visited);
    
    return temp;
}

void display(Node* head){
    // pointer to move right
    Node* Rp;
    // pointer to move down
    Node* Dp = head;

    // loop till node->down is not NULL
    while (Dp) {
        Rp = Dp;
        // loop till node->right is not NULL
        while (Rp) {
            cout << Rp->data << " ";
            Rp = Rp->right;
        }
        cout << "\n";
        Dp = Dp->down;
    }
}

int main(){
    int arr[][4] = {
        { 1, 2, 3, 0},
        { 4, 5, 6 , 1},
        { 7, 8, 9 , 2},
        { 7, 8, 9 , 2}
    };

    int m = 4, n = 4;

    vector<vector<Node*>> visited(m, vector<Node*>(n));

    Node* head = construct(arr, 0, 0, m, n, visited);

    display(head);

    return 0;
}