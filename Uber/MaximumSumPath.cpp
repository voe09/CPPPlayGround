// Tree Largest Sum Path
#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maximumSubPath(TreeNode *node, int &res) {
    if (!node) return 0;
    int left = maximumSubPath(node->left, res);
    int right = maximumSubPath(node->right, res);
    res = max(res, node->val + ((left > 0) ? left : 0) + ((right > 0) ? right : 0));
    return (max(left, right) > 0) ? max(left, right) + node->val : node->val;
}

int maximumPath(TreeNode *root) {
    if (!root) return 0;
    int res = root->val;
    maximumSubPath(root, res);
    return res;
}

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(11);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(13);

    std::cout << maximumPath(root) << std::endl;
}
