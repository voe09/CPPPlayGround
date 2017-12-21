/*
Given an unsorted integer array, find the first missing positive integer.

Have you met this question in a real interview? Yes
Example
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Challenge 
Your algorithm should run in O(n) time and uses constant space.
 */

class Solution {
public:
    /*
     * @param A: An array of integers
     * @return: An integer
     */
    int firstMissingPositive(vector<int> &A) {
        // write your code here
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            while (A[i] > 0 && A[i] <= n && A[i] != i + 1) {
                int idx = A[i] - 1;
                if (A[i] == A[idx]) break;
                swap(A[i], A[idx]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (A[i] <= 0 || A[i] > n || A[i] != i + 1) return i + 1;
        }

        return A.size() + 1;
    }
};
