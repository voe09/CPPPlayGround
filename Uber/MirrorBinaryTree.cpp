/*
Mirror Binary Tree
*/
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x) {}
};

TreeNode* MirrorBinaryTree(TreeNode *root) {
    if (!root) return nullptr;
    TreeNode *mirror = new TreeNode(root->val);
    mirror->left = MirrorBinaryTree(root->right);
    mirror->right = MirrorBinaryTree(root->left);
    return mirror;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    
    TreeNode *mirror = MirrorBinaryTree(root);
    std::cout << mirror->val << std::endl;
    std::cout << mirror->right->val << std::endl;
    std::cout << mirror->right->left->val << std::endl;
    std::cout << mirror->left->val << std::endl;
}
