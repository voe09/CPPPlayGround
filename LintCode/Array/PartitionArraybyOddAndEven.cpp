/*
Partition an integers array into odd number first and even number second.

Have you met this question in a real interview? Yes
Example
Given [1, 2, 3, 4], return [1, 3, 2, 4]

Challenge 
Do it in-place.
 */

class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            while (start < end && nums[start] % 2 == 1) ++start;
            while (start < end && nums[end] % 2 == 0) --end;
            if (start < end) {
                swap(nums[start], nums[end]);
                ++start, --end;
            }
        }
    }
};
