/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<pair<TreeNode*, int>> stk;
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> res;
        if (!root) return res;
        q.push({root, 0});
        while (!q.empty()) {
            pair<TreeNode*, int> curr = q.front();
            q.pop();
            stk.push(curr);
            if (curr.first->right) q.push({curr.first->right, curr.second + 1});
            if (curr.first->left) q.push({curr.first->left, curr.second + 1});
        }

        int curr_level = stk.top().second;
        vector<int> level_val;
        while (!stk.empty()) {
            pair<TreeNode*, int> curr = stk.top();
            stk.pop();
            if (curr.second == curr_level) {
                level_val.push_back(curr.first->val);
            } else {
                res.push_back(level_val);
                level_val.clear();
                level_val.push_back(curr.first->val);
                curr_level = curr.second;
            }
        }
        if (!level_val.empty()) res.push_back(level_val);
        return res;
    }
};


