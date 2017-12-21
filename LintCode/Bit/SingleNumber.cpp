/*
Given 2*n + 1 numbers, every numbers occurs twice except one, find it.

Have you met this question in a real interview? Yes
Example
Given [1,2,2,1,3,4,3], return 4

Challenge 
One-pass, constant extra space.
 */

class Solution {
public:
    /*
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        // write your code here
        int res = 0;
        for (const auto &num : A) {
            res ^= num;
        }
        return res;
    }
};
