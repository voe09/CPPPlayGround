/*
Given a positive integer n, break it into the sum of at least two positive 
integers and maximize the product of those integers. Return the maximum 
product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, 
return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 1;
        if (n == 2) return dp[1];
        for (int i = 3; i <= n; ++i) {
            for (int j = 2; j < i; ++j) {
                int tmp = max(dp[j - 1] * dp[i - j - 1], dp[j - 1] * (i - j));
                tmp = max(tmp, j * (i - j));
                dp[i - 1] = max(dp[i - 1], tmp);
            }
        }
        return dp[n - 1];
    }
};
