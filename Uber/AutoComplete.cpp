/*
给一个字典和一个字符串S，在字典的所有单词中找出一个最长的单词并且其所有字母都在S中出现过
 */

class TreeNode {
public:
    bool isWord;
    vector<TreeNode*> childs;
    TreeNode() : isWord(false), childs (26, nullptr) {}
};

class Trie {
public:
    Trie(vector<string> strs) : root(new TreeNode()) {
        for (const auto &str : strs) {
            TreeNode *curr = root;
            for (const auto c : str) {
                int idx = c - 'a';
                if (!curr->childs[idx])
                    curr->childs[idx] = new TreeNode();
                curr = curr->childs[idx];
            }
            curr->isWord = true;
        }
    }

    TreeNode* prefix(string s) {
        TreeNode *curr = root;
        for (const auto &c : s) {
            int idx = c - 'a';
            if (curr)
                curr = curr->childs[idx];
        }
        return curr;
    }

private:
    TreeNode *root;
};

void helper(TreeNode *node, string &curr, string &res) {
    if (node->isWord) {
        if (res.empty() || curr.size() > res.size()) {
            res = curr;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (node->childs[i]) {
            curr += static_cast<char>('a' + i);
            helper(node->childs[i], curr, res);
            curr.pop_back();
        }
    }
}

string AutoComplete(string s, vector<string> dict) {
    Trie tree(dict);
    TreeNode *root = tree.prefix(s);
    if (!root) return "";
    string res;
    string curr = s;
    helper(root, s, res);
    return res;
}

int main() {
    vector<string> dict {"uberpool", "ubershareride", "ubereat"};
    auto res = AutoComplete("uber", dict);
    cout << res << endl;
}
