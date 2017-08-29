/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number 
on it represented by array nums. You are asked to burst all the balloons. If 
the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
Here left and right are adjacent indices of i. After the burst, the left and 
right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 */

/*
dp[i][j]表示打爆区间[i,j]中的所有气球能得到的最多金币
for each subarray, find the last balloon you need to burst which would maximize the coins
我们可以在原数组两边各填充一个1，这样方便于计算
dp[i][j] = max(dp[i][j], nums[i - 1]*nums[k]*nums[j + 1] + dp[i][k - 1] + dp[k + 1][j])      ( i ≤ k ≤ j )
只是更新了dp数组的右上三角区域，我们最终要返回的值存在dp[1][n]中，其中n是两端添加1之前数组nums的个数
 */


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size() , 0));
        for (int len = 1; len <= n; ++len) {
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    dp[left][right] = max(dp[left][right],
                            nums[left - 1] * nums[k] * nums[right + 1]
                            + dp[left][k - 1] + dp[k + 1][right]);
                }
            }
        }
        return dp[1][n];
    }
};
