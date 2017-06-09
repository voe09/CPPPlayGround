/*
 * Calculate the sum of two integers a and b, but you are not allowed to use 
 * the operator + and -.
 * Example:
 * Given a = 1 and b = 2, return 3.
 */

class Solution {
public:
    int getSum(int a, int b) {
        int res = 0, carry = 0;
        for (int i = 0; i < 32; a >>= 1, b >>= 1, ++i) {
            int last_a = a & 1;
            int last_b = b & 1;
            res |= (last_a ^ last_b ^ carry) << i;
            carry = (last_a & last_b) | (carry & last_a) | (carry & last_b);
        }
        return res;
    }
};
