/*
Given an array and a window size that is sliding along the array, 
find the sum of the count of unique elements in each window.

Have you met this question in a real interview? Yes
Example
Given a array nums = [1, 2, 1, 3, 3] and k = 3

First window [1, 2, 1], only 2 is unique, count is 1.
Second window [2, 1, 3], all elements unique, count is 3.
Third window [1, 3, 3], only 1 is unique, count is 1.
sum of count = 1 + 3 + 1 = 5

Return 5
 */

class Solution {
public:
    /*
     * @param : the given array
     * @param : the window size
     * @return: the sum of the count of unique elements in each window
     */
    int slidingWindowUniqueElementsSum(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, int> m;
        unordered_set<int> uniqueSet;
        int left = 0, right = 0;
        int res = 0;
        while (right < nums.size() && right < k) {
            int num = nums[right];
            ++m[num];
            if (m[num] == 1) uniqueSet.insert(num);
            else if (m[num] > 0) uniqueSet.erase(num);
            ++right;
        }
        res += uniqueSet.size();
        while (right < nums.size()) {
            --m[nums[left]];
            ++m[nums[right]];
            if (m[nums[left]] == 0) uniqueSet.erase(nums[left]);
            else if (m[nums[left]] == 1) uniqueSet.insert(nums[left]);
            if (m[nums[right]] == 1) uniqueSet.insert(nums[right]);
            else if (m[nums[right]] > 1) uniqueSet.erase(nums[right]);
            res += uniqueSet.size();
            ++left, ++right;
        }
        return res;
    }
};
