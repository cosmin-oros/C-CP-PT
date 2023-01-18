#include <iostream>
#include <climits>

/*
    Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

    Return the number of good nodes in the binary tree.

    

    Example 1:



    Input: root = [3,1,4,3,null,1,5]
    Output: 4
    Explanation: Nodes in blue are good.
    Root Node (3) is always a good node.
    Node 4 -> (3,4) is the maximum value in the path starting from the root.
    Node 5 -> (3,4,5) is the maximum value in the path
    Node 3 -> (3,1,3) is the maximum value in the path.
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
    int c = 0;

	void helper(TreeNode* root, int cmp){
		if (root){

			if(root->val >= cmp) {
                c++;
            }

			if(root->left) {
				helper(root->left, std::max(root->val,cmp));
            }

			if(root->right) {
				helper(root->right, std::max(root->val,cmp));
            }
		}
	}
	int goodNodes(TreeNode* root) {
		helper(root, INT_MIN);
		return c;
	}
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->right = NULL;
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    std::cout << s.goodNodes(root) << std::endl;

    return 0;
}