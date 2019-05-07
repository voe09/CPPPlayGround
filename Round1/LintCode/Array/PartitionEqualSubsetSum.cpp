/*
Given a non-empty array containing only positive integers, find if the array
can be partitioned into two subsets such that the sum of elements in both
subsets is equal.

 Notice

Each of the array element will not exceed 100.
The array size will not exceed 200.

Have you met this question in a real interview? Yes
Example
Given nums = [1, 5, 11, 5], return true
two subsets: [1, 5, 5], [11]

Given nums = [1, 2, 3, 9], return false
 */

// TLE
class Solution {
public:
    /*
     * @param nums: a non-empty array only positive integers
     * @return: true if can partition or false
     */
    bool canPartition(vector<int> &nums) {
        // write your code here
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        for (int i = 0; i < nums.size(); ++i) {
            if (helper(nums, i, sum / 2, 0)) return true;
        }
        return false;
    }

private:
    bool helper(vector<int> &nums, int idx, int target, int curSum) {
        curSum += nums[idx];
        if (curSum == target) return true;
        if (curSum > target) return false;

        for (int i = idx + 1; i < nums.size(); ++i) {
            if (helper(nums, i, target, curSum)) return true;
        }

        return false;
    }
};


// DP : dp[j] = dp[j] || dp[j - nums[i]]         (nums[i] <= j <= target)
class Solution {
public:
    /*
     * @param nums: a non-empty array only positive integers
     * @return: true if can partition or false
     */
    bool canPartition(vector<int> &nums) {
        // write your code here
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<bool> dp (target + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
