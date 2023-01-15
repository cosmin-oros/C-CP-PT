#include <iostream>

/*
    Given a binary tree, determine if it is height-balanced

    Example 1:


    Input: root = [3,9,20,null,null,15,7]
    Output: true
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
    int check(TreeNode* root){
        if(root == NULL) {
            return 0;
        }

        int l = check(root->left);
        int r = check(root->right);

        if(l == -1 || r == -1) {
            return -1;
        }
        if(abs(l-r) > 1) {
            return -1;
        }
        
        return 1 + std::max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);

    std::cout << s.isBalanced(root) << std::endl;

    return 0;
}