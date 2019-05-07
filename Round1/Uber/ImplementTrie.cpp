/*
Implement a trie with insert, search, delete, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
 */

class TreeNode {
public:
    bool isWord;
    vector<TreeNode*> child;
    TreeNode() : isWord(false), child (26, nullptr) {}
};

class Trie {
public:
    Trie() : root(new TreeNode()) {}

    void insert(string s) {
        TreeNode *curr = root;
        for (const auto &c : S) {
            int idx = c - 'a';
            if (!curr->child[idx]) curr->child[idx] = new TreeNode();
            curr = curr->child[idx];
        }
        curr->isWord = true;
    }

    void remove(string s) {
        TreeNode *curr = root;
        stack<TreeNode*> stk;
        for (const auto &c : s) {
            int idx = c - 'a';
            stk.push(curr->child[idx]);
            curr = curr->child;
        }

    }

    bool search(string s) {
        TreeNode *curr = root;
        for (const auto &c : s) {
            int idx = c - 'a';
            if (!curr->child[idx]) return false;
            curr = curr->child[idx];
        }
        return curr->isWord;
    }

    bool startWith(string s) {
        TreeNode *curr = root;
        for (const auto &c : s) {
            int idx = c - 'a';
            if (!curr->child[idx]) return false;
            curr = curr->child[idx];
        }
        return true;
    }

private:
    TreeNode *root;
};
