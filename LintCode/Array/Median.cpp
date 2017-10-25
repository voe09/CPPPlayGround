/*
Given a unsorted array with integers, find the median of it.

A median is the middle number of the array after it is sorted.

If there are even numbers in the array, return the N/2-th number
after sorted.

Have you met this question in a real interview? Yes
Example
Given [4, 5, 1, 2, 3], return 3.

Given [7, 9, 4, 5], return 5.
 */

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the middle number of the array
     */
    int median(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int limit = (n % 2 == 0) ? n / 2: n / 2 + 1;
        priority_queue<int> heap;
        for (int i = 0; i < n; ++i) {
            if (heap.size() < limit) heap.push(nums[i]);
            else {
                if (nums[i] < heap.top()) {
                    heap.pop();
                    heap.push(nums[i]);
                }
            }
        }
        return heap.top();
    }
};

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the middle number of the array
     */
    int median(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if (n % 2 == 0) return helper(nums, n / 2 - 1, 0, n - 1);
        else return helper(nums, n / 2, 0, n - 1);
    }

private:
    int helper(vector<int> &nums, int idx, int start, int end) {
        int l = start, r = end;
        int pivot = start;
        while (l < r) {
            while (l < r && nums[l] < nums[pivot]) ++l;
            while (l < r && nums[r] > nums[pivot]) --r;
            if (l != r) {
                swap(nums[l], nums[r]);
            }
        }
        swap(nums[l], nums[pivot]);
        if (l == idx) return nums[l];
        else if (l < idx) return helper(nums, idx, l + 1, end);
        else return helper(nums, idx, start, l - 1);
    }
};
