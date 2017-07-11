/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }

private:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if ((!left && right) || (left && !right)) return false;
        if (left->val != right->val) return false;
        return isSymmetric(left->right, right->left) && isSymmetric(left->left, right->right);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        // isSymmetricHelper(root->left, root->right)
        stack<TreeNode *> nodes;
        nodes.emplace(root->left);
        nodes.emplace(root->right);

        while (!nodes.empty())  {
            auto right = nodes.top();
            nodes.pop();
            auto left = nodes.top();
            nodes.pop();
            if (!left && !right) {
                continue;
            }
            if (!left || !right || left->val != right->val) {
                return false;
            }
            // isSymmetricHelper(left->right, right->left)
            nodes.emplace(left->right);
            nodes.emplace(right->left);

            // isSymmetricHelper(left->left, right->right)
            nodes.emplace(left->left);
            nodes.emplace(right->right);
        }
        return true;
    }
};
