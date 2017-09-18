/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some 
starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        findMaxUtil(root, res);
        return res;
    }

private:
    // This function returns overall maximum path sum in 'res'
    // And returns max path sum going through root.
    int findMaxUtil(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        // l and r store maximum path sum going through left and
        // right child of root respectively
        int l = findMaxUtil(root->left, res);
        int r = findMaxUtil(root->left, res);

        // Max path for parent call of root. This path must
        // include at-most one child of root
        int max_single = max(max(l, r) + root->val, root->val);

        // Max Top represents the sum when the Node under
        // consideration is the root of the maxsum path and no
        // ancestors of root are there in max sum path
        int max_top = max(max_single, l + r + root->val);

        res = max(res, max_top); // Store the Maximum Result.

        return max_single;
    }
};
