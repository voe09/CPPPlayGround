/*
Given a binary tree, find the lowest common ancestor (LCA) of 
two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest 
common ancestor is defined between two nodes v and w as the 
lowest node in T that has both v and w as descendants 
(where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 */

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* helper(TreeNode *node, TreeNode *w, TreeNode *v) {
    if (!node || node == w || node == v) return node;
    TreeNode *left = helper(node->left, w, v);
    TreeNode *right = helper(node->right, w, v);
    if (left && right) return node;
    return left ? left : right;
}

TreeNode* CommonAncestor(TreeNode *root, TreeNode *w, TreeNode *v) {
    if (!root || !w || !v) return nullptr; 
    return helper(root, w, v);
}


// Optimization
TreeNode* LowerCommonAncestor(TreeNode *root, TreeNode *w, TreeNode *v) {
    if (!root || root == w || root == v) return root;
    TreeNode *left = LowerCommonAncestor(root->left, w, v);
    if (left && left != w && left != v) return left;
    TreeNode *right = LowerCommonAncestor(root->right, w, v);
    if (right && right != w && right != v) return right;
    if (left && right) return root;
    return left ? left : right;
}
