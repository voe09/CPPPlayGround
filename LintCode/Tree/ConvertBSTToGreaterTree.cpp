/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that
every key of the original BST is changed to the original key plus sum of 
all keys greater than the original key in BST.

Have you met this question in a real interview? Yes
Example
Given a binary search Tree ｀{5,2,3}｀:

              5
            /   \
           2     13
Return the root of new tree

             18
            /   \
          20     13
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
     * @return: the new root
     */
    TreeNode * convertBST(TreeNode * root) {
        // write your code here
        int cnt = 0;
        InOrderTraversal(root, cnt);
        return root;
    }

private:
    void InOrderTraversal(TreeNode *node, int &cnt) {
        if (!node) return;
        InOrderTraversal(node->right, cnt);
        node->val += cnt;
        cnt = node->val;
        InOrderTraversal(node->left, cnt);
    }
};
