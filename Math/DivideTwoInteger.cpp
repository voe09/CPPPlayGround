/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

// 二分法找
ass Solution {
public:
    int divide(int dividend, int divisor) {        
        int sign;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            sign = 1;
        else
            sign = -1;
        

        
        if (divisor == INT_MIN) {
            if (dividend == divisor) return 1;
            else return 0;
        }
        
        int overflow = 0;
        if (dividend == INT_MIN) {
            dividend += 1;
            overflow = 1;
        }
        
        dividend = std::abs(dividend);
        divisor = std::abs(divisor);
        
        
        int res = 0;
        while (dividend >= divisor) {
            std::cout << "before: " << dividend << std::endl;
            int shift = 1;
            while ((dividend > (divisor << shift)) && (divisor << shift) > 0 && shift < 32)
                ++shift;
            --shift;
            dividend -= (divisor << shift);
            if (overflow == 1) {
                dividend += 1;
                overflow -= 1;
            }
            std::cout << "after: " << dividend << std::endl;
            res += (1 << shift);
            if (res == INT_MAX && dividend >= divisor && sign == 1) return INT_MAX;
            if (res == INT_MAX && dividend >= divisor && sign == -1) return INT_MIN;
        }
        res = (sign > 0) ? res : -res;
        return res;
    }
};
