/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. 
Could you devise a constant space solution?
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
    void recoverTree(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> nodes;
        vector<int> values;
        inorderTraversal(root, nodes, values);
        sort(values.begin(), values.end());
        for (int i = 0; i < values.size(); ++i) {
            nodes[i]->val = values[i];
        }
    }

private:
    void inorderTraversal(TreeNode* root, vector<TreeNode*> &nodes,
                          vector<int> &values) {
        if (root->left) inorderTraversal(root->left, values);
        nodes.push_back(root);
        values.push_back(root->val);
        if (root->right) inorderTraversal(root->right, values);
    }
};


// O(1) space要用的inorder traversal的方法是Morris Traversal
// http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
// http://www.cnblogs.com/grandyang/p/4298069.html

class Solution {
public:
    void recoverTree(TreeNode *root) {
        MorrisTraversal(root);
    }

private:
    void MorrisTraversal(TreeNode *root) {
        if (!root) {
            return;
        }
        pair<TreeNode *, TreeNode *> broken;
        TreeNode *prev = nullptr;
        TreeNode *cur = root;
        while (cur) {
            if (!cur->left) {
                detect(prev, cur, &broken);
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode *node = cur->left;
                while (node->right && node->right != cur) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = cur;
                    cur = cur->left;
                } else {
                    detect(prev, cur, &broken);
                    prev = cur;
                    node->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        swap(broken.first->val, broken.second->val);
    }

    void detect(TreeNode *prev, TreeNode *cur, pair<TreeNode *, TreeNode *> *broken) {
        if (prev && prev->val > cur->val) {
            if (!broken->first) { // Find the first broken node.
                broken->first = prev;
            }
            broken->second = cur;  // Find the last broken node.
        }
    }
};
