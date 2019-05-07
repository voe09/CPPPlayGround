/*
Find K-th largest element in an array.

You can swap elements in the array

Have you met this question in a real interview? Yes
Example
In array [9,3,2,4,8], the 3rd largest element is 4.

In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.

Challenge 
O(n) time, O(1) extra memory.
 */

class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int partition(vector<int> &nums, int start, int end) {
        int pivot = nums[end];

        int i = start;
        for (int j = start; j <= end; ++j) {
            if (nums[j] >= pivot) {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
        return i - 1;
    }

    int quickSort(vector<int> &nums, int start, int end, int k) {
        if (start < end) {
            int pivot = partition(nums, start, end);
            if (pivot == k) return nums[pivot];
            else if (pivot < k) return quickSort(nums, pivot + 1, end, k);
            else return quickSort(nums, start, pivot - 1, k);
        }
        return nums[start];
    }

    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        int length = nums.size() - 1;
        return quickSort(nums, 0, length, n - 1);
    }
};
