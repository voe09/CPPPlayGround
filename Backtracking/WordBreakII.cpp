/*
Given a non-empty string s and a dictionary wordDict containing a list of 
non-empty words, add spaces in s to construct a sentence where each word is
a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

// TLE
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> possible(s.size() + 1, true);
        vector<string> sentence;
        DFS(s, 0, sentence, words, possible, res);
        return res;
    }

private:
    void DFS(string& s, int start, vector<string>& sentence, unordered_set<string>& words,
            vector<bool>& possible, vector<string>& res) {
        if (start >= s.size()) {
            if (!sentence.empty()) {
                string tmp = "";
                for (int i = 0; i < sentence.size() - 1; ++i) {
                    tmp += sentence[i] + " ";
                }
                tmp += sentence.back();
                res.push_back(tmp);
            }
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            string tmp = s.substr(start, i - start + 1);
            if (words.count(tmp) && possible[i + 1]) {
                sentence.push_back(tmp);
                int oldSize = res.size();
                DFS(s, i + 1, sentence, words, possible, res);
                if (res.size() == oldSize) possible[i + 1] = false;
                sentence.pop_back();
            }
        }
    }
};


// 定义一个一位数组possible，其中possible[i] = true表示在[i, n]区间上有解，n为s的长度，如果某个区间之前被判定了无解，下次循环时就会跳过这个区间，从而大大减少了运行时间
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        string out;
        vector<bool> possible(s.size() + 1, true);
        wordBreakDFS(s, wordDict, 0, possible, out, res);
        return res;
    }
    void wordBreakDFS(string &s, unordered_set<string> &wordDict, int start,
            vector<bool> &possible, string &out, vector<string> &res) {
        if (start == s.size()) {
            res.push_back(out.substr(0, out.size() - 1));
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string word = s.substr(start, i - start + 1);
            if (wordDict.find(word) != wordDict.end() && possible[i + 1]) {
                out.append(word).append(" ");
                int oldSize = res.size();
                wordBreakDFS(s, wordDict, i + 1, possible, out, res);
                if (res.size() == oldSize) possible[i + 1] = false;
                out.resize(out.size() - word.size() - 1);
            }
        }
    }
};
