/*
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

Have you met this question in a real interview? Yes
Example
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
 

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
Challenge 
Challenge 1: Using only 1 queue to implement it.

Challenge 2: Use DFS algorithm to do it.
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
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> res;
        if (!root) return res;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        vector<int> curr;
        int level = 0;
        while (!q.empty()) {
            pair<TreeNode*, int> tmp = q.front();
            q.pop();
            if (tmp.second == level) {
                curr.push_back(tmp.first->val);
            }
            else {
                res.push_back(curr);
                curr.clear();
                curr.push_back(tmp.first->val);
                level = tmp.second;
            }
            if (tmp.first->left)
                q.push({tmp.first->left, tmp.second + 1});
            if (tmp.first->right)
                q.push({tmp.first->right, tmp.second + 1});
        }
        res.push_back(curr);
        return res;
    }
};

class Solution {
public:
    /*
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> res;
        if (!root) return res;
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 0});
        while (!stk.empty()) {
            pair<TreeNode*, int> tmp = stk.top();
            stk.pop();
            if (res.size() <= tmp.second) {
                res.push_back({tmp.first->val});
            }
            else {
                res[tmp.second].push_back(tmp.first->val);
            }
            if (tmp.first->right)
                stk.push({tmp.first->right, tmp.second + 1});
            if (tmp.first->left)
                stk.push({tmp.first->left, tmp.second + 1});
        }
        return res;
    }
};
