/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different
substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
 */
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            if (i < n - 1)
                dp[i + 1][i] = true;
        }
        int res = n;
        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                dp[i][i + k - 1] = (dp[i + 1][i + k - 2] && s[i] == s[i + k - 1]);
                if (dp[i][i + k - 1]) ++res;
            }
        }
        return res;
    }
};


