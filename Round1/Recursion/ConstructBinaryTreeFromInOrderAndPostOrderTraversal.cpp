/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());    
    }

private:
    TreeNode* buildTree(iter inorder_beg, iter inorder_end,
            iter postorder_beg, iter postorder_end) {
        if (inorder_beg >= inorder_end && postorder_beg >= postorder_end) return NULL;

        auto root_val = postorder_end - 1;
        TreeNode* root = new TreeNode(*root_val);
        auto inorder_root = std::find(inorder_beg, inorder_end, *root_val);
        iter inorder_left_end = inorder_root, inorder_right_beg = inorder_root + 1;
        iter postorder_right_end = postorder_end - 1;
        iter postorder_right_beg = postorder_right_end - (inorder_end - inorder_right_beg);
        iter postorder_left_end = postorder_right_beg;
        root->left = buildTree(inorder_beg, inorder_left_end, postorder_beg, postorder_left_end);
        root->right = buildTree(inorder_right_beg, inorder_end, postorder_right_beg, postorder_right_end);
        return root;
    }
};
