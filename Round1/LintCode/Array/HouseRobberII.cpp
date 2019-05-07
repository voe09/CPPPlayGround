/*
After robbing those houses on that street, the thief has found himself a new 
place for his thievery so that he will not get too much attention. This time, 
all houses at this place are arranged in a circle. That means the first house 
is the neighbor of the last one. Meanwhile, the security system for these houses 
remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each 
house, determine the maximum amount of money you can rob tonight without alerting the police.

 Notice

This is an extension of House Robber.

Have you met this question in a real interview? Yes
Example
nums = [3,6,4], return 6
 */

class Solution {
public:
    /*
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> nums) {
        // write your code here
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp1 (n + 1, 0);
        vector<int> dp2 (n + 1, 0);

        dp1[0] = 0, dp2[0] = 0;
        dp1[1] = 0, dp2[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
            if (i != n) {
                dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
            } else {
                dp2[i] = dp2[i - 1];
            }
        }
        return max(dp1[n], dp2[n]);
    }
};


class Solution {
public:
    /*
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> nums) {
        // write your code here
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        int n = nums.size();
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }

private:
    int rob(vector<int>& nums, int left, int right) {
        int length = right - left + 1;
        if (length <= 2)
            return length == 1 ? nums[left] : max(nums[left], nums[right]);
        int a = 0, b = nums[left];
        for (int i = left + 1; i <= right; ++i) {
            int tmp = max(a + nums[i], b);
            a = b;
            b = tmp;
        }
        return b;
    }
};
