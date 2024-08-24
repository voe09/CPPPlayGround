class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> sum = piles;
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for (int i = n - 2; i >= 0; i--) sum[i] += sum[i+1];
        for (int i = 0; i < n; i++) dp[i][n] = sum[i];

        for (int i = n-1; i >= 0; i--) {
            for (int m = n; m >= 1; m--) {
                for (int x = 1; x <= 2 * m && i + x <= n; x++) {
                    dp[i][m] = max(dp[i][m], sum[i] - dp[i+x][max(x, m)]);
                }
            }
        }

        return dp[0][1];
    }
};