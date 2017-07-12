/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing
only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root_ = new TreeNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TreeNode *curr = root_;
        for (const auto &ch: word) {
            if (!curr->links[ch - 'a'])
                curr->links[ch - 'a'] = new TreeNode();
            curr = curr->links[ch - 'a'];
        }
        curr->is_word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        stack<TreeNode*> stk;
        stk.push(root_);
        int i = 0;
        while (!stk.empty()) {
            TreeNode *curr = stk.top();
            stk.pop();
            if (word[i] != '.') {
                if (curr->links[word[i] - 'a']) {
                    stk.push(curr->links[word[i] - 'a']);
                    ++i;
                }
                else
                    --i;
            } else {
                for (const auto &ptr: curr->links) {
                    if (ptr) {
                        stk.push(ptr);
                    }
                }
            }
        }
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
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
