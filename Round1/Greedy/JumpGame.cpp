/*
Given an array of non-negative integers, you are initially positioned at the
first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
 */


// TLE
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> des(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            int jump = nums[i];
            des[i] = i + jump;
            for (int j = 1; j <= jump && i + j < n; ++j)
                des[i] = max(des[i], des[i + j]);
        }
        return (des[0] >= n - 1);
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxIndex || maxIndex >= nums.size() - 1) break;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return maxIndex >= nums.size() - 1;
    }
};


// dp[i] = max(dp[i - 1], A[i - 1]) - 1
class Solution {
public:
    bool canJump(int A[], int n) {
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1], A[i - 1]) - 1;
            if (dp[i] < 0) return false;
        }
        return dp[n - 1] >= 0;
    }
};


class Solution {
public:
    bool canJump(int A[], int n) {
        int maxIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (i > maxIdx || maxIdx >= n - 1) break;
            maxIdx = max(maxIdx, i + A[i]);
        }
        return maxIdx >= n - 1;
    }
};
