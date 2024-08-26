/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        Node* p = new Node(-1);
        while (!stk.empty()) {
            Node* t = stk.top();
            if (t->children.empty() || isChild(t->children, p)) {
                res.push_back(t->val);
                stk.pop();
                p = t;
            } else {
                for (auto it = t->children.rbegin(); it != t->children.rend(); it++) {
                    stk.push(*it);
                }
            }
        }
        return res;
    }

private:
    bool isChild(vector<Node*>& children, Node* p) {
        for (Node* c : children) {
            if (c == p) return true;
        }
        return false;
    }
};