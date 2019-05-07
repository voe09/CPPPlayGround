

class TreeNode {
public:
    char val;
    vector<TreeNode*> childs;
    TreeNode(char x) : val(x) {}
};


void Serialize(TreeNode *node, istringstream &is) {
    is << "(";
    if (node) {
        for (const auto &child : node->childs) {
            Serialize(child, is);
        }
    }
    is << ")";
}

string Serialize(TreeNode *root) {
    istringstream is;
    Serialize(root, is);
    return is.str();
}

TreeNode* Deserialize(string s) {
    TreeNode *dummy = new TreeNode('a');
    stack<TreeNode*> stk;
    stk.push(dummy);
    int idx = 0;
    char val = '-';
    while (!stk.empty()) {
        if (s[idx] == '(') {
            if (val != '-') {
                stk.push(new TreeNode(val));
                val = '-';
            }
            stk.push(nullptr);
        } else if (s[idx] == ')') {
            stack<TreeNode*> tmp;
            while (stk.top()) {
                tmp.push(stk.top());
                stk.pop();
            }

            stk.pop();
            TreeNode *curr = stk.top();
            while (!tmp.empty()) {
                curr->childs.push_back(tmp.top());
                tmp.pop();
            }
        } else {
            val = s[idx];
        }
        ++idx;
    }
    return dummy->childs.empty() ? nullptr : dummy->childs[0];
}
