/*
In English, we have a concept called root, which can be followed by some other 
words to form another longer word - let's call this word successor. For example,
the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to
replace all the successor in the sentence with the root forming it. If a 
successor has many roots can form it, replace it with the root with the shortest
length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
 */

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TreeNode* words = ConstructTree(dict);
        stringstream ss(sentence);
        string word;
        string res = "";
        while (ss >> word) {
            string replaceWord = ReplaceWord(words, word);
            res += replaceWord;
            res += " ";
        }
        
        if (res != "") res.resize(res.size() - 1);
        return res;
    }

private:
    struct TreeNode {
        int val;
        vector<TreeNode*> next;
        TreeNode() :val(0), next(26, nullptr) {};
    };

    TreeNode* ConstructTree(vector<string>& dict) {
        TreeNode* root = new TreeNode();
        for (const auto& word : dict) {
            TreeNode* prev = root;
            for (int i = 0; i < word.size(); ++i) {
                if (prev->val == 1) break;
                TreeNode* curr = new TreeNode();
                if (i == word.size() - 1) curr->val = 1;
                if (!prev->next[word[i] - 'a']) {
                    prev->next[word[i] - 'a'] = curr;
                } else {
                    if (curr->val == 1 || prev->next[word[i] - 'a']->val == 1)
                        prev->next[word[i] - 'a']->val = 1;
                }
                prev = prev->next[word[i] - 'a'];
            }
        }
        return root;
    }

    string ReplaceWord(TreeNode* root, string& word) {
        TreeNode* curr = root;
        string replaced = "";
        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (!curr->next[idx]) return word;
            curr = curr->next[idx];
            replaced += word[i];
            if (curr->val == 1) return replaced;
        }
        return word;
    }
};
