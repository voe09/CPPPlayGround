/*
Given a binary search tree and a number n, find two numbers in the tree that sums up to n.

 Notice

Without any extra space.

Have you met this question in a real interview? Yes
Example
Given a binary search tree:

    4
   / \
  2   5
 / \
1   3
and a number n = 3
return [1, 2] or [2, 1]
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
     * @param : the root of tree
     * @param : the target sum
     * @return: two number from tree witch sum is n
     */
    vector<int> twoSum(TreeNode * root, int n) {
        // write your code here
        unordered_set<int> m;
        vector<int> res;
        twoSum(root, n, m, res);
        return res;
    }

private:
    void twoSum(TreeNode *node, int target,
            unordered_set<int> &m, vector<int> &res) {
        if (!node) return;
        if (!res.empty()) return;
        twoSum(node->left, target, m, res);
        if (res.empty() && m.count(target - node->val)) {
            res.push_back(target - node->val);
            res.push_back(node->val);
        }
        m.insert(node->val);
        twoSum(node->right, target, m, res);
    }
};
