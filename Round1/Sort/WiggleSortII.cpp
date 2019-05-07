/*
Given an unsorted array nums, reorder it such that 
nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
 */

// https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing
// https://github.com/kamyu104/LeetCode/blob/master/C++/wiggle-sort-ii.cpp



class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        int n = nums.size(), k = (n + 1) / 2, j = n;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; ++i) {
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];
        }
    }
};
