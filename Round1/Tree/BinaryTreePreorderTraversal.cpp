/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        preOrderTraversal(root, res);
        return res;
    }

private:
    void preOrderTraversal(TreeNode* node, vector<int> &vec) {
        vec.push_back(node->val);
        if (node->left) preOrderTraversal(node->left, vec);
        if (node->right) preOrderTraversal(node->right, vec);
    }
};

// Stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<pair<TreeNode*, bool>> stk;
        stk.push({root, false});
        while (!stk.empty()) {
            bool visit;
            std::tie(root, visit) = stk.top();
            stk.pop();
            if (!root) continue;
            if (visit) res.push_back(root->val);
            else {
                stk.push({root->right, false});
                stk.push({root->left, false});
                stk.push({root, true});
            }
        }
        return res;
    }
};


// Morris Traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *curr = root;
        while (curr) {
            if (!curr->left) {
                res.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                    prev = prev->right;
                if (!prev->right) {
                    res.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};
