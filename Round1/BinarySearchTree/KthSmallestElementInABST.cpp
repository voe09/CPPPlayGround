/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ? k ? BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to 
find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        inorderTraversal(root, k, res);
        return res;
    }

private:
    int inorderTraversal(TreeNode* root, int& remaining, int& res) {
        if (root->left) inorderTraversal(root->left, remaining, res);
        --remaining;
        if (remaining == 0) res = root->val;
        if (root->right) inorderTraversal(root->right, remaining, res);
    }
};
