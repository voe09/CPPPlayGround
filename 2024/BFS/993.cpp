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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            bool hasX = false, hasY = false;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *t = q.front();
                hasX = hasX || (t->val == x);
                hasY = hasY || (t->val == y);
                q.pop();
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
                if (t->left && t->right) {
                    if ((t->left->val == x && t->right->val == y) || (t->right->val == x && t->left->val == y)) return false;
                }
            }
            cout << endl;

            if (hasX && hasY) return true;
        }

        return false;
    }
};