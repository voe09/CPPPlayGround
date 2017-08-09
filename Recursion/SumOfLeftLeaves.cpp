/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively.
Return 24.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        int res = 0;
        sumOfLeftLeaves(root, res);
        return res;
    }

private:
    // Preorder Traversal
    void sumOfLeftLeaves(TreeNode* root, int& sum) {
        if (!root) return;
        if (!root->left && !root->right) {
            sum += root->val;
            return;
        }
        if (root->left) sumOfLeftLeaves(root->left, sum);
        if (root->right && !root->right->left && !root->right->right) return;
        if (root->right && (root->right->left || root->right->right)) 
            sumOfLeftLeaves(root->right, sum);
    }
};
