class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        for (int i = 0; i < n; i++) dp[i][i] = piles[i];
        for (int gap = 1; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = i + gap;
                dp[i][j] = max(dp[i][j], piles[i] - dp[i+1][j]);
                dp[i][j] = max(dp[i][j], piles[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};