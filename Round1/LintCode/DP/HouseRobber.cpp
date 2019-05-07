/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security system connected and it will automatically contact the police
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money
of each house, determine the maximum amount of money you can rob tonight
without alerting the police.

Have you met this question in a real interview? Yes
Example
Given [3, 8, 4], return 8.

Challenge 
O(n) time and O(1) memory.
 */

class Solution {
public:
    /*
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        // write your code here
        if (A.empty()) return 0;
        int n = A.size();
        vector<long long> dp(n + 1, 0);
        dp[1] = A[0];
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + A[i - 1]);
        }
        return dp[n];
    }
};
