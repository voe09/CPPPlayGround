/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
 */

// https://en.wikipedia.org/wiki/Trailing_zero

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int k = 1;
        while (power(5, k) <= n) {
            res += n / (pow(5, k));
            ++k;
        }
        return res;
    }
};
