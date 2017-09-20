/*
Given a list of non-negative numbers and a target integer k, write a function 
to check if the array has a continuous subarray of size at least 2 that sums 
up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
 */
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return false; 
        vector<int> sum(nums);
        for (int i = 1; i < sum.size(); ++i) {
            sum[i] += sum[i - 1];
        }

        for (int i = 0; i < sum.size() - 1; ++i) {
            for (int j = i + 1; j < sum.size(); ++j) {
                int rangeSum;
                if (i = 0) rangeSum = sum[j];
                else rangeSum = sum[j] - sum[i - 1];
                if (rangeSum == k) return true;
                if (k != 0 && rangeSum % k == 0)
                    return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i) {
            int sum = nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k) return true;
                if (k != 0 && sum % k == 0) return true;
            }
        }
        return false;
    }
};
