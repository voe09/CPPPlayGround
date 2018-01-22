/*
Given 3*n + 1 numbers, every numbers occurs triple times except one, find it.

Have you met this question in a real interview? Yes
Example
Given [1,1,2,3,3,3,2,2,4,1] return 4

Challenge 
One-pass, constant extra space.
 */

class Solution {
public:
    /*
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < A.size(); ++j) {
                sum += (A[j] >> i) & 1;
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
};
