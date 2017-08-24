/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> path;
        pathSum(root, sum, path, res);
        return res;
    }
    
private:
    void pathSum(TreeNode* node, int sum, vector<int> path, vector<vector<int>>& res) {
        if (!node) return;
        path.push_back(node->val);
        if (!node->left && !node->right && node->val == sum) {
            res.push_back(path);
        }
        pathSum(node->left, sum - node->val, path, res);
        pathSum(node->right, sum - node->val, path, res);
    }    
};
