/*
The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called the "root." 
Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that "all houses in this 
place forms a binary tree". It will automatically contact the 
police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without 
alerting the police.

Example 1:

     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

 

Example 2:

     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
 */
#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int helper(TreeNode *node) {
    if (!node) return 0;
    if (!node->left && !node->right) return node->val;
    if (!node->left) {
        int rl = helper(node->right->left), rr = helper(node->right->right);
        int r = helper(node->right);
        return max(rl + rr + node->val, r);
    } else if (!node->right) {
        int ll = helper(node->left->left), lr = helper(node->left->right);
        int l = helper(node->left);
        return max(ll + lr + node->val, l);
    } else {
        int ll = helper(node->left->left), lr = helper(node->left->left);
        int rl = helper(node->right->left), rr = helper(node->right->right);
        int l = helper(node->left), r = helper(node->right);
        return max(ll + lr + rl + rr + node->val, l + r);
    }
}

int robberMoney(TreeNode *root) {
    if (!root) return 0;
    int res = helper(root);
    return res;
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << robberMoney(root) << endl;
}
