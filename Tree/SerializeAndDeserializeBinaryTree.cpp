/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
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

// Memory Limit Exceeded
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (!root) {
            res = res + "#";
            return res;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode *curr = nodes.front();
            nodes.pop();
            if (curr) {
                nodes.push(curr->left);
                nodes.push(curr->right);
                res = res + to_string(curr->val) + ",";
            } else {
                res = res + "#" + ",";
            }
        }
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> values;
        for (int i = 0; i < data.size(); ++i) {
            string tmp;
            while (i < data.size() && data[i] != ',') {
                tmp = tmp + data[i++];
            }
            values.push(tmp);
        }
        TreeNode *root;
        if (values.front() == "#") {
            root = nullptr;
            return root;
        }
        else {
            root = new TreeNode(stoi(values.front()));
            values.pop();
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!values.empty()) {
            TreeNode *curr = nodes.front();
            nodes.pop();
            if (values.front() != "#") {
                curr->left = new TreeNode(stoi(values.front()));
                nodes.push(curr->left);
                values.pop();
            } else {
                curr->left = nullptr;
                values.pop();
            }
            if (values.front() != "#") {
                curr->right = new TreeNode(stoi(values.front()));
                nodes.push(curr->right);
                values.pop();
            } else {
                curr->right = nullptr;
                values.pop();
            }
        }
        return root;
    }
};

// 也可以有那个preorder search 
