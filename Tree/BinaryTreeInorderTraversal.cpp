/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        inorderTraversal(root, res);
        return res;
    }
private:
    void inorderTraversal(TreeNode* root, vector<int> &res) {
        if (root->left) inorderTraversal(root->left, res);
        res.push_back(root->val);
        if (root->right) inorderTraversal(root->right, res);
    }
};


/*
Inorder Traversal:

Algorithm Inorder(tree)
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)
*/

// Iterative: Use stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode *, bool>> s;
        s.emplace(root, false);
        while (!s.empty()) {
            bool visited;
            tie(root, visited) = s.top();
            s.pop();
            if (root == nullptr) {
                continue;
            }
            if (visited) {
                res.emplace_back(root->val);
            } else {
                s.emplace(root->right, false);
                s.emplace(root, true);
                s.emplace(root->left, false);
            }
        }
        return res;
    }
};


// Morris Traveral

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr;
        while (curr) {
            if (!curr->left) {
                res.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;
                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                }
                if (prev->right == curr) {
                    prev->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};
