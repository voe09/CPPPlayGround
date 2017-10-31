/*
Given two array of integers(the first array is array A, the second array is
array B), now we are going to find a element in array A which is A[i], and
another element in array B which is B[j], so that the difference between A[i]
and B[j] (|A[i] - B[j]|) is as small as possible, return their smallest difference.

Have you met this question in a real interview? Yes
Example
For example, given array A = [3,6,7,4], B = [2,8,9,3], return 0

Challenge 
O(n log n) time
 */

class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int res = INT_MAX;
        if (A.size() > B.size()) {
            for (const auto &num : B) {
                res = min(res, abs(num - findClosest(A, num)));
            }
        } else {
            for (const auto &num : A) {
                res = min(res, abs(num - findClosest(B, num)));
            }
        }
        return res;
    }

private:
    int findClosest(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return (abs(target - nums[left]) < abs(target - nums[right])) ? nums[left] : nums[right];
    }
};
