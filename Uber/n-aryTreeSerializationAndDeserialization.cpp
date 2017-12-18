/*
Serialize and Deserialize n-ary tree
 */
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    vector<TreeNode*> childs;
    TreeNode(int x) : val(x) {}
};

void Serialize(TreeNode *node, ostringstream &os) {
    if (!node) return;
    os << "(";
    os << node->val;
    for (const auto &child : node->childs) {
        Serialize(child, os);
    }
    os << ")";
}

string Serialize(TreeNode *root) {
    ostringstream os;
    Serialize(root, os);
    return os.str();
}

TreeNode* Deserialize(string s) {
    string val;
    stack<TreeNode*> stk;
    TreeNode *dummy = new TreeNode(0);
    stk.push(dummy);
    TreeNode *curr = nullptr;
    for (const auto &c : s) {
        if (c == '(') {
            if (!val.empty()) {
                stk.push(new TreeNode(stoi(val)));
                val.clear();
            }
            stk.push(nullptr);
        } else if (c == ')') {
            if (!val.empty()) {
                stk.push(new TreeNode(stoi(val)));
                val.clear();
            }
            stack<TreeNode*> tmp;
            while (stk.top()) {
                tmp.push(stk.top());
                stk.pop();
            }
            stk.pop();
            curr = stk.top();
            while (!tmp.empty()) {
                curr->childs.push_back(tmp.top());
                tmp.pop();
            }
        } else {
            val += c;
        }
    }
    return (dummy->childs.empty()) ? nullptr : dummy->childs[0];
}

int main() {
    TreeNode *a = new TreeNode(0);
    a->childs.push_back(new TreeNode(1));
    a->childs.push_back(new TreeNode(2));
    a->childs[0]->childs.push_back(new TreeNode(3));
    a->childs[1]->childs.push_back(new TreeNode(4));
    a->childs[1]->childs.push_back(new TreeNode(5));
    string s = Serialize(a);
    cout << s << endl;
    TreeNode *copy = Deserialize(s);
    string cp = Serialize(copy);
    cout << cp << endl;
}
