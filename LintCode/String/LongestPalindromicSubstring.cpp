/*
Given a string S, find the longest palindromic substring in S. You may assume 
that the maximum length of S is 1000, and there exists one unique longest 
palindromic substring.

Example
Given the string = "abcdzdcab", return "cdzdc".

Challenge 
O(n2) time is acceptable. Can you do it in O(n) time.
 */

class Solution {
public:
    /*
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        string res;
        if (s.empty()) return res;
        int n = s.size();
        vector<vector<bool>> dp (n, vector<bool>(n, false));
        for (int gap = 0; gap < n; ++gap) {
            for (int i = 0; i < n - gap; ++i) {
                if (gap == 0) dp[i][i + gap] = true;
                else if (gap == 1) dp[i][i + gap] = (s[i] == s[i + gap]);
                else
                    dp[i][i + gap] = (s[i] == s[i + gap] && dp[i + 1][i + gap - 1]);
                if (dp[i][i + gap]) {
                    if (gap + 1 > res.size()) res = s.substr(i, gap + 1);
                }
            }
        }
        return res;
    }
};
