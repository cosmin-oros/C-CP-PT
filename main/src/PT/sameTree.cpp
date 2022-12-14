#include <iostream>
#include <cstdio>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }

    if (p == nullptr || q == nullptr) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    // Example:
    //     1         1
    //    / \       / \
    //   2   3     2   3
    //  /           \
    // 4             4
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    q->left->right = new TreeNode(4);

    if (isSameTree(p, q)) {
        std::cout << "The trees are the same." << std::endl;
    } else {
        std::cout << "The trees are different." << std::endl;
    }

    return 0;
}