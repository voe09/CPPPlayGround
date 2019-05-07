/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        postorderTraversal(root, res);
        return res;
    }

private:
    void postorderTraversal(TreeNode* node, vector<int> &vec) {
        if (node->left) postorderTraversal(node->left, vec);
        if (node->right) postorderTraversal(node->right, vec);
        res.push_back(node->val);
    }
};


// Morris Traversal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode dummy(INT_MIN);
        dummy.left = root;
        auto *cur = &dummy;
        while (cur) {
            if (!cur->left) {
                cur = cur->right;
            } else {
                auto *node = cur->left;
                while (node->right && node->right != cur) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = cur;
                    cur = cur->left;
                } else {
                    const auto& v = trace_back(cur->left, node);
                    res.insert(res.end(), v.cbegin(), v.cend());
                    node->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }

private:
    vector<int> trace_back(const TreeNode *from, const TreeNode *to) {
        vector<int> res;
        auto *cur = from;
        while (cur != to) {
            res.emplace_back(cur->val);
            cur = cur->right;
        }
        res.emplace_back(to->val);
        reverse(res.begin(), res.end());
        return res;
    }
};

// Stack
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*, bool>> stk;
        stk.push({root, false});
        while (!stk.empty()) {
            bool visit;
            std::tie(root, visit) = stk.top();
            stk.pop();
            if (!root) continue;
            if (visit) res.push_back(root->val);
            else {
                stk.push({root, true});
                stk.push({root->right, false});
                stk.push({root->left, false});
            }
        }
        return res;
    }
};
