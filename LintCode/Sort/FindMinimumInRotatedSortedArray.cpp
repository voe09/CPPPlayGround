/*
Suppose a sorted array is rotated at some pivot unknown to \
you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

 Notice

You may assume no duplicate exists in the array.

Have you met this question in a real interview? Yes
Example
Given [4, 5, 6, 7, 0, 1, 2] return 0
 */

class Solution {
public:
    /*
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> nums) {
        // write your code here
        int left = 0, right = nums.size() - 1;
        if (nums[left] < nums[right]) return nums[left];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[left]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
