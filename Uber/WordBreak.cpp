/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

bool WordBreak(string s, unordered_set<string> &dict) {
    if (s.empty()) return true;
    int n = s.size();
    vector<bool> dp (n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = dp[i] || (dp[j] && dict.count(s.substr(j, i - j)));
        }
    }
    return dp[n];
}

int main() {
    unordered_set<string> dict {"uber", "ride", "pool", "eats"};
    cout << WordBreak("uberride", dict) << endl;
    cout << WordBreak("ubereat", dict) << endl;
}
