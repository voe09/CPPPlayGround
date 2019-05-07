/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root
node down to the farthest leaf node.

Have you met this question in a real interview? Yes
Example
Given a binary tree as follow:

  1
 / \ 
2   3
   / \
  4   5
The maximum depth is 3.
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
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if (!root) return 0;
        int res = helper(root);
        return res;
    }

private:
    int helper(TreeNode *node) {
        if (!node) return 0;
        int left_depth = helper(node->left);
        int right_depth = helper(node->right);
        return max(left_depth, right_depth) + 1;
    }
};
