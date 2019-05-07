/*
Given an array of integers, the majority number is the number that occurs more than half of the size of the array. Find it.

 Notice

You may assume that the array is non-empty and the majority number always exist in the array.

Have you met this question in a real interview? Yes
Example
Given [1, 1, 1, 1, 2, 2, 2], return 1

Challenge 
O(n) time and O(1) extra space
 */

class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
        // write your code here
        int cnt = 0;
        int res;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt == 0) {
                res = nums[i];
                ++cnt;
            }
            else {
                if (res == nums[i]) ++cnt;
                else --cnt;
            }
        }
        return res;
    }
};
