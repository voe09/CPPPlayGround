/*
Design an algorithm and write code to serialize and deserialize a binary tree. 
Writing the tree to a file is called 'serialization' and reading back from the 
file to reconstruct the exact same binary tree is 'deserialization'.

 Notice

There is no limit of how you deserialize or serialize a binary tree, 
LintCode will take your output of serialize as the input of deserialize, 
it won't check the result of serialize.

Have you met this question in a real interview? Yes
Example
An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:

  3
 / \
9  20
  /  \
 15   7
Our data serialization use bfs traversal. This is just for when you got wrong answer and want to debug the input.

You can use other method to do serializaiton and deserialization.
 */

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        // write your code here
        if (!root) return "";
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            if (curr) {
                out << curr->val << " ";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                out << "# ";
            }
        }
        return out.str();
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        // write your code here
        if (data.empty()) return nullptr;
        istringstream in(data);
        queue<TreeNode*> q;
        string val;
        in >> val;
        TreeNode *root = new TreeNode(stoi(val));
        q.push(root);
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            if (in >> val && val != "#") {
                TreeNode *tmp = new TreeNode(stoi(val));
                q.push(tmp);
                curr->left = tmp;
            }
            if (in >> val && val != "#") {
                TreeNode *tmp = new TreeNode(stoi(val));
                q.push(tmp);
                curr->right = tmp;
            }
        }
        return root;
    }
};


class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        // write your code here
        istringstream os;
        serialize(root, os);
        return os.str();
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        // write your code here
        istringstream is(data);
        return deserialize(is);
    }

private:
    void serialize(TreeNode *node, ostringstream &os) {
        if (node) {
            os << node->val << " ";
            serialize(node->left, os);
            serialize(node->right, os);
        } else {
            os << "# ";
        }
    }

    TreeNode * deserialize(istringstream &is) {
        string val;
        if (is >> val) {
            if (val == "#") return nullptr;
            TreeNode *node = new TreeNode(stoi(val));
            node->left = deserialize(is);
            node->right = deserialize(is);
            return node;
        }
        return nullptr;
    }
};
