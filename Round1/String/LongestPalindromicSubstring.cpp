/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/


class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len <= 1) return s;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        // Initialization
        for (int i = 0; i < len; ++i) {
            dp[i][i] = true;
            if (i - 1 < 0) continue;
            dp[i][i - 1] = true;
        }
        int max = 1, right = 0, left = 0;
        for (int k = 2; k <= len; ++k) {
            for (int i = 0; i <= len - k; ++i) {
                dp[i][i + k - 1] = (s[i] == s[i + k - 1] && dp [i + 1][i + k - 2]);
                if (dp[i][i + k - 1]) {
                    if (k > max) {
                        max = k;
                        right = i, left = i + k - 1;
                    }
                }
            }
        }
        return s.substr(right, max);
    }
};
