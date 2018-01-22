/*
You have two very large binary trees: T1, with millions of nodes, and T2, 
with hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.

 Notice

A tree T2 is a subtree of T1 if there exists a node n in T1 such that the 
subtree of n is identical to T2. That is, if you cut off the tree at node n, 
the two trees would be identical.

Example
T2 is a subtree of T1 in the following case:

       1                3
      / \              / 
T1 = 2   3      T2 =  4
        /
       4
T2 isn't a subtree of T1 in the following case:

       1               3
      / \               \
T1 = 2   3       T2 =    4
        /
       4
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
     * @param T1: The roots of binary tree T1.
     * @param T2: The roots of binary tree T2.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode * T1, TreeNode * T2) {
        // write your code here
        queue<TreeNode> q;
        q.push(T1);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            if (isEqual(tmp, T2)) return true;
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmo->right);
        }
        return false;
    }

private:
    bool isEqual(TreeNode *node1, TreeNode *node2) {
        if (!node1 && !node2) return true;
        else if (!node1 || !node2) return false;
        else {
            if (node1->val != node2->val) return false;
            else {
                return isEqual(node1->left, node2->left) 
                    && isEqual(node1->right, node2->right);
            }
        }
    }
};
