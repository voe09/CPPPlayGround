/*
Given an array S of n integers, find three integers in S such that the sum is 
closest to a given number, target. Return the sum of the three integers.

 Notice

You may assume that each input would have exactly one solution.

Have you met this question in a real interview? Yes
Example
For example, given array S = [-1 2 1 -4], and target = 1. The sum that is 
closest to the target is 2. (-1 + 2 + 1 = 2).

Challenge 
O(n^2) time, O(1) extra space
 */

class Solution {
public:
    /*
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        // write your code here
        sort(numbers.begin(), numbers.end());

        int dist = INT_MAX, res;
        for (int i = 0; i < numbers.size() - 2; ++i) {
            int tmp = twoSumClosest(numbers, i + 1, target - numbers[i]);
            if (dist > abs(target - numbers[i] - tmp)) {
                dist = abs(target - numbers[i] - tmp);
                res = numbers[i] + tmp;
            }
        }
        return res;
    }

private:
    int twoSumClosest(vector<int> &nums, int idx, int target) {
        int left = idx, right = nums.size() - 1;
        int dist = INT_MAX, res;
        int curSum = 0;
        while (left < right) {
            curSum = nums[left] + nums[right];
            if (dist > abs(curSum - target)) {
                dist = abs(curSum - target);
                res = curSum;
            }
            if (curSum > target) --right;
            else if (curSum < target) ++left;
            else return curSum;
        }
        return res;
    }
};
