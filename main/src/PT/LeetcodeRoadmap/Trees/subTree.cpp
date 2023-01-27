#include <iostream>

/*
    Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

    A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

    

    Example 1:


    Input: root = [3,4,5,1,2], subRoot = [4,1,2]
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL) {
            return false;
        }

        bool res = false;
        res = res || isEqual(s, t);
        if(res) {
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
	
	//check a subtree of s , to show if every node of s's subtree equals to reflect t's node
    bool isEqual(TreeNode*s, TreeNode* t){
        if(s == NULL){
            if(t == NULL) {
                return true;
            } else {
                return false;
            }
            
        }
        else{
            if(t == NULL) {
                return false;
            }

            if(s->val != t->val) {
                return false;
            } else {
                return isEqual(s->left ,t->left) && isEqual(s->right, t->right);
            }
        }
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    TreeNode* root2 = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    std::cout << s.isSubtree(root, root2);

    return 0;
}