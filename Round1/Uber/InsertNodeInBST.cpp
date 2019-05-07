/*
Insert Node in a Binary Search Tree
*/

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* InsertNode(TreeNode *root, int val) {
    if (!root) {
        TreeNode* newNode = new TreeNode(val);
        return newNode;
    }

    TreeNode *curr = root;
    while (curr) {
        if (curr->val >= val) {
            if (!curr->left) {
                curr->left = new TreeNode(val);
                return root;
            }
            curr = curr->left;
        } else {
            if (!curr->right) {
                curr->right = new TreeNode(val);
                return root;
            }
            curr = curr->right;
        }
    }
    return root;
}
