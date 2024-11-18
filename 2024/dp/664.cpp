class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            // j - i + 1 = len => j = i - 1 + len < n
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = 1 + dp[i+1][j];
                for (int k = i + 1; k <= j; k++) {
                    if (s[k] == s[i]) dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]);
                }
            }
        }

        return dp[0][n-1];
    }
}; 