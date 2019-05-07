/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<pair<TreeNode*, int>> stk;
        set<int> visited;
        stk.push({root, 0});
        while (!stk.empty()) {
            pair<TreeNode*, int> curr = stk.top();
            stk.pop();
            TreeNode* node = curr.first;
            int layer = curr.second;
            if (visited.count(layer) == 0) {
                res.push_back(node->val);`
		visited.insert(layer);
            }
            if (node->left) stk.push({node->left, layer + 1});
            if (node->right) stk.push({node->right, layer + 1});
        }
        return res;
    }
};
