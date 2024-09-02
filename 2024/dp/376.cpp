class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int peak = 1, valley = 1;
        for (int i = 1; i < nums.size();  i++) {
            if (nums[i] > nums[i-1]) peak = max(peak, valley + 1);
            else if (nums[i] < nums[i-1]) valley = max(valley, peak+1);
        }

        return max(peak, valley);
    }
};


// O(n^2)

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 1, dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i][0] = max(dp[j][1] + 1, dp[j][0]);
                else if (nums[i] < nums[j]) dp[i][1] = max(dp[j][0] + 1, dp[j][1]);
                else {
                    dp[i][0] = dp[j][0];
                    dp[i][1] = dp[j][1];
                }
            }
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};