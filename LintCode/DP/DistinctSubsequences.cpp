/*
Given a string S and a string T, count the number of distinct 
subsequences of T in S.

A subsequence of a string is a new string which is formed from the 
original string by deleting some (can be none) of the characters without 
disturbing the relative positions of the remaining characters. (ie, "ACE" is a
subsequence of "ABCDE" while "AEC" is not).

Have you met this question in a real interview? Yes
Examplerabb
Given S = "rabbbit", T = "rabbit", return 3.

Challenge 
Do it in O(n2) time and O(n) memory.

O(n2) memory is also acceptable if you do not know how to optimize memory.
 */

class Solution {
public:
    /*
     * @param : A string
     * @param : A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string S, string T) {
        // write your code here
        int m = S.size(), n = T.size();
        if (m < n) return numDistinct(T, S);
        vector<vector<int>> dp (m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i) dp[i][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= min(i, n); ++j) {
                if (S[i - 1] != T[j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
