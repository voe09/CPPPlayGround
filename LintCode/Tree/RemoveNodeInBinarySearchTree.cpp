/*
Given a root of Binary Search Tree with unique value for each node. Remove the 
node with given value. If there is no such a node with given value in the 
binary search tree, do nothing. You should keep the tree still a binary search 
tree after removal.

Have you met this question in a real interview? Yes
Example
Given binary search tree:

    5
   / \
  3   6
 / \
2   4
Remove 3, you can either return:

    5
   / \
  2   6
   \
    4
or

    5
   / \
  4   6
 /
2
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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode * removeNode(TreeNode * root, int value) {
        // write your code here
        TreeNode *dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        TreeNode *prev = dummy;
        TreeNode *curr = root;
        while (curr && curr->val != value) {
            prev = curr;
            if (curr->val > value) curr = curr->left;
            else curr = curr->right;
        }

        if (!curr) return dummy->left;
        if (prev->left == curr) {
            TreeNode *tmp = curr->left;
            if (!tmp) prev->left = curr->right;
            else {    
                prev->left = curr->left;
                while (tmp->right) {
                    tmp = tmp->right;
                }
                tmp->right = curr->right;
            }
        } else {
            TreeNode *tmp = curr->right;
            if (!tmp) prev->right = curr->left;
            else {
                prev->right = curr->right;
                while (tmp->left) {
                    tmp = tmp->left;
                }
                tmp->left = curr->left;
            }
        }
        return dummy->left;
    }
};
