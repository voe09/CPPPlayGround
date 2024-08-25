/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        while (!stk.empty() || p) {
            while (p) {
                stk.push(p);
                p = p->left;
            }
            TreeNode* t = stk.top();
            stk.pop();
            res.push_back(t->val);
            p = t->right;
        }
        return res;
    }
};