/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        string path;
        binaryTreePaths(root, path, res);
        return res;
    }

private:
    void binaryTreePaths(TreeNode* node, string path, vector<string>& res) {
        path += to_string(node->val);
        if (node->left) {
            binaryTreePaths(node->left, path + "->", res);
        }
        if (node->right) {
            binaryTreePaths(node->right, path + "->", res);
        }
        if (!node->left && !node->right)
            res.push_back(path);
    }
};
