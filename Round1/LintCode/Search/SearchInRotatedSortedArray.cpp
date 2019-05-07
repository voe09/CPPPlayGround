/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Have you met this question in a real interview? Yes
Example
For [4, 5, 1, 2, 3] and target=1, return 2.

For [4, 5, 1, 2, 3] and target=0, return -1.

Challenge 
O(logN) time
 */

class Solution {
public:
    /*
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here
        if (A.empty()) return -1;
        int left = 0, right = A.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) return mid;
            if (A[mid] > A[left]) { // left to mid is sorted
                if (A[mid] > target && A[left] <= target)
                    right = mid - 1;
                else
                    left = mid;
            }
            else { // mid to right is sorted
                if (A[mid] < target && A[right] >= target)
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return (A[left] == target) ? left : -1;
    }
};
