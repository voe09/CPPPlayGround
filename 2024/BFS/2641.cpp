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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        unordered_map<TreeNode*, int> m;
        m[root] = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sum = 0;
            vector<TreeNode*> v;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *t = q.front();
                q.pop();
                v.push_back(t);
                sum += t->val;
                int non_cousine = (t->left ? t->left->val : 0) + (t->right ? t->right->val : 0);
                if (t->left) {
                    q.push(t->left);
                    m[t->left] = non_cousine;
                }
                if (t->right) {
                    q.push(t->right);
                    m[t->right] = non_cousine;
                }
            }

            for (TreeNode *t : v) {
                t->val = sum - m[t];
            }
        }

        return root;
    }
};