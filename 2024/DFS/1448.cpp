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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int cnt = 0;
        helper(root, -1e4, cnt);
        return cnt;
    }

    void helper(TreeNode *node, int mx, int &cnt) {
        if (!node) return;
        
        if (node->val >= mx) cnt++;
        helper(node->left, max(node->val, mx), cnt);
        helper(node->right, max(node->val, mx), cnt);
    }
};