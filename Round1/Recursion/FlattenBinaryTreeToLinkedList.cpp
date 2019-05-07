/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Hints:
If you notice carefully in the flattened tree, each node's right child points 
to the next node of a pre-order traversal.
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
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> nodes;
        preorderTraversal(root, nodes);
        for (int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;
    }
private:
    void preorderTraversal(TreeNode* root, vector<TreeNode*>& nodes) {
        nodes.push_back(root);
        if (root->left) preorderTraversal(root->left, nodes);
        if (root->right) preorderTraversal(root->right, nodes);
    }
};


// Recursion
假设某节点的左右子树T(root->left)和T(root->right)已经flatten成linked list了：

    1
  /    \
 2     5
  \       \
   3      6 <- rightTail
     \
      4  <- leftTail

如何将root、T(root->left)、T(root->right) flatten成一整个linked list？显而易见：

temp = root->right
root->right  = root->left
root->left = NULL
leftTail->right = temp

这里需要用到已经flatten的linked list的尾部元素leftTail, rightTail。所以递归返回值应该是生成的整个linked list的尾部

class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode* rightTail = flattenBT(root);
    }

    TreeNode* flattenBT(TreeNode* root) {
        if(!root) return NULL;
        TreeNode *leftTail = flattenBT(root->left);
        TreeNode *rightTail = flattenBT(root->right);
        if(root->left) {
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            leftTail->right = temp;
        }

        if(rightTail) return rightTail;
        if(leftTail) return leftTail;
        return root;
    }
};
