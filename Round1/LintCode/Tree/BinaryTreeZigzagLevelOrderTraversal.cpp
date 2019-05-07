/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

Have you met this question in a real interview? Yes
Example
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
 

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
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
     * @param root: A Tree
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> res;
        if (!root) return res;
        queue<pair<TreeNode*, int>> q;
        int layer = 0;
        q.push({root, layer});
        vector<int> curr;
        while (!q.empty()) {
            pair<TreeNode*, int> tmp = q.front();
            q.pop();
            if (tmp.second != layer) {
                if (layer % 2 != 0) {
                    std::reverse(curr.begin(), curr.end());
                }
                res.push_back(curr);
                curr.clear();
                layer = tmp.second;
            }
            curr.push_back(tmp.first->val);
            if (tmp.first->left) {
                q.push({tmp.first->left, tmp.second + 1});
            }
            if (tmp.first->right) {
                q.push({tmp.first->right, tmp.second + 1});
            }
        }

        if (layer % 2 != 0) {
            std::reverse(curr.begin(), curr.end());
        }
        res.push_back(curr);
        return res;
    }
};
