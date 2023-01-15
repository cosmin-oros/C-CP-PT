#include <iostream>

/*
    Given the root of a binary tree, invert the tree, and return its root.

    Example 1:


    Input: root = [4,2,7,1,3,6,9]
    Output: [4,7,2,9,6,3,1]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) {
            return root;
        }
        
        TreeNode* left_tree  = invertTree(root->left);
        TreeNode* right_tree = invertTree(root->right);
        root->left  = right_tree;
        root->right = left_tree;
        return root;
    }

    void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    root = s.invertTree(root);

    s.printTree(root);

    return 0;
}