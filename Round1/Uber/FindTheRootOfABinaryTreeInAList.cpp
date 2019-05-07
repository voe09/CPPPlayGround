/*
Given list of nodes of a tree, find the root of the tree. Nodes in the list are
not in any particular order. If some of the nodes in the tree are not given, 
return null
Eg:

        A
   B        C
E         F
Input : [B, C, A, E, F] Output : A
 */

class TreeNode {
public:
    char val;
    TreeNode *left, *right;
    TreeNode(char x) : val(x) {}
};

struct TreeNodeHash {
    std::size_t operator() (TreeNode *node) {
        string tmp;
        tmp += node->val;
        tmp += (node->left) ? node->left->val : "";
        tmp += (node->right) ? node->right->val : "";
        return std::hash<string>()(tmp);
    }
};

TreeNode* RootNode(vector<TreeNode*> &nodes) {
    unordered_map<TreeNode*, int, TreeNodeHash> node_set;
    for (auto &node : nodes) {
        ++node_set[node->left];
        ++node_set[node->right];
    }
    
    TreeNode *res;
    int cnt;
    for (const auto &pair : node_set) {
        if (pair->second == 0) {
            ++cnt;
            res = pair->first;
        }
        if (cnt > 1) return nullptr;
    }
    return res;
}
