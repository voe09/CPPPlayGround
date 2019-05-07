/*
Given a binary search tree and the lowest and highest boundaries as L and R,
trim the tree so that all its elements lies in [L, R] (R >= L). You might need
to change the root of the tree, so the result should return the new root of the
trimmed binary search tree.

Example 1:
Input: 
    1
   / \
  0   2

  L = 1
  R = 2

Output: 
    1
      \
       2
Example 2:
Input: 
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

Output: 
      3
     / 
   2   
  /
 1
 */

/*
There are two possible cases for every node.
1) Node’s key is outside the given range. This case has two sub-cases.
…….a) Node’s key is smaller than the min value.
…….b) Node’s key is greater that the max value.
2) Node’s key is in range.

We don’t need to do anything for case 2. In case 1, we need to remove the node
and change root of sub-tree rooted with this node.
The idea is to fix the tree in Postorder fashion. When we visit a node, we make
sure that its left and right sub-trees are already fixed. In case 1.a), we 
simply remove root and return right sub-tree as new root. In case 1.b), we 
remove root and return left sub-tree as new root.
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return nullptr;

        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);

        if (root->val < L) {
            return root->right;
        }

        if (root->val > R) {
            return root->left;
        }

        return root;
    }
};
