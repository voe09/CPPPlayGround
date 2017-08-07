/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
typedef vector<int>::iterator iter;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

private:
    TreeNode* buildTree(iter preorder_beg, iter preorder_end,
            iter inorder_beg, iter inorder_end) {
        if (preorder_beg >= preorder_end && inorder_beg >= inorder_end) return NULL;
        TreeNode* root = new TreeNode(*preorder_beg);
        iter inorder_root = std::find(inorder_beg, inorder_end, *preorder_beg);
        iter inorder_left_end = inorder_root, inorder_right_beg = inorder_root + 1;
        iter preorder_left_beg = preorder_beg + 1;
        iter preorder_left_end = preorder_left_beg + (inorder_left_end - inorder_beg);
        iter preorder_right_beg = preorder_left_end;
        root->left = buildTree(preorder_left_beg, preorder_left_end, inorder_beg, inorder_left_end);
        root->right = buildTree(preorder_right_beg, preorder_end, inorder_right_beg, inorder_end);
        return root;
    }
};
