#include <iostream>

/*
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:

    The left 
    subtree
    of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    

    Example 1:


    Input: root = [2,1,3]
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
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }
    bool isValid(TreeNode* root, TreeNode* left, TreeNode* right) { 
        if (!root) {
            return true;
        }

        if (left && left->val >= root->val || right && right->val <= root-> val) { 
            return false;
        }

        return isValid(root->left, left, root) && isValid(root->right, root, right);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution s;

    std::cout << s.isValidBST(root) << std::endl;

    return 0;
}