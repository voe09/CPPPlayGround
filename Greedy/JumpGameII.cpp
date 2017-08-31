/*
Given an array of non-negative integers, you are initially positioned at the 
first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from 
index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
 */

// 同样可以用greedy解决。与I不同的是，求的不是对每个i，从A[0:i]能跳到的最远距离
// 而是计算跳了k次后能达到的最远距离，这里的通项公式为：

// greedy: d[k] = max(i+A[i])     d[k-2] < i <= d[k-1]


// DP
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] != INT_MAX && j + A[j] >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};

// Greedy: http://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int last = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (i > last) {
                last = curr;
                ++res;
            }
            curr = max(curr, i + nums[i]);
        }
        return res;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curr_far = 0, most_far = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (most_far >= n - 1) break;
            if (i < most_far) {
                curr_far = max(curr_far, i + nums[i]);
            }
            if (i >= most_far) {
                curr_far = max(curr_far, i + nums[i]);
                most_far = curr_far;
                ++res;
            }
        }
        return res;
    }
};
