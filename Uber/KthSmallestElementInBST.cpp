/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
 How would you optimize the kthSmallest routine?
*/
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void helper(TreeNode *node, int k, int &cnt, int &res) {
    if (!node) return;
    if (cnt < k) helper(node->left, k, cnt, res);
    ++cnt;
    if (cnt == k) res = node->val;
    if (cnt < k) helper(node->right, k, cnt, res);
}

int kthSmallestElement(TreeNode *root, int k) {
    int cnt = 0;
    int res;
    helper(root, k, cnt, res);
    return res;
}

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(0);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(6);
    cout << kthSmallestElement(root, 1) << " " << kthSmallestElement(root, 2) << " " 
        << kthSmallestElement(root, 3) << " " << kthSmallestElement(root, 4) << " " 
        << kthSmallestElement(root, 5) << " " << kthSmallestElement(root, 6) << " " 
        << kthSmallestElement(root, 7) << " " << kthSmallestElement(root, 8) << " " 
        << endl;
}


/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
 How would you optimize the kthSmallest routine?
*/
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTreeNode {
public:
    int val;
    int counts;
    BSTreeNode *left, *right;
    BSTreeNode(int x) : val(x), counts(1), left(nullptr), right(nullptr) {}
};

void helper(BSTreeNode *node, int k, int &res) {
    if (node->left) {
        int cnt = node->left->counts;
        if (k <= cnt) {
            helper(node->left, k, res);
        } else if (k > cnt + 1) {
            helper(node->right, k - 1 - cnt, res);
        } else {
            res = node->val;
        }
    } else {
        if (k == 1) res = node->val;
        else (node->right, k - 1, res);
    }
}

BSTreeNode* buildBST(TreeNode *node) {
    if (!node) return nullptr;
    BSTreeNode *left = buildBST(node->left);
    BSTreeNode *right = buildBST(node->right);

    BSTreeNode *res = new BSTreeNode(node->val);
    res->left = left;
    res->right = right;
    res->counts += left ? left->counts : 0;
    res->counts += right ? right->counts : 0;
    return res;
}

int kthSmallestElement(TreeNode *root, int k) {
    BSTreeNode *newRoot = buildBST(root);
    int res;
    helper(newRoot, k, res);
    return res;
}

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(0);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(6);
    cout << kthSmallestElement(root, 1) << " " << kthSmallestElement(root, 2) << " "
        << kthSmallestElement(root, 3) << " " << kthSmallestElement(root, 4) << " "
        << kthSmallestElement(root, 5) << " " << kthSmallestElement(root, 6) << " "
        << kthSmallestElement(root, 7) << " " << kthSmallestElement(root, 8) << " "
        << endl;
}

