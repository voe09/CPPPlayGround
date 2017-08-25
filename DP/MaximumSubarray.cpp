/*
Find the contiguous subarray within an array (containing at least one number) 
which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using
the divide and conquer approach, which is more subtle.
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        int maxVal = nums[0];
        int dp = nums[0];
        for (int i = 1; i < n; ++i) {
            dp = (dp > 0) ? dp + nums[i] : nums[i];
            maxVal = std::max(maxVal, dp);
        }
        return maxVal;
    }
};
