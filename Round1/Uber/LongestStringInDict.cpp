// 另一题是给一个字典和一个字符串S，在字典的所有单词中找出一个最长的单词并且其所有字母>    都在S中出现过。面试官希望看到的是trie+dfs。
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class TreeNode {
public:
    bool isWord;
    vector<TreeNode*> subnodes;
    TreeNode() : isWord(false), subnodes(26, nullptr) {}
};

TreeNode* ConstructTrie(vector<string> &dict) {
    TreeNode *root = new TreeNode();
    for (const auto &word : dict) {
        TreeNode *curr = root;
        for (const auto &c : word) {
            int idx = c - 'a';
            if (!curr->subnodes[idx])
                curr->subnodes[idx] = new TreeNode();
            curr = curr->subnodes[idx];
        }
        curr->isWord = true;
    }
    return root;
}

void helper(TreeNode *node, unordered_set<char> set,
            string &curr, string &res) {
    if (node->isWord) {
        if (curr.size() > res.size()) {
            res = curr;
        }
    }
    
    for (int i = 0; i < 26; ++i) {
        if (node->subnodes[i] && set.count(static_cast<char>('a' + i))) {
            curr.push_back('a' + i);
            helper(node->subnodes[i], set, curr, res);
            curr.pop_back();
        }
    }
}

string LongestWords(vector<string> &dict, string s) {
    if (dict.empty()) return {};
    unordered_set<char> set;
    for (const auto &c : s) {
        set.insert(c);
    }
    
    TreeNode *root = ConstructTrie(dict);
    
    string res = "";
    string curr = "";
    helper(root, set, curr, res);
    
    return res;
}

int main() {
    vector<string> dict {"uber", "uberride", "haoyang", "uberrideeats", "uberpool"};
    std::cout << LongestWords(dict, "beruirdeeats") << std::endl;
}
