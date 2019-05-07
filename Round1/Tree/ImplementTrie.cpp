/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root_ = new TreeNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode *curr = root_;
        for (auto &ch: word) {
            if (!curr->links[ch - 'a'])
                curr->links[ch - 'a'] = new TreeNode();
            curr = curr->links[ch - 'a'];
        }
        curr->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *curr = root_;
        for (auto &ch: word) {
            if (curr->links[ch - 'a']) {
                curr = curr->links[ch - 'a'];
            } else {
                return false;
            }
        }
        if (curr->is_word) return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode *curr = root_;
        for (auto &ch: prefix) {
            if (curr->links[ch - 'a']) {
                curr = curr->links[ch - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    struct TreeNode {
        bool is_word;
        vector<TreeNode*> links;
        TreeNode(): is_word(false), links(vector<TreeNode*>(26, nullptr)) {}
    };

    TreeNode *root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
