/*
Given an array of integers, find a contiguous subarray which has the
largest sum.

 Notice

The subarray should contain at least one number.

Have you met this question in a real interview? Yes
Example
Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1]
has the largest sum = 6.

Challenge 
Can you do it in time complexity O(n)?
 */

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        int left = 0, right = 0;
        int currSum = 0;
        for (int i = 1; i < nums.size(); ++i) {
            currSum += nums[i];
            if (currSum > 0) {
                right = i;
                currSum = 0;
            }
        }

        currSum = 0;
        for (int i = 0; i < right; ++i) {
            currSum += nums[i];
            if (currSum < 0) {
                left = i + 1;
                currSum = 0;
            }
        }

        int res = 0;
        for (int i = left; i <= right; ++i)
            res += nums[i];
        
        return res;
    }
};


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int res = INT_MIN, curSum = 0;
        for (int num : nums) {
            curSum += num;
            curSum = max(curSum, num);
            res = max(res, curSum);
        }
        return res;
    }
};
