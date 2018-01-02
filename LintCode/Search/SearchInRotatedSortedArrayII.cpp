/*
Follow up for Search in Rotated Sorted Array:

What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Have you met this question in a real interview? Yes
Example
Given [1, 1, 0, 1, 1, 1] and target = 0, return true.
Given [1, 1, 1, 1, 1, 1] and target = 0, return false.
 */

class Solution {
public:
    /*
     * @param A: an integer ratated sorted array and duplicates are allowed
     * @param target: An integer
     * @return: a boolean
     */
    bool search(vector<int> &A, int target) {
        // write your code here
        int left = 0, right = A.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) return true;
            if (A[left] < A[mid]) { // left sorted
                if (A[mid] > target && A[left] <= target) right = mid - 1;
                else left = mid + 1;
            } else if (A[left] > A[mid]) {
                if (A[mid] < target && A[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else ++left;
        }
        return false;
    }
};
