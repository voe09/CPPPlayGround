/*
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> res;
        if (!root) return res;
        q.push({root, 0});
        int cur_level = 0;
        vector<int> level_val;
        while (!q.empty()) {
            pair<TreeNode*, int> curr = q.front();
            q.pop();
            if (curr.first->left) q.push({curr.first->left, curr.second + 1});
            if (curr.first->right) q.push({curr.first->right, curr.second + 1});
            if (curr.second == cur_level) {
                level_val.push_back(curr.first->val);
            } else {
                res.push_back(level_val);
                level_val.clear();
                level_val.push_back(curr.first->val);
                cur_level = curr.second;
            }
        }
        if (!level_val.empty()) res.push_back(level_val);
        return res;
    }
};
