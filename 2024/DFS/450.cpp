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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *dummy = new TreeNode(1e9);
        dummy->left = root;
        helper(dummy, root, key);
        return dummy->left;
    }

    void helper(TreeNode *p, TreeNode *t, int k) {
        if (!t) return;
        if (t->val == k) {
            TreeNode *l = t->left, *r = t->right;
            if (p->left == t) {
                if (!r) {
                    p->left = l;
                    return;
                } else {
                    TreeNode *c = r;
                    while (c->left) c = c->left;
                    c->left = l;
                    p->left = r;
                    return;
                }
            } else {
                if (!l) {
                    p->right = r;
                    return;
                } else {
                    TreeNode *c = l;
                    while (c->right) c = c->right;
                    c->right = r;
                    p->right = l;
                    return;
                }
            }
        } else {
            helper(t, t->left, k);
            helper(t, t->right, k);
        }
    }
};