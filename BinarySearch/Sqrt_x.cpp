/*
Implement int sqrt(int x).

Compute and return the square root of x.
 */

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        int low = 0, high = x;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == x / mid) return mid;
            else if (mid > x / mid) high = mid - 1;
            else low = mid + 1;
        }
        return high;
    }
};
