/*
Given a Binary Search Tree and a target number, return true if there exist two 
elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while (p || !stk.empty()) {
            while (p) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            nums.push_back(p->val);
            p = p->right;
        }

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] > k) --r;
            else if (nums[l] + nums[r] < k) ++l;
            else return true;
        }
        return false;
    }
};
