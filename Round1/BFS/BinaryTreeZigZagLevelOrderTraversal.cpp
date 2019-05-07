/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(root);
        vector<int> layer;
        while (!stk1.empty() || !stk2.empty()) {
            while (!stk1.empty()) {
                TreeNode* curr = stk1.top();
                stk1.pop();
                layer.push_back(curr->val);
                if (curr->left) stk2.push(curr->left);
                if (curr->right) stk2.push(curr->right);
            }
            if (!layer.empty()) res.push_back(layer);
            layer.clear();
            while (!stk2.empty()) {
                TreeNode* curr = stk2.top();
                stk2.pop();
                layer.push_back(curr->val);
                if (curr->right) stk1.push(curr->right);
                if (curr->left) stk1.push(curr->left);
            }
            if (!layer.empty()) res.push_back(layer);
            layer.clear();
        }
        return res;
    }
};
