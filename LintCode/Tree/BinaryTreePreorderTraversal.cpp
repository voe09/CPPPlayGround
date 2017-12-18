/*
Given a binary tree, return the preorder traversal of its nodes' values.

Have you met this question in a real interview? Yes
Example
Given:

    1
   / \
  2   3
 / \
4   5
return [1,2,4,5,3].

Challenge 
Can you do it without recursion?
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
     * @return: Preorder in ArrayList which contains node values.
     */
    void preorderTraversal(TreeNode *node, vector<int> &res) {
        if (!node) return;
        res.push_back(node->val);
        preorderTraversal(node->left, res);
        preorderTraversal(node->right, res);
    }

    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> res;
        if (!root) return res;
        preorderTraversal(root, res);
        return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *curr = stk.top();
            stk.pop();
            if (!curr) continue;
            res.push_back(curr->val);
            stk.push(curr->right);
            stk.push(curr->left);
        }
        return res;
    } 
};
