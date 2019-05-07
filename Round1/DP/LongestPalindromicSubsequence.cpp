/*
Given a string s, find the longest palindromic subsequence's length in s. 
You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
 */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                if (s[i] == s[i + k - 1])
                    dp[i][i + k - 1] = dp[i + 1][i + k -2] + 2;
                else
                    dp[i][i + k - 1] = max(dp[i][i + k - 2], dp[i + 1][i + k - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
