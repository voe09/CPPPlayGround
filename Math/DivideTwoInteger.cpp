/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

// 二分法找
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            sign = 1;
        else
            sign = -1;
    }
};
