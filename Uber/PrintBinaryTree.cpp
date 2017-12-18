/*
Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:

Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
 

Example 2:

Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
 

Example 3:

Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
 

Note: The height of binary tree is in the range of [1, 10].
 */


class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode *node) {
    if (!node) return 0;
    return 1 + max(maxDepth(node->left), maxDepth(node->right));
}

void helper(TreeNode *node, vector<vector<string>>> &outputs,
            int i, int j, int currDepth) {
    if (!node || currDepth == outputs.size()) return;
    int mid = i + (j - i) / 2;
    outputs[currDepth][mid] = to_string(node->val);
    helper(node->left, outputs, i, mid, currDepth + 1);
    helper(node->right, outputs, mid + 1, j, currDepth + 1);
}

vector<vector<string>> printTree(TreeNode *root) {
    int m = maxDepth(root);
    int n = pow(2, m) - 1;
    vector<vector<string>> outputs (m, vector<string>(n, ""));
    helper(root, outputs, 0, n - 1, 0);
    return outputs;
}
