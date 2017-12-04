/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored
 in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or 
 another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your 
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can 
be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. 
You do not necessarily need to follow this format, so please be creative and 
come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize 
and deserialize algorithms should be stateless.
*/
#include <string>
#include <sstream>
#include <iostream>
#include <queue>
using namespace std;


class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* Deserialization(string s) {
    if (s.empty()) return nullptr;
    istringstream is(s);
    string curr;
    is >> curr;
    if (curr == "#") return nullptr;
    TreeNode *root = new TreeNode(stoi(curr));
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *tmp = q.front();
        q.pop();
        if (is >> curr) {
            if (curr != "#") {
                tmp->left = new TreeNode(stoi(curr));
                q.push(tmp->left);
            }
        }

        if (is >> curr) {
            if (curr != "#") {
                tmp->right = new TreeNode(stoi(curr));
                q.push(tmp->right);
            }
        }
    }
    return root;
}

string Serialization(TreeNode *root) {
    ostringstream os;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();
        if (!curr) {
            os << "# ";
        } else {
            os << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        }
    }

    return os.str();
}

bool isEqual(TreeNode *a, TreeNode *b) {
    if (!a && !b) return true;
    else if ((!a && b) || (a && !b)) return false;

    if (isEqual(a->left, b->left) && (a->right, b->right)) {
        if (a->val == b->val) return true;
        else return false;
    }
    return false;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);
    string s = Serialization(root);
    cout << s << endl;
    TreeNode *reconstruct = Deserialization(s);
    cout << isEqual(root, reconstruct) << endl;
}
