/*
The thief has found himself a new place for his thievery again. There is only 
one entrance to this area, called the "root." Besides the root, each house has 
one and only one parent house. After a tour, the smart thief realized that "all 
houses in this place forms a binary tree". It will automatically contact the 
police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without 
alerting the police.

Have you met this question in a real interview? Yes
Example
  3
 / \
2   3
 \   \ 
  3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

    3
   / \
  4   5
 / \   \ 
1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
 */

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode * root) {
        // write your code here 
        int l = 0, r = 0;
        return helper(root, l, r);
    }

private:
    int helper(TreeNode *node, int &l, int &r) {
        if (!node) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = helper(node->left, ll, lr);
        r = helper(node->right, rl, rr);
        return max(node->val + ll + lr + rl + rr, l + r);
    }
};
