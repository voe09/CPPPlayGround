/*
Given an array with n integers, your task is to check if it could become 
non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 
4
 to 
1
 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].
 */

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0, j = 1; j < nums.size(); ++i, ++j) {
            if (nums[i] > nums[j]) {
                if (j == nums.size() - 1) return true;
                if (i > 0)
                    return checkNonDecreasing(nums, i - 1, i) || checkNonDecreasing(nums, i, j);
                else 
                    return checkNonDecreasing(nums, i + 1, i) || checkNonDecreasing(nums, i, j);
            }
        }
        return true;
    }

private:
    bool checkNonDecreasing(vector<int> &nums, int start, int skip) {
        for (int i = start, j = start + 1; j < nums.size(); ++i, ++j) {
            if (i == skip) ++i;
            else if (j == skip) ++j;
            if (nums[i] > nums[j]) return false;
        }
        return true;

    }
};
