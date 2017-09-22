/*
Given a non-empty binary tree, return the average value of the nodes on each 
level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 
is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long sum = 0;
        int prev = 0, cnt = 0;
        while (!q.empty()) {
            pair<TreeNode*, int> curr = q.front();
            q.pop();
            if (curr.second == prev) {
                sum += curr.first->val;
                ++cnt;
            } else {
                res.push_back(static_cast<double>(sum) / static_cast<double>(cnt));
                cnt = 1;
                sum = curr.first->val;
                prev = curr.second;
            }
            if (curr.first->left) q.push({curr.first->left, curr.second + 1});
            if (curr.first->right) q.push({curr.first->right, curr.second + 1});
        }
        res.push_back(static_cast<double>(sum) / static_cast<double>(cnt));
        return res;
    }
};
