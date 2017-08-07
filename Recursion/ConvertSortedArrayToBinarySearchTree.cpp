/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums.begin(), nums.end());    
    }
private:
    TreeNode* sortedArrayToBST(iter beg, iter end) {
        if (beg == end) return nullptr;
        iter mid = beg + (end - beg) / 2;
        TreeNode* root = new TreeNode(*mid);
        root->left = sortedArrayToBST(beg, mid);
        root->right = sortedArrayToBST(mid + 1, end);
        return root;
    }
};
