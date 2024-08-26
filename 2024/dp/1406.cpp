/* OOM
*/
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        for (int i = 0; i < n; i++) dp[i][i] = stoneValue[i];
        for (int gap = 1; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = i + gap;
                dp[i][j] = max(dp[i][j], stoneValue[i] - dp[i+1][j]); 
                dp[i][j] = max(dp[i][j], stoneValue[i] + stoneValue[i+1] - (i + 2 > j ? 0 : dp[i+2][j]));
                if (gap > 1) dp[i][j] = max(dp[i][j], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - (i+3 > j ? 0 : dp[i+3][j]));
            }
        }
        return dp[0][n-1] == 0 ? "Tie" : (dp[0][n-1] > 0 ? "Alice" : "Bob");
    }
};



class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MIN));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < min(3, n - i); j++) {
                int sum = accumulate(stoneValue.begin() + i, stoneValue.begin() + i + j + 1, 0);
                if (i + j == n - 1) dp[i][j] = max(dp[i][j], sum);
                else {
                    int mxLoss = maxLoss(dp, i, j);
                    dp[i][j] = max(dp[i][j], sum - mxLoss);
                }
            }
        }
        
        if (dp[0][0] > 0) return "Alice";
        if (dp[0][1] > 0) return "Alice";
        if (dp[0][2] > 0) return "Alice";
        if (dp[0][0] == 0) return "Tie";
        if (dp[0][1] == 0) return "Tie";
        if (dp[0][2] == 0) return "Tie";
        return "Bob";
    }

    int maxLoss(vector<vector<int>>& dp, int i, int j) {
        int n = dp.size();
        int res = INT_MIN;
        for (int k = 0; k < min(3, n - 1 - i - j); k++) {
            res = max(res, dp[i+j+1][k]);
        }
        return res;
    }
};