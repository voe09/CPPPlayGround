/*
 * Calculate the sum of two integers a and b, but you are not allowed to use 
 * the operator + and -.
 * Example:
 * Given a = 1 and b = 2, return 3.
 */

class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if ((a >> i) & 1 && (b >> i) & 1) {
                res += (1 << (i + 1));
            } else if ((a >> i) & 1 || (b >> i) & 1) {
                res += (1 << i);
            }
        }
        return res;
    }
};
