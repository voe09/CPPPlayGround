/*
具体介绍一下这个题， input是String[] array(大小写都有), 和一个String name（全小写）
输出要求有点复杂，在name一个个substring里找，如果这个substring没有在array里出现过，
就直接输出。如果在array里出现过，就找尽量长的可以在array里匹配得到的，
然后把第一个字母变成大写并且前后加上[]符号再输出
比如array = {"b", "Bc", "e"}  name = "abcde";
output就是a[Bc]d[E]
这里因为b可以匹配到b，bc可以匹配到bc而且更长所以答案就是这样
 */


class TreeNode {
    bool isWord;
    bool isUpper;
    vector<TreeNode*> subs;
    TreeNode() : isWord(false), isUpper(false), subs(26, nullptr) {}
};

TreeNode* ConstructTrie(vector<string> &dict) {
    TreeNode *root = TreeNode();
    for (const auto &word : dict) {
        TreeNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = (word[i] >= 'a' && word[i] <= 'z') ? word[i] - 'a' : word[i] - 'A';
            if (!word[idx]) word[idx] = new TreeNode();
            curr = curr->subs[idx];
            if (word[i] >= 'A' && word[i] <= 'Z') curr->isUpper = true;
        }
        curr->isWord = true;
    }
}

string isInDict(TreeNode *curr, string &s, int start, int end) {
    vector<string> res;
    string tmp;
    for (int i = start; i <= end; ++i) {
        int idx = s[i] - 'a';
        if (!curr->subs[idx]) return "";
        else {
            curr = curr->subs[idx];
            if (curr
        }
    }
}

string Resemble(vector<string> &dict, string &name) {
    TreeNode* root = ConstructTrie(dict);

    string res;
    int i = 0;
    while (i < name.size()) {
        int 
    }
}
