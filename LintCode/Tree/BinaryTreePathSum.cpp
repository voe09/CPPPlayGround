/*
Given a binary tree, find all paths that sum of the nodes in the path equals to a given number target.

A valid path is from root node to any of the leaf nodes.

Have you met this question in a real interview? Yes
Example
Given a binary tree, and target = 5:

     1
    / \
   2   4
  / \
 2   3
return

[
  [1, 2, 2],
  [1, 4]
]
 */

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        // write your code here
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> curr;
        curr.push_back(root->val);
        helper(root, curr, res, root->val, target);
        return res;
    }

private:
    void helper(TreeNode *node, vector<int> &curr, vector<vector<int>> &res,
            int sum, int target) {
        if (!node->left && !node->right) {
            if (sum == target) res.push_back(curr);
            return;
        }

        if (node->left) {
            int tmp = node->left->val;
            curr.push_back(tmp);
            sum += tmp;
            helper(node->left, curr, res, sum, target);
            sum -= tmp;
            curr.pop_back();
        }

        if (node->right) {
            int tmp = node->right->val;
            curr.push_back(tmp);
            sum += tmp;
            helper(node->right, curr, res, sum, target);
            sum -= tmp;
            curr.pop_back();
        }
    }
};
