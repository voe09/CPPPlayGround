/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely 
filled, and all nodes in the last level are as far left as possible. It can 
have between 1 and 2h nodes inclusive at the last level h.
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

// BFS first then binary search is wrong, too slow
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<TreeNode*> bottleneck;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* curr = queue.front();
            queue.pop();
            if (isBottleneck(curr)) 
        }
    }
};

// Binary Search
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        TreeNode *node = root;
        int level = 0;
        while (node->left != nullptr) {
            node = node->left;
            ++level;
        }

        // Binary search.
        int left = pow(2, level), right = pow(2, level + 1);
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!exist(root, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }

    // Check if the nth node exist.
    bool exist(TreeNode *root, int n) {
        int k = 1;
        while (k <= n) {
            k <<= 1;
        }
        k >>= 2;

        TreeNode *node = root;
        while (k > 0) {
            if ((n & k) == 0) {
                node = node->left;
            } else {
                node = node->right;
            }
            k >>= 1;
        }
        return node != nullptr;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int depth = 0;
        TreeNode* node = root;
        while (node) {
            depth++;
            node = node->left;
        }
        if (depth == 0) {
            return 0;
        }
        int left = 0, right = (1 << (depth - 1)) - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (getNode(root, mid, depth - 1)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (1 << (depth - 1)) + right;
    }
    TreeNode* getNode(TreeNode* root, int path, int depth) {
        while (depth-- && root) {
            if (path & (1 << depth)) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return root;
    }
};



// Recursion
/*
分别找出以当前节点为根节点的左子树和右子树的高度并对比，如果相等，则说明是满二叉树，
直接返回节点个数，如果不相等，则节点个数为左子树的节点个数加上右子树的节点个数再加1(根节点)，
其中左右子树节点个数的计算可以使用递归来计算
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int hLeft = 0, hRight = 0;
        TreeNode *pLeft = root, *pRight = root;
        while (pLeft) {
            ++hLeft;
            pLeft = pLeft->left;
        }
        while (pRight) {
            ++hRight;
            pRight = pRight->right;
        }
        if (hLeft == hRight) return pow(2, hLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
