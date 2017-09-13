/*
Given a root node reference of a BST and a key, delete the node with the given
key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        TreeNode* prev = dummy;
        TreeNode* curr = root;

        while (curr && curr->val != key) {
            if (key > curr->val) {
                prev = curr;
                curr = curr->right;
            } else {
                prev = curr;
                curr = curr->left;
            }
        }

        if (!curr) return root;
        
        if (key < prev->val) {
            if (curr->right) {
                prev->left = curr->right;
                TreeNode* tmp = curr->left;
                curr = curr->right;
                while (curr->left) {
                    curr = curr->left;
                }
                curr->left = tmp;
            } else {
                prev->left = curr->left;
            }
        } else {
            if (curr->left) {
                prev->right = curr->left;
                TreeNode* tmp = curr->right;
                curr = curr->left;
                while (curr-> right) {
                    curr = curr->right;
                }
                curr->right = tmp;
            } else {
                prev->right = curr->right;
            }
        }
        return dummy->left;
    }
};
