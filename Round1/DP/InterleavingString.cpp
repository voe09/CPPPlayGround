/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), l = s3.size();
        if (m + n != l) return false;
        vector<vector<vector<bool>>> dp(m + 1, vector<vector<bool>>(n + 1, vector<bool>(l + 1, false)));
        dp[0][0][0] = true;
        
        for (int k = 1; k <= l; ++k) {
            int min_s1_length = std::max(0, k - n);
            for (int i = min_s1_length; i <= std::min(m, k); ++i) {
                if (i == 0) {
                    dp[i][k - i][k] = dp[i][k - i - 1][k - 1] && s2[k - i - 1] == s3[k - i - 1];
                } else if (i == k) {
                    dp[i][k - i][k] = dp[i - 1][k - i][k - 1] && s1[i - 1] == s3[k - 1];
                } else {
                    dp[i][k - i][k] = ((dp[i - 1][k - i][k - 1] && s1[i - 1] == s3[k - 1])
                            || (dp[i][k - i - 1][k - 1] && s2[k - i - 1] == s3[k - 1]));
                }
            }
        }

        return dp[m][n][l];
    }
};


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<bool> > dp(n1 + 1, vector<bool> (n2 + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n1; ++i) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        for (int i = 1; i <= n2; ++i) {
            dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
        }
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i]);
            }
        }
        return dp[n1][n2];
    }
};
