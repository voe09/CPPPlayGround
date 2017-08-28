/*
Given a non-empty string s and a dictionary wordDict containing a list of 
non-empty words, determine if s can be segmented into a space-separated 
sequence of one or more dictionary words. You may assume the dictionary does not
contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty()) return false;
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        set<string> words(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                dp[i] = dp[i] || (dp[j] && words.count(s.substr(j, i - j)));
            }
        }
        return dp[n];
    }
};
