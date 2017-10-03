/*
Given a non-negative integer c, your task is to decide whether there're two
integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False
 */

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) return true;
        if (isSquare(c)) return true;
        for (int i = 1; i <= c / 2; ++i ) {
            if ( i < c / i) {
                if (isSquare(c - i * i)) return true;
            } else break;
        }
        return false;
    }

private:
    bool isSquare(int num) {
        long left = 0, right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2, t = mid * mid;
            if (t == num) return true;
            else if (t < num) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};
