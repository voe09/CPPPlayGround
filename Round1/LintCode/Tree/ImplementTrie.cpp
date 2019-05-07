/*
Implement a trie with insert, search, and startsWith methods.

 Notice

You may assume that all inputs are consist of lowercase letters a-z.

Have you met this question in a real interview? Yes
Example
insert("lintcode")
search("code")
>>> false
startsWith("lint")
>>> true
startsWith("linterror")
>>> false
insert("linterror")
search("lintcode)
>>> true
startsWith("linterror")
>>> true
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */

class TrieNode {
public:
    // Initialize your data structure here.
    vector<TrieNode*> subs;
    bool isWord;
    TrieNode() : subs (26, nullptr), isWord(false) {}
};

class Trie {
public:
    Trie() {
        // do intialization if necessary
        root = new TrieNode();
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        // write your code here
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if(!curr->subs[idx]) curr->subs[idx] = new TrieNode();
            curr = curr->subs[idx];
        }
        curr->isWord = true;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        // write your code here
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            curr = curr->subs[idx];
            if (!curr) return false;
        }
        return curr->isWord;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
        // write your code here
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int idx = prefix[i] - 'a';
            curr = curr->subs[idx];
            if (!curr) return false;
        }
        return true;
    }

private:
    TrieNode* root;
};
