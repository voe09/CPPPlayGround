/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Have you met this question in a real interview? Yes
Example
Gieve s = lintcode,
dict = ["de", "ding", "co", "code", "lint"].

A solution is ["lint code", "lint co de"].
 */

class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        // write your code here
        vector<string> res;
        string sentence;
        vector<bool> possible (s.size() + 1, true);
        helper(s, wordDict, 0, possible, sentence, res);
        return res;
    }

private:
    void helper(string &s, unordered_set<string> &wordDict, 
            int start, vector<bool> &possible, string &sentence,
            vector<string> &res) {
        if (start == s.size()) {
            res.push_back(sentence.substr(0, sentence.size() - 1));
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            string tmp = s.substr(start, i - start + 1);
            if (wordDict.count(tmp) && possible[i + 1]) {
                sentence += tmp + " ";
                int oldSize = res.size();
                helper(s, wordDict, i + 1, possible, sentence, res);
                if (res.size() == oldSize) possible[i + 1] = false;
                sentence = sentence.substr(0, sentence.size() - (i - start + 1) - 1);
            }
        }
    }
};
